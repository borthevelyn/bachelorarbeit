#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(int* _bf1) { " 
    "    *_bf1 = 2;" 
    "}" 
    "void path1(int _bf0, int _bf1, int* _bf2) { " 
    "    *_bf2 = _bf0 * _bf1;" 
    "}" 
    "void path2(int* _bf4) { " 
    "    *_bf4 = 3;" 
    "}" 
    "void path3(int _bf3, int _bf4, int* _bf5) { " 
    "    *_bf5 = _bf3 * _bf4;" 
    "}" 
    "void path4(int _bf7, int _bf6, int* c) { " 
    "    *c = _bf7 + _bf6;" 
    "}" 
    "void path5(int a, int* _bf0, int* _bf3) { " 
    "    *_bf0 = a;" 
    "    *_bf3 = a;" 
    "}" 
    "void path6(int _bf2, int* _bf6, int* b) { " 
    "    *_bf6 = _bf2;" 
    "    *b = _bf2;" 
    "}" 
    "void path7(int _bf5, int* _bf7) { " 
    "    *_bf7 = _bf5;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    int a = inputs[threadId * 1 + 0];" 
    "" 
    "    int _bf1;" 
    "    path0(&_bf1);" 
    "" 
    "    int _bf4;" 
    "    path2(&_bf4);" 
    "" 
    "    int _bf0;" 
    "    int _bf3;" 
    "    path5(a, &_bf0, &_bf3);" 
    "" 
    "    int _bf2;" 
    "    path1(_bf0, _bf1, &_bf2);" 
    "" 
    "    int _bf5;" 
    "    path3(_bf3, _bf4, &_bf5);" 
    "" 
    "    int _bf6;" 
    "    int b;" 
    "    path6(_bf2, &_bf6, &b);" 
    "" 
    "    int _bf7;" 
    "    path7(_bf5, &_bf7);" 
    "" 
    "    int c;" 
    "    path4(_bf7, _bf6, &c);" 
    "" 
    "    outputs[threadId * 2 + 0] = b;" 
    "    outputs[threadId * 2 + 1] = c;" 
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
    int* outputs = new int[DATA_SIZE * 2];
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

    input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * DATA_SIZE * 1, NULL, &err);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE * 2, NULL, &err);

    int* nums = new int[DATA_SIZE * 1];
    memset(nums, 0, 1 * DATA_SIZE * sizeof(int));

    clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 1, nums, 0, NULL, NULL);
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    clFinish(command_queue);

    size_t global = DATA_SIZE;

    auto start = chrono::steady_clock::now();
    clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    clFinish(command_queue);
    auto end = chrono::steady_clock::now();

    clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 2, outputs, 0, NULL, NULL);
    if (!onlyTimeOutput)
           printf("b: %i, c: %i", outputs[0], outputs[1]);
       

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
