module Translator.SingleThreadWriter
open Averest.MiniC.DataflowProcessNetworks
open Translator.CommonWriter
open Translator.PathAnalyzer
open Types


let generateSingleThreadCode (dpn: DataflowProcessNetwork) (buffers : Map<string, Types.Buffer>) (orderedPaths : list<Set<int * list<int> * PathBuffers>>) mnc : string = 
    let mutable code = ""
    let tabSpace = "    "
    
    let array = calculateArrayVariables dpn mnc
    code <- code + writeIncludes
    code <- code + writeMain
    code <- code + startTiming
    dpn.inVars |> Set.iter (fun x  -> 
        code <- code + tabSpace + buffers[x].TranslatedType + " " + x + ";\n"
    )

    for arr in array do
        code <- code + 
            (sprintf "%s%s %s = new %s[%d];\n" tabSpace arr.TranslatedType arr.Name (typeCtoStr (arrayBaseType arr.TypeC)).Value (arraySize arr))
    

    for executablePaths in orderedPaths do
        for i in executablePaths do
            let _, nodes, _ = i
            code <- code + generateMethodBodyCode dpn buffers nodes [] []  

    code <- code + endTiming
    for arr in array do
        code <- code + (sprintf "delete %s;" arr.Name)
    
    code <- code + tabSpace + "std::cout << "
    for output in dpn.outVars do
        code <- code + (sprintf "\"%s: \" << %s << " output output)
    code <- code + "std::endl;\n"
    code <- writeTime
    code <- code + tabSpace +  "return 0;" + "\n}"
    code