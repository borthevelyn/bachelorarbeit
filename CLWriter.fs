module Translator.CLWriter

open Translator.PathAnalyzer
open Averest.MiniC.DataflowProcessNetworks
open Averest.MiniC.Types
open System
open System.Collections.Generic

let tabSpace = "    "

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

let generateCLCode dpn (bufferTypes : Map<string, string>) (pathsAndBuffers : Set<(int list) * PathBuffers>) : string =
    let mutable code = ""
    let mutable count = 0;
    let mutable calc = dpn.inVars

    for pathBuffer in pathsAndBuffers do
        let (path, buffer) = pathBuffer
        code <- code + generateMethodCode dpn bufferTypes path buffer ("path" + (count.ToString()))
        count <- count + 1
    
    count <- 0
    code <- code + "__kernel void Execute(__global int* inputs, __global int* outputs) { \n    size_t threadId = get_global_id(0); \n"
    dpn.inVars |> Set.iter (fun x  -> 
        code <- code + tabSpace + bufferTypes[x] + " "+ x.ToString() + " = inputs[threadId * "
            + dpn.inVars.Count.ToString() + " + " + count.ToString() + "];\n"
        count <- count + 1
        )

    let paths = pathsAndBuffers |> Set.toList
    let pathExec = List<bool>()

    for p in paths do
        pathExec.Add false

    while not (pathExec.TrueForAll id) do
        for i in 0 .. paths.Length - 1 do
            let (input, output) = snd paths[i]
            if not pathExec[i] then
                if List.forall calc.Contains input then
                    // path can be executed
                    calc <- calc |> Set.union (output |> Set.ofList)
                    pathExec[i] <- true
    
                    output |> List.iter (fun x -> code <- code + tabSpace + bufferTypes[x] + " " + x + ";\n")
                    code <- code + tabSpace + "path" + i.ToString() + "(" 
                    input |> List.iter (fun x -> code <- code + x + ", ")
                    output |> List.iter (fun x -> code <- code + "&" + x + ", ")
                    code <- code[0 ..  code.Length - 3] + ");\n\n"

    count <- 0
    dpn.outVars |> Set.iter (fun x -> 
        code <- code + tabSpace + "outputs[threadId * "+ dpn.outVars.Count.ToString() + " + " 
            + count.ToString() + "] = " + x.ToString() + ";\n"
        count <- count + 1)
    code <- code +  "}"
    code