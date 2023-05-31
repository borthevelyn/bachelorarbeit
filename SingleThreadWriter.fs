module Translator.SingleThreadWriter
open Averest.MiniC.DataflowProcessNetworks
open Translator.CommonWriter
open Translator.PathAnalyzer
open Types


let generateSingleThreadCode (dpn: DataflowProcessNetwork) (buffers : Map<string, Types.Buffer>) (orderedOneNodePaths : list<Set<int * list<int> * PathBuffers>>) mnc : string = 
    let mutable code = ""
    
    let array = calculateArrayVariables dpn mnc
    code <- code + writeIncludes
    code <- code + writeMain
    
    dpn.inVars |> Set.iter (fun x  -> 
        code <- code + tabSpace + buffers[x].TranslatedType + " " + x + ";\n"
    )

    for arr in array do
        code <- code + 
            (sprintf "%s%s %s = new %s[%d];\n" tabSpace arr.TranslatedType arr.Name (typeCtoStr (arrayBaseType arr.TypeC)).Value (arraySize arr))
        code <- code + (sprintf "%smemset(%s, 0, %d * sizeof(%s));\n" tabSpace arr.Name  (arraySize arr) (typeCtoStr (arrayBaseType arr.TypeC)).Value)
    
    code <- code + startTiming
    
    // since the whole code is stitched together from its paths, the global outputs are only the arrays
    let globalOutputs = 
        array |>
        Set.toList |>
        List.map (fun buf -> buf.Name)
    let flaggedInputs = ["singleThreaded"] @ globalOutputs
    
    // iteratively add all paths to one big body
    for executablePaths in orderedOneNodePaths do
        for i in executablePaths do
            let _, nodes, _ = i
            code <- code + generateFunctionBodyCode dpn buffers nodes flaggedInputs globalOutputs

    code <- code + endTiming
    for arr in array do
        code <- code + (sprintf "%sdelete %s;\n" tabSpace arr.Name)
    code <- code + notOnlyTimeOutput
    code <- code + tabSpace2 + "std::cout << "
    for output in dpn.outVars do
        code <- code + (sprintf "\"%s: \" << %s << " output output)
    code <- code + "std::endl;\n"
    code <- code + writeTime
    code <- code + tabSpace +  "return 0;" + "\n}"
    code