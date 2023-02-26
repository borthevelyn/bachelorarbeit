module Translator.CLWriter

open Translator.CommonWriter
open Translator.PathAnalyzer
open Averest.MiniC.DataflowProcessNetworks
open System


let tabSpace = "    "

let generateHeader datasize = 
    "#define DATA_SIZE " + (string datasize) + "\n#include \"CL/opencl.h\"\n#include <stdio.h>\n#include <chrono>\n\nusing namespace std;\n\n"

let generatePathCode dpn bufferTypes pathsAndBuffers =
    let mutable res = ""
    let mutable count = 0
    for pathBuffer in pathsAndBuffers do 
        let (path, buffer) = pathBuffer
        res <- res + generateMethodCode dpn bufferTypes path buffer ("path" + ( string count ))
        count <- count + 1
    res <- res + "\n"

    res

let generateExecuteCode dpn (buffers : Map<string, Types.Buffer>) pathsAndBuffers mnc = 
    let mutable res = ""
    let mutable count = 0
    let calc = calculateKnownVariables dpn mnc

    res <- res + "__kernel void Execute(__global int* inputs, __global int* outputs) { \n    size_t threadId = get_global_id(0); \n"
    dpn.inVars |> Set.iter (fun x  -> 
        res <- res + tabSpace + buffers[x].TranslatedType + " "+ string x + " = inputs[threadId * "
            + string dpn.inVars.Count + " + " + string count + "];\n"
        count <- count + 1
        )

    let paths = pathsAndBuffers |> Set.toList

    findExectuablePaths paths calc (fun executablePaths ->
        for i in executablePaths do
            let (input, output) = snd paths[i]
            output |> List.iter (fun x -> res <- res + tabSpace + buffers[x].TranslatedType + " " + x + ";\n")
            res <- res + tabSpace + "path" + string i + "(" 
            input |> List.iter (fun x -> res <- res + x + ", ")
            output |> List.iter (fun x -> res <- res + "&" + x + ", ")
            res <- res[0 ..  res.Length - 3] + ");\n\n")
    
    count <- 0
    dpn.outVars |> Set.iter (fun x -> 
        res  <- sprintf"%s%soutputs[threadId * %d + %d] = %s;\n" res  tabSpace  dpn.outVars.Count  count  x 
        count <- count + 1)
    res <- res +  "}\n"
    
    res

let generateKernelSourceCode (pathCode:string) (executeCode:string)= 
    let mutable res = ""
    res <- res + "const char* KernelSource = \n"
    let lines = (pathCode + executeCode).Split([| "\n" |], StringSplitOptions.None)

    for line in lines do
        res <- res + tabSpace + "\""+ line + "\" \n"

    res <- res[0 .. res.Length - 3]
    res <- res + ";\n\n"


    res

let generateMainCode (inputSize:string) (outputSize:string) (resultOutput:string) = 
    let mutable res = "" 
    res <- res 
        + "int main(void) \n { \n" 
        + tabSpace + "cl_context context;\n"
        + tabSpace + "cl_context_properties properties[3];\n"
        + tabSpace + "cl_kernel kernel;\n"
        + tabSpace + "cl_command_queue command_queue;\n"
        + tabSpace + "cl_program program;\n"
        + tabSpace + "cl_int err;\n"
        + tabSpace + "cl_uint num_of_platforms = 0;\n"
        + tabSpace + "cl_platform_id platform_id;\n"
        + tabSpace + "cl_device_id device_id;\n"
        + tabSpace + "cl_uint num_of_devices = 0;\n"
        + tabSpace + "cl_mem input, output;\n"   
        + tabSpace + "int* outputs = new int[DATA_SIZE * " + outputSize + "];\n\n"
        + tabSpace + "err = clGetPlatformIDs(1, &platform_id, &num_of_platforms);\n"
        + tabSpace + "if (clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_of_devices) != CL_SUCCESS) {\n"
        + tabSpace + "  printf(\"unable to get device_id\");\n"
        + tabSpace + "  return 1;\n}\n"
        + tabSpace + "properties[0] = CL_CONTEXT_PLATFORM;\n"
        + tabSpace + "properties[1] = (cl_context_properties)platform_id;\n"
        + tabSpace + "properties[2] = 0;\n\n"
        + tabSpace + "context = clCreateContext(properties, 1, &device_id, NULL, NULL, &err);\n"
        + tabSpace + "command_queue = clCreateCommandQueueWithProperties(context, device_id, 0, &err);\n"
        + tabSpace + "program = clCreateProgramWithSource(context, 1, (const char**)&KernelSource, NULL, &err);\n"
        + tabSpace + "err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);\n"
        + tabSpace + "kernel = clCreateKernel(program, \"Execute\", &err);\n\n"
        + tabSpace + "input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * DATA_SIZE * " + inputSize + ", NULL, NULL);\n"
        + tabSpace + "output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE * " + outputSize + ", NULL, NULL);\n"
        + tabSpace + "int* nums = new int[DATA_SIZE * " + inputSize + "];\n"
        + tabSpace + "memset(nums, 0,"+ inputSize + " * DATA_SIZE * sizeof(int));\n"
        + tabSpace + "clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(int) * DATA_SIZE, nums, NULL, NULL, NULL);\n\n"
        + tabSpace + "clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);\n"
        + tabSpace + "clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);\n"
        + tabSpace + "size_t global = DATA_SIZE;\n"
        + tabSpace + "clFinish(command_queue);\n"
        + tabSpace + "clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);\n"
        + tabSpace + "auto start = chrono::steady_clock::now();\n"
        + tabSpace + "clFinish(command_queue);\n"
        + tabSpace + "auto end = chrono::steady_clock::now();\n"
        + tabSpace + "clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE * " + outputSize + ", outputs, 0, NULL, NULL);\n"
        
    let lines = (resultOutput).Split([| "\n" |], StringSplitOptions.None)
    for line in lines do 
        res <- res + tabSpace + line + "\n"

    res <- res 
        + "\n"
        + tabSpace + "clReleaseMemObject(input);\n"
        + tabSpace + "clReleaseMemObject(output);\n"
        + tabSpace + "clReleaseProgram(program);\n"
        + tabSpace + "clReleaseKernel(kernel);\n"
        + tabSpace + "clReleaseCommandQueue(command_queue);\n"
        + tabSpace + "clReleaseContext(context);\n\n"
        + tabSpace + "printf(\"time: %lld ms\n\", chrono::duration_cast<chrono::milliseconds>(end - start).count());\n\n"
        + tabSpace + "return 0;\n}\n#endif"

    res
    

let generateCLCode dpn (buffers : Map<string, Types.Buffer>) (pathsAndBuffers : Set<(int list) * PathBuffers>) mnc : string =
    let mutable code = "#if 0 \n" 
    let datasize = 1
    let pathCode = generatePathCode dpn buffers pathsAndBuffers
    let executeCode = generateExecuteCode dpn buffers pathsAndBuffers mnc
    let resultOutput = generateResultOutput dpn.outVars datasize
    
    let writeCode str = 
        code <- code + str

    writeCode (generateHeader datasize)
    writeCode (generateKernelSourceCode pathCode executeCode)
    writeCode (generateMainCode (string dpn.inVars.Count) (string dpn.outVars.Count) resultOutput)

    code

