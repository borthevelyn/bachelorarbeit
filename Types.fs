module Translator.Types

open Averest.MiniC.Types
open Averest.MiniC.DataflowProcessNetworks

/// <summary>
/// Given a dpn, a table of predefined type of buffers and a buffer name, this function
/// will return the type of the given buffer name.
/// </summary>
let rec lookupBufferType dpn defs buffer =
    // look up in defined table
    let opt = Array.tryFind (fun x -> fst x = buffer) defs

    match opt with
    | Some v -> snd v
    | None ->
        // analyze node types
        let (_, dp, inA) = dpn.nodes[dpn.prod[buffer]]
        match dp with
        | BinOp op ->
            match op with
            | AddN | MulN | DivN | SubN | ModN -> Cnat
            | AddZ | MulZ | DivZ | SubZ | ModZ -> Cint
            | _ -> Cbool
        | MonOp op ->
            match op with
            | NotB | CastB -> Cbool
            | CastN -> Cnat
            | CastZ -> Cint
        | Const _ -> Cint
        | Copy | Dup -> 
            // recursively look one level down
            lookupBufferType dpn defs inA[0]
        | _ -> Cnat


/// <summary>
/// Translates a given TypeC to an OpenCL type. None for those types which can't be translated.
/// </summary>
let typeCtoStr tc =
    match tc with
        |Cbool -> Some "bool" 
        |Cnat -> Some "int"  
        |Cint -> Some "int"  
        |Carr (_, t) -> 
            match t with 
            |Cbool -> Some "bool[]"
            |Cnat -> Some "int[]"
            |Cint -> Some "int[]"
            |_ -> None
        |Ctup _ -> None
        |Cfun _-> None