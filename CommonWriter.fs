module Translator.CommonWriter

open Averest.MiniC.DataflowProcessNetworks
open Averest.MiniC.Types
open Types
open PathAnalyzer

exception UndefinedNodeInPath
exception NoExecutablePaths

let tabSpace = "    "


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
       

let findExectuablePaths (paths : list<list<int> * PathBuffers>) (calcIn : string Set) writePaths =
    let mutable calc = calcIn
    let mutable remainingPaths = 
        { 0 .. paths.Length - 1 }
        |> Seq.toList

    while not (remainingPaths.IsEmpty) do
        let mutable executablePaths = List.Empty
        for i in remainingPaths do
            let (input,_) = snd paths[i]
            if List.forall calc.Contains input then
                // path can be executed
                executablePaths <- i::executablePaths
                remainingPaths <- List.removeAt(List.findIndex (fun x-> x = i) remainingPaths) remainingPaths
        if executablePaths.IsEmpty then raise NoExecutablePaths 
        else
        executablePaths |> List.iter(fun i ->
            let (_, output) = snd paths[i]
            calc <- calc |> Set.union (output |> Set.ofList)
        )

        writePaths executablePaths

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

/// generate one path
let generateMethodCode dpn (buffers : Map<string, Types.Buffer>) path buffer name : string =
    let (input, output) = buffer

    // write signature
    let mutable code = "void " + name + "("
    input |> 
    List.filter (fun i -> not (List.contains i output)) |>
    List.iter (fun x -> code <- code + buffers[x].TranslatedType + " " + x + ", ")
    output |> 
    List.iter (fun (x: string) -> code <- sprintf "%s%s* %s, " code buffers[x].TranslatedType x)
    code <- code[0 .. code.Length - 3] + ") { \n"

    let ioValues = input |> List.filter (fun i -> List.contains i output)

    let formatArray name =
        if List.contains name ioValues then
            "(*" + name + ")"
        else
            name

    // helpers
    let formatWriteVariable name =
        if List.contains name output then
            "*" + name
        else
            buffers[name].TranslatedType + " " + name

    let formatReadVariable value =
        if ioValues |> List.contains value then
            "*" + value
        else
            value
        

    let writeBodyInst str =
        code <- code + tabSpace + str + "\n"

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

    let writeArrayRename newVar oldArr =
        if List.contains newVar output then
            writeBodyInst (sprintf "*%s = %s;" newVar (formatArray oldArr))
        else 
            writeBodyInst (sprintf "%s %s = %s;" buffers[newVar].TranslatedType newVar (formatArray oldArr))
            

    let writeInitialization name =
        if not (List.contains name output) then
            writeBodyInst (buffers[name].TranslatedType + " " + name + " = 0;")

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
            writeArrayRename outA[arrayOut] inA[arrayIn]
                         
        | Store x ->             
            writeStore inA[1] inA[0] inA[2]
            writeArrayRename outA[0] inA[1]

        | ParITE-> 
            writeInitialization outA[0]
            code <- sprintf "%s%sif ( %s ) {\n%s" code  tabSpace inA[0] tabSpace
            writeRename outA[0] inA[1]
            code <- code + tabSpace + "} else  { \n" + tabSpace
            writeRename outA[0] inA[2]
            code <- code + tabSpace + "} \n"
        | _ -> raise UndefinedNodeInPath

    code <- code + "}\n"
    code