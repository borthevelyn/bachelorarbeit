#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(bool m_0_1, bool* _bf4, bool* _bf17) { " 
    "    bool _bf15 = m_0_1;" 
    "    *_bf17 = m_0_1;" 
    "    bool _bf0 = _bf15;" 
    "    bool _bf1 = _bf0;" 
    "    bool _bf2 = _bf1;" 
    "    bool _bf3 = _bf2;" 
    "    *_bf4 = _bf3;" 
    "}" 
    "void path1(bool m_1_0, bool* _bf48, bool* _bf22) { " 
    "    bool _bf21 = m_1_0;" 
    "    *_bf22 = m_1_0;" 
    "    bool _bf19 = _bf21;" 
    "    bool _bf25 = _bf19;" 
    "    bool _bf27 = _bf25;" 
    "    bool _bf36 = _bf27;" 
    "    bool _bf42 = _bf36;" 
    "    *_bf48 = _bf42;" 
    "}" 
    "void path2(bool _bf48, bool _bf4, bool _bf22, bool _bf17, bool m_0_0, bool* _bf78, bool* _bf72, bool* t_0_0, bool* _bf45, bool* _bf38, bool* _bf28, bool* _bf29) { " 
    "    bool _bf8 = m_0_0;" 
    "    bool _bf11 = m_0_0;" 
    "    bool _bf9 = _bf11;" 
    "    bool _bf10 = _bf11;" 
    "    bool _bf5 = _bf17;" 
    "    bool _bf55 = _bf22;" 
    "    bool _bf83 = _bf8;" 
    "    bool _bf12 = _bf9 && _bf10;" 
    "    bool _bf6 = _bf5;" 
    "    bool _bf56 = _bf55;" 
    "    bool _bf84 = _bf83;" 
    "    bool _bf14 = _bf84 || _bf12;" 
    "    bool _bf7 = _bf6;" 
    "    bool _bf57 = _bf56;" 
    "    bool _bf16 = _bf14;" 
    "    bool _bf74 = _bf14;" 
    "    bool _bf13 = _bf7;" 
    "    bool _bf58 = _bf57;" 
    "    bool _bf23 = _bf74;" 
    "    bool _bf32 = _bf74;" 
    "    bool _bf18 = _bf16 && _bf13;" 
    "    bool _bf59 = _bf58;" 
    "    bool _bf61 = _bf32;" 
    "    bool _bf20 = _bf4 || _bf18;" 
    "    bool _bf24 = _bf59 && _bf23;" 
    "    bool _bf62 = _bf61;" 
    "    *_bf29 = _bf20;" 
    "    bool _bf70 = _bf20;" 
    "    bool _bf26 = _bf48 || _bf24;" 
    "    bool _bf63 = _bf62;" 
    "    bool _bf33 = _bf70;" 
    "    bool _bf41 = _bf70;" 
    "    *_bf28 = _bf26;" 
    "    bool _bf71 = _bf26;" 
    "    bool _bf64 = _bf63;" 
    "    bool _bf37 = _bf41;" 
    "    *_bf38 = _bf41;" 
    "    bool _bf67 = _bf33;" 
    "    bool _bf34 = _bf71;" 
    "    bool _bf47 = _bf71;" 
    "    bool _bf65 = _bf64;" 
    "    bool _bf68 = _bf37;" 
    "    bool _bf35 = _bf67 && _bf34;" 
    "    bool _bf43 = _bf47;" 
    "    *_bf45 = _bf47;" 
    "    *t_0_0 = _bf65 || _bf35;" 
    "    bool _bf69 = _bf68;" 
    "    bool _bf76 = _bf43;" 
    "    *_bf72 = _bf69;" 
    "    bool _bf77 = _bf76;" 
    "    *_bf78 = _bf77;" 
    "}" 
    "void path3(bool m_1_1, bool _bf28, bool _bf29, bool* t_1_1, bool* _bf44, bool* _bf39) { " 
    "    bool _bf60 = _bf29;" 
    "    bool _bf30 = _bf28 && _bf60;" 
    "    bool _bf31 = m_1_1 || _bf30;" 
    "    *_bf39 = _bf31;" 
    "    bool _bf66 = _bf31;" 
    "    *_bf44 = _bf66;" 
    "    bool _bf54 = _bf66;" 
    "    bool _bf49 = _bf54;" 
    "    bool _bf52 = _bf54;" 
    "    bool _bf50 = _bf52;" 
    "    bool _bf51 = _bf52;" 
    "    bool _bf81 = _bf49;" 
    "    bool _bf53 = _bf50 && _bf51;" 
    "    bool _bf82 = _bf81;" 
    "    *t_1_1 = _bf82 || _bf53;" 
    "}" 
    "void path4(bool _bf72, bool _bf39, bool _bf38, bool* t_0_1) { " 
    "    bool _bf73 = _bf38;" 
    "    bool _bf75 = _bf73;" 
    "    bool _bf40 = _bf75 && _bf39;" 
    "    *t_0_1 = _bf72 || _bf40;" 
    "}" 
    "void path5(bool _bf78, bool _bf44, bool _bf45, bool* t_1_0) { " 
    "    bool _bf79 = _bf45;" 
    "    bool _bf80 = _bf79;" 
    "    bool _bf46 = _bf44 && _bf80;" 
    "    *t_1_0 = _bf78 || _bf46;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    bool m_0_0 = inputs[threadId * 4 + 0];" 
    "    bool m_0_1 = inputs[threadId * 4 + 1];" 
    "    bool m_1_0 = inputs[threadId * 4 + 2];" 
    "    bool m_1_1 = inputs[threadId * 4 + 3];" 
    "" 
    "    bool _bf4;" 
    "    bool _bf17;" 
    "    path0(m_0_1, &_bf4, &_bf17);" 
    "" 
    "    bool _bf48;" 
    "    bool _bf22;" 
    "    path1(m_1_0, &_bf48, &_bf22);" 
    "" 
    "    bool _bf78;" 
    "    bool _bf72;" 
    "    bool t_0_0;" 
    "    bool _bf45;" 
    "    bool _bf38;" 
    "    bool _bf28;" 
    "    bool _bf29;" 
    "    path2(_bf48, _bf4, _bf22, _bf17, m_0_0, &_bf78, &_bf72, &t_0_0, &_bf45, &_bf38, &_bf28, &_bf29);" 
    "" 
    "    bool t_1_1;" 
    "    bool _bf44;" 
    "    bool _bf39;" 
    "    path3(m_1_1, _bf28, _bf29, &t_1_1, &_bf44, &_bf39);" 
    "" 
    "    bool t_0_1;" 
    "    path4(_bf72, _bf39, _bf38, &t_0_1);" 
    "" 
    "    bool t_1_0;" 
    "    path5(_bf78, _bf44, _bf45, &t_1_0);" 
    "" 
    "    outputs[threadId * 4 + 0] = t_0_0;" 
    "    outputs[threadId * 4 + 1] = t_0_1;" 
    "    outputs[threadId * 4 + 2] = t_1_0;" 
    "    outputs[threadId * 4 + 3] = t_1_1;" 
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
    int* outputs = new int[DATA_SIZE * 4];
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

    input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * DATA_SIZE * 4, NULL, &err);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE * 4, NULL, &err);

    int* nums = new int[DATA_SIZE * 4];
    memset(nums, 0, 4 * DATA_SIZE * sizeof(int));

    clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 4, nums, 0, NULL, NULL);
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    clFinish(command_queue);

    size_t global = DATA_SIZE;

    auto start = chrono::steady_clock::now();
    clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    clFinish(command_queue);
    auto end = chrono::steady_clock::now();

    clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 4, outputs, 0, NULL, NULL);
    if (!onlyTimeOutput)
           printf("t_0_0: %i, t_0_1: %i, t_1_0: %i, t_1_1: %i", outputs[0], outputs[1], outputs[2], outputs[3]);
       

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
