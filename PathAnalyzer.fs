module Translator.PathAnalyzer

open Averest.MiniC.DataflowProcessNetworks

exception UndefindedNodeInPath

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
        | MonOp _
        | Copy ->
            readFrom inA[0]
            writeTo outA[0]
        | Dup ->
            readFrom inA[0]
            writeTo outA[0]
            writeTo outA[1]
        | Const _ -> writeTo outA[0]
        | ParITE ->
            readFrom inA[0]
            readFrom inA[1]
            readFrom inA[2]
            writeTo outA[0]
        | Join ->
            readFrom inA[0]
            readFrom inA[1]
            writeTo outA[0]
        | Load _ ->
            readFrom inA[0]
            readFrom inA[1]
            writeTo outA[0]
            writeTo outA[1]
        | Store _ ->
            readFrom inA[0]
            readFrom inA[1]
            readFrom inA[2]
            writeTo outA[0]
        | _ -> raise UndefindedNodeInPath

/// <summary>
/// Relies on the assumption that the path is ordered, returns first the read and written buffers
/// then the external read and written buffers
/// </summary>
let calculatePathBuffers dpn path : PathBuffers * PathBuffers =
    // stores the buffers set by this path
    let mutable setBuffers: string list = []
    // stores all buffers used in a get operation in this path
    let mutable getBuffers: string list = []


    //each external variable is built while reading the path
    //a variable is declared an external input if it is read before it is set
    let mutable externalInput: string list = []
    //a varibale is declared an external output if it is not read after it is set
    let mutable externalOutput: string list = []

    let appendGetBufferName (name: string) =
        if not (List.contains name getBuffers) then
            getBuffers <- name :: getBuffers

            if not (List.contains name setBuffers) then
                externalInput <- name :: externalInput

        externalOutput <- List.filter ((<>) name) externalOutput

    let appendSetBufferName name =
        if List.contains name setBuffers then ()
        externalOutput <- name :: externalOutput
        setBuffers <- name :: setBuffers

    traversePathBuffer dpn path appendSetBufferName appendGetBufferName

    (getBuffers, setBuffers), (externalInput, externalOutput)


/// <summary>
/// Calculate the dependencies for one path using a specified list of paths
/// </summary>
let calculatePathDependency dpn (paths: NamedPathBuffers list) pathName =
    let pathBuf = snd (List.find (fun x -> fst x = pathName) paths)
    let gets = (fst pathBuf) |> List.filter(fun x -> not (Set.contains x dpn.inVars || Set.contains x dpn.memAdrs))
    let mutable result: Set<PathDependency> = Set.empty

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

    let mutable result: Set<PathDependency list> = Set.empty

    for dep in fromDeps do
        let (_, next, _) = dep

        if next = to_ then
            result <- Set.add [dep] result

        if not (Set.contains next visited) then
            for found in traverseDependenciesTo dependencies next to_ (Set.add from visited) do
                result <- Set.add (dep :: found) result

    result


/// <summary>
/// Returns a set of deadlocks found.
/// </summary>
let calculateDeadlocks dependencies =
    let mutable result: Set<PathDeadlock> = Set.empty

    for dep in dependencies do
        let (from, _, _) = dep
        let cycles = traverseDependenciesTo dependencies from from Set.empty
        result <- cycles |> Set.map Set.ofList |> Set.union result

    result


let resolveDeadlocksPathJoin (nodeLevels: Map<int, int>) (paths: int list list) (deadlocks: Set<PathDeadlock>) =
    // stores a list of the paths to be merged by their index in "paths"
    // this is built up for every deadlock such that, at the end, every deadlock that requires joining is one list
    // paths never touched by deadlocks remain as a single element list
    let mutable pathsToJoin: Set<int list> =
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
        let (toRemain, toJoin) =
            Set.partition (List.forall (fun y -> not (Set.contains y pathIndices))) pathsToJoin

        pathsToJoin <-
            toRemain
            |> Set.add (toJoin |> Set.toList |> List.collect id)

    pathsToJoin
    |> Set.map (List.collect (fun n -> paths[n]))
    |> Set.map (List.sortBy (fun n -> nodeLevels[n]))


let resolveDeadlocksPathSplit (nodeLevels: Map<int, int>) dpn (initialPaths: int list list) (initialDeadlocks: Set<PathDeadlock>) =
    // basic idea: taking one dependency out of a deadlock, resolves it:
    // we try to take the topmost dependent node by level (whose path can be executed)
    // and split it into an upper and a lower part.

    let rec helper handledDependencies newPaths deadlocks =
        match deadlocks with
        | [] -> handledDependencies, newPaths
        | head::tail ->
            let newHandledDependencies, newPaths = helper handledDependencies newPaths tail

            if newHandledDependencies |> Set.exists (fun dep -> head |> Set.contains dep) then
                // one of the dependencies in the deadlock was already resolved.
                newHandledDependencies, newPaths
            else

                let dependencyToSplit, producersToSplit =
                    head
                    |> Set.toList
                    |> List.map (fun dep ->
                        let _, _, buffers = dep
                        dep,  buffers |> List.map (fun x -> dpn.prod[x])
                    )
                    |> List.minBy (fun (_, prods) -> prods |> List.map (fun x -> nodeLevels[x]) |> List.min)

                let pathToSplitAsList, otherPaths = 
                    newPaths 
                    |> List.partition (fun path -> producersToSplit |> List.forall (fun producer -> path |> List.contains producer))
                    
                match pathToSplitAsList with
                | [pathToSplit] ->

                    let highestProducerLevel =
                        producersToSplit 
                        |> List.map (fun x -> nodeLevels[x])
                        |> List.min

                    let pathAbove, pathBelow = pathToSplit |> List.partition (fun node -> nodeLevels[node] <= highestProducerLevel)

                    newHandledDependencies |> Set.add dependencyToSplit, 
                    pathAbove::pathBelow::otherPaths
                    
                | _ -> 
                    // if no path could be found, only abort if this path was not already split.
                    // it could be that the path we tried to split was already split and thus is no longer existent
                    // rely on the iteration below to resolve this deadlock (if it still exists)
                    if newHandledDependencies |> Set.exists (
                        fun dep ->
                        let _, targetPath, _ = dep
                        let _, thisPath, _ = dependencyToSplit
                        targetPath = thisPath
                    ) then
                        newHandledDependencies, newPaths
                    else                
                        failwith "no path could be split - abort"



    let mutable newPaths = initialPaths
    let mutable currentDeadlocks = initialDeadlocks |> Set.toList

    while currentDeadlocks <> List.empty do        
        let _, returnedPaths = helper Set.empty newPaths currentDeadlocks
        newPaths <- returnedPaths

        let pathBuffers =
            newPaths
            |> List.map (fun path -> fst (calculatePathBuffers dpn path))
            |> List.indexed

        let pathDependencies =
            seq { 0 .. pathBuffers.Length - 1 }
            |> Set.ofSeq
            |> Set.map (calculatePathDependency dpn pathBuffers)
            |> Set.unionMany
        
        currentDeadlocks <- calculateDeadlocks pathDependencies |> Set.toList

            

    newPaths |> Set.ofList