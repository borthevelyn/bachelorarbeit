module Translator.OpenMPWriter
open Translator.PathAnalyzer
open Averest.MiniC.DataflowProcessNetworks
open Translator.CommonWriter
open Averest.MiniC.Types
open Types

let tabSpace = "    "
let tabSpace2 = "       "
let tabSpace3 = "           "
let tabSpace4 = "               "

let generateOpenMPCode dpn (buffers : Map<string, Buffer>) (pathsAndBuffers : Set<(int list) * PathBuffers>) (mnc:MiniCProgram) : string =
    let mutable code = ""
    let mutable count = 0

    let mutable calc = 
        Set.difference 
            (Set.unionMany  
                [dpn.inVars; 
                (mnc.SharedVariables 
                |> Set.ofArray 
                |> Set.map fst);
                dpn.arrDecls
                |> Map.keys
                |> Set.ofSeq
                ]) 
            dpn.outVars

    let mutable dpnArrays = 
        Set.filter (isArrayBuffer)
            (Set.union(mnc.SharedVariables
                |> Set.ofArray
                |> Set.map (fun entry -> constructBuffer (snd entry) (fst entry) Standard))
                (dpn.arrDecls
                |> Map.map (fun name typeC -> constructBuffer typeC name Standard)
                |> Map.values
                |> Set.ofSeq))

    printfn "Enter data size:"
    let datasize = int32 (System.Console.ReadLine())
    printfn "Enter input:"
    let inputData = System.Console.ReadLine()

    let paths = pathsAndBuffers |> Set.toList
    let mutable remainingPaths = {0..paths.Length-1}
                                |>Seq.toList
    let writePath path tabSpace =
                let (input,output) = snd paths[path];
                code <- sprintf "%s%spath%d(" code tabSpace path  
                input |> List.iter (fun x -> code <- sprintf "%s%s, " code x)
                output |> List.iter (fun x -> if not (List.contains x input) then code <- sprintf "%s&%s, "code x)
                code <- code[0 ..  code.Length - 3] + ");\n"

    code <- sprintf "%s#include<stdio.h>\n#include<omp.h>\n#include<chrono>\n#include <iostream>\n#define DATA_SIZE %d\n\nusing namespace std;\n\n" code datasize

    for pathBuffer in pathsAndBuffers do
        let (path, buffer) = pathBuffer
        code <- code + generateMethodCode dpn buffers path buffer ("path" + (count.ToString()))
        count <- count + 1
    count <- 0
    
    code <- sprintf "%svoid main() { \n%sint inputs[] = {%s}; \n" code tabSpace inputData 

    if dpn.outVars.Count > 0 then
        code <- sprintf "%s%sint outputs[DATA_SIZE * %d];\n" code tabSpace dpn.outVars.Count

    let writeArrayDeclaration name typeC =
        match typeC with
        | Carr (Some count, t) ->
            match typeCtoStr t with
            | Some str -> code <- sprintf "%s%s%s %s[%d * DATA_SIZE] = { 0 };\n" code tabSpace str name count
            | None -> raise (System.Exception "Cannot print required array")
        | _ -> raise (System.Exception "Cannot print required array")

    for arr in dpnArrays do
        writeArrayDeclaration arr.Name arr.TypeC

    code <- sprintf "%sauto start = chrono::steady_clock::now();\n" code    
    code <- sprintf "%s%s#pragma omp parallel for \n%sfor (int i = 0; i < DATA_SIZE; i++) {\n" code tabSpace tabSpace

    dpn.inVars |> Set.iter (fun x  -> 
    code <- sprintf "%s%s%s %s = inputs[i * %d + %d];\n" code tabSpace2 buffers[x].TranslatedType (x.ToString()) dpn.inVars.Count count
    count <- count + 1
    )
    
    remainingPaths |> List.iter (fun i ->
      let (input, output) = snd paths[i]
      output|> List.iter(fun x -> 
       if not (List.contains x input) && not (dpnArrays.Contains buffers[x] ) then 
            code <- sprintf "%s%s%s %s;\n" code tabSpace2 buffers[x].TranslatedType x)
    )
    code <-sprintf"%s\n" code

    while not (remainingPaths.IsEmpty) do
        let mutable executablePaths = List.Empty
        for i in remainingPaths do
            let (input,_) = snd paths[i]
            if List.forall calc.Contains input then
                // path can be executed
                executablePaths <- i::executablePaths
                remainingPaths <- List.removeAt(List.findIndex (fun x-> x = i) remainingPaths) remainingPaths
        if executablePaths.IsEmpty then raise (System.Exception "no executable paths") 
        else
        executablePaths |> List.iter(fun i ->
            let (_, output) = snd paths[i]
            calc <- calc |> Set.union (output |> Set.ofList)
        )
        
        if executablePaths.Length = 1 then
            writePath executablePaths[0] tabSpace2 
        else 
            code <- sprintf "%s%s#pragma omp parallel sections\n%s{\n" code tabSpace2 tabSpace2
            executablePaths |> List.iter(fun i ->
                code <-sprintf "%s%s#pragma omp section\n" code tabSpace3
                writePath i tabSpace4
            )
            code <- sprintf "%s%s}\n" code tabSpace2

    code <- code + "\n"
    count <- 0
    dpn.outVars |> Set.iter (fun x -> 
        code  <- sprintf"%s%soutputs[i * %d + %d] = %s;\n"code  tabSpace2  dpn.outVars.Count  count  x 
        count <- count + 1
        )
    code <- sprintf "%s%s}\n"code tabSpace

    code <- sprintf "%sauto end = chrono::steady_clock::now();\nprintf(\"time: %%lld ms\", chrono::duration_cast<chrono::milliseconds>(end - start).count());\n" code
        
    
    // print outputs
    let mutable pos = 0

    while pos < datasize && dpn.outVars.Count <> 0 do
        code <-sprintf "%sprintf(\"" code
        dpn.outVars|> Set.iter(fun x -> code <- sprintf "%s%s: %%i, " code x)
        code <- code[0 ..  code.Length - 2] + "\","

        count <- 0
        dpn.outVars |> Set.iter (fun x -> 
            code  <- sprintf"%soutputs[%d],"code  (pos*dpn.outVars.Count + count )  
            count <- count + 1
            )
        code <- code[0 ..  code.Length - 2] + ");\n"
        pos <- pos + 1

    for arr in dpnArrays do
        match arr.TypeC with
        | Carr (Some count, _) ->
            code <- sprintf "%s%scout << \"\\n%s: \";\n" code tabSpace arr.Name
            code <- sprintf "%s%sfor(int i = 0; i < %d * DATA_SIZE; i++) {\n%scout << %s[i] << \" \";\n%s}\n" code tabSpace count tabSpace2 arr.Name tabSpace
        | _ -> ()

    code + "\n}"
    
    