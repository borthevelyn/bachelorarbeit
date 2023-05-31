open System
open System.IO
open FSharp.Data

type MyCsvType = CsvProvider<Sample = "Program, Execution time, Physical Memory, Paged Memory, Virtual Memory",
                             Schema = "Program (string), Execution time (string), Physical Memory (int64),Paged Memory (int64),Virtual Memory (int64)", 
                             HasHeaders = true>

let mutable rows = []
let fileEntries = Directory.GetFiles "TranslatedPrograms"
let pathCompiledPrograms = "CompiledPrograms/"

let writeFilePath fileName  =
        pathCompiledPrograms + fileName 

let compilePrograms () = 
    //compile translated programs
    System.Threading.Tasks.Parallel.ForEach(fileEntries,
        fun (translatedProgramFilePath : string) ->
            let compiledFileName = (Path.GetFileName translatedProgramFilePath).Split(".")[0]
            let openCLFlag = (Path.GetFileName translatedProgramFilePath).Split("_")[0] = "OpenCL"
            let openMPFlag = (Path.GetFileName translatedProgramFilePath).Split("_")[0] = "OpenMP"
            let c = new Diagnostics.Process()
            c.StartInfo.FileName    <- "/usr/bin/g++"
            if openCLFlag then    
                c.StartInfo.Arguments <- translatedProgramFilePath + " -lOpenCL -Ofast -o " + writeFilePath compiledFileName
            elif openMPFlag then 
                c.StartInfo.Arguments <- translatedProgramFilePath + " -Ofast  -o " + writeFilePath compiledFileName + " -fopenmp"
            else
                c.StartInfo.Arguments <- translatedProgramFilePath + " -Ofast -o " + writeFilePath compiledFileName

            c.StartInfo.UseShellExecute          <- false
            c.StartInfo.RedirectStandardInput    <- true
            c.StartInfo.RedirectStandardOutput   <- true
            c.StartInfo.RedirectStandardError    <- true
            c.Start() |> ignore
            c.WaitForExit()
            let s = c.StandardError.ReadToEnd()
            if s <> "" then
                ()
            printf "%s" s
            c.Close())
        |> ignore

let executePrograms () =
    //execute compiled programs
    let compiledFileEntries = Directory.GetFiles "CompiledPrograms"
    for compiledProgramFilePath in compiledFileEntries do
        let p = new Diagnostics.Process()
        let mutable peakPagedMem = 0L
        let mutable peakVirtualMem = 0L
        let mutable peakWorkingSet = 0L

        let compiledFileName = (Path.GetFileName compiledProgramFilePath).Split(".")[0]
        p.StartInfo.FileName    <- writeFilePath compiledFileName    
        p.StartInfo.Arguments                <- "--onlytime"
        p.StartInfo.UseShellExecute          <- false
        p.StartInfo.RedirectStandardInput    <- true
        p.StartInfo.RedirectStandardOutput   <- true
        p.StartInfo.RedirectStandardError    <- true

        let executionTime = 
            seq { 0 .. 49 }
            |> List.ofSeq
            |> List.map (fun _ ->
                let started = p.Start()
                peakWorkingSet <- max peakWorkingSet p.PeakWorkingSet64
                peakPagedMem <- max peakPagedMem p.PeakPagedMemorySize64
                peakVirtualMem <- max peakVirtualMem p.PeakVirtualMemorySize64
                let time = p.StandardOutput.ReadToEnd()
                p.WaitForExit()
                p.Close()
                double time)
            |> List.average


        let newRow = [MyCsvType.Row(compiledFileName, string executionTime, peakWorkingSet, peakPagedMem, peakVirtualMem)]
        rows <- rows @ newRow

let createCsvTables () =
    let sortedByFramework = rows |> List.sort
    let sortedByProgram = 
        rows
        |> List.sortBy (fun x -> x.Program.Split("_")[2]) 
        |> List.sortByDescending (fun x -> x.Program.Split("_")[0])
        |> List.sortBy(fun x -> x.Program.Split("_")[1])
    let csvSortedByFramework = new MyCsvType(sortedByFramework)
    let csvSortedByProgram= new MyCsvType(sortedByProgram)

    let pathSortedByFramework = "CSVTables/TableSortedByFramework.csv"
    let pathSortedByProgram = "CSVTables/TableSortedByProgram.csv"
    File.WriteAllText(pathSortedByFramework, csvSortedByFramework.SaveToString())
    File.WriteAllText(pathSortedByProgram, csvSortedByProgram.SaveToString())

compilePrograms ()
executePrograms ()
createCsvTables ()


