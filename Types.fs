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

/// <summary>
/// Given a dpn, a table of predefined type of buffers and a buffer name, this function
/// will return the type of the given buffer name.
/// </summary>
let rec lookupBufferType dpn defs buffer : Buffer =
    // look up in defined table
    let opt = Array.tryFind (fun x -> fst x = buffer) defs

    let constructStandardFromType typeC =
        constructBuffer typeC buffer Standard

    let constructFromRecursion name =
        let recursed = lookupBufferType dpn defs name
        constructStandardFromType recursed.TypeC

    match opt with
    | Some v -> snd v
    | None ->
        // analyze node types
        let (outA, dp, inA) = dpn.nodes[dpn.prod[buffer]]
        match dp with
        | BinOp op ->
            match op with
            | AddN | MulN | DivN | SubN | ModN -> constructStandardFromType Cnat
            | AddZ | MulZ | DivZ | SubZ | ModZ -> constructStandardFromType Cint
            | _ -> constructStandardFromType Cbool
        | MonOp op ->
            match op with
            | NotB | CastB -> constructStandardFromType Cbool
            | CastN -> constructStandardFromType Cnat
            | CastZ -> constructStandardFromType Cint
        | Const value -> constructBuffer Cint buffer Constant
        | Copy | Dup -> 
            // recursively look one level down
            constructFromRecursion inA[0]
        // Input type is Cbool and for output type look recursively one level down
        | ParITE ->
            constructFromRecursion inA[1]      
        | Join -> constructFromRecursion inA[0]
        | Load _ -> 
            // load node has different outputs: one is a Carr and the other is the read value 
            let x0 = constructFromRecursion inA[0]
            let x1 = constructFromRecursion inA[1]

            match x0.TypeC with
            | Carr (_, t) -> 
                match x1.TypeC with
                | Cint | Cnat -> 
                    constructBuffer 
                        (if outA[0] = buffer then x0.TypeC else t) 
                        buffer
                        (Loader (inA[0], inA[1]))

                | _ -> raise (System.Exception "couldn't identify variable type") 
            | Cint | Cnat -> 
                match x1.TypeC with
                | Carr (_, t) -> 
                    constructBuffer
                        (if outA[0] = buffer then x1.TypeC else t)
                        buffer
                        (Loader (inA[1], inA[0]))
                | _ -> raise (System.Exception "couldn't identify variable type")
            | _ -> raise (System.Exception "couldn't identify variable type")  
        | Store _ -> 
            // store node has three inputs: inA[0] = index, inA[1] = name, inA[2] = value
            let x0 = constructFromRecursion inA[0]
            let x1 = constructFromRecursion inA[1]
            
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

            constructBuffer 
                (constructFromRecursion arrayName).TypeC 
                buffer 
                (Storer (arrayName, indexName, valueName))

        | _ -> raise (System.Exception "couldn't identify node type")

