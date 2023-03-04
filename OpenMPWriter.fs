module Translator.OpenMPWriter
open Translator.PathAnalyzer
open Averest.MiniC.DataflowProcessNetworks
open Translator.CommonWriter
open Averest.MiniC.Types
open Types

exception CannotPrintRequiredArray

let tabSpace = "    "
let tabSpace2 = "       "
let tabSpace3 = "           "
let tabSpace4 = "               "

let generateHeader datasize = 
    sprintf "
#if 0 
#include<stdio.h>
#include<omp.h>
#include<chrono>
#include <iostream>
#include <string>
#define DATA_SIZE %d

using namespace std;

"       
        datasize

    
let generateInputVariableInitialization dpnInVars (buffers : Map<string, Types.Buffer>) =
    let mutable count = 0
    let mutable res = ""
    dpnInVars |> 
    Set.iter (fun x  -> 
        res <- res + (sprintf "%s%s %s = inputs[i * %d + %d];\n" tabSpace2 buffers[x].TranslatedType (string x) dpnInVars.Count count)
        count <- count + 1
    )
    res

let generatePathCode dpn buffers (pathsAndBuffers: Set<int list * PathBuffers>) = 
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
        | None -> raise CannotPrintRequiredArray
    | _ -> raise CannotPrintRequiredArray

/// Generates the body of the file. Buffers is a mapping of buffer names from the dpn
/// Paths is a list with each entry containg the required information of a set of paths. 
/// Those paths in the same set may be executed in parallel.
/// The paths should be called in the order of the list.
let generateBody dpn (buffers : Map<string, Buffer>) (pathsCollection : list<Set<int * PathBuffers>>) inputData mnc =
    let mutable count = 0
    let mutable res = ""
    let writeCode str = res <- res + str

    // the list of arrays used in this calculation
    let dpnArrays = calculateArrayVariables dpn mnc
    
    let writeCallPath path tabSpace =
        let (input, output) = snd path;
        writeCode (sprintf "%spath%d(" tabSpace (fst path))
        let ioArrays = input |> List.filter (fun x -> output |> List.contains x)
        input |> List.iter (fun x ->
                if not (ioArrays |> List.contains x) then
                    writeCode (sprintf "%s, " x))
        output |> List.iter (fun x -> writeCode (sprintf "&%s, " x))
        res <- res[0 ..  res.Length - 3] + ");\n"

    writeCode (writeMain)
    writeCode (sprintf "\n%sint inputs[] = { %s }; \n" tabSpace inputData)

    if dpn.outVars.Count > 0 then
        writeCode (sprintf "%sint outputs[DATA_SIZE * %d];\n" tabSpace dpn.outVars.Count)
    
    for arr in dpnArrays do
        writeCode (generateArrayDeclaration arr.Name arr.TypeC)
    
    writeCode startTiming
    writeCode (sprintf "%s#pragma omp parallel for \n%sfor (int i = 0; i < DATA_SIZE; i++) {\n" tabSpace tabSpace)

    writeCode (generateInputVariableInitialization dpn.inVars buffers)
    
    // declare variables shared between paths.
    // this is done by handling each output of each path - since every buffer is read only, this will only happen once
    // for each variable    
    pathsCollection
    |> List.collect Set.toList
    |> List.iter
        (fun (_, (_, output)) ->
            output |> 
            List.iter(fun x -> 
                if dpn.inVars |> Set.contains x then 
                    ()
                elif isArrayBuffer buffers[x] && Set.exists (fun arr -> arr.Name = x) dpnArrays then 
                    // because arrays are generally shared between executions, calculate an offset
                    writeCode (sprintf "%s%s %s = %s_arr + i * %d;\n" tabSpace2 buffers[x].TranslatedType x x (arraySize buffers[x]))
                else
                    writeCode (sprintf "%s%s %s;\n" tabSpace2 buffers[x].TranslatedType x))
        )

    writeCode "\n"

    // call each path
    for paths in pathsCollection do
        if paths.Count = 1 then
            writeCallPath paths.MaximumElement tabSpace2 
        else 
            writeCode (sprintf "%s#pragma omp parallel sections\n%s{\n" tabSpace2 tabSpace2)
            for path in paths do
                writeCode(sprintf "%s#pragma omp section\n" tabSpace3)
                writeCallPath path tabSpace4
            
            writeCode(sprintf "%s}\n" tabSpace2)

    writeCode "\n"
    count <- 0
    dpn.outVars |> Set.iter (fun x -> 
        writeCode(sprintf "%soutputs[i * %d + %d] = %s;\n" tabSpace2  dpn.outVars.Count  count  x) 
        count <- count + 1
        )
    writeCode (sprintf "%s}\n" tabSpace)

    writeCode endTiming 
    writeCode writeTime

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

let generateOpenMPCode dpn (buffers : Map<string, Buffer>) (orderedPaths : list<Set<int * list<int> * PathBuffers>>) (mnc:MiniCProgram) =
    
    let mutable code = ""

    let writeCode str = 
        code <- code + str

    printfn "Enter data size:"
    let datasize = int32 (System.Console.ReadLine())
    printfn "Enter input:"
    let inputData = System.Console.ReadLine()

    let pathBuffers: Set<list<int> * PathBuffers> = 
        orderedPaths
        |> List.map(fun x -> (x |> Set.map (fun (_ , path , buffer) -> path, buffer)))
        |> List.collect Set.toList
        |> Set.ofList

    let idBuffers: list<Set<int * PathBuffers>> = 
        orderedPaths
        |> List.map(fun x -> (x |> Set.map (fun (id, _, buffer) -> id, buffer)))

    writeCode (generateHeader datasize)
    writeCode (generatePathCode dpn buffers pathBuffers)
    let str = generateBody dpn buffers idBuffers inputData mnc 
    writeCode str
    writeCode (tabSpace + "if (!onlyTimeOutput) {")
    writeCode (generateResultOutput dpn.outVars datasize)
    writeCode (generateArrayOutput dpn mnc) 
    writeCode (tabSpace + "}")
    code + "\n}\n#endif"
    