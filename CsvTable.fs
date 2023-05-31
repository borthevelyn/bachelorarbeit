module Translator.CsvTable
open Translator.PathAnalyzer
open System.IO
open FSharp.Data
open Averest.MiniC.DataflowProcessNetworks

let mutable csvRows = []

type CsvType =
    CsvProvider<
        Sample="Benchmark, OneNodePath, Joined VertexDisjointPaths, Split VertexDisjointPaths", 
        Schema = "Benchmark, OneNodePath (string), Joined VertexDisjointCover (string), Split VertexDisjointPaths (string)", 
        HasHeaders=true>

type CsvTypeBenchmarks =
    CsvProvider<
        Sample="Program, Variant, Threads, Number of nodes, Minimum path length, Maximum path length, Average path length, Maximum parallelized threads, Paths after VertexDisjointCover, Deadlocks after VertexDisjointCover", 
        Schema="Program, Variant, Threads, Number of nodes, Minimum path length, Maximum path length, Average path length, Maximum parallelized threads, Paths after VertexDisjointCover, Deadlocks after VertexDisjointCover", 
        HasHeaders=true>

let createCsvTablesForBenchmarks
    (orderedNodePaths: list<Set<int * list<int> * PathBuffers>>)
    (orderedResolvedPathsJoin: list<Set<int * list<int> * PathBuffers>>)
    (orderedResolvedPathsSplit: list<Set<int * list<int> * PathBuffers>>)
    (namedOneNodePaths: list<int * list<int> * PathBuffers>)
    (namedResolvedPathsJoin: list<int * list<int> * PathBuffers>)
    (namedResolvedPathsSplit: list<int * list<int> * PathBuffers>)
    (pathsList: list<list<int>>)
    (deadlocks: Set<PathDeadlock>)
    (dpn: DataflowProcessNetwork)
    fileName
    =
    let minPathLength (path: list<int * list<int> * PathBuffers>) =
        path
        |> List.map (fun x ->
            let _, a, _ = x
            a.Length)
        |> List.min
        |> string

    let maxPathLength (path: list<int * list<int> * PathBuffers>) =
        path
        |> List.map (fun x ->
            let _, a, _ = x
            a.Length)
        |> List.max
        |> string

    let avgPathLength (path: list<int * list<int> * PathBuffers>) =
        path
        |> List.map (fun x ->
            let _, a, _ = x
            float a.Length)
        |> List.average
        |> string

    let maxExecutablePaths0 =
        orderedNodePaths
        |> List.maxBy Set.count
        |> Set.count
        |> string

    let maxExecutablePaths1 =
        orderedResolvedPathsJoin
        |> List.maxBy Set.count
        |> Set.count
        |> string

    let maxExecutablePaths2 =
        orderedResolvedPathsSplit
        |> List.maxBy Set.count
        |> Set.count
        |> string

    // notation: 0 stands for paths containing one node, 1 for joined vertex-disjoint paths, 2 for split vertex-disjoint paths
    let threads0 = string namedOneNodePaths.Length
    let threads1 = string namedResolvedPathsJoin.Length
    let threads2 = string namedResolvedPathsSplit.Length
    let nodesCount = string dpn.nodes.Length
    let minPathLength0 = minPathLength namedOneNodePaths
    let minPathLength1 = minPathLength namedResolvedPathsJoin
    let minPathLength2 = minPathLength namedResolvedPathsSplit
    let maxPathLength0 = maxPathLength namedOneNodePaths
    let maxPathLength1 = maxPathLength namedResolvedPathsJoin
    let maxPathLength2 = maxPathLength namedResolvedPathsSplit
    let avgPathLength0 = avgPathLength namedOneNodePaths
    let avgPathLength1 = avgPathLength namedResolvedPathsJoin
    let avgPathLength2 = avgPathLength namedResolvedPathsSplit
    let pathsAfterVDC = string pathsList.Length
    let deadlocksAfterVDC = string deadlocks.Count

    // create csv table for every program
    let csv =
        new CsvType(
            [ CsvType.Row("Measurement", "OneNodePath", "Joined VertexDisjointPaths", "Split VertexDisjointPaths")
              CsvType.Row("Threads", threads0, threads1, threads2)
              CsvType.Row("Number of nodes", nodesCount, nodesCount, nodesCount)
              CsvType.Row("Minimum path length", minPathLength0, minPathLength1, minPathLength2)
              CsvType.Row("Maximum path length", maxPathLength0, maxPathLength1, maxPathLength2)
              CsvType.Row("Average path length", avgPathLength0, avgPathLength1, avgPathLength2)
              CsvType.Row("Maximum parallelized threads", maxExecutablePaths0, maxExecutablePaths1, maxExecutablePaths2)
              CsvType.Row("Paths after VertexDisjointCover", "", pathsAfterVDC, pathsAfterVDC)
              CsvType.Row("Deadlocks after VertexDisjointCover", "", deadlocksAfterVDC,  deadlocksAfterVDC) ]
        )

    let filePath = "CSVTables/" + fileName + ".csv"
    File.WriteAllText(filePath, csv.SaveToString())

    // create continuously a csv table containing all programs and benchmarks
    let newRowOneNodePaths =
        [ CsvTypeBenchmarks.Row(
              fileName,
              "OneNodePaths",
              threads0,
              nodesCount,
              minPathLength0,
              maxPathLength0,
              avgPathLength0,
              maxExecutablePaths0,
              "",
              ""
          ) ]

    let newRowVertexDisjointPathsJoined =
        [ CsvTypeBenchmarks.Row(
              fileName,
              "JoinedVertexDisjointPaths",
              threads1,
              nodesCount,
              minPathLength1,
              maxPathLength1,
              avgPathLength1,
              maxExecutablePaths1,
              pathsAfterVDC,
              deadlocksAfterVDC
          ) ]
    
    let newRowVertexDisjointPathsSplit =
        [ CsvTypeBenchmarks.Row(
                fileName,
                "SplitVertexDisjointPaths",
                threads2,
                nodesCount,
                minPathLength2,
                maxPathLength2,
                avgPathLength2,
                maxExecutablePaths2,
                pathsAfterVDC,
                deadlocksAfterVDC
            ) ]

    csvRows <- csvRows @ newRowOneNodePaths @ newRowVertexDisjointPathsJoined @ newRowVertexDisjointPathsSplit


let createCsvTableForAllPrograms () =
    let sortedRows = csvRows |> List.sort

    let csvSorted = new CsvTypeBenchmarks(sortedRows)

    let pathSortedByFramework = "CSVTables/BenchmarkTableForAllPrograms.csv"

    File.WriteAllText(pathSortedByFramework, csvSorted.SaveToString())