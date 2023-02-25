module Translator.Types

open Averest.MiniC.Types
open Averest.MiniC.DataflowProcessNetworks

/// <summary>
/// Translates a given TypeC to an OpenCL type. None for those types which can't be translated.
/// </summary>
let rec typeCtoStr tc =
    match tc with
        | Cbool -> Some "bool" 
        | Cnat -> Some "int"  
        | Cint -> Some "int"  
        | Carr (_, t) -> 
            match typeCtoStr t with 
            | None -> None
            | Some str -> Some (str + "*")
        | Ctup _ -> None
        | Cfun _-> None


type ProducerKind =
    | Constant
    | Standard
    // first is the buffer name of the previous array, second the index, third the name of the stored element
    | Storer of string * string * string
    // first is name of previous array, second is buffer name of index
    | Loader of string * string

and Buffer = {
    TranslatedType: string
    Name: string
    TypeC: TypeC
    Producer: ProducerKind
}

let isArrayBuffer buffer =
    match buffer.TypeC with
    | Carr _ -> true
    | _ -> false

let arraySize arr = 
    match arr.TypeC with
        | Carr (Some count, _) -> count
        | _ -> raise (System.Exception "The type should be an array")

let rec collapseArray typeC =
    match typeC with
    | Carr (Some len1, inner) ->
        match collapseArray inner with
        | Carr (Some len2, primitive) -> 
            Carr (Some (len1 * len2), primitive)
        | _ -> typeC
    | _ -> typeC



let constructBuffer typeC name producer =
    match typeCtoStr typeC with
    | None -> raise (System.Exception "Cannot construct buffer from invalid TypeC")
    | Some str ->
        {
            TranslatedType = str
            Name = name
            TypeC = typeC
            Producer = producer
        }

let rec buildBufferTypeLookup dpn (defs : Map<string, Buffer>) buffers : Map<string, Buffer> =
    /// <summary>
    /// Given a dpn, a table of predefined type of buffers and a buffer name, this function
    /// will return the type of the given buffer name.
    /// </summary>
    let rec lookupBufferType dpn (defs : Map<string, Buffer>) buffer : Map<string, Buffer> =
        // look up in defined table
        match Map.tryFindKey (fun x _ -> x = buffer) defs with
        | Some _ -> defs
        | None ->

        let returnCustomBuffer custombuffer =
            defs |> Map.add buffer custombuffer
        let returnStandardBuffer typeC =
            returnCustomBuffer (constructBuffer typeC buffer Standard)
        let returnConstantBuffer typeC =
            returnCustomBuffer (constructBuffer typeC buffer Constant)

        let returnRecursion prev =
            let recursedDefs = lookupBufferType dpn defs prev
            recursedDefs |> Map.add buffer (constructBuffer recursedDefs[prev].TypeC buffer Standard)

        // analyze node types
        let (outA, dp, inA) = dpn.nodes[dpn.prod[buffer]]
        match dp with
        | BinOp op ->
            match op with
            | AddN | MulN | DivN | SubN | ModN -> returnStandardBuffer Cnat
            | AddZ | MulZ | DivZ | SubZ | ModZ -> returnStandardBuffer Cint
            | _ -> returnStandardBuffer Cbool
        | MonOp op ->
            match op with
            | NotB | CastB -> returnStandardBuffer Cbool
            | CastN -> returnStandardBuffer Cnat
            | CastZ -> returnStandardBuffer Cint
        | Const value -> returnConstantBuffer Cint
        | Copy | Dup -> 
            // recursively look one level down
            returnRecursion inA[0]
        // Input type is Cbool and for output type look recursively one level down
        | ParITE ->
            returnRecursion inA[1]      
        | Join -> returnRecursion inA[0]
        | Load _ -> 
            // load node has different outputs: one is a Carr and the other is the read value 
            let newDefs1 = lookupBufferType dpn defs inA[0]
            let newDefs2 = lookupBufferType dpn newDefs1 inA[1]

            let x0 = newDefs2[inA[0]]
            let x1 = newDefs2[inA[1]]

            match x0.TypeC with
            | Carr (_, t) -> 
                match x1.TypeC with
                | Cint | Cnat -> 
                    returnCustomBuffer
                        (constructBuffer 
                        (if outA[0] = buffer then x0.TypeC else t) 
                        buffer
                        (Loader (inA[0], inA[1])))

                | _ -> raise (System.Exception "couldn't identify variable type") 
            | Cint | Cnat -> 
                match x1.TypeC with
                | Carr (_, t) -> 
                    returnCustomBuffer
                        (constructBuffer
                        (if outA[0] = buffer then x1.TypeC else t)
                        buffer
                        (Loader (inA[1], inA[0])))
                | _ -> raise (System.Exception "couldn't identify variable type")
            | _ -> raise (System.Exception "couldn't identify variable type")  
        | Store _ -> 
            // store node has three inputs: inA[0] = index, inA[1] = name, inA[2] = value
            let newDefs1 = lookupBufferType dpn defs inA[0]
            let newDefs2 = lookupBufferType dpn newDefs1 inA[1]
            let newDefs3 = lookupBufferType dpn newDefs2 inA[2]

            let x0 = newDefs3[inA[0]]
            let x1 = newDefs3[inA[1]]

            let indexName = 
                if x0.Producer = Constant && (x0.TypeC = Cint || x0.TypeC = Cnat) then
                    inA[0]
                elif x1.Producer = Constant && (x1.TypeC = Cint || x1.TypeC = Cnat) then
                    inA[1]
                else
                    inA[2]

            let arrayName = 
                match x1.TypeC with
                | Carr _ -> inA[1]
                | _ ->

                match x0.TypeC with
                | Carr _ -> inA[0]
                | _ ->

                inA[2]

            let valueName =
                if inA[2] <> arrayName && inA[2] <> indexName then
                    inA[2]
                elif inA[1] <> arrayName && inA[1] <> indexName then
                    inA[1]
                else
                    inA[0]

            returnCustomBuffer
                (constructBuffer 
                (newDefs3[arrayName]).TypeC 
                buffer 
                (Storer (arrayName, indexName, valueName)))

        | _ -> raise (System.Exception "couldn't identify node type")

    let mutable currentDefs = defs
    for buffer in buffers do
        lookupBufferType dpn currentDefs buffer |>
        Map.iter (fun newBufferName newBufferElem -> currentDefs <- currentDefs |> Map.add newBufferName newBufferElem)

    currentDefs

