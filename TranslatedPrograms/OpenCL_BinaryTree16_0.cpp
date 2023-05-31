#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(int* _bf0) { " 
    "    *_bf0 = 0;" 
    "}" 
    "void path1(int _bf79, int _bf93, int* _bf102) { " 
    "    *_bf102 = _bf79 + _bf93;" 
    "}" 
    "void path2(int _bf85, int _bf99, int* _bf105) { " 
    "    *_bf105 = _bf85 + _bf99;" 
    "}" 
    "void path3(int _bf29, int _bf105, int* z) { " 
    "    *z = _bf29 + _bf105;" 
    "}" 
    "void path4(int* _bf12) { " 
    "    *_bf12 = 3;" 
    "}" 
    "void path5(int* _bf16) { " 
    "    *_bf16 = 4;" 
    "}" 
    "void path6(int* _bf20) { " 
    "    *_bf20 = 5;" 
    "}" 
    "void path7(int* _bf24) { " 
    "    *_bf24 = 6;" 
    "}" 
    "void path8(int* _bf28) { " 
    "    *_bf28 = 7;" 
    "}" 
    "void path9(int* _bf32) { " 
    "    *_bf32 = 8;" 
    "}" 
    "void path10(int* _bf36) { " 
    "    *_bf36 = 9;" 
    "}" 
    "void path11(int* _bf4) { " 
    "    *_bf4 = 1;" 
    "}" 
    "void path12(int* _bf40) { " 
    "    *_bf40 = 10;" 
    "}" 
    "void path13(int* _bf44) { " 
    "    *_bf44 = 11;" 
    "}" 
    "void path14(int* _bf48) { " 
    "    *_bf48 = 12;" 
    "}" 
    "void path15(int* _bf52) { " 
    "    *_bf52 = 13;" 
    "}" 
    "void path16(int* _bf56) { " 
    "    *_bf56 = 14;" 
    "}" 
    "void path17(int* _bf60) { " 
    "    *_bf60 = 15;" 
    "}" 
    "void path18(int _bf45, int _bf7, int* _bf66) { " 
    "    *_bf66 = _bf45 + _bf7;" 
    "}" 
    "void path19(int _bf33, int _bf15, int* _bf69) { " 
    "    *_bf69 = _bf33 + _bf15;" 
    "}" 
    "void path20(int _bf37, int _bf23, int* _bf72) { " 
    "    *_bf72 = _bf37 + _bf23;" 
    "}" 
    "void path21(int _bf41, int _bf31, int* _bf75) { " 
    "    *_bf75 = _bf41 + _bf31;" 
    "}" 
    "void path22(int _bf49, int _bf39, int* _bf78) { " 
    "    *_bf78 = _bf49 + _bf39;" 
    "}" 
    "void path23(int* _bf8) { " 
    "    *_bf8 = 2;" 
    "}" 
    "void path24(int _bf53, int _bf47, int* _bf81) { " 
    "    *_bf81 = _bf53 + _bf47;" 
    "}" 
    "void path25(int _bf57, int _bf55, int* _bf84) { " 
    "    *_bf84 = _bf57 + _bf55;" 
    "}" 
    "void path26(int _bf61, int _bf63, int* _bf87) { " 
    "    *_bf87 = _bf61 + _bf63;" 
    "}" 
    "void path27(int _bf64, int _bf69, int* _bf90) { " 
    "    *_bf90 = _bf64 + _bf69;" 
    "}" 
    "void path28(int _bf67, int _bf75, int* _bf93) { " 
    "    *_bf93 = _bf67 + _bf75;" 
    "}" 
    "void path29(int _bf70, int _bf81, int* _bf96) { " 
    "    *_bf96 = _bf70 + _bf81;" 
    "}" 
    "void path30(int _bf73, int _bf87, int* _bf99) { " 
    "    *_bf99 = _bf73 + _bf87;" 
    "}" 
    "void path31(int _bf8, int* _bf6, int** _bf10, int* _bf11) { " 
    "    *_bf11 = _bf6[_bf8];" 
    "    *_bf10 = _bf6;" 
    "}" 
    "void path32(int _bf12, int* _bf10, int** _bf14, int* _bf15) { " 
    "    *_bf15 = _bf10[_bf12];" 
    "    *_bf14 = _bf10;" 
    "}" 
    "void path33(int _bf16, int* _bf14, int** _bf18, int* _bf19) { " 
    "    *_bf19 = _bf14[_bf16];" 
    "    *_bf18 = _bf14;" 
    "}" 
    "void path34(int _bf0, int* x, int** _bf2, int* _bf3) { " 
    "    *_bf3 = x[_bf0];" 
    "    *_bf2 = x;" 
    "}" 
    "void path35(int _bf20, int* _bf18, int** _bf22, int* _bf23) { " 
    "    *_bf23 = _bf18[_bf20];" 
    "    *_bf22 = _bf18;" 
    "}" 
    "void path36(int _bf24, int* _bf22, int** _bf26, int* _bf27) { " 
    "    *_bf27 = _bf22[_bf24];" 
    "    *_bf26 = _bf22;" 
    "}" 
    "void path37(int _bf28, int* _bf26, int** _bf30, int* _bf31) { " 
    "    *_bf31 = _bf26[_bf28];" 
    "    *_bf30 = _bf26;" 
    "}" 
    "void path38(int _bf32, int* _bf30, int** _bf34, int* _bf35) { " 
    "    *_bf35 = _bf30[_bf32];" 
    "    *_bf34 = _bf30;" 
    "}" 
    "void path39(int _bf36, int* _bf34, int** _bf38, int* _bf39) { " 
    "    *_bf39 = _bf34[_bf36];" 
    "    *_bf38 = _bf34;" 
    "}" 
    "void path40(int _bf40, int* _bf38, int** _bf42, int* _bf43) { " 
    "    *_bf43 = _bf38[_bf40];" 
    "    *_bf42 = _bf38;" 
    "}" 
    "void path41(int _bf44, int* _bf42, int** _bf46, int* _bf47) { " 
    "    *_bf47 = _bf42[_bf44];" 
    "    *_bf46 = _bf42;" 
    "}" 
    "void path42(int _bf48, int* _bf46, int** _bf50, int* _bf51) { " 
    "    *_bf51 = _bf46[_bf48];" 
    "    *_bf50 = _bf46;" 
    "}" 
    "void path43(int _bf52, int* _bf50, int** _bf54, int* _bf55) { " 
    "    *_bf55 = _bf50[_bf52];" 
    "    *_bf54 = _bf50;" 
    "}" 
    "void path44(int _bf56, int* _bf54, int** _bf58, int* _bf59) { " 
    "    *_bf59 = _bf54[_bf56];" 
    "    *_bf58 = _bf54;" 
    "}" 
    "void path45(int _bf4, int* _bf2, int** _bf6, int* _bf7) { " 
    "    *_bf7 = _bf2[_bf4];" 
    "    *_bf6 = _bf2;" 
    "}" 
    "void path46(int _bf60, int* _bf58, int** x, int* _bf63) { " 
    "    *_bf63 = _bf58[_bf60];" 
    "    *x = _bf58;" 
    "}" 
    "void path47(int _bf102, int* _bf1) { " 
    "    *_bf1 = _bf102;" 
    "}" 
    "void path48(int _bf1, int* _bf5) { " 
    "    *_bf5 = _bf1;" 
    "}" 
    "void path49(int _bf5, int* _bf9) { " 
    "    *_bf9 = _bf5;" 
    "}" 
    "void path50(int _bf9, int* _bf13) { " 
    "    *_bf13 = _bf9;" 
    "}" 
    "void path51(int _bf13, int* _bf17) { " 
    "    *_bf17 = _bf13;" 
    "}" 
    "void path52(int _bf17, int* _bf21) { " 
    "    *_bf21 = _bf17;" 
    "}" 
    "void path53(int _bf21, int* _bf25) { " 
    "    *_bf25 = _bf21;" 
    "}" 
    "void path54(int _bf25, int* _bf29) { " 
    "    *_bf29 = _bf25;" 
    "}" 
    "void path55(int _bf11, int* _bf33) { " 
    "    *_bf33 = _bf11;" 
    "}" 
    "void path56(int _bf19, int* _bf37) { " 
    "    *_bf37 = _bf19;" 
    "}" 
    "void path57(int _bf27, int* _bf41) { " 
    "    *_bf41 = _bf27;" 
    "}" 
    "void path58(int _bf3, int* _bf45) { " 
    "    *_bf45 = _bf3;" 
    "}" 
    "void path59(int _bf35, int* _bf49) { " 
    "    *_bf49 = _bf35;" 
    "}" 
    "void path60(int _bf43, int* _bf53) { " 
    "    *_bf53 = _bf43;" 
    "}" 
    "void path61(int _bf51, int* _bf57) { " 
    "    *_bf57 = _bf51;" 
    "}" 
    "void path62(int _bf59, int* _bf61) { " 
    "    *_bf61 = _bf59;" 
    "}" 
    "void path63(int _bf66, int* _bf62) { " 
    "    *_bf62 = _bf66;" 
    "}" 
    "void path64(int _bf62, int* _bf64) { " 
    "    *_bf64 = _bf62;" 
    "}" 
    "void path65(int _bf72, int* _bf65) { " 
    "    *_bf65 = _bf72;" 
    "}" 
    "void path66(int _bf65, int* _bf67) { " 
    "    *_bf67 = _bf65;" 
    "}" 
    "void path67(int _bf78, int* _bf68) { " 
    "    *_bf68 = _bf78;" 
    "}" 
    "void path68(int _bf68, int* _bf70) { " 
    "    *_bf70 = _bf68;" 
    "}" 
    "void path69(int _bf84, int* _bf71) { " 
    "    *_bf71 = _bf84;" 
    "}" 
    "void path70(int _bf71, int* _bf73) { " 
    "    *_bf73 = _bf71;" 
    "}" 
    "void path71(int _bf90, int* _bf74) { " 
    "    *_bf74 = _bf90;" 
    "}" 
    "void path72(int _bf74, int* _bf76) { " 
    "    *_bf76 = _bf74;" 
    "}" 
    "void path73(int _bf76, int* _bf77) { " 
    "    *_bf77 = _bf76;" 
    "}" 
    "void path74(int _bf77, int* _bf79) { " 
    "    *_bf79 = _bf77;" 
    "}" 
    "void path75(int _bf96, int* _bf80) { " 
    "    *_bf80 = _bf96;" 
    "}" 
    "void path76(int _bf80, int* _bf82) { " 
    "    *_bf82 = _bf80;" 
    "}" 
    "void path77(int _bf82, int* _bf83) { " 
    "    *_bf83 = _bf82;" 
    "}" 
    "void path78(int _bf83, int* _bf85) { " 
    "    *_bf85 = _bf83;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    int* x = inputs + threadId * 16 + 0;" 
    "" 
    "    int _bf0;" 
    "    path0(&_bf0);" 
    "" 
    "    int _bf12;" 
    "    path4(&_bf12);" 
    "" 
    "    int _bf16;" 
    "    path5(&_bf16);" 
    "" 
    "    int _bf20;" 
    "    path6(&_bf20);" 
    "" 
    "    int _bf24;" 
    "    path7(&_bf24);" 
    "" 
    "    int _bf28;" 
    "    path8(&_bf28);" 
    "" 
    "    int _bf32;" 
    "    path9(&_bf32);" 
    "" 
    "    int _bf36;" 
    "    path10(&_bf36);" 
    "" 
    "    int _bf4;" 
    "    path11(&_bf4);" 
    "" 
    "    int _bf40;" 
    "    path12(&_bf40);" 
    "" 
    "    int _bf44;" 
    "    path13(&_bf44);" 
    "" 
    "    int _bf48;" 
    "    path14(&_bf48);" 
    "" 
    "    int _bf52;" 
    "    path15(&_bf52);" 
    "" 
    "    int _bf56;" 
    "    path16(&_bf56);" 
    "" 
    "    int _bf60;" 
    "    path17(&_bf60);" 
    "" 
    "    int _bf8;" 
    "    path23(&_bf8);" 
    "" 
    "    int* _bf2;" 
    "    int _bf3;" 
    "    path34(_bf0, x, &_bf2, &_bf3);" 
    "" 
    "    int* _bf6;" 
    "    int _bf7;" 
    "    path45(_bf4, _bf2, &_bf6, &_bf7);" 
    "" 
    "    int _bf45;" 
    "    path58(_bf3, &_bf45);" 
    "" 
    "    int _bf66;" 
    "    path18(_bf45, _bf7, &_bf66);" 
    "" 
    "    int* _bf10;" 
    "    int _bf11;" 
    "    path31(_bf8, _bf6, &_bf10, &_bf11);" 
    "" 
    "    int* _bf14;" 
    "    int _bf15;" 
    "    path32(_bf12, _bf10, &_bf14, &_bf15);" 
    "" 
    "    int _bf33;" 
    "    path55(_bf11, &_bf33);" 
    "" 
    "    int _bf62;" 
    "    path63(_bf66, &_bf62);" 
    "" 
    "    int _bf69;" 
    "    path19(_bf33, _bf15, &_bf69);" 
    "" 
    "    int* _bf18;" 
    "    int _bf19;" 
    "    path33(_bf16, _bf14, &_bf18, &_bf19);" 
    "" 
    "    int _bf64;" 
    "    path64(_bf62, &_bf64);" 
    "" 
    "    int _bf90;" 
    "    path27(_bf64, _bf69, &_bf90);" 
    "" 
    "    int* _bf22;" 
    "    int _bf23;" 
    "    path35(_bf20, _bf18, &_bf22, &_bf23);" 
    "" 
    "    int _bf37;" 
    "    path56(_bf19, &_bf37);" 
    "" 
    "    int _bf72;" 
    "    path20(_bf37, _bf23, &_bf72);" 
    "" 
    "    int* _bf26;" 
    "    int _bf27;" 
    "    path36(_bf24, _bf22, &_bf26, &_bf27);" 
    "" 
    "    int _bf74;" 
    "    path71(_bf90, &_bf74);" 
    "" 
    "    int* _bf30;" 
    "    int _bf31;" 
    "    path37(_bf28, _bf26, &_bf30, &_bf31);" 
    "" 
    "    int _bf41;" 
    "    path57(_bf27, &_bf41);" 
    "" 
    "    int _bf65;" 
    "    path65(_bf72, &_bf65);" 
    "" 
    "    int _bf76;" 
    "    path72(_bf74, &_bf76);" 
    "" 
    "    int _bf75;" 
    "    path21(_bf41, _bf31, &_bf75);" 
    "" 
    "    int* _bf34;" 
    "    int _bf35;" 
    "    path38(_bf32, _bf30, &_bf34, &_bf35);" 
    "" 
    "    int _bf67;" 
    "    path66(_bf65, &_bf67);" 
    "" 
    "    int _bf77;" 
    "    path73(_bf76, &_bf77);" 
    "" 
    "    int _bf93;" 
    "    path28(_bf67, _bf75, &_bf93);" 
    "" 
    "    int* _bf38;" 
    "    int _bf39;" 
    "    path39(_bf36, _bf34, &_bf38, &_bf39);" 
    "" 
    "    int _bf49;" 
    "    path59(_bf35, &_bf49);" 
    "" 
    "    int _bf79;" 
    "    path74(_bf77, &_bf79);" 
    "" 
    "    int _bf102;" 
    "    path1(_bf79, _bf93, &_bf102);" 
    "" 
    "    int _bf78;" 
    "    path22(_bf49, _bf39, &_bf78);" 
    "" 
    "    int* _bf42;" 
    "    int _bf43;" 
    "    path40(_bf40, _bf38, &_bf42, &_bf43);" 
    "" 
    "    int* _bf46;" 
    "    int _bf47;" 
    "    path41(_bf44, _bf42, &_bf46, &_bf47);" 
    "" 
    "    int _bf1;" 
    "    path47(_bf102, &_bf1);" 
    "" 
    "    int _bf53;" 
    "    path60(_bf43, &_bf53);" 
    "" 
    "    int _bf68;" 
    "    path67(_bf78, &_bf68);" 
    "" 
    "    int _bf81;" 
    "    path24(_bf53, _bf47, &_bf81);" 
    "" 
    "    int* _bf50;" 
    "    int _bf51;" 
    "    path42(_bf48, _bf46, &_bf50, &_bf51);" 
    "" 
    "    int _bf5;" 
    "    path48(_bf1, &_bf5);" 
    "" 
    "    int _bf70;" 
    "    path68(_bf68, &_bf70);" 
    "" 
    "    int _bf96;" 
    "    path29(_bf70, _bf81, &_bf96);" 
    "" 
    "    int* _bf54;" 
    "    int _bf55;" 
    "    path43(_bf52, _bf50, &_bf54, &_bf55);" 
    "" 
    "    int _bf9;" 
    "    path49(_bf5, &_bf9);" 
    "" 
    "    int _bf57;" 
    "    path61(_bf51, &_bf57);" 
    "" 
    "    int _bf84;" 
    "    path25(_bf57, _bf55, &_bf84);" 
    "" 
    "    int* _bf58;" 
    "    int _bf59;" 
    "    path44(_bf56, _bf54, &_bf58, &_bf59);" 
    "" 
    "    int _bf13;" 
    "    path50(_bf9, &_bf13);" 
    "" 
    "    int _bf80;" 
    "    path75(_bf96, &_bf80);" 
    "" 
    "    int _bf63;" 
    "    path46(_bf60, _bf58, &x, &_bf63);" 
    "" 
    "    int _bf17;" 
    "    path51(_bf13, &_bf17);" 
    "" 
    "    int _bf61;" 
    "    path62(_bf59, &_bf61);" 
    "" 
    "    int _bf71;" 
    "    path69(_bf84, &_bf71);" 
    "" 
    "    int _bf82;" 
    "    path76(_bf80, &_bf82);" 
    "" 
    "    int _bf87;" 
    "    path26(_bf61, _bf63, &_bf87);" 
    "" 
    "    int _bf21;" 
    "    path52(_bf17, &_bf21);" 
    "" 
    "    int _bf73;" 
    "    path70(_bf71, &_bf73);" 
    "" 
    "    int _bf83;" 
    "    path77(_bf82, &_bf83);" 
    "" 
    "    int _bf99;" 
    "    path30(_bf73, _bf87, &_bf99);" 
    "" 
    "    int _bf25;" 
    "    path53(_bf21, &_bf25);" 
    "" 
    "    int _bf85;" 
    "    path78(_bf83, &_bf85);" 
    "" 
    "    int _bf105;" 
    "    path2(_bf85, _bf99, &_bf105);" 
    "" 
    "    int _bf29;" 
    "    path54(_bf25, &_bf29);" 
    "" 
    "    int z;" 
    "    path3(_bf29, _bf105, &z);" 
    "" 
    "    outputs[threadId * 17 + 0] = z;" 
    "    outputs[threadId * 17 + 1] = x[0];" 
    "    outputs[threadId * 17 + 2] = x[1];" 
    "    outputs[threadId * 17 + 3] = x[2];" 
    "    outputs[threadId * 17 + 4] = x[3];" 
    "    outputs[threadId * 17 + 5] = x[4];" 
    "    outputs[threadId * 17 + 6] = x[5];" 
    "    outputs[threadId * 17 + 7] = x[6];" 
    "    outputs[threadId * 17 + 8] = x[7];" 
    "    outputs[threadId * 17 + 9] = x[8];" 
    "    outputs[threadId * 17 + 10] = x[9];" 
    "    outputs[threadId * 17 + 11] = x[10];" 
    "    outputs[threadId * 17 + 12] = x[11];" 
    "    outputs[threadId * 17 + 13] = x[12];" 
    "    outputs[threadId * 17 + 14] = x[13];" 
    "    outputs[threadId * 17 + 15] = x[14];" 
    "    outputs[threadId * 17 + 16] = x[15];" 
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
    int* outputs = new int[DATA_SIZE * 17];
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

    input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * DATA_SIZE * 16, NULL, &err);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * DATA_SIZE * 17, NULL, &err);

    int* nums = new int[DATA_SIZE * 16];
    memset(nums, 0, 16 * DATA_SIZE * sizeof(int));

    clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 16, nums, 0, NULL, NULL);
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    clFinish(command_queue);

    size_t global = DATA_SIZE;

    auto start = chrono::steady_clock::now();
    clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    clFinish(command_queue);
    auto end = chrono::steady_clock::now();

    clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(int) * DATA_SIZE * 17, outputs, 0, NULL, NULL);
    if (!onlyTimeOutput)
           printf("z: %i", outputs[0]);
       

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
