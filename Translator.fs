module Translator.Main

open Translator.Types
open Translator.PathAnalyzer
open Translator.CLWriter
open Translator.OpenMPWriter
open Translator.SingleThreadWriter
open Averest.MiniC.IO
open Averest.MiniC.Types
open Averest.MiniC.DataflowProcessNetworks
open CommonWriter

let WriteCLCode mncs =
    // generate program and dpn
    let errorStr = Some System.Console.Out
    let mncPrg = ParseMiniCFromString errorStr mncs
    let unleveledDpn = (MiniC2DPN mncPrg)[0]
    WriteDPN2Dotfile "myDPN.gv" unleveledDpn None None None
    let (dpn, _, nodeLevels, _) = LevelizeDPN false false unleveledDpn
    WriteDPN2Dotfile "myLeveledDPN.gv" dpn None None None

    let preDefTypes = 
        Array.concat [(
            dpn.arrDecls
            |> Map.toArray
            ); mncPrg.SharedVariables] |> 
        Array.map (fun entry -> fst entry, constructBuffer (collapseArray (snd entry)) (fst entry) Standard)

    // analyze buffer types
    let varTypes : Map<string, Buffer> = buildBufferTypeLookup dpn (preDefTypes |> Map.ofArray) dpn.buffers
    
    // analyze vertex disjoint paths for deadlocks    
    let (edges, paths) = MinimumNumberOfVertexDisjointPathsDPN dpn
    let pathsList = Set.toList paths
    let pathBuffers : NamedPathBuffers list =
        pathsList
        |> List.map (fun path -> fst (calculatePathBuffers dpn path))
        |> List.zip (seq { 0 .. paths.Count - 1 } |> List.ofSeq)

    let pathDependencies : Set<PathDependency> =
        seq { 0 .. pathBuffers.Length - 1 }
        |> Set.ofSeq
        |> Set.map (calculatePathDependency pathBuffers)
        |> Set.fold Set.union Set.empty

    let deadlocks : Set<PathDeadlock> = 
        calculateDeadlocks pathDependencies

    let resolvedPaths = 
        resolveDeadlocksPathJoin nodeLevels pathsList deadlocks
        |> Set.toList

    let namedOneNodePaths = 
        seq { 0 .. dpn.nodes.Length - 1 }
        |> List.ofSeq
        |> List.map(fun x -> 
            let (outA, _, inA) = dpn.nodes[x]     
            x, [x], (PathBuffers) (List.ofArray inA, List.ofArray outA))
    
    let namedResolvedPaths =
        resolvedPaths
        |> List.map (fun x -> (x, snd (calculatePathBuffers dpn x)))
        |> List.mapi (fun i (path, pb) -> i, path, pb)
    
    let inputs = calculateKnownVariables dpn mncPrg

    let orderedNodePaths = calculateExecutionOrder namedOneNodePaths inputs
    let orderedResolvedPaths = calculateExecutionOrder namedResolvedPaths inputs
    


    //System.IO.File.WriteAllText("test.cpp", generateSingleThreadCode dpn varTypes orderedNodePaths mncPrg)
    //System.IO.File.WriteAllText("OpenMP_MatrixMultSimple_1.cpp", generateOpenMPCode dpn varTypes orderedNodePaths mncPrg)
    //System.IO.File.WriteAllText("OpenMP_MatrixMultSimple_2.cpp", generateOpenMPCode dpn varTypes orderedResolvedPaths mncPrg)
    System.IO.File.WriteAllText("OpenCL_MatrixMultSimple_1.cpp", generateCLCode dpn varTypes orderedNodePaths mncPrg)
    //System.IO.File.WriteAllText("OpenCL_MatrixMultSimple_2.cpp", generateCLCode dpn varTypes orderedResolvedPaths mncPrg)

    let minPathLength (path: list<int * list<int> * PathBuffers>) = 
        path
        |> List.map (fun x -> 
            let _, a, _ = x
            a.Length)
        |> List.min

    let maxPathLength (path: list<int * list<int> * PathBuffers>) = 
        path
        |> List.map (fun x -> 
            let _, a, _ = x
            a.Length)
        |> List.max
        

    let avgPathLength (path: list<int * list<int> * PathBuffers>) = 
        path
        |> List.map (fun x -> 
            let _, a, _ = x
            float a.Length)
        |> List.average
        |> string
    
    let maxExecutablePaths1 = 
        orderedNodePaths
        |> List.maxBy Set.count
        |> Set.count
        |> string

    let maxExecutablePaths2 =
        orderedResolvedPaths
        |> List.maxBy Set.count
        |> Set.count
        |> string
    
       
    printfn "%s" ("              |".PadLeft(35) +  "Variante 1".PadLeft(10) + "|".PadRight(2) + "Variante 2 " + "\n" +
                       "Threads:            " + "|".PadLeft(15)+ (string namedOneNodePaths.Length).PadRight(10) + "|".PadRight(2) + string namedResolvedPaths.Length + "\n" +
                       "Knotenanzahl:       " + "|".PadLeft(15) + (string dpn.nodes.Length).PadRight(10)  + "|".PadRight(2) + dpn.nodes.Length.ToString() + "\n" +
                       "Minimale Pfadlänge: " + "|".PadLeft(15) + (string (minPathLength namedOneNodePaths)).PadRight(10) + "|".PadRight(2) + string (minPathLength namedResolvedPaths) + "\n" +
                       "Maximale Pfadlänge: " + "|".PadLeft(15) + (string (maxPathLength namedOneNodePaths)).PadRight(10) + "|".PadRight(2) + string (maxPathLength namedResolvedPaths) + "\n" + 
                       "Durchschnittliche Pfadlänge: " + "|".PadLeft(6) + (avgPathLength namedOneNodePaths).PadRight(10) + "|".PadRight(2) + avgPathLength namedResolvedPaths + "\n" +
                       "Maximale Thread Parallelisierung:"+ "|".PadLeft(2) + (maxExecutablePaths1).PadRight(10) + "|".PadRight(2) + (maxExecutablePaths2) + "\n")
   

        

