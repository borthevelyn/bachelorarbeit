#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(int* _bf104) { " 
    "    *_bf104 = 0;" 
    "}" 
    "void path1(int* _bf109) { " 
    "    *_bf109 = 1;" 
    "}" 
    "void path2(int* _bf114) { " 
    "    *_bf114 = 2;" 
    "}" 
    "void path3(int* _bf119) { " 
    "    *_bf119 = 3;" 
    "}" 
    "void path4(int* _bf0, int* _bf5, int* _bf93, int* _bf52, int* _bf48, int* _bf82, int* _bf39, int* _bf134, int* _bf50, int* _bf70, int** b, int** a) { " 
    "    int _bf24 = 2;" 
    "    int _bf4 = 1;" 
    "    int _bf12 = 2;" 
    "    int _bf28 = 1;" 
    "    int _bf27 = (*b)[_bf24];" 
    "    int* _bf26 = (*b);" 
    "    int _bf7 = (*a)[_bf4];" 
    "    int* _bf6 = (*a);" 
    "    int _bf15 = _bf6[_bf12];" 
    "    *a = _bf6;" 
    "    int _bf31 = _bf26[_bf28];" 
    "    *b = _bf26;" 
    "    int _bf32 = _bf27;" 
    "    int _bf41 = _bf27;" 
    "    int _bf34 = _bf7;" 
    "    int _bf43 = _bf7;" 
    "    *_bf70 = _bf15;" 
    "    int _bf79 = _bf15;" 
    "    *_bf50 = _bf31;" 
    "    int _bf59 = _bf31;" 
    "    int _bf47 = _bf41;" 
    "    *_bf134 = _bf41;" 
    "    *_bf39 = _bf34 * _bf32;" 
    "    int _bf46 = _bf43;" 
    "    int _bf139 = _bf43;" 
    "    *_bf82 = _bf79;" 
    "    int _bf127 = _bf79;" 
    "    int _bf65 = _bf59;" 
    "    int _bf128 = _bf59;" 
    "    *_bf48 = _bf46 * _bf47;" 
    "    *_bf52 = _bf139;" 
    "    int _bf61 = _bf139;" 
    "    int _bf88 = _bf127;" 
    "    int _bf97 = _bf127;" 
    "    int _bf86 = _bf128;" 
    "    int _bf95 = _bf128;" 
    "    int _bf66 = _bf61 * _bf65;" 
    "    int _bf102 = _bf97 * _bf95;" 
    "    *_bf93 = _bf88 * _bf86;" 
    "    *_bf5 = _bf66;" 
    "    *_bf0 = _bf102;" 
    "}" 
    "void path5(int* c, int _bf104, int _bf48, int _bf39, int** _bf2) { " 
    "    int _bf36 = 0;" 
    "    int _bf40 = _bf36 + _bf39;" 
    "    int _bf49 = _bf40 + _bf48;" 
    "    c[_bf104] = _bf49;" 
    "    int* _bf108 = c;" 
    "    *_bf2 = _bf108;" 
    "}" 
    "void path6(int _bf10, int _bf114, int* _bf2, int _bf109, int _bf5, int _bf57, int** _bf118) { " 
    "    int _bf54 = 0;" 
    "    int _bf58 = _bf54 + _bf57;" 
    "    int _bf67 = _bf58 + _bf5;" 
    "    _bf2[_bf109] = _bf67;" 
    "    int* _bf113 = _bf2;" 
    "    _bf113[_bf114] = _bf10;" 
    "    *_bf118 = _bf113;" 
    "}" 
    "void path7(int _bf9, int _bf75, int* _bf10) { " 
    "    int _bf72 = 0;" 
    "    int _bf76 = _bf72 + _bf75;" 
    "    int _bf85 = _bf76 + _bf9;" 
    "    *_bf10 = _bf85;" 
    "}" 
    "void path8(int* _bf118, int _bf119, int _bf0, int _bf93, int** c) { " 
    "    int _bf90 = 0;" 
    "    int _bf94 = _bf90 + _bf93;" 
    "    int _bf103 = _bf94 + _bf0;" 
    "    int _bf1 = _bf103;" 
    "    _bf118[_bf119] = _bf1;" 
    "    *c = _bf118;" 
    "}" 
    "void path9(int _bf82, int _bf134, int* _bf9, int* _bf68) { " 
    "    *_bf68 = _bf134;" 
    "    int _bf77 = _bf134;" 
    "    int _bf84 = _bf82 * _bf77;" 
    "    *_bf9 = _bf84;" 
    "}" 
    "void path10(int _bf52, int _bf50, int* _bf57) { " 
    "    int _bf3 = _bf50;" 
    "    *_bf57 = _bf52 * _bf3;" 
    "}" 
    "void path11(int _bf68, int _bf70, int* _bf75) { " 
    "    int _bf8 = _bf70;" 
    "    *_bf75 = _bf8 * _bf68;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    int* a = inputs + threadId * 12 + 0;" 
    "    int* b = inputs + threadId * 12 + 4;" 
    "    int* c = inputs + threadId * 12 + 8;" 
    "" 
    "    int _bf104;" 
    "    path0(&_bf104);" 
    "" 
    "    int _bf109;" 
    "    path1(&_bf109);" 
    "" 
    "    int _bf114;" 
    "    path2(&_bf114);" 
    "" 
    "    int _bf119;" 
    "    path3(&_bf119);" 
    "" 
    "    int _bf0;" 
    "    int _bf5;" 
    "    int _bf93;" 
    "    int _bf52;" 
    "    int _bf48;" 
    "    int _bf82;" 
    "    int _bf39;" 
    "    int _bf134;" 
    "    int _bf50;" 
    "    int _bf70;" 
    "    path4(&_bf0, &_bf5, &_bf93, &_bf52, &_bf48, &_bf82, &_bf39, &_bf134, &_bf50, &_bf70, &b, &a);" 
    "" 
    "    int* _bf2;" 
    "    path5(c, _bf104, _bf48, _bf39, &_bf2);" 
    "" 
    "    int _bf9;" 
    "    int _bf68;" 
    "    path9(_bf82, _bf134, &_bf9, &_bf68);" 
    "" 
    "    int _bf57;" 
    "    path10(_bf52, _bf50, &_bf57);" 
    "" 
    "    int _bf75;" 
    "    path11(_bf68, _bf70, &_bf75);" 
    "" 
    "    int _bf10;" 
    "    path7(_bf9, _bf75, &_bf10);" 
    "" 
    "    int* _bf118;" 
    "    path6(_bf10, _bf114, _bf2, _bf109, _bf5, _bf57, &_bf118);" 
    "" 
    "    path8(_bf118, _bf119, _bf0, _bf93, &c);" 
    "" 
    "    outputs[threadId * 12 + 0] = a[0];" 
    "    outputs[threadId * 12 + 1] = a[1];" 
    "    outputs[threadId * 12 + 2] = a[2];" 
    "    outputs[threadId * 12 + 3] = a[3];" 
    "    outputs[threadId * 12 + 4] = b[0];" 
    "    outputs[threadId * 12 + 5] = b[1];" 
    "    outputs[threadId * 12 + 6] = b[2];" 
    "    outputs[threadId * 12 + 7] = b[3];" 
    "    outputs[threadId * 12 + 8] = c[0];" 
    "    outputs[threadId * 12 + 9] = c[1];" 
    "    outputs[threadId * 12 + 10] = c[2];" 
    "    outputs[threadId * 12 + 11] = c[3];" 
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
    int* outputs = new int[DATA_SIZE * 12];
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

    input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * DATA_SIZE * 12, NULL, &err);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE * 12, NULL, &err);

    int* nums = new int[DATA_SIZE * 12];
    memset(nums, 0, 12 * DATA_SIZE * sizeof(int));

    clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 12, nums, 0, NULL, NULL);
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    clFinish(command_queue);

    size_t global = DATA_SIZE;

    auto start = chrono::steady_clock::now();
    clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    clFinish(command_queue);
    auto end = chrono::steady_clock::now();

    clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 12, outputs, 0, NULL, NULL);
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
