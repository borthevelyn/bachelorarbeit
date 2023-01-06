module Translator.OpenMPWriter
open Translator.PathAnalyzer
open Averest.MiniC.DataflowProcessNetworks
open Averest.MiniC.Types
open System

let tabSpace = "    "
let tabSpace2 = "       "
let tabSpace3 = "           "
let tabSpace4 = "               "

let generateMethodCode dpn (bufferTypes : Map<string, string>) path buffers name : string =
    let (input, output) = buffers

    // write signature
    let mutable code = "void " + name + "("
    input |> List.iter (fun x -> code <- code + bufferTypes[x] + " " + x + ", ")
    output |> List.iter (fun x -> code <- code + bufferTypes[x] + "* " + x + ", ")
    code <- code[0 .. code.Length - 3] + ") { \n"

    // write body

    // helpers
    let formatWriteVariable name =
        if  List.contains name output then
            "*" + name
        else
            bufferTypes[name] + " " + name

    let writeBodyInst str =
        code <- code + tabSpace + str + "\n"

    let writeAssign varName value = 
        writeBodyInst ((formatWriteVariable varName) + " = " + value + ";")

    let writeAssignFormula out v1 op v2 =
        writeBodyInst ((formatWriteVariable out) + " = " + (v1 + op + v2) + ";")


    for node in path do
        let (outA, dp, inA) = dpn.nodes[node]
        match dp with
        | Copy -> writeAssign outA[0] inA[0]
        | Dup -> 
            writeAssign outA[0] inA[0]
            writeAssign outA[1] inA[0]
        | BinOp op -> 
            let sign = 
                match op with
                | MulN | MulZ -> " * "
                | AddN | AddZ -> " + "
                | SubN | SubZ -> " - "
                | DivN | DivZ -> " / "
                | ModN | ModZ -> " % "
                | AndB -> " && "
                | OrB -> " || "
                | LesN | LesZ -> " < "
                | LeqN | LeqZ -> " <= "
                | EqqN | EqqZ | EqqB -> " == "
                | NeqN | NeqZ | NeqB -> " != "

            writeAssignFormula outA[0] inA[0] sign inA[1]

        | MonOp op ->
            match op with
            | NotB -> writeAssign outA[0] ("!" + inA[0])
            | CastB -> writeAssign outA[0] ("(bool)" + inA[0])
            | CastN | CastZ -> writeAssign outA[0] ("(int)" + inA[0])
        | Const value -> writeAssign outA[0] (value.ToString())
        | _ -> raise (Exception "Undefined node in path")

    code <- code + "}\n"
    code

let generateOpenMPCode dpn (bufferTypes : Map<string, string>) (pathsAndBuffers : Set<(int list) * PathBuffers>) : string =
    let mutable code = ""
    let mutable count = 0
    let mutable calc = dpn.inVars
    
    printfn "Enter data size:"
    let datasize = int32 (System.Console.ReadLine())
    printfn "Enter input:"
    let input = System.Console.ReadLine()
           
    code <- sprintf "%s#include<stdio.h>\n#include<omp.h>\n#define DATA_SIZE %d\n\n" code datasize

    for pathBuffer in pathsAndBuffers do
        let (path, buffer) = pathBuffer
        code <- code + generateMethodCode dpn bufferTypes path buffer ("path" + (count.ToString()))
        count <- count + 1
    
    count <- 0
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
        code  <- sprintf"%s%soutputs[i * %d + %d] = %s;\n"code  tabSpace2  dpn.outVars.Count  count  x 
        count <- count + 1)
    code <- sprintf "%s%s}\n"code tabSpace
    code <- sprintf "%sprintf(b: %%i, c: %%i, outputs[0], outputs[1]);\n" code
    code <- sprintf "%sprintf(b: %%i, c: %%i, outputs[2], outputs[3]);\n}" code
    code