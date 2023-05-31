#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(int* b, int* a, int* _bf56, int* _bf38, int* _bf17, int* _bf39, int* _bf37, int** _bf26, int** _bf10, int* _bf44, int* _bf33, int* _bf32) { " 
    "    int _bf0 = 0;" 
    "    int _bf16 = 0;" 
    "    int _bf3 = a[_bf0];" 
    "    int* _bf2 = a;" 
    "    int _bf19 = b[_bf16];" 
    "    int* _bf18 = b;" 
    "    int _bf20 = 1;" 
    "    int _bf4 = 1;" 
    "    *_bf32 = _bf3;" 
    "    int _bf41 = _bf3;" 
    "    *_bf33 = _bf19;" 
    "    int _bf51 = _bf19;" 
    "    int _bf23 = _bf18[_bf20];" 
    "    int* _bf22 = _bf18;" 
    "    int _bf7 = _bf2[_bf4];" 
    "    int* _bf6 = _bf2;" 
    "    int _bf8 = 2;" 
    "    int _bf24 = 2;" 
    "    int _bf13 = _bf41;" 
    "    int _bf29 = _bf51;" 
    "    int _bf42 = _bf23;" 
    "    int _bf60 = _bf23;" 
    "    int _bf35 = _bf7;" 
    "    *_bf44 = _bf7;" 
    "    int _bf11 = _bf6[_bf8];" 
    "    *_bf10 = _bf6;" 
    "    int _bf27 = _bf22[_bf24];" 
    "    *_bf26 = _bf22;" 
    "    int _bf43 = _bf13 * _bf42;" 
    "    int _bf30 = _bf29;" 
    "    int _bf48 = _bf60;" 
    "    int _bf9 = _bf35;" 
    "    int _bf50 = _bf11;" 
    "    int _bf59 = _bf11;" 
    "    int _bf36 = _bf27;" 
    "    int _bf54 = _bf27;" 
    "    int _bf14 = _bf43;" 
    "    int _bf52 = _bf50 * _bf30;" 
    "    *_bf37 = _bf9 * _bf36;" 
    "    int _bf61 = _bf59 * _bf48;" 
    "    *_bf39 = _bf54;" 
    "    *_bf17 = _bf14;" 
    "    *_bf38 = _bf52;" 
    "    *_bf56 = _bf61;" 
    "}" 
    "void path1(int _bf38, int _bf39, int* _bf10, int* _bf47, int* _bf62, int** a) { " 
    "    int _bf12 = 3;" 
    "    int _bf15 = _bf10[_bf12];" 
    "    *a = _bf10;" 
    "    int _bf53 = _bf15;" 
    "    *_bf62 = _bf15;" 
    "    int _bf55 = _bf53 * _bf39;" 
    "    int _bf58 = _bf38 + _bf55;" 
    "    *_bf47 = _bf58;" 
    "}" 
    "void path2(int _bf56, int _bf62, int* _bf26, int* _bf65, int* _bf45, int** b) { " 
    "    int _bf28 = 3;" 
    "    int _bf31 = _bf26[_bf28];" 
    "    *b = _bf26;" 
    "    *_bf45 = _bf31;" 
    "    int _bf63 = _bf31;" 
    "    int _bf64 = _bf62 * _bf63;" 
    "    int _bf67 = _bf56 + _bf64;" 
    "    int _bf57 = _bf67;" 
    "    *_bf65 = _bf57;" 
    "}" 
    "void path3(int _bf37, int _bf33, int _bf32, int* _bf40) { " 
    "    int _bf34 = _bf32 * _bf33;" 
    "    int _bf1 = _bf34;" 
    "    int _bf5 = _bf1;" 
    "    *_bf40 = _bf5 + _bf37;" 
    "}" 
    "void path4(int _bf40, int* c, int** _bf72) { " 
    "    int _bf68 = 0;" 
    "    c[_bf68] = _bf40;" 
    "    *_bf72 = c;" 
    "}" 
    "void path5(int* _bf73) { " 
    "    *_bf73 = 1;" 
    "}" 
    "void path6(int* _bf78) { " 
    "    *_bf78 = 2;" 
    "}" 
    "void path7(int* _bf83) { " 
    "    *_bf83 = 3;" 
    "}" 
    "void path8(int _bf65, int _bf83, int _bf47, int _bf78, int* _bf72, int _bf73, int _bf17, int _bf45, int _bf44, int** c) { " 
    "    int _bf21 = _bf44;" 
    "    int _bf25 = _bf21;" 
    "    int _bf46 = _bf25 * _bf45;" 
    "    int _bf49 = _bf17 + _bf46;" 
    "    _bf72[_bf73] = _bf49;" 
    "    int* _bf77 = _bf72;" 
    "    _bf77[_bf78] = _bf47;" 
    "    int* _bf82 = _bf77;" 
    "    _bf82[_bf83] = _bf65;" 
    "    *c = _bf82;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    int* a = inputs + threadId * 12 + 0;" 
    "    int* b = inputs + threadId * 12 + 4;" 
    "    int* c = inputs + threadId * 12 + 8;" 
    "" 
    "    int _bf56;" 
    "    int _bf38;" 
    "    int _bf17;" 
    "    int _bf39;" 
    "    int _bf37;" 
    "    int* _bf26;" 
    "    int* _bf10;" 
    "    int _bf44;" 
    "    int _bf33;" 
    "    int _bf32;" 
    "    path0(b, a, &_bf56, &_bf38, &_bf17, &_bf39, &_bf37, &_bf26, &_bf10, &_bf44, &_bf33, &_bf32);" 
    "" 
    "    int _bf73;" 
    "    path5(&_bf73);" 
    "" 
    "    int _bf78;" 
    "    path6(&_bf78);" 
    "" 
    "    int _bf83;" 
    "    path7(&_bf83);" 
    "" 
    "    int _bf47;" 
    "    int _bf62;" 
    "    path1(_bf38, _bf39, _bf10, &_bf47, &_bf62, &a);" 
    "" 
    "    int _bf40;" 
    "    path3(_bf37, _bf33, _bf32, &_bf40);" 
    "" 
    "    int _bf65;" 
    "    int _bf45;" 
    "    path2(_bf56, _bf62, _bf26, &_bf65, &_bf45, &b);" 
    "" 
    "    int* _bf72;" 
    "    path4(_bf40, c, &_bf72);" 
    "" 
    "    path8(_bf65, _bf83, _bf47, _bf78, _bf72, _bf73, _bf17, _bf45, _bf44, &c);" 
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
