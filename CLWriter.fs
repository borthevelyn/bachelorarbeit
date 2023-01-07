module Translator.CLWriter

open Translator.CommonWriter
open Translator.PathAnalyzer
open Averest.MiniC.DataflowProcessNetworks


let tabSpace = "    "

let generateCLCode dpn (bufferTypes : Map<string, string>) (pathsAndBuffers : Set<(int list) * PathBuffers>) : string =
    let mutable code = ""
    let mutable count = 0;
    let mutable calc = dpn.inVars

    for pathBuffer in pathsAndBuffers do
        let (path, buffer) = pathBuffer
        code <- code + generateMethodCode dpn bufferTypes path buffer ("path" + (count.ToString()))
        count <- count + 1
    
    count <- 0
    code <- code + "__kernel void Execute(__global int* inputs, __global int* outputs) { \n    size_t threadId = get_global_id(0); \n"
    dpn.inVars |> Set.iter (fun x  -> 
        code <- code + tabSpace + bufferTypes[x] + " "+ x.ToString() + " = inputs[threadId * "
            + dpn.inVars.Count.ToString() + " + " + count.ToString() + "];\n"
        count <- count + 1
        )

    let paths = pathsAndBuffers |> Set.toList
    let mutable remainingPaths = {0..paths.Length-1}
                                |>Seq.toList


    while not (remainingPaths.IsEmpty) do
        let mutable executablePaths = List.Empty
        for i in remainingPaths do
            let (input, output) = snd paths[i]
            if List.forall calc.Contains input then
                // path can be executed
                calc <- calc |> Set.union (output |> Set.ofList)
                executablePaths <- i::executablePaths
                remainingPaths <- List.removeAt(List.findIndex (fun x-> x = i) remainingPaths) remainingPaths

        for i in executablePaths do
            let (input, output) = snd paths[i]
            output |> List.iter (fun x -> code <- code + tabSpace + bufferTypes[x] + " " + x + ";\n")
            code <- code + tabSpace + "path" + i.ToString() + "(" 
            input |> List.iter (fun x -> code <- code + x + ", ")
            output |> List.iter (fun x -> code <- code + "&" + x + ", ")
            code <- code[0 ..  code.Length - 3] + ");\n\n"

    count <- 0
    dpn.outVars |> Set.iter (fun x -> 
        code  <- sprintf"%s%soutputs[threadId * %d + %d] = %s;\n"code  tabSpace  dpn.outVars.Count  count  x 
        count <- count + 1)
    code <- code +  "}"
    code