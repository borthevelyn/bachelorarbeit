#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf10, int _bf9, int* _bf41, int* _bf34) { 
    int _bf11 = _bf9 + _bf10;
    *_bf34 = _bf11;
    *_bf41 = _bf11;
}
void path1(int _bf13, int _bf12, int* _bf62, int* _bf56) { 
    int _bf14 = _bf12 - _bf13;
    *_bf56 = _bf14;
    *_bf62 = _bf14;
}
void path2(int _bf48, int _bf31, int _bf30, int* y_4, int* _bf44) { 
    int _bf32 = _bf30 + _bf31;
    *_bf44 = _bf32;
    int _bf47 = _bf32;
    *y_4 = _bf47 - _bf48;
}
void path3(int _bf34, int _bf33, int* _bf48, int* _bf45) { 
    int _bf35 = _bf33 + _bf34;
    *_bf45 = _bf35;
    *_bf48 = _bf35;
}
void path4(int _bf37, int _bf36, int* _bf53, int* _bf50) { 
    int _bf38 = _bf36 - _bf37;
    *_bf50 = _bf38;
    *_bf53 = _bf38;
}
void path5(int _bf45, int _bf44, int* y_0) { 
    *y_0 = _bf44 + _bf45;
}
void path6(int _bf52, int _bf46, int _bf41, int _bf4, int _bf3, int* y_6, int* _bf51, int* _bf33) { 
    int _bf5 = _bf3 + _bf4;
    *_bf33 = _bf5;
    int _bf40 = _bf5;
    int _bf42 = _bf40 - _bf41;
    int _bf43 = _bf46 * _bf42;
    *_bf51 = _bf43;
    int _bf54 = _bf43;
    *y_6 = _bf52 - _bf54;
}
void path7(int _bf63, int _bf72, int* _bf79, int* _bf76) { 
    int _bf64 = _bf72 - _bf63;
    *_bf76 = _bf64;
    *_bf79 = _bf64;
}
void path8(int _bf83, int _bf81, int _bf67, int _bf66, int* y_7, int* _bf77) { 
    int _bf68 = _bf66 - _bf67;
    int _bf69 = _bf81 * _bf68;
    *_bf77 = _bf69;
    int _bf80 = _bf69;
    *y_7 = _bf83 - _bf80;
}
void path9(int _bf71, int _bf70, int* y_1) { 
    *y_1 = _bf70 + _bf71;
}
void path10(int _bf7, int _bf6, int* _bf37, int* _bf31) { 
    int _bf8 = _bf6 + _bf7;
    *_bf31 = _bf8;
    *_bf37 = _bf8;
}
void path11(int _bf1, int x_0, int* _bf36, int* _bf30, int* _bf12) { 
    int _bf0 = x_0;
    *_bf12 = x_0;
    int _bf2 = _bf0 + _bf1;
    *_bf30 = _bf2;
    *_bf36 = _bf2;
}
void path12(int x_4, int* _bf13, int* _bf1) { 
    *_bf1 = x_4;
    *_bf13 = x_4;
}
void path13(int _bf59, int w_3, int _bf26, int x_7, int* _bf74, int* _bf71, int* _bf67, int* _bf10) { 
    *_bf10 = x_7;
    int _bf27 = x_7;
    int _bf28 = _bf26 - _bf27;
    int _bf29 = w_3 * _bf28;
    int _bf60 = _bf29;
    *_bf67 = _bf29;
    int _bf61 = _bf59 + _bf60;
    *_bf71 = _bf61;
    *_bf74 = _bf61;
}
void path14(int w_2, int* _bf46, int* _bf65, int* _bf20) { 
    *_bf20 = w_2;
    int _bf123 = w_2;
    int _bf39 = _bf123;
    *_bf65 = _bf123;
    int _bf25 = _bf39;
    *_bf46 = _bf25;
}
void path15(int w_1, int _bf17, int x_1, int* _bf66, int* _bf59, int* _bf3) { 
    *_bf3 = x_1;
    int _bf16 = x_1;
    int _bf18 = _bf16 - _bf17;
    int _bf19 = w_1 * _bf18;
    *_bf59 = _bf19;
    *_bf66 = _bf19;
}
void path16(int x_5, int* _bf17, int* _bf4) { 
    *_bf4 = x_5;
    *_bf17 = x_5;
}
void path17(int _bf15, int _bf22, int x_2, int* _bf63, int* _bf57, int* _bf6) { 
    *_bf6 = x_2;
    int _bf21 = x_2;
    int _bf23 = _bf21 - _bf22;
    int _bf24 = _bf15 * _bf23;
    *_bf57 = _bf24;
    *_bf63 = _bf24;
}
void path18(int x_6, int* _bf22, int* _bf7) { 
    *_bf7 = x_6;
    *_bf22 = x_6;
}
void path19(int x_3, int* _bf26, int* _bf9) { 
    *_bf9 = x_3;
    *_bf26 = x_3;
}
void path20(int _bf20, int* _bf15) { 
    *_bf15 = _bf20;
}
void path21(int _bf51, int _bf50, int* y_2) { 
    int _bf49 = _bf50;
    *y_2 = _bf49 + _bf51;
}
void path22(int _bf53, int* _bf52) { 
    *_bf52 = _bf53;
}
void path23(int _bf74, int _bf57, int _bf56, int* y_5, int* _bf70) { 
    int _bf55 = _bf56;
    int _bf58 = _bf55 + _bf57;
    *_bf70 = _bf58;
    int _bf73 = _bf58;
    *y_5 = _bf73 - _bf74;
}
void path24(int _bf62, int* _bf72) { 
    *_bf72 = _bf62;
}
void path25(int _bf65, int* _bf81) { 
    int _bf75 = _bf65;
    int _bf78 = _bf75;
    *_bf81 = _bf78;
}
void path26(int _bf77, int _bf76, int* y_3) { 
    int _bf82 = _bf76;
    *y_3 = _bf82 + _bf77;
}
void path27(int _bf79, int* _bf83) { 
    *_bf83 = _bf79;
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


    int* inputs = new int[DATA_SIZE * 11 ]; 
    memset(inputs, 0, 11 * DATA_SIZE * sizeof(int));
    int* outputs = new int[DATA_SIZE * 8 ]; 
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int w_1 = inputs[i * 11 + 0];
       int w_2 = inputs[i * 11 + 1];
       int w_3 = inputs[i * 11 + 2];
       int x_0 = inputs[i * 11 + 3];
       int x_1 = inputs[i * 11 + 4];
       int x_2 = inputs[i * 11 + 5];
       int x_3 = inputs[i * 11 + 6];
       int x_4 = inputs[i * 11 + 7];
       int x_5 = inputs[i * 11 + 8];
       int x_6 = inputs[i * 11 + 9];
       int x_7 = inputs[i * 11 + 10];
       int _bf13;
       int _bf1;
       int _bf46;
       int _bf65;
       int _bf20;
       int _bf17;
       int _bf4;
       int _bf22;
       int _bf7;
       int _bf26;
       int _bf9;
       int _bf36;
       int _bf30;
       int _bf12;
       int _bf66;
       int _bf59;
       int _bf3;
       int _bf15;
       int _bf81;
       int _bf62;
       int _bf56;
       int _bf74;
       int _bf71;
       int _bf67;
       int _bf10;
       int _bf63;
       int _bf57;
       int _bf6;
       int _bf41;
       int _bf34;
       int _bf37;
       int _bf31;
       int y_5;
       int _bf70;
       int _bf72;
       int _bf53;
       int _bf50;
       int _bf79;
       int _bf76;
       int y_1;
       int _bf52;
       int _bf83;
       int y_6;
       int _bf51;
       int _bf33;
       int y_7;
       int _bf77;
       int _bf48;
       int _bf45;
       int y_2;
       int y_3;
       int y_4;
       int _bf44;
       int y_0;

       #pragma omp parallel sections
       {
           #pragma omp section
               path12(x_4, &_bf13, &_bf1);
           #pragma omp section
               path14(w_2, &_bf46, &_bf65, &_bf20);
           #pragma omp section
               path16(x_5, &_bf17, &_bf4);
           #pragma omp section
               path18(x_6, &_bf22, &_bf7);
           #pragma omp section
               path19(x_3, &_bf26, &_bf9);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path11(_bf1, x_0, &_bf36, &_bf30, &_bf12);
           #pragma omp section
               path15(w_1, _bf17, x_1, &_bf66, &_bf59, &_bf3);
           #pragma omp section
               path20(_bf20, &_bf15);
           #pragma omp section
               path25(_bf65, &_bf81);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf13, _bf12, &_bf62, &_bf56);
           #pragma omp section
               path13(_bf59, w_3, _bf26, x_7, &_bf74, &_bf71, &_bf67, &_bf10);
           #pragma omp section
               path17(_bf15, _bf22, x_2, &_bf63, &_bf57, &_bf6);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path0(_bf10, _bf9, &_bf41, &_bf34);
           #pragma omp section
               path10(_bf7, _bf6, &_bf37, &_bf31);
           #pragma omp section
               path23(_bf74, _bf57, _bf56, &y_5, &_bf70);
           #pragma omp section
               path24(_bf62, &_bf72);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path4(_bf37, _bf36, &_bf53, &_bf50);
           #pragma omp section
               path7(_bf63, _bf72, &_bf79, &_bf76);
           #pragma omp section
               path9(_bf71, _bf70, &y_1);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path22(_bf53, &_bf52);
           #pragma omp section
               path27(_bf79, &_bf83);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path6(_bf52, _bf46, _bf41, _bf4, _bf3, &y_6, &_bf51, &_bf33);
           #pragma omp section
               path8(_bf83, _bf81, _bf67, _bf66, &y_7, &_bf77);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path3(_bf34, _bf33, &_bf48, &_bf45);
           #pragma omp section
               path21(_bf51, _bf50, &y_2);
           #pragma omp section
               path26(_bf77, _bf76, &y_3);
       }
       path2(_bf48, _bf31, _bf30, &y_4, &_bf44);
       path5(_bf45, _bf44, &y_0);

       outputs[i * 8 + 0] = y_0;
       outputs[i * 8 + 1] = y_1;
       outputs[i * 8 + 2] = y_2;
       outputs[i * 8 + 3] = y_3;
       outputs[i * 8 + 4] = y_4;
       outputs[i * 8 + 5] = y_5;
       outputs[i * 8 + 6] = y_6;
       outputs[i * 8 + 7] = y_7;
    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
        printf("y_0: %i, y_1: %i, y_2: %i, y_3: %i, y_4: %i, y_5: %i, y_6: %i, y_7: %i", outputs[0], outputs[1], outputs[2], outputs[3], outputs[4], outputs[5], outputs[6], outputs[7]);
    }
}