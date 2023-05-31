#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(int _bf81, int _bf46, int _bf15, int w_1, int w_3, int x_2, int x_6, int x_3, int x_5, int x_1, int x_7, int x_4, int x_0, int* y_3, int* y_7, int* y_2, int* y_6, int* y_1, int* y_5, int* y_0, int* y_4) { " 
    "    int _bf0 = x_0;" 
    "    int _bf12 = x_0;" 
    "    int _bf1 = x_4;" 
    "    int _bf13 = x_4;" 
    "    int _bf10 = x_7;" 
    "    int _bf27 = x_7;" 
    "    int _bf3 = x_1;" 
    "    int _bf16 = x_1;" 
    "    int _bf4 = x_5;" 
    "    int _bf17 = x_5;" 
    "    int _bf9 = x_3;" 
    "    int _bf26 = x_3;" 
    "    int _bf7 = x_6;" 
    "    int _bf22 = x_6;" 
    "    int _bf6 = x_2;" 
    "    int _bf21 = x_2;" 
    "    int _bf2 = _bf0 + _bf1;" 
    "    int _bf14 = _bf12 - _bf13;" 
    "    int _bf28 = _bf26 - _bf27;" 
    "    int _bf18 = _bf16 - _bf17;" 
    "    int _bf5 = _bf3 + _bf4;" 
    "    int _bf11 = _bf9 + _bf10;" 
    "    int _bf8 = _bf6 + _bf7;" 
    "    int _bf23 = _bf21 - _bf22;" 
    "    int _bf30 = _bf2;" 
    "    int _bf36 = _bf2;" 
    "    int _bf56 = _bf14;" 
    "    int _bf62 = _bf14;" 
    "    int _bf29 = w_3 * _bf28;" 
    "    int _bf19 = w_1 * _bf18;" 
    "    int _bf33 = _bf5;" 
    "    int _bf40 = _bf5;" 
    "    int _bf34 = _bf11;" 
    "    int _bf41 = _bf11;" 
    "    int _bf31 = _bf8;" 
    "    int _bf37 = _bf8;" 
    "    int _bf24 = _bf15 * _bf23;" 
    "    int _bf32 = _bf30 + _bf31;" 
    "    int _bf55 = _bf56;" 
    "    int _bf60 = _bf29;" 
    "    int _bf67 = _bf29;" 
    "    int _bf59 = _bf19;" 
    "    int _bf66 = _bf19;" 
    "    int _bf42 = _bf40 - _bf41;" 
    "    int _bf35 = _bf33 + _bf34;" 
    "    int _bf38 = _bf36 - _bf37;" 
    "    int _bf57 = _bf24;" 
    "    int _bf63 = _bf24;" 
    "    int _bf72 = _bf62;" 
    "    int _bf44 = _bf32;" 
    "    int _bf47 = _bf32;" 
    "    int _bf58 = _bf55 + _bf57;" 
    "    int _bf61 = _bf59 + _bf60;" 
    "    int _bf68 = _bf66 - _bf67;" 
    "    int _bf43 = _bf46 * _bf42;" 
    "    int _bf45 = _bf35;" 
    "    int _bf48 = _bf35;" 
    "    int _bf50 = _bf38;" 
    "    int _bf53 = _bf38;" 
    "    int _bf64 = _bf72 - _bf63;" 
    "    *y_4 = _bf47 - _bf48;" 
    "    int _bf70 = _bf58;" 
    "    int _bf73 = _bf58;" 
    "    int _bf71 = _bf61;" 
    "    int _bf74 = _bf61;" 
    "    int _bf69 = _bf81 * _bf68;" 
    "    int _bf51 = _bf43;" 
    "    int _bf54 = _bf43;" 
    "    *y_0 = _bf44 + _bf45;" 
    "    int _bf49 = _bf50;" 
    "    int _bf52 = _bf53;" 
    "    int _bf76 = _bf64;" 
    "    int _bf79 = _bf64;" 
    "    *y_5 = _bf73 - _bf74;" 
    "    *y_1 = _bf70 + _bf71;" 
    "    int _bf77 = _bf69;" 
    "    int _bf80 = _bf69;" 
    "    *y_6 = _bf52 - _bf54;" 
    "    *y_2 = _bf49 + _bf51;" 
    "    int _bf82 = _bf76;" 
    "    int _bf83 = _bf79;" 
    "    *y_7 = _bf83 - _bf80;" 
    "    *y_3 = _bf82 + _bf77;" 
    "}" 
    "void path1(int w_2, int* _bf46, int* _bf65, int* _bf20) { " 
    "    *_bf20 = w_2;" 
    "    int _bf123 = w_2;" 
    "    int _bf39 = _bf123;" 
    "    *_bf65 = _bf123;" 
    "    int _bf25 = _bf39;" 
    "    *_bf46 = _bf25;" 
    "}" 
    "void path2(int _bf20, int* _bf15) { " 
    "    *_bf15 = _bf20;" 
    "}" 
    "void path3(int _bf65, int* _bf81) { " 
    "    int _bf75 = _bf65;" 
    "    int _bf78 = _bf75;" 
    "    *_bf81 = _bf78;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    int w_1 = inputs[threadId * 11 + 0];" 
    "    int w_2 = inputs[threadId * 11 + 1];" 
    "    int w_3 = inputs[threadId * 11 + 2];" 
    "    int x_0 = inputs[threadId * 11 + 3];" 
    "    int x_1 = inputs[threadId * 11 + 4];" 
    "    int x_2 = inputs[threadId * 11 + 5];" 
    "    int x_3 = inputs[threadId * 11 + 6];" 
    "    int x_4 = inputs[threadId * 11 + 7];" 
    "    int x_5 = inputs[threadId * 11 + 8];" 
    "    int x_6 = inputs[threadId * 11 + 9];" 
    "    int x_7 = inputs[threadId * 11 + 10];" 
    "" 
    "    int _bf46;" 
    "    int _bf65;" 
    "    int _bf20;" 
    "    path1(w_2, &_bf46, &_bf65, &_bf20);" 
    "" 
    "    int _bf15;" 
    "    path2(_bf20, &_bf15);" 
    "" 
    "    int _bf81;" 
    "    path3(_bf65, &_bf81);" 
    "" 
    "    int y_3;" 
    "    int y_7;" 
    "    int y_2;" 
    "    int y_6;" 
    "    int y_1;" 
    "    int y_5;" 
    "    int y_0;" 
    "    int y_4;" 
    "    path0(_bf81, _bf46, _bf15, w_1, w_3, x_2, x_6, x_3, x_5, x_1, x_7, x_4, x_0, &y_3, &y_7, &y_2, &y_6, &y_1, &y_5, &y_0, &y_4);" 
    "" 
    "    outputs[threadId * 8 + 0] = y_0;" 
    "    outputs[threadId * 8 + 1] = y_1;" 
    "    outputs[threadId * 8 + 2] = y_2;" 
    "    outputs[threadId * 8 + 3] = y_3;" 
    "    outputs[threadId * 8 + 4] = y_4;" 
    "    outputs[threadId * 8 + 5] = y_5;" 
    "    outputs[threadId * 8 + 6] = y_6;" 
    "    outputs[threadId * 8 + 7] = y_7;" 
    "}" 
    "";


int main(int argc, char** argv)
{
    bool onlyTimeOutput = [&]() {
        if (argc < 2) return false;

        if (std::string(argv[1]) == "--onlytime")
            return true;
        else
            return false;
    }();


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
    int* outputs = new int[DATA_SIZE * 8];
    err = clGetPlatformIDs(3, platform_ids, &num_of_platforms);

    if (clGetDeviceIDs(platform_ids[1], CL_DEVICE_TYPE_CPU, 1, &device_id, &num_of_devices) != CL_SUCCESS) {
        printf("unable to get device_id");
        return 1;
    }

    properties[0] = CL_CONTEXT_PLATFORM;
    properties[1] = (cl_context_properties)platform_ids[1];
    properties[2] = 0;

    context = clCreateContext(properties, 1, &device_id, NULL, NULL, &err);
    command_queue = clCreateCommandQueueWithProperties(context, device_id, NULL, &err);
    program = clCreateProgramWithSource(context, 1, (const char**)&KernelSource, NULL, &err);

    err = clBuildProgram(program, 1, &device_id, "-cl-std=CL2.0", NULL, NULL);
    kernel = clCreateKernel(program, "Execute", &err);

    input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * DATA_SIZE * 11, NULL, &err);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE * 8, NULL, &err);

    int* nums = new int[DATA_SIZE * 11];
    memset(nums, 0, 11 * DATA_SIZE * sizeof(int));

    clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 11, nums, 0, NULL, NULL);
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    clFinish(command_queue);

    size_t global = DATA_SIZE;

    auto start = chrono::steady_clock::now();
    clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    clFinish(command_queue);
    auto end = chrono::steady_clock::now();

    clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 8, outputs, 0, NULL, NULL);
    if (!onlyTimeOutput)
           printf("y_0: %i, y_1: %i, y_2: %i, y_3: %i, y_4: %i, y_5: %i, y_6: %i, y_7: %i", outputs[0], outputs[1], outputs[2], outputs[3], outputs[4], outputs[5], outputs[6], outputs[7]);
       

    clReleaseMemObject(input);
    clReleaseMemObject(output);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(command_queue);
    clReleaseContext(context);
    
    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());


    return 0;
}
