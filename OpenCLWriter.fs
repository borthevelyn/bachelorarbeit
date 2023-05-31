module Translator.OpenCLWriter

open Translator.CommonWriter
open Translator.PathAnalyzer
open Averest.MiniC.DataflowProcessNetworks
open System
open Types


let generateHeader () =
    "#define CL_TARGET_OPENCL_VERSION 220\n#define DATA_SIZE 1\n#include <string>\n#include <cstring>\n#include \"CL/opencl.h\"\n#include <stdio.h>\n#include <chrono>\n\nusing namespace std;\n\n"

let generatePathCode dpn bufferTypes pathsAndBuffers =
    let mutable res = ""

    for pathBuffer in pathsAndBuffers do
        let (id, path, buffer) = pathBuffer
        res <- res + generateFunctionCode dpn bufferTypes path buffer ("path" + (string id))

    res <- res + "\n"

    res

let generateExecuteCode dpn (buffers: Map<string, Types.Buffer>) executablePathOrder inputSize outputSize  =
    let mutable res = ""
    let mutable count = 0

    res <- res + "__kernel void Execute(__global int* inputs, __global int* outputs) { \n    size_t threadId = get_global_id(0); \n"
     
     // variable input definition
    dpn.inVars
    |> Set.iter (fun x ->
        res <- res + tabSpace + buffers[x].TranslatedType + " " + string x + " = inputs[threadId * " 
                   + string dpn.inVars.Count + " + " + string count + "];\n"
        count <- count + 1)
    
    // array input definition
    if not (dpn.memAdrs.IsEmpty) then
        dpn.memAdrs
        |> Seq.iter (fun x -> 
            res <- sprintf "%s%s%s %s = inputs + threadId * %d + %d;\n" res tabSpace (buffers[x].TranslatedType) (string x) inputSize count
            count <- count + arraySize buffers[x] 
            )

    res <- res + "\n"

    for executablePaths in executablePathOrder do
        for i in executablePaths do
            let id, (input, output) = i

            output
            |> List.iter (fun x ->
                if not (dpn.memAdrs.Contains x) && not (dpn.inVars |> Set.contains x) then 
                    res <- res + tabSpace + buffers[x].TranslatedType + " " + x + ";\n")

            res <- res + tabSpace + "path" + string id + "("

            input
            |> List.filter (fun x -> not (List.contains x output))
            |> List.iter (fun x -> res <- res + x + ", ")

            output
            |> List.iter (fun x -> res <- res + "&" + x + ", ")

            res <- res[0 .. res.Length - 3] + ");\n\n"

    
    count <- 0
    
    // variable output assignment
    dpn.outVars
    |> Set.iter (fun x ->
        res <- sprintf "%s%soutputs[threadId * %d + %d] = %s;\n" res tabSpace outputSize count x
        count <- count + 1)

    // array output assignment
    if not (dpn.memAdrs.IsEmpty) then
        dpn.memAdrs
        |> Set.iter (fun x ->
            seq { 0 .. arraySize buffers[x] - 1 }
            |> Seq.iter (fun y -> 
                res <- sprintf "%s%soutputs[threadId * %d + %d] = %s[%d];\n" res tabSpace outputSize count x y
                count <- count + 1)
            )

    res <- res + "}\n"

    res

let generateKernelSourceCode (pathCode: string) (executeCode: string) =
    let mutable res = ""
    res <- res + "const char* KernelSource = \n"

    let lines = (pathCode + executeCode).Split('\n', StringSplitOptions.None)

    for line in lines do
        res <- res + tabSpace + "\"" + line + "\" \n"

    res <- res[0 .. res.Length - 3]
    res <- res + ";\n\n"


    res

let generateMainCode (inputSize: string) (outputSize: string) (resultOutput: string) =
    let mutable res = ""
    res <- res + writeMain

    res <-
        res
        + "
    cl_context context;
    cl_context_properties properties[3];
    cl_kernel kernel;
    cl_command_queue command_queue;
    cl_program program;
    cl_int err;
    cl_uint num_of_platforms = 0;
    cl_platform_id platform_ids[3];
    cl_device_id device_id;
    cl_uint num_of_devices = 0;
    cl_mem input, output;
    int* outputs = new int[DATA_SIZE * "
        + outputSize
        + "];
    err = clGetPlatformIDs(3, platform_ids, &num_of_platforms);

    if (clGetDeviceIDs(platform_ids[1], CL_DEVICE_TYPE_CPU, 1, &device_id, &num_of_devices) != CL_SUCCESS) {
        printf(\"unable to get device_id\");
        return 1;
    }

    properties[0] = CL_CONTEXT_PLATFORM;
    properties[1] = (cl_context_properties)platform_ids[1];
    properties[2] = 0;

    context = clCreateContext(properties, 1, &device_id, NULL, NULL, &err);
    command_queue = clCreateCommandQueueWithProperties(context, device_id, NULL, &err);
    program = clCreateProgramWithSource(context, 1, (const char**)&KernelSource, NULL, &err);

    err = clBuildProgram(program, 1, &device_id, \"-cl-std=CL2.0\", NULL, NULL);
    kernel = clCreateKernel(program, \"Execute\", &err);

    input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * DATA_SIZE * "
        + inputSize
        + ", NULL, &err);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE * "
        + outputSize
        + ", NULL, &err);

    int* nums = new int[DATA_SIZE * "
        + inputSize
        + "];
    memset(nums, 0, "
        + inputSize
        + " * DATA_SIZE * sizeof(int));

    clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(int) * DATA_SIZE * " + inputSize + ", nums, 0, NULL, NULL);
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    clFinish(command_queue);

    size_t global = DATA_SIZE;

    auto start = chrono::steady_clock::now();
    clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    clFinish(command_queue);
    auto end = chrono::steady_clock::now();

    clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE * "
        + outputSize
        + ", outputs, 0, NULL, NULL);"

    let lines = resultOutput.Split('\n', StringSplitOptions.None)


    if not (lines |> Array.forall String.IsNullOrWhiteSpace) then
        res <- res + notOnlyTimeOutput
        for line in lines do
            res <- res + tabSpace2 + line + "\n"

    res <-
        res
        + "
    clReleaseMemObject(input);
    clReleaseMemObject(output);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(command_queue);
    clReleaseContext(context);
    "

    res <-
        res
        + writeTime
        + "
    return 0;
}
"

    res


let generateCLCode
    dpn
    (buffers: Map<string, Types.Buffer>)
    (orderedPaths: Set<int * int list * PathBuffers> list)
    : string =
    let mutable code = ""

    // sum up all array sizes for input and output
    let arraySizes =
        dpn.memAdrs 
        |> Set.toList 
        |> List.map (fun x -> arraySize buffers[x])
        |> List.sum 

    let inputSize = arraySizes + dpn.inVars.Count
    let outputSize = arraySizes + dpn.outVars.Count

    let pathBuffers: Set<int * list<int> * PathBuffers> =
        orderedPaths
        |> List.collect Set.toList
        |> Set.ofList

    let idBuffers: list<Set<int * PathBuffers>> =
        orderedPaths
        |> List.map (fun x -> (x |> Set.map (fun (id, _, buffer) -> id, buffer)))

    let pathCode = generatePathCode dpn buffers pathBuffers
    let executeCode = generateExecuteCode dpn buffers idBuffers inputSize outputSize 
    let resultOutput = generateResultOutput dpn.outVars

    code <- code + generateHeader ()
    code <- code + (generateKernelSourceCode pathCode executeCode)
    code <- code + (generateMainCode (string inputSize) (string outputSize) resultOutput)

    code
