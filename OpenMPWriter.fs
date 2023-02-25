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

let generateHeader datasize = 
    sprintf "#include<stdio.h>\n#include<omp.h>\n#include<chrono>\n#include <iostream>\n#define DATA_SIZE %d\n\nusing namespace std;\n\n" datasize
    
let generateInputVariableInitialization dpnInVars (buffers : Map<string, Types.Buffer>) =
    let mutable count = 0
    let mutable res = ""
    dpnInVars |> 
    Set.iter (fun x  -> 
        res <- res + (sprintf "%s%s %s = inputs[i * %d + %d];\n" tabSpace2 buffers[x].TranslatedType (string x) dpnInVars.Count count)
        count <- count + 1
    )
    res

let generatePathCode dpn buffers pathsAndBuffers = 
    let mutable count = 0
    let mutable res = ""
    for pathBuffer in pathsAndBuffers do
        let (path, buffer) = pathBuffer
        res <- res + (generateMethodCode dpn buffers path buffer ("path" + (string count)))
        count <- count + 1

    res

let generateArrayDeclaration name typeC =
    match typeC with
    | Carr (Some count, t) ->
        match typeCtoStr t with
        | Some str -> sprintf "%s%s %s_arr[%d * DATA_SIZE] = { 0 };\n" tabSpace str name count
        | None -> raise (System.Exception "Cannot print required array")
    | _ -> raise (System.Exception "Cannot print required array")

let generateBody dpn (buffers : Map<string, Buffer>) (paths : list<list<int> * PathBuffers>) inputData mnc =
    let mutable count = 0
    let mutable res = ""
    let writeCode str = res <- res + str

    let writeCallPath path tabSpace =
        let (input, output) = snd paths[path];
        writeCode (sprintf "%spath%d(" tabSpace path)
        let ioArrays = input |> List.filter (fun x -> output |> List.contains x)
        input |> List.iter (fun x -> 
                if not (ioArrays |> List.contains x) then
                    writeCode (sprintf "%s, " x))
        output |> List.iter (fun x -> writeCode (sprintf "&%s, " x))
        res <- res[0 ..  res.Length - 3] + ");\n"

    // the list of already calculated variables - we can start with some initially known variables
    let mutable calc = calculateKnownVariables dpn mnc
    
    // the list of arrays used in this calculation
    let dpnArrays = calculateArrayVariables dpn mnc

    writeCode (sprintf "void main() { \n%sint inputs[] = { %s }; \n" tabSpace inputData)

    if dpn.outVars.Count > 0 then
        writeCode (sprintf "%sint outputs[DATA_SIZE * %d];\n" tabSpace dpn.outVars.Count)
    
    for arr in dpnArrays do
        writeCode (generateArrayDeclaration arr.Name arr.TypeC)
    
    writeCode "auto start = chrono::steady_clock::now();\n"
    writeCode (sprintf "%s#pragma omp parallel for \n%sfor (int i = 0; i < DATA_SIZE; i++) {\n" tabSpace tabSpace)

    writeCode (generateInputVariableInitialization dpn.inVars buffers)
    
    {0 .. paths.Length - 1} |> Seq.iter (fun i ->
        let (input, output) = snd paths[i]
        output |> 
        List.iter(fun x -> 
            if dpn.inVars |> Set.contains x then 
                ()
            elif isArrayBuffer buffers[x] && Set.exists (fun arr -> arr.Name = x) dpnArrays then 
                writeCode (sprintf "%s%s %s = %s_arr + i * %d;\n" tabSpace2 buffers[x].TranslatedType x x (arraySize buffers[x]))
            else
                writeCode (sprintf "%s%s %s;\n" tabSpace2 buffers[x].TranslatedType x))
    )
    writeCode "\n"

    findExectuablePaths paths calc (fun executablePaths ->        
        if executablePaths.Length = 1 then
            writeCallPath executablePaths[0] tabSpace2 
        else 
            writeCode(sprintf "%s#pragma omp parallel sections\n%s{\n" tabSpace2 tabSpace2)
            executablePaths |> List.iter(fun i ->
                writeCode(sprintf "%s#pragma omp section\n" tabSpace3)
                writeCallPath i tabSpace4
            )
            writeCode(sprintf "%s}\n" tabSpace2)
    )


    writeCode "\n"
    count <- 0
    dpn.outVars |> Set.iter (fun x -> 
        writeCode(sprintf "%soutputs[i * %d + %d] = %s;\n" tabSpace2  dpn.outVars.Count  count  x) 
        count <- count + 1
        )
    writeCode (sprintf "%s}\n" tabSpace)

    writeCode "auto end = chrono::steady_clock::now();\nprintf(\"time: %%lld ms\", chrono::duration_cast<chrono::milliseconds>(end - start).count());\n"

    res

let generateResultOutput (outVars : string Set) datasize =
    if outVars.Count = 0 then ""
    else

    let mutable res = ""

    for pos in { 0 .. datasize - 1 } do
        res <- res + "printf(\""
        outVars |> Set.iter (fun x -> res <- res + sprintf "%s: %%i, " x)
        res <- res[0 ..  res.Length - 3] + "\", "

        let mutable count = 0
        outVars |> Set.iter (fun x -> 
            res <- res + (sprintf "outputs[%d], " (pos * outVars.Count + count)) 
            count <- count + 1
            )
        res <- res[0 ..  res.Length - 3] + ");\n"

    res

let generateArrayOutput dpn mnc =
    let mutable res = ""
    let dpnArrays = calculateArrayVariables dpn mnc
    for arr in dpnArrays do
        match arr.TypeC with
        | Carr (Some count, _) ->
            res <- res + sprintf "%scout << \"\\n%s: \";\n" tabSpace arr.Name
            res <- res + sprintf "%sfor(int i = 0; i < %d * DATA_SIZE; i++) {\n%scout << %s_arr[i] << \" \";\n%s}\n" tabSpace count tabSpace2 arr.Name tabSpace
        | _ -> ()
    res

let generateOpenMPCode dpn (buffers : Map<string, Buffer>) (pathsAndBuffers : Set<(int list) * PathBuffers>) (mnc:MiniCProgram) : string =
    
    let mutable code = ""

    let writeCode str = 
        code <- code + str

    printfn "Enter data size:"
    let datasize = int32 (System.Console.ReadLine())
    printfn "Enter input:"
    let inputData = System.Console.ReadLine()

    let paths = pathsAndBuffers |> Set.toList
     
    writeCode (generateHeader datasize)
    writeCode (generatePathCode dpn buffers paths)
    writeCode (generateBody dpn buffers paths inputData mnc)
    writeCode (generateResultOutput dpn.outVars datasize)
    writeCode (generateArrayOutput dpn mnc) 
    code + "\n}"
    