#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf1, int _bf15, int* _bf16) { 
    *_bf16 = _bf1 * _bf15;
}
void path1(int _bf24, int _bf16, int* c_0_0) { 
    *c_0_0 = _bf24 + _bf16;
}
void path2(int _bf21, int _bf5, int* _bf26) { 
    *_bf26 = _bf21 * _bf5;
}
void path3(int c_0_1, int _bf26, int* _bf27) { 
    *_bf27 = c_0_1 + _bf26;
}
void path4(int _bf33, int _bf10, int* _bf35) { 
    *_bf35 = _bf33 * _bf10;
}
void path5(int _bf27, int _bf35, int* c_0_1) { 
    *c_0_1 = _bf27 + _bf35;
}
void path6(int _bf17, int _bf38, int* _bf45) { 
    *_bf45 = _bf17 * _bf38;
}
void path7(int c_1_0, int _bf45, int* _bf46) { 
    *_bf46 = c_1_0 + _bf45;
}
void path8(int _bf23, int _bf53, int* _bf54) { 
    *_bf54 = _bf23 * _bf53;
}
void path9(int _bf46, int _bf54, int* c_1_0) { 
    *c_1_0 = _bf46 + _bf54;
}
void path10(int _bf59, int _bf57, int* _bf64) { 
    *_bf64 = _bf59 * _bf57;
}
void path11(int c_1_1, int _bf64, int* _bf65) { 
    *_bf65 = c_1_1 + _bf64;
}
void path12(int _bf2, int _bf0, int* _bf7) { 
    *_bf7 = _bf2 * _bf0;
}
void path13(int _bf71, int _bf72, int* _bf73) { 
    *_bf73 = _bf71 * _bf72;
}
void path14(int _bf65, int _bf73, int* c_1_1) { 
    *c_1_1 = _bf65 + _bf73;
}
void path15(int c_0_0, int _bf7, int* _bf8) { 
    *_bf8 = c_0_0 + _bf7;
}
void path16(int b_1_0, int* _bf0, int* _bf9) { 
    *_bf0 = b_1_0;
    *_bf9 = b_1_0;
}
void path17(int _bf11, int* _bf14, int* _bf18) { 
    *_bf14 = _bf11;
    *_bf18 = _bf11;
}
void path18(int _bf96, int* _bf15, int* _bf90) { 
    *_bf15 = _bf96;
    *_bf90 = _bf96;
}
void path19(int b_1_1, int* _bf19, int* _bf28) { 
    *_bf19 = b_1_1;
    *_bf28 = b_1_1;
}
void path20(int a_0_1, int* _bf2, int* _bf11) { 
    *_bf2 = a_0_1;
    *_bf11 = a_0_1;
}
void path21(int _bf93, int* _bf21, int* _bf30) { 
    *_bf21 = _bf93;
    *_bf30 = _bf93;
}
void path22(int _bf30, int* _bf33, int* a_0_1) { 
    *_bf33 = _bf30;
    *a_0_1 = _bf30;
}
void path23(int _bf91, int* _bf34, int* _bf86) { 
    *_bf34 = _bf91;
    *_bf86 = _bf91;
}
void path24(int _bf90, int* _bf38, int* _bf47) { 
    *_bf38 = _bf90;
    *_bf47 = _bf90;
}
void path25(int a_1_1, int* _bf40, int* _bf49) { 
    *_bf40 = a_1_1;
    *_bf49 = a_1_1;
}
void path26(int _bf49, int* _bf52, int* _bf56) { 
    *_bf52 = _bf49;
    *_bf56 = _bf49;
}
void path27(int _bf47, int* _bf53, int* b_1_0) { 
    *_bf53 = _bf47;
    *b_1_0 = _bf47;
}
void path28(int _bf86, int* _bf57, int* _bf66) { 
    *_bf57 = _bf86;
    *_bf66 = _bf86;
}
void path29(int _bf85, int* _bf59, int* _bf68) { 
    *_bf59 = _bf85;
    *_bf68 = _bf85;
}
void path30(int _bf68, int* _bf71, int* a_1_1) { 
    *_bf71 = _bf68;
    *a_1_1 = _bf68;
}
void path31(int _bf66, int* _bf72, int* b_1_1) { 
    *_bf72 = _bf66;
    *b_1_1 = _bf66;
}
void path32(int _bf56, int* _bf85, int* a_1_0) { 
    *_bf85 = _bf56;
    *a_1_0 = _bf56;
}
void path33(int _bf28, int* _bf91, int* b_0_1) { 
    *_bf91 = _bf28;
    *b_0_1 = _bf28;
}
void path34(int _bf18, int* _bf93, int* a_0_0) { 
    *_bf93 = _bf18;
    *a_0_0 = _bf18;
}
void path35(int _bf9, int* _bf96, int* b_0_0) { 
    *_bf96 = _bf9;
    *b_0_0 = _bf9;
}
void path36(int _bf14, int* _bf1) { 
    *_bf1 = _bf14;
}
void path37(int _bf19, int* _bf3) { 
    *_bf3 = _bf19;
}
void path38(int _bf3, int* _bf4) { 
    *_bf4 = _bf3;
}
void path39(int _bf4, int* _bf5) { 
    *_bf5 = _bf4;
}
void path40(int _bf34, int* _bf6) { 
    *_bf6 = _bf34;
}
void path41(int _bf6, int* _bf10) { 
    *_bf10 = _bf6;
}
void path42(int _bf40, int* _bf12) { 
    *_bf12 = _bf40;
}
void path43(int _bf12, int* _bf13) { 
    *_bf13 = _bf12;
}
void path44(int _bf13, int* _bf17) { 
    *_bf17 = _bf13;
}
void path45(int _bf52, int* _bf20) { 
    *_bf20 = _bf52;
}
void path46(int _bf20, int* _bf22) { 
    *_bf22 = _bf20;
}
void path47(int _bf22, int* _bf23) { 
    *_bf23 = _bf22;
}
void path48(int _bf8, int* _bf24) { 
    *_bf24 = _bf8;
}

int main(int argc, char** argv)
{
    bool onlyTimeOutput = [&]() {
        if (argc < 2) return false;

        if (std::string(argv[1]) == "--onlytime")
            return true;
        else
            return false;
    }();


    int* inputs = new int[DATA_SIZE * 8 ]; 
    memset(inputs, 0, 8 * DATA_SIZE * sizeof(int));
    int* outputs = new int[DATA_SIZE * 12 ]; 
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int a_0_1 = inputs[i * 8 + 0];
       int a_1_1 = inputs[i * 8 + 1];
       int b_1_0 = inputs[i * 8 + 2];
       int b_1_1 = inputs[i * 8 + 3];
       int c_0_0 = inputs[i * 8 + 4];
       int c_0_1 = inputs[i * 8 + 5];
       int c_1_0 = inputs[i * 8 + 6];
       int c_1_1 = inputs[i * 8 + 7];
       int _bf0;
       int _bf9;
       int _bf19;
       int _bf28;
       int _bf2;
       int _bf11;
       int _bf40;
       int _bf49;
       int _bf7;
       int _bf14;
       int _bf18;
       int _bf52;
       int _bf56;
       int _bf91;
       int b_0_1;
       int _bf96;
       int b_0_0;
       int _bf3;
       int _bf12;
       int _bf8;
       int _bf15;
       int _bf90;
       int _bf34;
       int _bf86;
       int _bf85;
       int a_1_0;
       int _bf93;
       int a_0_0;
       int _bf1;
       int _bf4;
       int _bf13;
       int _bf20;
       int _bf16;
       int _bf21;
       int _bf30;
       int _bf38;
       int _bf47;
       int _bf57;
       int _bf66;
       int _bf59;
       int _bf68;
       int _bf5;
       int _bf6;
       int _bf17;
       int _bf22;
       int _bf24;
       int _bf26;
       int _bf45;
       int _bf64;
       int _bf33;
       int _bf53;
       int _bf71;
       int _bf72;
       int _bf10;
       int _bf23;
       int _bf27;
       int _bf35;
       int _bf46;
       int _bf54;
       int _bf65;
       int _bf73;

       #pragma omp parallel sections
       {
           #pragma omp section
               path16(b_1_0, &_bf0, &_bf9);
           #pragma omp section
               path19(b_1_1, &_bf19, &_bf28);
           #pragma omp section
               path20(a_0_1, &_bf2, &_bf11);
           #pragma omp section
               path25(a_1_1, &_bf40, &_bf49);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path12(_bf2, _bf0, &_bf7);
           #pragma omp section
               path17(_bf11, &_bf14, &_bf18);
           #pragma omp section
               path26(_bf49, &_bf52, &_bf56);
           #pragma omp section
               path33(_bf28, &_bf91, &b_0_1);
           #pragma omp section
               path35(_bf9, &_bf96, &b_0_0);
           #pragma omp section
               path37(_bf19, &_bf3);
           #pragma omp section
               path42(_bf40, &_bf12);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path15(c_0_0, _bf7, &_bf8);
           #pragma omp section
               path18(_bf96, &_bf15, &_bf90);
           #pragma omp section
               path23(_bf91, &_bf34, &_bf86);
           #pragma omp section
               path32(_bf56, &_bf85, &a_1_0);
           #pragma omp section
               path34(_bf18, &_bf93, &a_0_0);
           #pragma omp section
               path36(_bf14, &_bf1);
           #pragma omp section
               path38(_bf3, &_bf4);
           #pragma omp section
               path43(_bf12, &_bf13);
           #pragma omp section
               path45(_bf52, &_bf20);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path0(_bf1, _bf15, &_bf16);
           #pragma omp section
               path21(_bf93, &_bf21, &_bf30);
           #pragma omp section
               path24(_bf90, &_bf38, &_bf47);
           #pragma omp section
               path28(_bf86, &_bf57, &_bf66);
           #pragma omp section
               path29(_bf85, &_bf59, &_bf68);
           #pragma omp section
               path39(_bf4, &_bf5);
           #pragma omp section
               path40(_bf34, &_bf6);
           #pragma omp section
               path44(_bf13, &_bf17);
           #pragma omp section
               path46(_bf20, &_bf22);
           #pragma omp section
               path48(_bf8, &_bf24);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf24, _bf16, &c_0_0);
           #pragma omp section
               path2(_bf21, _bf5, &_bf26);
           #pragma omp section
               path6(_bf17, _bf38, &_bf45);
           #pragma omp section
               path10(_bf59, _bf57, &_bf64);
           #pragma omp section
               path22(_bf30, &_bf33, &a_0_1);
           #pragma omp section
               path27(_bf47, &_bf53, &b_1_0);
           #pragma omp section
               path30(_bf68, &_bf71, &a_1_1);
           #pragma omp section
               path31(_bf66, &_bf72, &b_1_1);
           #pragma omp section
               path41(_bf6, &_bf10);
           #pragma omp section
               path47(_bf22, &_bf23);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path3(c_0_1, _bf26, &_bf27);
           #pragma omp section
               path4(_bf33, _bf10, &_bf35);
           #pragma omp section
               path7(c_1_0, _bf45, &_bf46);
           #pragma omp section
               path8(_bf23, _bf53, &_bf54);
           #pragma omp section
               path11(c_1_1, _bf64, &_bf65);
           #pragma omp section
               path13(_bf71, _bf72, &_bf73);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path5(_bf27, _bf35, &c_0_1);
           #pragma omp section
               path9(_bf46, _bf54, &c_1_0);
           #pragma omp section
               path14(_bf65, _bf73, &c_1_1);
       }

       outputs[i * 12 + 0] = a_0_0;
       outputs[i * 12 + 1] = a_0_1;
       outputs[i * 12 + 2] = a_1_0;
       outputs[i * 12 + 3] = a_1_1;
       outputs[i * 12 + 4] = b_0_0;
       outputs[i * 12 + 5] = b_0_1;
       outputs[i * 12 + 6] = b_1_0;
       outputs[i * 12 + 7] = b_1_1;
       outputs[i * 12 + 8] = c_0_0;
       outputs[i * 12 + 9] = c_0_1;
       outputs[i * 12 + 10] = c_1_0;
       outputs[i * 12 + 11] = c_1_1;
    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
        printf("a_0_0: %i, a_0_1: %i, a_1_0: %i, a_1_1: %i, b_0_0: %i, b_0_1: %i, b_1_0: %i, b_1_1: %i, c_0_0: %i, c_0_1: %i, c_1_0: %i, c_1_1: %i", outputs[0], outputs[1], outputs[2], outputs[3], outputs[4], outputs[5], outputs[6], outputs[7], outputs[8], outputs[9], outputs[10], outputs[11]);
    }
}