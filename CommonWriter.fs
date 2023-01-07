module Translator.CommonWriter

open Averest.MiniC.DataflowProcessNetworks
open Averest.MiniC.Types
open System

let tabSpace = "    "

let generateMethodCode dpn (bufferTypes : Map<string, string>) path buffers name : string =
    let (input, output) = buffers

    // write signature
    let mutable code = "void " + name + "("
    input |> List.iter (fun x -> code <- code + bufferTypes[x] + " " + x + ", ")
    output |> List.iter (fun x -> code <- code + bufferTypes[x] + "* " + x + ", ")
    code <- code[0 .. code.Length - 3] + ") { \n"

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