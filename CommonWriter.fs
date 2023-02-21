module Translator.CommonWriter

open Averest.MiniC.DataflowProcessNetworks
open Averest.MiniC.Types
open Types
open System

let tabSpace = "    "

let generateMethodCode dpn (bufferTypes : Map<string, Types.Buffer>) path buffer name : string =
    let (input, output) = buffer

    // write signature
    let mutable code = "void " + name + "("
    input |> List.iter (fun x -> code <- code + bufferTypes[x].TranslatedType + " " + x + ", ")
    //output |> List.iter (fun (x: string) -> if not (isArrayBuffer bufferTypes[x]) then code <- code + bufferTypes[x].TranslatedType + "* " + x + ", ")
    output |> List.iter (fun (x: string) -> if not (List.contains x input) then
                                                if  not (isArrayBuffer bufferTypes[x]) then 
                                                    code <- code + bufferTypes[x].TranslatedType + "* " + x + ", "
                                                else 
                                                    code <- code + bufferTypes[x].TranslatedType + x + ", ")
    code <- code[0 .. code.Length - 3] + ") { \n"

    // helpers
    let formatWriteVariable name =
        if  List.contains name output then
            "*" + name
        else
            bufferTypes[name].TranslatedType + " " + name

    let writeBodyInst str =
        code <- code + tabSpace + str + "\n"

    let writeAssign varName value = 
        if varName = value then
            ()
        else
            writeBodyInst ((formatWriteVariable varName) + " = " + value + ";")

    let writeAssignFormula out v1 op v2 =
        writeBodyInst ((formatWriteVariable out) + " = " + (v1 + op + v2) + ";")

    let writeDeclaration name =
        writeBodyInst (bufferTypes[name].TranslatedType + " " + name + ";")

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
        | Join -> writeAssign outA[0] inA[1]
        | Load x -> 
            let valueOut = if isArrayBuffer bufferTypes[outA[1]] then 0 else 1
            let arrayOut = if valueOut = 1 then 0 else 1
            let selectedIn = if not (isArrayBuffer bufferTypes[inA[0]]) then 0 else 1
            let arrayIn = if selectedIn = 1 then 0 else 1
            writeAssign outA[valueOut] (inA[arrayIn] + "[" + inA[selectedIn] + "]")
            writeAssign outA[arrayOut] inA[arrayIn]
                         
        | Store x -> 
            let bufferName = 
                dpn.prod
                |> Map.tryPick (fun key value -> 
                    if value = node then 
                        match bufferTypes[key].Producer with
                        | Storer _ -> Some key
                        | _ -> None
                    else None)
            
            writeBodyInst (sprintf "%s[%s] = %s;" inA[1] inA[0] inA[2])
            writeAssign outA[0] inA[1]

        | ParITE-> 
            code <- sprintf "%s%sif ( %s ) {\n%s" code  tabSpace inA[0] tabSpace
            writeBodyInst ("*" + outA[0] + " = " +  inA[1] + ";")
            code <- code + tabSpace + "} else  { \n" + tabSpace
            writeBodyInst ("*" + outA[0] + " = " +  inA[2] + ";")
            code <- code + tabSpace + "} \n"
        | _ -> raise (Exception "Undefined node in path")

    code <- code + "}\n"
    code