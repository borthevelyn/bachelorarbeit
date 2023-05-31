#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(bool _bf9, bool _bf10, bool* _bf12) { " 
    "    *_bf12 = _bf9 && _bf10;" 
    "}" 
    "void path1(bool _bf84, bool _bf12, bool* _bf14) { " 
    "    *_bf14 = _bf84 || _bf12;" 
    "}" 
    "void path2(bool _bf16, bool _bf13, bool* _bf18) { " 
    "    *_bf18 = _bf16 && _bf13;" 
    "}" 
    "void path3(bool _bf4, bool _bf18, bool* _bf20) { " 
    "    *_bf20 = _bf4 || _bf18;" 
    "}" 
    "void path4(bool _bf59, bool _bf23, bool* _bf24) { " 
    "    *_bf24 = _bf59 && _bf23;" 
    "}" 
    "void path5(bool _bf48, bool _bf24, bool* _bf26) { " 
    "    *_bf26 = _bf48 || _bf24;" 
    "}" 
    "void path6(bool _bf28, bool _bf60, bool* _bf30) { " 
    "    *_bf30 = _bf28 && _bf60;" 
    "}" 
    "void path7(bool m_1_1, bool _bf30, bool* _bf31) { " 
    "    *_bf31 = m_1_1 || _bf30;" 
    "}" 
    "void path8(bool _bf67, bool _bf34, bool* _bf35) { " 
    "    *_bf35 = _bf67 && _bf34;" 
    "}" 
    "void path9(bool _bf65, bool _bf35, bool* t_0_0) { " 
    "    *t_0_0 = _bf65 || _bf35;" 
    "}" 
    "void path10(bool _bf75, bool _bf39, bool* _bf40) { " 
    "    *_bf40 = _bf75 && _bf39;" 
    "}" 
    "void path11(bool _bf72, bool _bf40, bool* t_0_1) { " 
    "    *t_0_1 = _bf72 || _bf40;" 
    "}" 
    "void path12(bool _bf44, bool _bf80, bool* _bf46) { " 
    "    *_bf46 = _bf44 && _bf80;" 
    "}" 
    "void path13(bool _bf78, bool _bf46, bool* t_1_0) { " 
    "    *t_1_0 = _bf78 || _bf46;" 
    "}" 
    "void path14(bool _bf50, bool _bf51, bool* _bf53) { " 
    "    *_bf53 = _bf50 && _bf51;" 
    "}" 
    "void path15(bool _bf82, bool _bf53, bool* t_1_1) { " 
    "    *t_1_1 = _bf82 || _bf53;" 
    "}" 
    "void path16(bool m_0_1, bool* _bf15, bool* _bf17) { " 
    "    *_bf15 = m_0_1;" 
    "    *_bf17 = m_0_1;" 
    "}" 
    "void path17(bool _bf14, bool* _bf16, bool* _bf74) { " 
    "    *_bf16 = _bf14;" 
    "    *_bf74 = _bf14;" 
    "}" 
    "void path18(bool m_1_0, bool* _bf21, bool* _bf22) { " 
    "    *_bf21 = m_1_0;" 
    "    *_bf22 = m_1_0;" 
    "}" 
    "void path19(bool _bf74, bool* _bf23, bool* _bf32) { " 
    "    *_bf23 = _bf74;" 
    "    *_bf32 = _bf74;" 
    "}" 
    "void path20(bool _bf26, bool* _bf28, bool* _bf71) { " 
    "    *_bf28 = _bf26;" 
    "    *_bf71 = _bf26;" 
    "}" 
    "void path21(bool _bf20, bool* _bf29, bool* _bf70) { " 
    "    *_bf29 = _bf20;" 
    "    *_bf70 = _bf20;" 
    "}" 
    "void path22(bool _bf70, bool* _bf33, bool* _bf41) { " 
    "    *_bf33 = _bf70;" 
    "    *_bf41 = _bf70;" 
    "}" 
    "void path23(bool _bf71, bool* _bf34, bool* _bf47) { " 
    "    *_bf34 = _bf71;" 
    "    *_bf47 = _bf71;" 
    "}" 
    "void path24(bool _bf41, bool* _bf37, bool* _bf38) { " 
    "    *_bf37 = _bf41;" 
    "    *_bf38 = _bf41;" 
    "}" 
    "void path25(bool _bf31, bool* _bf39, bool* _bf66) { " 
    "    *_bf39 = _bf31;" 
    "    *_bf66 = _bf31;" 
    "}" 
    "void path26(bool _bf47, bool* _bf43, bool* _bf45) { " 
    "    *_bf43 = _bf47;" 
    "    *_bf45 = _bf47;" 
    "}" 
    "void path27(bool _bf66, bool* _bf44, bool* _bf54) { " 
    "    *_bf44 = _bf66;" 
    "    *_bf54 = _bf66;" 
    "}" 
    "void path28(bool _bf54, bool* _bf49, bool* _bf52) { " 
    "    *_bf49 = _bf54;" 
    "    *_bf52 = _bf54;" 
    "}" 
    "void path29(bool _bf52, bool* _bf50, bool* _bf51) { " 
    "    *_bf50 = _bf52;" 
    "    *_bf51 = _bf52;" 
    "}" 
    "void path30(bool m_0_0, bool* _bf8, bool* _bf11) { " 
    "    *_bf8 = m_0_0;" 
    "    *_bf11 = m_0_0;" 
    "}" 
    "void path31(bool _bf11, bool* _bf9, bool* _bf10) { " 
    "    *_bf9 = _bf11;" 
    "    *_bf10 = _bf11;" 
    "}" 
    "void path32(bool _bf15, bool* _bf0) { " 
    "    *_bf0 = _bf15;" 
    "}" 
    "void path33(bool _bf0, bool* _bf1) { " 
    "    *_bf1 = _bf0;" 
    "}" 
    "void path34(bool _bf1, bool* _bf2) { " 
    "    *_bf2 = _bf1;" 
    "}" 
    "void path35(bool _bf2, bool* _bf3) { " 
    "    *_bf3 = _bf2;" 
    "}" 
    "void path36(bool _bf3, bool* _bf4) { " 
    "    *_bf4 = _bf3;" 
    "}" 
    "void path37(bool _bf17, bool* _bf5) { " 
    "    *_bf5 = _bf17;" 
    "}" 
    "void path38(bool _bf5, bool* _bf6) { " 
    "    *_bf6 = _bf5;" 
    "}" 
    "void path39(bool _bf6, bool* _bf7) { " 
    "    *_bf7 = _bf6;" 
    "}" 
    "void path40(bool _bf7, bool* _bf13) { " 
    "    *_bf13 = _bf7;" 
    "}" 
    "void path41(bool _bf21, bool* _bf19) { " 
    "    *_bf19 = _bf21;" 
    "}" 
    "void path42(bool _bf19, bool* _bf25) { " 
    "    *_bf25 = _bf19;" 
    "}" 
    "void path43(bool _bf25, bool* _bf27) { " 
    "    *_bf27 = _bf25;" 
    "}" 
    "void path44(bool _bf27, bool* _bf36) { " 
    "    *_bf36 = _bf27;" 
    "}" 
    "void path45(bool _bf36, bool* _bf42) { " 
    "    *_bf42 = _bf36;" 
    "}" 
    "void path46(bool _bf42, bool* _bf48) { " 
    "    *_bf48 = _bf42;" 
    "}" 
    "void path47(bool _bf22, bool* _bf55) { " 
    "    *_bf55 = _bf22;" 
    "}" 
    "void path48(bool _bf55, bool* _bf56) { " 
    "    *_bf56 = _bf55;" 
    "}" 
    "void path49(bool _bf56, bool* _bf57) { " 
    "    *_bf57 = _bf56;" 
    "}" 
    "void path50(bool _bf57, bool* _bf58) { " 
    "    *_bf58 = _bf57;" 
    "}" 
    "void path51(bool _bf58, bool* _bf59) { " 
    "    *_bf59 = _bf58;" 
    "}" 
    "void path52(bool _bf29, bool* _bf60) { " 
    "    *_bf60 = _bf29;" 
    "}" 
    "void path53(bool _bf32, bool* _bf61) { " 
    "    *_bf61 = _bf32;" 
    "}" 
    "void path54(bool _bf61, bool* _bf62) { " 
    "    *_bf62 = _bf61;" 
    "}" 
    "void path55(bool _bf62, bool* _bf63) { " 
    "    *_bf63 = _bf62;" 
    "}" 
    "void path56(bool _bf63, bool* _bf64) { " 
    "    *_bf64 = _bf63;" 
    "}" 
    "void path57(bool _bf64, bool* _bf65) { " 
    "    *_bf65 = _bf64;" 
    "}" 
    "void path58(bool _bf33, bool* _bf67) { " 
    "    *_bf67 = _bf33;" 
    "}" 
    "void path59(bool _bf37, bool* _bf68) { " 
    "    *_bf68 = _bf37;" 
    "}" 
    "void path60(bool _bf68, bool* _bf69) { " 
    "    *_bf69 = _bf68;" 
    "}" 
    "void path61(bool _bf69, bool* _bf72) { " 
    "    *_bf72 = _bf69;" 
    "}" 
    "void path62(bool _bf38, bool* _bf73) { " 
    "    *_bf73 = _bf38;" 
    "}" 
    "void path63(bool _bf73, bool* _bf75) { " 
    "    *_bf75 = _bf73;" 
    "}" 
    "void path64(bool _bf43, bool* _bf76) { " 
    "    *_bf76 = _bf43;" 
    "}" 
    "void path65(bool _bf76, bool* _bf77) { " 
    "    *_bf77 = _bf76;" 
    "}" 
    "void path66(bool _bf77, bool* _bf78) { " 
    "    *_bf78 = _bf77;" 
    "}" 
    "void path67(bool _bf45, bool* _bf79) { " 
    "    *_bf79 = _bf45;" 
    "}" 
    "void path68(bool _bf79, bool* _bf80) { " 
    "    *_bf80 = _bf79;" 
    "}" 
    "void path69(bool _bf49, bool* _bf81) { " 
    "    *_bf81 = _bf49;" 
    "}" 
    "void path70(bool _bf81, bool* _bf82) { " 
    "    *_bf82 = _bf81;" 
    "}" 
    "void path71(bool _bf8, bool* _bf83) { " 
    "    *_bf83 = _bf8;" 
    "}" 
    "void path72(bool _bf83, bool* _bf84) { " 
    "    *_bf84 = _bf83;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    bool m_0_0 = inputs[threadId * 4 + 0];" 
    "    bool m_0_1 = inputs[threadId * 4 + 1];" 
    "    bool m_1_0 = inputs[threadId * 4 + 2];" 
    "    bool m_1_1 = inputs[threadId * 4 + 3];" 
    "" 
    "    bool _bf15;" 
    "    bool _bf17;" 
    "    path16(m_0_1, &_bf15, &_bf17);" 
    "" 
    "    bool _bf21;" 
    "    bool _bf22;" 
    "    path18(m_1_0, &_bf21, &_bf22);" 
    "" 
    "    bool _bf8;" 
    "    bool _bf11;" 
    "    path30(m_0_0, &_bf8, &_bf11);" 
    "" 
    "    bool _bf9;" 
    "    bool _bf10;" 
    "    path31(_bf11, &_bf9, &_bf10);" 
    "" 
    "    bool _bf0;" 
    "    path32(_bf15, &_bf0);" 
    "" 
    "    bool _bf5;" 
    "    path37(_bf17, &_bf5);" 
    "" 
    "    bool _bf19;" 
    "    path41(_bf21, &_bf19);" 
    "" 
    "    bool _bf55;" 
    "    path47(_bf22, &_bf55);" 
    "" 
    "    bool _bf83;" 
    "    path71(_bf8, &_bf83);" 
    "" 
    "    bool _bf12;" 
    "    path0(_bf9, _bf10, &_bf12);" 
    "" 
    "    bool _bf1;" 
    "    path33(_bf0, &_bf1);" 
    "" 
    "    bool _bf6;" 
    "    path38(_bf5, &_bf6);" 
    "" 
    "    bool _bf25;" 
    "    path42(_bf19, &_bf25);" 
    "" 
    "    bool _bf56;" 
    "    path48(_bf55, &_bf56);" 
    "" 
    "    bool _bf84;" 
    "    path72(_bf83, &_bf84);" 
    "" 
    "    bool _bf14;" 
    "    path1(_bf84, _bf12, &_bf14);" 
    "" 
    "    bool _bf2;" 
    "    path34(_bf1, &_bf2);" 
    "" 
    "    bool _bf7;" 
    "    path39(_bf6, &_bf7);" 
    "" 
    "    bool _bf27;" 
    "    path43(_bf25, &_bf27);" 
    "" 
    "    bool _bf57;" 
    "    path49(_bf56, &_bf57);" 
    "" 
    "    bool _bf16;" 
    "    bool _bf74;" 
    "    path17(_bf14, &_bf16, &_bf74);" 
    "" 
    "    bool _bf3;" 
    "    path35(_bf2, &_bf3);" 
    "" 
    "    bool _bf13;" 
    "    path40(_bf7, &_bf13);" 
    "" 
    "    bool _bf36;" 
    "    path44(_bf27, &_bf36);" 
    "" 
    "    bool _bf58;" 
    "    path50(_bf57, &_bf58);" 
    "" 
    "    bool _bf18;" 
    "    path2(_bf16, _bf13, &_bf18);" 
    "" 
    "    bool _bf23;" 
    "    bool _bf32;" 
    "    path19(_bf74, &_bf23, &_bf32);" 
    "" 
    "    bool _bf4;" 
    "    path36(_bf3, &_bf4);" 
    "" 
    "    bool _bf42;" 
    "    path45(_bf36, &_bf42);" 
    "" 
    "    bool _bf59;" 
    "    path51(_bf58, &_bf59);" 
    "" 
    "    bool _bf20;" 
    "    path3(_bf4, _bf18, &_bf20);" 
    "" 
    "    bool _bf24;" 
    "    path4(_bf59, _bf23, &_bf24);" 
    "" 
    "    bool _bf48;" 
    "    path46(_bf42, &_bf48);" 
    "" 
    "    bool _bf61;" 
    "    path53(_bf32, &_bf61);" 
    "" 
    "    bool _bf26;" 
    "    path5(_bf48, _bf24, &_bf26);" 
    "" 
    "    bool _bf29;" 
    "    bool _bf70;" 
    "    path21(_bf20, &_bf29, &_bf70);" 
    "" 
    "    bool _bf62;" 
    "    path54(_bf61, &_bf62);" 
    "" 
    "    bool _bf28;" 
    "    bool _bf71;" 
    "    path20(_bf26, &_bf28, &_bf71);" 
    "" 
    "    bool _bf33;" 
    "    bool _bf41;" 
    "    path22(_bf70, &_bf33, &_bf41);" 
    "" 
    "    bool _bf60;" 
    "    path52(_bf29, &_bf60);" 
    "" 
    "    bool _bf63;" 
    "    path55(_bf62, &_bf63);" 
    "" 
    "    bool _bf30;" 
    "    path6(_bf28, _bf60, &_bf30);" 
    "" 
    "    bool _bf34;" 
    "    bool _bf47;" 
    "    path23(_bf71, &_bf34, &_bf47);" 
    "" 
    "    bool _bf37;" 
    "    bool _bf38;" 
    "    path24(_bf41, &_bf37, &_bf38);" 
    "" 
    "    bool _bf64;" 
    "    path56(_bf63, &_bf64);" 
    "" 
    "    bool _bf67;" 
    "    path58(_bf33, &_bf67);" 
    "" 
    "    bool _bf31;" 
    "    path7(m_1_1, _bf30, &_bf31);" 
    "" 
    "    bool _bf35;" 
    "    path8(_bf67, _bf34, &_bf35);" 
    "" 
    "    bool _bf43;" 
    "    bool _bf45;" 
    "    path26(_bf47, &_bf43, &_bf45);" 
    "" 
    "    bool _bf65;" 
    "    path57(_bf64, &_bf65);" 
    "" 
    "    bool _bf68;" 
    "    path59(_bf37, &_bf68);" 
    "" 
    "    bool _bf73;" 
    "    path62(_bf38, &_bf73);" 
    "" 
    "    bool t_0_0;" 
    "    path9(_bf65, _bf35, &t_0_0);" 
    "" 
    "    bool _bf39;" 
    "    bool _bf66;" 
    "    path25(_bf31, &_bf39, &_bf66);" 
    "" 
    "    bool _bf69;" 
    "    path60(_bf68, &_bf69);" 
    "" 
    "    bool _bf75;" 
    "    path63(_bf73, &_bf75);" 
    "" 
    "    bool _bf76;" 
    "    path64(_bf43, &_bf76);" 
    "" 
    "    bool _bf79;" 
    "    path67(_bf45, &_bf79);" 
    "" 
    "    bool _bf40;" 
    "    path10(_bf75, _bf39, &_bf40);" 
    "" 
    "    bool _bf44;" 
    "    bool _bf54;" 
    "    path27(_bf66, &_bf44, &_bf54);" 
    "" 
    "    bool _bf72;" 
    "    path61(_bf69, &_bf72);" 
    "" 
    "    bool _bf77;" 
    "    path65(_bf76, &_bf77);" 
    "" 
    "    bool _bf80;" 
    "    path68(_bf79, &_bf80);" 
    "" 
    "    bool t_0_1;" 
    "    path11(_bf72, _bf40, &t_0_1);" 
    "" 
    "    bool _bf46;" 
    "    path12(_bf44, _bf80, &_bf46);" 
    "" 
    "    bool _bf49;" 
    "    bool _bf52;" 
    "    path28(_bf54, &_bf49, &_bf52);" 
    "" 
    "    bool _bf78;" 
    "    path66(_bf77, &_bf78);" 
    "" 
    "    bool t_1_0;" 
    "    path13(_bf78, _bf46, &t_1_0);" 
    "" 
    "    bool _bf50;" 
    "    bool _bf51;" 
    "    path29(_bf52, &_bf50, &_bf51);" 
    "" 
    "    bool _bf81;" 
    "    path69(_bf49, &_bf81);" 
    "" 
    "    bool _bf53;" 
    "    path14(_bf50, _bf51, &_bf53);" 
    "" 
    "    bool _bf82;" 
    "    path70(_bf81, &_bf82);" 
    "" 
    "    bool t_1_1;" 
    "    path15(_bf82, _bf53, &t_1_1);" 
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
