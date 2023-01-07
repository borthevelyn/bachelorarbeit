module Translator.OpenMPWriter
open Translator.PathAnalyzer
open Averest.MiniC.DataflowProcessNetworks
open Translator.CommonWriter

let tabSpace = "    "
let tabSpace2 = "       "
let tabSpace3 = "           "
let tabSpace4 = "               "

let generateOpenMPCode dpn (bufferTypes : Map<string, string>) (pathsAndBuffers : Set<(int list) * PathBuffers>) : string =
    let mutable code = ""
    let mutable count = 0
    let mutable calc = dpn.inVars
    
    printfn "Enter data size:"
    let datasize = int32 (System.Console.ReadLine())
    printfn "Enter input:"
    let input = System.Console.ReadLine()
    let inputArray = input.Split ','
   
    code <- sprintf "%s#include<stdio.h>\n#include<omp.h>\n#define DATA_SIZE %d\n\n" code datasize

    for pathBuffer in pathsAndBuffers do
        let (path, buffer) = pathBuffer
        code <- code + generateMethodCode dpn bufferTypes path buffer ("path" + (count.ToString()))
        count <- count + 1
    
    count <- 0
    code <- sprintf "%sauto start = chrono::steady_clock::now();" code
    code <- sprintf "%sint main() { \n%sint inputs[] = {%s} \n%sint outputs = [DATA_SIZE * 2]\n" code tabSpace input tabSpace
           
    let paths = pathsAndBuffers |> Set.toList
    let mutable remainingPaths = {0..paths.Length-1}
                                |>Seq.toList
    
    code <- sprintf "%s%s#pragma omp parallel for \n%sfor (int i = 0; i < DATA_SIZE; i++) {\n" code tabSpace tabSpace

    dpn.inVars |> Set.iter (fun x  -> 
    code <- sprintf "%s%s%s %s = inputs[i * %d + %d];\n" code tabSpace2 bufferTypes[x] (x.ToString()) dpn.inVars.Count count
    count <- count + 1
    )

    for i in remainingPaths do
        let (_, output) = snd paths[i]
        output|> List.iter(fun x -> code <- sprintf "%s%s%s %s;\n" code tabSpace2 bufferTypes[x] x)

    while not (remainingPaths.IsEmpty) do
        let mutable executablePaths = List.Empty
        for i in remainingPaths do
            let (input,_) = snd paths[i]
            if List.forall calc.Contains input then
                // path can be executed
                executablePaths <- i::executablePaths
                remainingPaths <- List.removeAt(List.findIndex (fun x-> x = i) remainingPaths) remainingPaths
        
        for i in executablePaths do
            let (_, output) = snd paths[i]
            calc <- calc |> Set.union (output |> Set.ofList)
        
        let writePath name input output tabSpace =
            code <- sprintf "%s%spath%d(" code tabSpace name  
            input |> List.iter (fun x -> code <- sprintf "%s%s, " code x)
            output |> List.iter (fun x -> code <- sprintf "%s&%s, "code x)
            code <- code[0 ..  code.Length - 3] + ");\n"

        if (executablePaths.Length = 1) then
            let (input,output) = snd paths[executablePaths[0]]
            writePath executablePaths[0] input output tabSpace2
        else 
            code <- sprintf "%s%s#pragma omp parallel sections\n%s{\n" code tabSpace2 tabSpace2
            for i in executablePaths do
                let (input, output) = snd paths[i]
                code <-sprintf "%s%s#pragma omp section\n" code tabSpace3
                writePath i input output tabSpace4

            code <- sprintf "%s%s}\n" code tabSpace2
    
    count <- 0
    dpn.outVars |> Set.iter (fun x -> 
        code  <- sprintf"%s%s outputs[i * %d + %d] = %s;\n"code  tabSpace2  dpn.outVars.Count  count  x 
        count <- count + 1
        )
    code <- sprintf "%s%s}\n"code tabSpace
    
    let mutable i = 0
    while(i < inputArray.Length) do
        code <-sprintf "%sprintf(" code
        for out in dpn.outVars do
            code <- sprintf "%s%s: %%i, " code out
        code <- code[0 ..  code.Length - 3] + ","
        count <- 0
        dpn.outVars |> Set.iter (fun x -> 
            code  <- sprintf"%soutputs[%d],"code  (i*dpn.outVars.Count + count )  
            count <- count + 1
            )
        code <- code[0 ..  code.Length - 2] + ");\n"
        i<- i+1

    code <- sprintf "%sauto end = chrono::steady_clock::now();\nprintf(\"time: %%i\", (end - start).count());" code
    code
    
    