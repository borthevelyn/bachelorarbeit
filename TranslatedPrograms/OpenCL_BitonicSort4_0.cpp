#define CL_TARGET_OPENCL_VERSION 220
#define DATA_SIZE 1
#include <string>
#include <cstring>
#include "CL/opencl.h"
#include <stdio.h>
#include <chrono>

using namespace std;

const char* KernelSource = 
    "void path0(bool _bf7, int _bf92, int _bf93, int* _bf10) { " 
    "    if ( _bf7 ) {" 
    "        *_bf10 = _bf92;" 
    "    } else  { " 
    "        *_bf10 = _bf93;" 
    "    } " 
    "}" 
    "void path1(int _bf11, int _bf12, bool* _bf13) { " 
    "    *_bf13 = _bf11 < _bf12;" 
    "}" 
    "void path2(bool _bf14, int _bf50, int _bf54, int* _bf17) { " 
    "    if ( _bf14 ) {" 
    "        *_bf17 = _bf50;" 
    "    } else  { " 
    "        *_bf17 = _bf54;" 
    "    } " 
    "}" 
    "void path3(int _bf0, int _bf1, bool* _bf2) { " 
    "    *_bf2 = _bf0 < _bf1;" 
    "}" 
    "void path4(bool _bf18, int _bf61, int _bf65, int* _bf21) { " 
    "    if ( _bf18 ) {" 
    "        *_bf21 = _bf61;" 
    "    } else  { " 
    "        *_bf21 = _bf65;" 
    "    } " 
    "}" 
    "void path5(int _bf22, int _bf23, bool* _bf24) { " 
    "    *_bf24 = _bf22 < _bf23;" 
    "}" 
    "void path6(bool _bf25, int _bf66, int _bf69, int* _bf28) { " 
    "    if ( _bf25 ) {" 
    "        *_bf28 = _bf66;" 
    "    } else  { " 
    "        *_bf28 = _bf69;" 
    "    } " 
    "}" 
    "void path7(bool _bf29, int _bf70, int _bf71, int* _bf32) { " 
    "    if ( _bf29 ) {" 
    "        *_bf32 = _bf70;" 
    "    } else  { " 
    "        *_bf32 = _bf71;" 
    "    } " 
    "}" 
    "void path8(int _bf33, int _bf34, bool* _bf35) { " 
    "    *_bf35 = _bf33 < _bf34;" 
    "}" 
    "void path9(bool _bf36, int _bf72, int _bf75, int* _bf39) { " 
    "    if ( _bf36 ) {" 
    "        *_bf39 = _bf72;" 
    "    } else  { " 
    "        *_bf39 = _bf75;" 
    "    } " 
    "}" 
    "void path10(bool _bf40, int _bf77, int _bf78, int* _bf43) { " 
    "    if ( _bf40 ) {" 
    "        *_bf43 = _bf77;" 
    "    } else  { " 
    "        *_bf43 = _bf78;" 
    "    } " 
    "}" 
    "void path11(int _bf44, int _bf45, bool* _bf46) { " 
    "    *_bf46 = _bf44 < _bf45;" 
    "}" 
    "void path12(int _bf55, int _bf56, bool* _bf57) { " 
    "    *_bf57 = _bf55 < _bf56;" 
    "}" 
    "void path13(bool _bf3, int _bf76, int _bf83, int* _bf6) { " 
    "    if ( _bf3 ) {" 
    "        *_bf6 = _bf76;" 
    "    } else  { " 
    "        *_bf6 = _bf83;" 
    "    } " 
    "}" 
    "void path14(bool _bf47, int _bf79, int _bf80, int* x_0_3) { " 
    "    if ( _bf47 ) {" 
    "        *x_0_3 = _bf79;" 
    "    } else  { " 
    "        *x_0_3 = _bf80;" 
    "    } " 
    "}" 
    "void path15(bool _bf51, int _bf84, int _bf85, int* x_1_3) { " 
    "    if ( _bf51 ) {" 
    "        *x_1_3 = _bf84;" 
    "    } else  { " 
    "        *x_1_3 = _bf85;" 
    "    } " 
    "}" 
    "void path16(bool _bf62, int _bf88, int _bf91, int* x_2_3) { " 
    "    if ( _bf62 ) {" 
    "        *x_2_3 = _bf88;" 
    "    } else  { " 
    "        *x_2_3 = _bf91;" 
    "    } " 
    "}" 
    "void path17(bool _bf58, int _bf86, int _bf87, int* x_3_3) { " 
    "    if ( _bf58 ) {" 
    "        *x_3_3 = _bf86;" 
    "    } else  { " 
    "        *x_3_3 = _bf87;" 
    "    } " 
    "}" 
    "void path18(int x_0_0, int* _bf0, int* _bf105) { " 
    "    *_bf0 = x_0_0;" 
    "    *_bf105 = x_0_0;" 
    "}" 
    "void path19(int x_1_0, int* _bf1, int* _bf106) { " 
    "    *_bf1 = x_1_0;" 
    "    *_bf106 = x_1_0;" 
    "}" 
    "void path20(int x_2_0, int* _bf11, int* _bf97) { " 
    "    *_bf11 = x_2_0;" 
    "    *_bf97 = x_2_0;" 
    "}" 
    "void path21(int x_3_0, int* _bf12, int* _bf98) { " 
    "    *_bf12 = x_3_0;" 
    "    *_bf98 = x_3_0;" 
    "}" 
    "void path22(bool _bf13, bool* _bf14, bool* _bf18) { " 
    "    *_bf14 = _bf13;" 
    "    *_bf18 = _bf13;" 
    "}" 
    "void path23(int _bf97, int* _bf15, int* _bf20) { " 
    "    *_bf15 = _bf97;" 
    "    *_bf20 = _bf97;" 
    "}" 
    "void path24(int _bf98, int* _bf16, int* _bf19) { " 
    "    *_bf16 = _bf98;" 
    "    *_bf19 = _bf98;" 
    "}" 
    "void path25(int _bf6, int* _bf22, int* _bf89) { " 
    "    *_bf22 = _bf6;" 
    "    *_bf89 = _bf6;" 
    "}" 
    "void path26(int _bf21, int* _bf23, int* _bf90) { " 
    "    *_bf23 = _bf21;" 
    "    *_bf90 = _bf21;" 
    "}" 
    "void path27(bool _bf24, bool* _bf25, bool* _bf29) { " 
    "    *_bf25 = _bf24;" 
    "    *_bf29 = _bf24;" 
    "}" 
    "void path28(int _bf89, int* _bf26, int* _bf31) { " 
    "    *_bf26 = _bf89;" 
    "    *_bf31 = _bf89;" 
    "}" 
    "void path29(int _bf90, int* _bf27, int* _bf30) { " 
    "    *_bf27 = _bf90;" 
    "    *_bf30 = _bf90;" 
    "}" 
    "void path30(bool _bf2, bool* _bf3, bool* _bf7) { " 
    "    *_bf3 = _bf2;" 
    "    *_bf7 = _bf2;" 
    "}" 
    "void path31(int _bf10, int* _bf33, int* _bf81) { " 
    "    *_bf33 = _bf10;" 
    "    *_bf81 = _bf10;" 
    "}" 
    "void path32(int _bf17, int* _bf34, int* _bf82) { " 
    "    *_bf34 = _bf17;" 
    "    *_bf82 = _bf17;" 
    "}" 
    "void path33(bool _bf35, bool* _bf36, bool* _bf40) { " 
    "    *_bf36 = _bf35;" 
    "    *_bf40 = _bf35;" 
    "}" 
    "void path34(int _bf81, int* _bf37, int* _bf42) { " 
    "    *_bf37 = _bf81;" 
    "    *_bf42 = _bf81;" 
    "}" 
    "void path35(int _bf82, int* _bf38, int* _bf41) { " 
    "    *_bf38 = _bf82;" 
    "    *_bf41 = _bf82;" 
    "}" 
    "void path36(int _bf105, int* _bf4, int* _bf9) { " 
    "    *_bf4 = _bf105;" 
    "    *_bf9 = _bf105;" 
    "}" 
    "void path37(int _bf28, int* _bf44, int* _bf73) { " 
    "    *_bf44 = _bf28;" 
    "    *_bf73 = _bf28;" 
    "}" 
    "void path38(int _bf39, int* _bf45, int* _bf74) { " 
    "    *_bf45 = _bf39;" 
    "    *_bf74 = _bf39;" 
    "}" 
    "void path39(bool _bf46, bool* _bf47, bool* _bf51) { " 
    "    *_bf47 = _bf46;" 
    "    *_bf51 = _bf46;" 
    "}" 
    "void path40(int _bf73, int* _bf48, int* _bf53) { " 
    "    *_bf48 = _bf73;" 
    "    *_bf53 = _bf73;" 
    "}" 
    "void path41(int _bf74, int* _bf49, int* _bf52) { " 
    "    *_bf49 = _bf74;" 
    "    *_bf52 = _bf74;" 
    "}" 
    "void path42(int _bf106, int* _bf5, int* _bf8) { " 
    "    *_bf5 = _bf106;" 
    "    *_bf8 = _bf106;" 
    "}" 
    "void path43(int _bf32, int* _bf55, int* _bf68) { " 
    "    *_bf55 = _bf32;" 
    "    *_bf68 = _bf32;" 
    "}" 
    "void path44(int _bf43, int* _bf56, int* _bf67) { " 
    "    *_bf56 = _bf43;" 
    "    *_bf67 = _bf43;" 
    "}" 
    "void path45(bool _bf57, bool* _bf58, bool* _bf62) { " 
    "    *_bf58 = _bf57;" 
    "    *_bf62 = _bf57;" 
    "}" 
    "void path46(int _bf68, int* _bf59, int* _bf64) { " 
    "    *_bf59 = _bf68;" 
    "    *_bf64 = _bf68;" 
    "}" 
    "void path47(int _bf67, int* _bf60, int* _bf63) { " 
    "    *_bf60 = _bf67;" 
    "    *_bf63 = _bf67;" 
    "}" 
    "void path48(int _bf15, int* _bf50) { " 
    "    *_bf50 = _bf15;" 
    "}" 
    "void path49(int _bf16, int* _bf54) { " 
    "    *_bf54 = _bf16;" 
    "}" 
    "void path50(int _bf19, int* _bf61) { " 
    "    *_bf61 = _bf19;" 
    "}" 
    "void path51(int _bf20, int* _bf65) { " 
    "    *_bf65 = _bf20;" 
    "}" 
    "void path52(int _bf26, int* _bf66) { " 
    "    *_bf66 = _bf26;" 
    "}" 
    "void path53(int _bf27, int* _bf69) { " 
    "    *_bf69 = _bf27;" 
    "}" 
    "void path54(int _bf30, int* _bf70) { " 
    "    *_bf70 = _bf30;" 
    "}" 
    "void path55(int _bf31, int* _bf71) { " 
    "    *_bf71 = _bf31;" 
    "}" 
    "void path56(int _bf37, int* _bf72) { " 
    "    *_bf72 = _bf37;" 
    "}" 
    "void path57(int _bf38, int* _bf75) { " 
    "    *_bf75 = _bf38;" 
    "}" 
    "void path58(int _bf4, int* _bf76) { " 
    "    *_bf76 = _bf4;" 
    "}" 
    "void path59(int _bf41, int* _bf77) { " 
    "    *_bf77 = _bf41;" 
    "}" 
    "void path60(int _bf42, int* _bf78) { " 
    "    *_bf78 = _bf42;" 
    "}" 
    "void path61(int _bf48, int* _bf79) { " 
    "    *_bf79 = _bf48;" 
    "}" 
    "void path62(int _bf49, int* _bf80) { " 
    "    *_bf80 = _bf49;" 
    "}" 
    "void path63(int _bf5, int* _bf83) { " 
    "    *_bf83 = _bf5;" 
    "}" 
    "void path64(int _bf52, int* _bf84) { " 
    "    *_bf84 = _bf52;" 
    "}" 
    "void path65(int _bf53, int* _bf85) { " 
    "    *_bf85 = _bf53;" 
    "}" 
    "void path66(int _bf59, int* _bf86) { " 
    "    *_bf86 = _bf59;" 
    "}" 
    "void path67(int _bf60, int* _bf87) { " 
    "    *_bf87 = _bf60;" 
    "}" 
    "void path68(int _bf63, int* _bf88) { " 
    "    *_bf88 = _bf63;" 
    "}" 
    "void path69(int _bf64, int* _bf91) { " 
    "    *_bf91 = _bf64;" 
    "}" 
    "void path70(int _bf8, int* _bf92) { " 
    "    *_bf92 = _bf8;" 
    "}" 
    "void path71(int _bf9, int* _bf93) { " 
    "    *_bf93 = _bf9;" 
    "}" 
    "" 
    "__kernel void Execute(__global int* inputs, __global int* outputs) { " 
    "    size_t threadId = get_global_id(0); " 
    "    int x_0_0 = inputs[threadId * 4 + 0];" 
    "    int x_1_0 = inputs[threadId * 4 + 1];" 
    "    int x_2_0 = inputs[threadId * 4 + 2];" 
    "    int x_3_0 = inputs[threadId * 4 + 3];" 
    "" 
    "    int _bf0;" 
    "    int _bf105;" 
    "    path18(x_0_0, &_bf0, &_bf105);" 
    "" 
    "    int _bf1;" 
    "    int _bf106;" 
    "    path19(x_1_0, &_bf1, &_bf106);" 
    "" 
    "    int _bf11;" 
    "    int _bf97;" 
    "    path20(x_2_0, &_bf11, &_bf97);" 
    "" 
    "    int _bf12;" 
    "    int _bf98;" 
    "    path21(x_3_0, &_bf12, &_bf98);" 
    "" 
    "    bool _bf13;" 
    "    path1(_bf11, _bf12, &_bf13);" 
    "" 
    "    bool _bf2;" 
    "    path3(_bf0, _bf1, &_bf2);" 
    "" 
    "    int _bf15;" 
    "    int _bf20;" 
    "    path23(_bf97, &_bf15, &_bf20);" 
    "" 
    "    int _bf16;" 
    "    int _bf19;" 
    "    path24(_bf98, &_bf16, &_bf19);" 
    "" 
    "    int _bf4;" 
    "    int _bf9;" 
    "    path36(_bf105, &_bf4, &_bf9);" 
    "" 
    "    int _bf5;" 
    "    int _bf8;" 
    "    path42(_bf106, &_bf5, &_bf8);" 
    "" 
    "    bool _bf14;" 
    "    bool _bf18;" 
    "    path22(_bf13, &_bf14, &_bf18);" 
    "" 
    "    bool _bf3;" 
    "    bool _bf7;" 
    "    path30(_bf2, &_bf3, &_bf7);" 
    "" 
    "    int _bf50;" 
    "    path48(_bf15, &_bf50);" 
    "" 
    "    int _bf54;" 
    "    path49(_bf16, &_bf54);" 
    "" 
    "    int _bf61;" 
    "    path50(_bf19, &_bf61);" 
    "" 
    "    int _bf65;" 
    "    path51(_bf20, &_bf65);" 
    "" 
    "    int _bf76;" 
    "    path58(_bf4, &_bf76);" 
    "" 
    "    int _bf83;" 
    "    path63(_bf5, &_bf83);" 
    "" 
    "    int _bf92;" 
    "    path70(_bf8, &_bf92);" 
    "" 
    "    int _bf93;" 
    "    path71(_bf9, &_bf93);" 
    "" 
    "    int _bf10;" 
    "    path0(_bf7, _bf92, _bf93, &_bf10);" 
    "" 
    "    int _bf17;" 
    "    path2(_bf14, _bf50, _bf54, &_bf17);" 
    "" 
    "    int _bf21;" 
    "    path4(_bf18, _bf61, _bf65, &_bf21);" 
    "" 
    "    int _bf6;" 
    "    path13(_bf3, _bf76, _bf83, &_bf6);" 
    "" 
    "    int _bf22;" 
    "    int _bf89;" 
    "    path25(_bf6, &_bf22, &_bf89);" 
    "" 
    "    int _bf23;" 
    "    int _bf90;" 
    "    path26(_bf21, &_bf23, &_bf90);" 
    "" 
    "    int _bf33;" 
    "    int _bf81;" 
    "    path31(_bf10, &_bf33, &_bf81);" 
    "" 
    "    int _bf34;" 
    "    int _bf82;" 
    "    path32(_bf17, &_bf34, &_bf82);" 
    "" 
    "    bool _bf24;" 
    "    path5(_bf22, _bf23, &_bf24);" 
    "" 
    "    bool _bf35;" 
    "    path8(_bf33, _bf34, &_bf35);" 
    "" 
    "    int _bf26;" 
    "    int _bf31;" 
    "    path28(_bf89, &_bf26, &_bf31);" 
    "" 
    "    int _bf27;" 
    "    int _bf30;" 
    "    path29(_bf90, &_bf27, &_bf30);" 
    "" 
    "    int _bf37;" 
    "    int _bf42;" 
    "    path34(_bf81, &_bf37, &_bf42);" 
    "" 
    "    int _bf38;" 
    "    int _bf41;" 
    "    path35(_bf82, &_bf38, &_bf41);" 
    "" 
    "    bool _bf25;" 
    "    bool _bf29;" 
    "    path27(_bf24, &_bf25, &_bf29);" 
    "" 
    "    bool _bf36;" 
    "    bool _bf40;" 
    "    path33(_bf35, &_bf36, &_bf40);" 
    "" 
    "    int _bf66;" 
    "    path52(_bf26, &_bf66);" 
    "" 
    "    int _bf69;" 
    "    path53(_bf27, &_bf69);" 
    "" 
    "    int _bf70;" 
    "    path54(_bf30, &_bf70);" 
    "" 
    "    int _bf71;" 
    "    path55(_bf31, &_bf71);" 
    "" 
    "    int _bf72;" 
    "    path56(_bf37, &_bf72);" 
    "" 
    "    int _bf75;" 
    "    path57(_bf38, &_bf75);" 
    "" 
    "    int _bf77;" 
    "    path59(_bf41, &_bf77);" 
    "" 
    "    int _bf78;" 
    "    path60(_bf42, &_bf78);" 
    "" 
    "    int _bf28;" 
    "    path6(_bf25, _bf66, _bf69, &_bf28);" 
    "" 
    "    int _bf32;" 
    "    path7(_bf29, _bf70, _bf71, &_bf32);" 
    "" 
    "    int _bf39;" 
    "    path9(_bf36, _bf72, _bf75, &_bf39);" 
    "" 
    "    int _bf43;" 
    "    path10(_bf40, _bf77, _bf78, &_bf43);" 
    "" 
    "    int _bf44;" 
    "    int _bf73;" 
    "    path37(_bf28, &_bf44, &_bf73);" 
    "" 
    "    int _bf45;" 
    "    int _bf74;" 
    "    path38(_bf39, &_bf45, &_bf74);" 
    "" 
    "    int _bf55;" 
    "    int _bf68;" 
    "    path43(_bf32, &_bf55, &_bf68);" 
    "" 
    "    int _bf56;" 
    "    int _bf67;" 
    "    path44(_bf43, &_bf56, &_bf67);" 
    "" 
    "    bool _bf46;" 
    "    path11(_bf44, _bf45, &_bf46);" 
    "" 
    "    bool _bf57;" 
    "    path12(_bf55, _bf56, &_bf57);" 
    "" 
    "    int _bf48;" 
    "    int _bf53;" 
    "    path40(_bf73, &_bf48, &_bf53);" 
    "" 
    "    int _bf49;" 
    "    int _bf52;" 
    "    path41(_bf74, &_bf49, &_bf52);" 
    "" 
    "    int _bf59;" 
    "    int _bf64;" 
    "    path46(_bf68, &_bf59, &_bf64);" 
    "" 
    "    int _bf60;" 
    "    int _bf63;" 
    "    path47(_bf67, &_bf60, &_bf63);" 
    "" 
    "    bool _bf47;" 
    "    bool _bf51;" 
    "    path39(_bf46, &_bf47, &_bf51);" 
    "" 
    "    bool _bf58;" 
    "    bool _bf62;" 
    "    path45(_bf57, &_bf58, &_bf62);" 
    "" 
    "    int _bf79;" 
    "    path61(_bf48, &_bf79);" 
    "" 
    "    int _bf80;" 
    "    path62(_bf49, &_bf80);" 
    "" 
    "    int _bf84;" 
    "    path64(_bf52, &_bf84);" 
    "" 
    "    int _bf85;" 
    "    path65(_bf53, &_bf85);" 
    "" 
    "    int _bf86;" 
    "    path66(_bf59, &_bf86);" 
    "" 
    "    int _bf87;" 
    "    path67(_bf60, &_bf87);" 
    "" 
    "    int _bf88;" 
    "    path68(_bf63, &_bf88);" 
    "" 
    "    int _bf91;" 
    "    path69(_bf64, &_bf91);" 
    "" 
    "    int x_0_3;" 
    "    path14(_bf47, _bf79, _bf80, &x_0_3);" 
    "" 
    "    int x_1_3;" 
    "    path15(_bf51, _bf84, _bf85, &x_1_3);" 
    "" 
    "    int x_2_3;" 
    "    path16(_bf62, _bf88, _bf91, &x_2_3);" 
    "" 
    "    int x_3_3;" 
    "    path17(_bf58, _bf86, _bf87, &x_3_3);" 
    "" 
    "    outputs[threadId * 4 + 0] = x_0_3;" 
    "    outputs[threadId * 4 + 1] = x_1_3;" 
    "    outputs[threadId * 4 + 2] = x_2_3;" 
    "    outputs[threadId * 4 + 3] = x_3_3;" 
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
           printf("x_0_3: %i, x_1_3: %i, x_2_3: %i, x_3_3: %i", outputs[0], outputs[1], outputs[2], outputs[3]);
       

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
