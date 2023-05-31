#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(int _bf23, int* _bf54, int* b_1_0, int* _bf38, int* _bf15, int* b_0_0, int* _bf0) { " 
    "    *_bf0 = *b_1_0;" 
    "    int _bf9 = *b_1_0;" 
    "    int _bf96 = _bf9;" 
    "    *b_0_0 = _bf9;" 
    "    *_bf15 = _bf96;" 
    "    int _bf90 = _bf96;" 
    "    *_bf38 = _bf90;" 
    "    int _bf47 = _bf90;" 
    "    int _bf53 = _bf47;" 
    "    *b_1_0 = _bf47;" 
    "    *_bf54 = _bf23 * _bf53;" 
    "}" 
    "void path1(int _bf10, int _bf11, int* _bf35, int* a_0_1, int* _bf21, int* a_0_0, int* _bf14) { " 
    "    *_bf14 = _bf11;" 
    "    int _bf18 = _bf11;" 
    "    int _bf93 = _bf18;" 
    "    *a_0_0 = _bf18;" 
    "    *_bf21 = _bf93;" 
    "    int _bf30 = _bf93;" 
    "    int _bf33 = _bf30;" 
    "    *a_0_1 = _bf30;" 
    "    *_bf35 = _bf33 * _bf10;" 
    "}" 
    "void path2(int* b_1_1, int* _bf72, int* _bf57, int* _bf34, int* b_0_1, int* _bf19) { " 
    "    *_bf19 = *b_1_1;" 
    "    int _bf28 = *b_1_1;" 
    "    int _bf91 = _bf28;" 
    "    *b_0_1 = _bf28;" 
    "    *_bf34 = _bf91;" 
    "    int _bf86 = _bf91;" 
    "    *_bf57 = _bf86;" 
    "    int _bf66 = _bf86;" 
    "    *_bf72 = _bf66;" 
    "    *b_1_1 = _bf66;" 
    "}" 
    "void path3(int c_0_0, int _bf0, int a_0_1, int* _bf24, int* _bf11) { " 
    "    int _bf2 = a_0_1;" 
    "    *_bf11 = a_0_1;" 
    "    int _bf7 = _bf2 * _bf0;" 
    "    int _bf8 = c_0_0 + _bf7;" 
    "    *_bf24 = _bf8;" 
    "}" 
    "void path4(int _bf72, int _bf57, int* c_1_1, int* a_1_1, int* a_1_0, int* _bf52, int* _bf40) { " 
    "    *_bf40 = *a_1_1;" 
    "    int _bf49 = *a_1_1;" 
    "    *_bf52 = _bf49;" 
    "    int _bf56 = _bf49;" 
    "    int _bf85 = _bf56;" 
    "    *a_1_0 = _bf56;" 
    "    int _bf59 = _bf85;" 
    "    int _bf68 = _bf85;" 
    "    int _bf64 = _bf59 * _bf57;" 
    "    int _bf71 = _bf68;" 
    "    *a_1_1 = _bf68;" 
    "    int _bf65 = *c_1_1 + _bf64;" 
    "    int _bf73 = _bf71 * _bf72;" 
    "    *c_1_1 = _bf65 + _bf73;" 
    "}" 
    "void path5(int _bf24, int _bf15, int _bf14, int* c_0_0) { " 
    "    int _bf1 = _bf14;" 
    "    int _bf16 = _bf1 * _bf15;" 
    "    *c_0_0 = _bf24 + _bf16;" 
    "}" 
    "void path6(int _bf35, int _bf21, int _bf19, int* c_0_1) { " 
    "    int _bf3 = _bf19;" 
    "    int _bf4 = _bf3;" 
    "    int _bf5 = _bf4;" 
    "    int _bf26 = _bf21 * _bf5;" 
    "    int _bf27 = *c_0_1 + _bf26;" 
    "    *c_0_1 = _bf27 + _bf35;" 
    "}" 
    "void path7(int _bf34, int* _bf10) { " 
    "    int _bf6 = _bf34;" 
    "    *_bf10 = _bf6;" 
    "}" 
    "void path8(int _bf54, int _bf38, int _bf40, int* c_1_0) { " 
    "    int _bf12 = _bf40;" 
    "    int _bf13 = _bf12;" 
    "    int _bf17 = _bf13;" 
    "    int _bf45 = _bf17 * _bf38;" 
    "    int _bf46 = *c_1_0 + _bf45;" 
    "    *c_1_0 = _bf46 + _bf54;" 
    "}" 
    "void path9(int _bf52, int* _bf23) { " 
    "    int _bf20 = _bf52;" 
    "    int _bf22 = _bf20;" 
    "    *_bf23 = _bf22;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    int a_0_1 = inputs[threadId * 8 + 0];" 
    "    int a_1_1 = inputs[threadId * 8 + 1];" 
    "    int b_1_0 = inputs[threadId * 8 + 2];" 
    "    int b_1_1 = inputs[threadId * 8 + 3];" 
    "    int c_0_0 = inputs[threadId * 8 + 4];" 
    "    int c_0_1 = inputs[threadId * 8 + 5];" 
    "    int c_1_0 = inputs[threadId * 8 + 6];" 
    "    int c_1_1 = inputs[threadId * 8 + 7];" 
    "" 
    "    int _bf72;" 
    "    int _bf57;" 
    "    int _bf34;" 
    "    int b_0_1;" 
    "    int _bf19;" 
    "    path2(&b_1_1, &_bf72, &_bf57, &_bf34, &b_0_1, &_bf19);" 
    "" 
    "    int a_1_0;" 
    "    int _bf52;" 
    "    int _bf40;" 
    "    path4(_bf72, _bf57, &c_1_1, &a_1_1, &a_1_0, &_bf52, &_bf40);" 
    "" 
    "    int _bf10;" 
    "    path7(_bf34, &_bf10);" 
    "" 
    "    int _bf23;" 
    "    path9(_bf52, &_bf23);" 
    "" 
    "    int _bf54;" 
    "    int _bf38;" 
    "    int _bf15;" 
    "    int b_0_0;" 
    "    int _bf0;" 
    "    path0(_bf23, &_bf54, &b_1_0, &_bf38, &_bf15, &b_0_0, &_bf0);" 
    "" 
    "    int _bf24;" 
    "    int _bf11;" 
    "    path3(c_0_0, _bf0, a_0_1, &_bf24, &_bf11);" 
    "" 
    "    path8(_bf54, _bf38, _bf40, &c_1_0);" 
    "" 
    "    int _bf35;" 
    "    int _bf21;" 
    "    int a_0_0;" 
    "    int _bf14;" 
    "    path1(_bf10, _bf11, &_bf35, &a_0_1, &_bf21, &a_0_0, &_bf14);" 
    "" 
    "    path5(_bf24, _bf15, _bf14, &c_0_0);" 
    "" 
    "    path6(_bf35, _bf21, _bf19, &c_0_1);" 
    "" 
    "    outputs[threadId * 12 + 0] = a_0_0;" 
    "    outputs[threadId * 12 + 1] = a_0_1;" 
    "    outputs[threadId * 12 + 2] = a_1_0;" 
    "    outputs[threadId * 12 + 3] = a_1_1;" 
    "    outputs[threadId * 12 + 4] = b_0_0;" 
    "    outputs[threadId * 12 + 5] = b_0_1;" 
    "    outputs[threadId * 12 + 6] = b_1_0;" 
    "    outputs[threadId * 12 + 7] = b_1_1;" 
    "    outputs[threadId * 12 + 8] = c_0_0;" 
    "    outputs[threadId * 12 + 9] = c_0_1;" 
    "    outputs[threadId * 12 + 10] = c_1_0;" 
    "    outputs[threadId * 12 + 11] = c_1_1;" 
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

    input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * DATA_SIZE * 8, NULL, &err);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE * 12, NULL, &err);

    int* nums = new int[DATA_SIZE * 8];
    memset(nums, 0, 8 * DATA_SIZE * sizeof(int));

    clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 8, nums, 0, NULL, NULL);
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    clFinish(command_queue);

    size_t global = DATA_SIZE;

    auto start = chrono::steady_clock::now();
    clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    clFinish(command_queue);
    auto end = chrono::steady_clock::now();

    clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 12, outputs, 0, NULL, NULL);
    if (!onlyTimeOutput)
           printf("a_0_0: %i, a_0_1: %i, a_1_0: %i, a_1_1: %i, b_0_0: %i, b_0_1: %i, b_1_0: %i, b_1_1: %i, c_0_0: %i, c_0_1: %i, c_1_0: %i, c_1_1: %i", outputs[0], outputs[1], outputs[2], outputs[3], outputs[4], outputs[5], outputs[6], outputs[7], outputs[8], outputs[9], outputs[10], outputs[11]);
       

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
