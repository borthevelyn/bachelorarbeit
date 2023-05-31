module Translator.CommonWriter

open Averest.MiniC.DataflowProcessNetworks
open Averest.MiniC.Types
open Types
open PathAnalyzer

exception UndefinedNodeInPath
exception NoExecutablePaths

let tabSpace = "    "
let tabSpace2 = "       "
let tabSpace3 = "           "
let tabSpace4 = "               "

let writeIncludes = "
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

"
let writeMain = "
int main(int argc, char** argv)
{
    bool onlyTimeOutput = [&]() {
        if (argc < 2) return false;

        if (std::string(argv[1]) == \"--onlytime\")
            return true;
        else
            return false;
    }();

"
let startTiming = tabSpace + "auto start = chrono::steady_clock::now();\n"
let endTiming = tabSpace + "auto end = chrono::steady_clock::now();\n"
let writeTime = "
    if (!onlyTimeOutput)
        printf(\"time: %ld ms\", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf(\"%ld\", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

"
let notOnlyTimeOutput = "
    if (!onlyTimeOutput)
"

let calculateKnownVariables dpn mnc =
    (Set.unionMany  
        [dpn.inVars; 
        (mnc.SharedVariables 
        |> Set.ofArray 
        |> Set.map fst);
        dpn.arrDecls
        |> Map.keys
        |> Set.ofSeq
        ])

let calculateArrayVariables dpn mnc =
    Set.filter (isArrayBuffer)
        (Set.union(mnc.SharedVariables
            |> Set.ofArray
            |> Set.map (fun entry -> constructBuffer (collapseArray (snd entry)) (fst entry) Standard))
            (dpn.arrDecls
            |> Map.map (fun name typeC -> constructBuffer (collapseArray typeC) name Standard)
            |> Map.values
            |> Set.ofSeq))
       
let rec calculateExecutionOrder (paths : list<int * int list * PathBuffers>) (calculated : string Set) = 
    match paths with
    | [] -> []
    | _ -> 

    let calculateNow, calculateLater =
        paths
        |> List.partition (fun (_, _, (inputs, _)) -> inputs |> List.forall calculated.Contains)
    
    if calculateNow.IsEmpty then raise NoExecutablePaths 
    else

    let resultNow =
        calculateNow
        |> Set.ofList

    let resultRecursed =
        calculateNow
        |> List.collect (fun (_, _, (_, outputs)) -> outputs)
        |> Set.ofList
        |> Set.union calculated
        |> calculateExecutionOrder calculateLater 

    resultNow::resultRecursed

let generateResultOutput (outVars : string Set)  =
    if outVars.Count = 0 then ""
    else

    let mutable res = ""
    // datasize replaced by 1
    for pos in { 0 .. 0 } do
        res <- res + tabSpace + "printf(\""
        outVars |> Set.iter (fun x -> res <- res + sprintf "%s: %%i, " x)
        res <- res[0 ..  res.Length - 3] + "\", "

        let mutable count = 0
        outVars |> Set.iter (fun x -> 
            res <- res + (sprintf "outputs[%d], " (pos * outVars.Count + count)) 
            count <- count + 1
            )
        res <- res[0 ..  res.Length - 3] + ");\n"
    res

/// generates the body for an executable method for both C++ and OpenCL when given 
let generateFunctionBodyCode dpn (buffers : Map<string, Types.Buffer>) path input output =
    let ioValues = input |> List.filter (fun i -> List.contains i output)
    let mutable res = ""
    let singleThreaded = List.contains "singleThreaded" input
    let formatArray name =
        if List.contains name output && not singleThreaded  then
            "(*" + name + ")"
        else
            name

    // helpers
    let formatWriteVariable name =
        if List.contains name output && not singleThreaded then
            "*" + name
        elif (Set.contains name dpn.inVars || List.contains name input) && singleThreaded then 
            name
        else
            buffers[name].TranslatedType + " " + name

    let formatReadVariable value =
        if ioValues |> List.contains value && not singleThreaded then
            "*" + value
        else
            value
        
    let writeBodyInst str =
        res <- res + tabSpace + str + "\n"

    let writeRename varName value = 
        if varName = value then
            ()
        else
            writeBodyInst ((formatWriteVariable varName) + " = " + (formatReadVariable value) + ";")
        
    let writeUnaryOperation varName value op =
        writeBodyInst ((formatWriteVariable varName) + " = " + op + (formatReadVariable value) + ";")

    let writeBinaryOperation out v1 op v2 =
        writeBodyInst ((formatWriteVariable out) + " = " + ((formatReadVariable v1) + op + (formatReadVariable v2)) + ";")

    let writeStore arrName index value =
        writeBodyInst (sprintf "%s[%s] = %s;" (formatArray arrName) index value)

    let writeLoad arrName index var =
        if List.contains var output then 
            writeBodyInst (sprintf "*%s = %s[%s];"  var (formatArray arrName) index)
        else 
            writeBodyInst (sprintf "%s %s = %s[%s];" buffers[var].TranslatedType var (formatArray arrName) index)

    let writeArrayRename input newVar oldArr =
        if List.contains "singleThreaded" input && List.contains newVar output then 
            writeBodyInst (sprintf "%s = %s;" newVar (formatArray oldArr))
        elif List.contains newVar output then
            writeBodyInst (sprintf "*%s = %s;" newVar (formatArray oldArr))
        else 
            writeBodyInst (sprintf "%s %s = %s;" buffers[newVar].TranslatedType newVar (formatArray oldArr))
            
    let writeInitialization name =
        if not (List.contains name output) then
            writeBodyInst (buffers[name].TranslatedType + " " + name + ";")
        

    for node in path do
        let (outA, dp, inA) = dpn.nodes[node]
        match dp with
        | Copy -> writeRename outA[0] inA[0]
        | Dup -> 
            writeRename outA[0] inA[0]
            writeRename outA[1] inA[0]
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
        

            writeBinaryOperation outA[0] inA[0] sign inA[1]

        | MonOp op ->
            match op with
            | NotB -> writeUnaryOperation outA[0] inA[0] "!"
            | CastB -> writeUnaryOperation outA[0] inA[0] "(bool)"
            | CastN | CastZ -> writeUnaryOperation outA[0] inA[0] "(int)"
        | Const value -> writeRename outA[0] (string value)
        | Join -> writeRename outA[0] inA[1]
        | Load x -> 
            let valueOut = if isArrayBuffer buffers[outA[1]] then 0 else 1
            let arrayOut = if valueOut = 1 then 0 else 1
            let selectedIn = if not (isArrayBuffer buffers[inA[0]]) then 0 else 1
            let arrayIn = if selectedIn = 1 then 0 else 1
            writeLoad inA[arrayIn] inA[selectedIn] outA[valueOut]
            writeArrayRename input outA[arrayOut] inA[arrayIn]
                         
        | Store x ->             
            writeStore inA[1] inA[0] inA[2]
            writeArrayRename input outA[0] inA[1]

        | ParITE-> 
            let leftSide = 
                if output |> List.contains outA[0] && not singleThreaded then
                    "*" + outA[0]
                else
                    outA[0]
        
            writeInitialization outA[0]
            res <- sprintf "%s%sif ( %s ) {\n%s" res  tabSpace inA[0] tabSpace
            writeBodyInst (leftSide + " = " + (formatReadVariable inA[1]) + ";")
            res <- res + tabSpace + "} else  { \n" + tabSpace
            writeBodyInst (leftSide + " = " + (formatReadVariable inA[2]) + ";")
            res <- res + tabSpace + "} \n"
        | _ -> raise UndefinedNodeInPath

    res

/// generate one path
let generateFunctionCode dpn (buffers : Map<string, Types.Buffer>) path buffer name : string =
    let (input, output) = buffer

    // write signature
    let mutable code = "void " + name + "("
    input |> 
    List.filter (fun i -> not (List.contains i output)) |>
    List.iter (fun x -> code <- code + buffers[x].TranslatedType + " " + x + ", ")
    output |> 
    List.iter (fun (x: string) -> code <- sprintf "%s%s* %s, " code buffers[x].TranslatedType x)
    code <- code[0 .. code.Length - 3] + ") { \n"

    code <- code + generateFunctionBodyCode dpn buffers path input output
    code <- code + "}\n"
    code

