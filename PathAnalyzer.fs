module Translator.PathAnalyzer

open Averest.MiniC.DataflowProcessNetworks
open System

let neq x y =
    x <> y

/// <summary>
/// requires input buffers 0 and provides output buffers 1
/// </summary>
type PathBuffers = string list * string list
/// <summary>
/// The name (= id) of the path times the buffers
/// </summary>
type NamedPathBuffers = int * PathBuffers
/// <summary>
/// Path 0 is dependent on path 1 with buffer names...
/// </summary>
type PathDependency = int * int * string list
/// <summary>
/// A list of paths which all are dependent on themselves. This connection is not exclusive,
/// meaning there can still be dependencies outside of this list. Those are just the "deadlock" dependencies
/// </summary>
type PathDeadlock = Set<PathDependency>

let traversePathBuffer dpn path writeTo readFrom =
    for index in path do
        let (outA, dp, inA) = dpn.nodes[index]
        match dp with
        | BinOp _ -> 
            readFrom inA[0]
            readFrom inA[1]
            writeTo outA[0]
        | MonOp _ | Copy ->
            readFrom inA[0]
            writeTo outA[0]
        | Dup ->
            readFrom inA[0]
            writeTo outA[0]
            writeTo outA[1]
        | Const _ ->
            writeTo outA[0]
        | _ ->
            raise (Exception "Undefined node in path")

/// <summary> 
/// Relies on the assumption that the path is ordered, returns first the read and written buffers
/// then the external read and written buffers
/// </summary>
let calculatePathBuffers dpn path : PathBuffers * PathBuffers =
    // stores the buffers set by this path
    let mutable setBuffers : string list = []
    // stores all buffers used in a get operation in this path
    let mutable getBuffers : string list = []


    //each external variable is built while reading the path
    //a variable is declared an external input if it is read before it is set
    let mutable externalInput : string list = []
    //a varibale is declared an external output if it is not read after it is set
    let mutable externalOutput : string list = []

    let appendGetBufferName (name : string) =       
        if not (List.contains name getBuffers) then
            getBuffers <- name::getBuffers
            if not (List.contains name setBuffers) then
                externalInput <- name::externalInput
        
        externalOutput <- List.filter (neq name) externalOutput
            
    let appendSetBufferName name =
        if List.contains name setBuffers then  
            ()
        externalOutput <- name::externalOutput
        setBuffers <- name::setBuffers

    traversePathBuffer dpn path appendSetBufferName appendGetBufferName

    (getBuffers, setBuffers), (externalInput, externalOutput)


/// <summary>
/// Calculate the dependencies for one path using a specified list of paths
/// </summary>
let calculatePathDependency (paths : NamedPathBuffers list) pathName =
    let pathBuf = snd (List.find (fun x -> fst x = pathName) paths)
    let gets = fst pathBuf
    let mutable result : Set<PathDependency> = Set.empty

    for path in paths do
        if (fst path) = pathName then
            ()
        else
            // search buffers set by this path and if not empty, create a dependency
            let setByPath = snd (snd path)
            let relevantSet = List.filter (fun e -> List.contains e gets) setByPath
            if List.isEmpty relevantSet then
                ()
            else
                result <- Set.add (pathName, fst path, relevantSet) result
            
    result

let rec traverseDependenciesTo dependencies from to_ visited : Set<PathDependency list> =
    let fromDeps = 
        dependencies 
        |> Set.filter (fun d -> 
            let (f, _, _) = d
            f = from)
    
    let mutable result : Set<PathDependency list> = Set.empty

    for dep in fromDeps do
        let (_, next, _) = dep
        if next = to_ then
            result <- Set.add [dep] result
        if not (Set.contains next visited) then
            for found in traverseDependenciesTo dependencies next to_ (Set.add from visited) do
                result <- Set.add (dep::found) result

    result
    



/// <summary>
/// Returns a set of deadlocks found.
/// </summary>
let calculateDeadlocks dependencies =
    let mutable result : Set<PathDeadlock> = Set.empty
    
    for dep in dependencies do
        let (from, _, _) = dep
        let cycles = traverseDependenciesTo dependencies from from Set.empty
        result <-
            cycles
            |> Set.map Set.ofList
            |> Set.union result

    result


let resolveDeadlocksPathJoin (nodeLevels : Map<int, int>) (paths : int list list) (deadlocks: Set<PathDeadlock>) =
    // stores a list of the paths to be merged by their index in "paths"
    // this is build up for every deadlock such that, at the end, every deadlock that requires joining is one list
    // paths never touched by deadlocks remain as a single element list
    let mutable pathsToJoin : Set<int list> = 
        seq { 0 .. paths.Length - 1 }
        |> Set.ofSeq
        |> Set.map List.singleton

    for deadlock in deadlocks do
        let pathIndices = 
            deadlock
            |> Set.map (fun x -> 
                let (from, to_, _) = x
                from)
        
        // sort the path indices from pathsToJoin into those not touched by the deadlock and those to be merged
        let (toRemain, toJoin) = Set.partition (fun x -> 
            List.forall (fun y -> not (Set.contains y pathIndices)) x) pathsToJoin

        pathsToJoin <-
            toRemain
            |> Set.add (
                toJoin
                |> Set.toList
                |> List.collect id)


    pathsToJoin
    |> Set.map (List.collect (fun n -> paths[n]))
    |> Set.map (List.sortBy (fun n -> nodeLevels[n]))



    