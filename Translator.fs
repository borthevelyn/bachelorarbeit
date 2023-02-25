module Translator.Main

open Translator.Types
open Translator.PathAnalyzer
open Translator.CLWriter
open Translator.OpenMPWriter
open Averest.MiniC.IO
open Averest.MiniC.Types
open Averest.MiniC.DataflowProcessNetworks

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

    let resolvedPaths = resolveDeadlocksPathJoin nodeLevels pathsList deadlocks

    let resolvedPathBuffers =
        resolvedPaths
        |> Set.map (fun x -> (x, snd (calculatePathBuffers dpn x)))
    
    let oneNodePaths = 
         seq { 0 .. dpn.nodes.Length-1 }
        |> Set.ofSeq
        |> Set.map(fun x -> let (outA, _ , inA) = dpn.nodes[x]     
                            ([x], (PathBuffers) (List.ofArray inA, List.ofArray outA)))
    
    
    System.IO.File.WriteAllText("test1.cpp", generateOpenMPCode dpn varTypes oneNodePaths mncPrg)
    System.IO.File.WriteAllText("test2.cpp", generateOpenMPCode dpn varTypes resolvedPathBuffers mncPrg)

    let minPathLength (path:Set<list<int> * PathBuffers>) = 
        path
        |> Set.map(fun x -> let a,_ = x
                            a.Length)
        |> Set.minElement

    let maxPathLength (path:Set<list<int> * PathBuffers>) = 
        path
        |> Set.map(fun x -> let a,_ = x
                            a.Length)
        |> Set.maxElement

    
    printfn "%s" ("              |".PadLeft(22) +  "Variante 1".PadLeft(10) + "|".PadRight(2) + "Variante 2 " + "\n" +
                       "Threads:            " + "|".PadLeft(2)+ oneNodePaths.Count.ToString().PadRight(10) + "|".PadRight(2) + resolvedPathBuffers.Count.ToString() + "\n" +
                       "Knotenanzahl:       " + "|".PadLeft(2) + dpn.nodes.Length.ToString().PadRight(10)  + "|".PadRight(2) + dpn.nodes.Length.ToString() + "\n" +
                       "Minimale Pfadlänge: " + "|".PadLeft(2) + (minPathLength oneNodePaths).ToString().PadRight(10) + "|".PadRight(2) + (minPathLength resolvedPathBuffers).ToString() + "\n" +
                       "Maximale Pfadlänge: " + "|".PadLeft(2) + (maxPathLength oneNodePaths).ToString().PadRight(10) + "|".PadRight(2) + (maxPathLength resolvedPathBuffers).ToString() )
   

        

