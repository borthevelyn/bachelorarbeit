#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int* _bf0) { 
    *_bf0 = 0;
}
void path1(int* _bf12) { 
    *_bf12 = 3;
}
void path2(int* _bf16) { 
    *_bf16 = 0;
}
void path3(int* _bf20) { 
    *_bf20 = 1;
}
void path4(int* _bf24) { 
    *_bf24 = 2;
}
void path5(int* _bf28) { 
    *_bf28 = 3;
}
void path6(int _bf32, int _bf33, int* _bf34) { 
    *_bf34 = _bf32 * _bf33;
}
void path7(int _bf9, int _bf36, int* _bf37) { 
    *_bf37 = _bf9 * _bf36;
}
void path8(int* _bf4) { 
    *_bf4 = 1;
}
void path9(int _bf5, int _bf37, int* _bf40) { 
    *_bf40 = _bf5 + _bf37;
}
void path10(int _bf13, int _bf42, int* _bf43) { 
    *_bf43 = _bf13 * _bf42;
}
void path11(int _bf25, int _bf45, int* _bf46) { 
    *_bf46 = _bf25 * _bf45;
}
void path12(int _bf17, int _bf46, int* _bf49) { 
    *_bf49 = _bf17 + _bf46;
}
void path13(int _bf50, int _bf30, int* _bf52) { 
    *_bf52 = _bf50 * _bf30;
}
void path14(int _bf53, int _bf39, int* _bf55) { 
    *_bf55 = _bf53 * _bf39;
}
void path15(int _bf38, int _bf55, int* _bf58) { 
    *_bf58 = _bf38 + _bf55;
}
void path16(int _bf59, int _bf48, int* _bf61) { 
    *_bf61 = _bf59 * _bf48;
}
void path17(int _bf62, int _bf63, int* _bf64) { 
    *_bf64 = _bf62 * _bf63;
}
void path18(int _bf56, int _bf64, int* _bf67) { 
    *_bf67 = _bf56 + _bf64;
}
void path19(int* _bf68) { 
    *_bf68 = 0;
}
void path20(int _bf68, int* c, int _bf40, int** _bf72) { 
    c[_bf68] = _bf40;
    *_bf72 = c;
}
void path21(int* _bf73) { 
    *_bf73 = 1;
}
void path22(int _bf73, int* _bf72, int _bf49, int** _bf77) { 
    _bf72[_bf73] = _bf49;
    *_bf77 = _bf72;
}
void path23(int* _bf78) { 
    *_bf78 = 2;
}
void path24(int* _bf8) { 
    *_bf8 = 2;
}
void path25(int _bf78, int* _bf77, int _bf47, int** _bf82) { 
    _bf77[_bf78] = _bf47;
    *_bf82 = _bf77;
}
void path26(int* _bf83) { 
    *_bf83 = 3;
}
void path27(int _bf83, int* _bf82, int _bf65, int** c) { 
    _bf82[_bf83] = _bf65;
    *c = _bf82;
}
void path28(int _bf8, int* _bf6, int** _bf10, int* _bf11) { 
    *_bf11 = _bf6[_bf8];
    *_bf10 = _bf6;
}
void path29(int _bf16, int* b, int** _bf18, int* _bf19) { 
    *_bf19 = b[_bf16];
    *_bf18 = b;
}
void path30(int _bf0, int* a, int** _bf2, int* _bf3) { 
    *_bf3 = a[_bf0];
    *_bf2 = a;
}
void path31(int _bf20, int* _bf18, int** _bf22, int* _bf23) { 
    *_bf23 = _bf18[_bf20];
    *_bf22 = _bf18;
}
void path32(int _bf24, int* _bf22, int** _bf26, int* _bf27) { 
    *_bf27 = _bf22[_bf24];
    *_bf26 = _bf22;
}
void path33(int _bf3, int* _bf32, int* _bf41) { 
    *_bf32 = _bf3;
    *_bf41 = _bf3;
}
void path34(int _bf19, int* _bf33, int* _bf51) { 
    *_bf33 = _bf19;
    *_bf51 = _bf19;
}
void path35(int _bf7, int* _bf35, int* _bf44) { 
    *_bf35 = _bf7;
    *_bf44 = _bf7;
}
void path36(int _bf27, int* _bf36, int* _bf54) { 
    *_bf36 = _bf27;
    *_bf54 = _bf27;
}
void path37(int _bf23, int* _bf42, int* _bf60) { 
    *_bf42 = _bf23;
    *_bf60 = _bf23;
}
void path38(int _bf31, int* _bf45, int* _bf63) { 
    *_bf45 = _bf31;
    *_bf63 = _bf31;
}
void path39(int _bf11, int* _bf50, int* _bf59) { 
    *_bf50 = _bf11;
    *_bf59 = _bf11;
}
void path40(int _bf15, int* _bf53, int* _bf62) { 
    *_bf53 = _bf15;
    *_bf62 = _bf15;
}
void path41(int _bf4, int* _bf2, int** _bf6, int* _bf7) { 
    *_bf7 = _bf2[_bf4];
    *_bf6 = _bf2;
}
void path42(int _bf12, int* _bf10, int** a, int* _bf15) { 
    *_bf15 = _bf10[_bf12];
    *a = _bf10;
}
void path43(int _bf28, int* _bf26, int** b, int* _bf31) { 
    *_bf31 = _bf26[_bf28];
    *b = _bf26;
}
void path44(int _bf34, int* _bf1) { 
    *_bf1 = _bf34;
}
void path45(int _bf1, int* _bf5) { 
    *_bf5 = _bf1;
}
void path46(int _bf35, int* _bf9) { 
    *_bf9 = _bf35;
}
void path47(int _bf41, int* _bf13) { 
    *_bf13 = _bf41;
}
void path48(int _bf43, int* _bf14) { 
    *_bf14 = _bf43;
}
void path49(int _bf14, int* _bf17) { 
    *_bf17 = _bf14;
}
void path50(int _bf44, int* _bf21) { 
    *_bf21 = _bf44;
}
void path51(int _bf21, int* _bf25) { 
    *_bf25 = _bf21;
}
void path52(int _bf51, int* _bf29) { 
    *_bf29 = _bf51;
}
void path53(int _bf29, int* _bf30) { 
    *_bf30 = _bf29;
}
void path54(int _bf52, int* _bf38) { 
    *_bf38 = _bf52;
}
void path55(int _bf54, int* _bf39) { 
    *_bf39 = _bf54;
}
void path56(int _bf58, int* _bf47) { 
    *_bf47 = _bf58;
}
void path57(int _bf60, int* _bf48) { 
    *_bf48 = _bf60;
}
void path58(int _bf61, int* _bf56) { 
    *_bf56 = _bf61;
}
void path59(int _bf67, int* _bf57) { 
    *_bf57 = _bf67;
}
void path60(int _bf57, int* _bf65) { 
    *_bf65 = _bf57;
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

    int* a_arr = new int[4 * DATA_SIZE];
    int* b_arr = new int[4 * DATA_SIZE];
    int* c_arr = new int[4 * DATA_SIZE];
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int _bf0;
       int _bf12;
       int _bf16;
       int _bf20;
       int _bf24;
       int _bf28;
       int _bf4;
       int _bf68;
       int _bf73;
       int _bf78;
       int _bf8;
       int _bf83;
       int* _bf18;
       int _bf19;
       int* _bf2;
       int _bf3;
       int* _bf22;
       int _bf23;
       int _bf32;
       int _bf41;
       int _bf33;
       int _bf51;
       int* _bf6;
       int _bf7;
       int _bf34;
       int* _bf10;
       int _bf11;
       int* _bf26;
       int _bf27;
       int _bf35;
       int _bf44;
       int _bf42;
       int _bf60;
       int _bf13;
       int _bf29;
       int _bf43;
       int _bf36;
       int _bf54;
       int _bf50;
       int _bf59;
       int* a = a_arr + i * 4;
       int _bf15;
       int* b = b_arr + i * 4;
       int _bf31;
       int _bf1;
       int _bf9;
       int _bf21;
       int _bf30;
       int _bf48;
       int _bf37;
       int _bf52;
       int _bf61;
       int _bf45;
       int _bf63;
       int _bf53;
       int _bf62;
       int _bf5;
       int _bf14;
       int _bf25;
       int _bf39;
       int _bf40;
       int _bf46;
       int _bf55;
       int _bf64;
       int _bf17;
       int _bf38;
       int _bf56;
       int _bf49;
       int _bf58;
       int _bf67;
       int* _bf72;
       int* _bf77;
       int _bf47;
       int _bf57;
       int* _bf82;
       int _bf65;
       int* c = c_arr + i * 4;

       #pragma omp parallel sections
       {
           #pragma omp section
               path0(&_bf0);
           #pragma omp section
               path1(&_bf12);
           #pragma omp section
               path2(&_bf16);
           #pragma omp section
               path3(&_bf20);
           #pragma omp section
               path4(&_bf24);
           #pragma omp section
               path5(&_bf28);
           #pragma omp section
               path8(&_bf4);
           #pragma omp section
               path19(&_bf68);
           #pragma omp section
               path21(&_bf73);
           #pragma omp section
               path23(&_bf78);
           #pragma omp section
               path24(&_bf8);
           #pragma omp section
               path26(&_bf83);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path29(_bf16, b, &_bf18, &_bf19);
           #pragma omp section
               path30(_bf0, a, &_bf2, &_bf3);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path31(_bf20, _bf18, &_bf22, &_bf23);
           #pragma omp section
               path33(_bf3, &_bf32, &_bf41);
           #pragma omp section
               path34(_bf19, &_bf33, &_bf51);
           #pragma omp section
               path41(_bf4, _bf2, &_bf6, &_bf7);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path6(_bf32, _bf33, &_bf34);
           #pragma omp section
               path28(_bf8, _bf6, &_bf10, &_bf11);
           #pragma omp section
               path32(_bf24, _bf22, &_bf26, &_bf27);
           #pragma omp section
               path35(_bf7, &_bf35, &_bf44);
           #pragma omp section
               path37(_bf23, &_bf42, &_bf60);
           #pragma omp section
               path47(_bf41, &_bf13);
           #pragma omp section
               path52(_bf51, &_bf29);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path10(_bf13, _bf42, &_bf43);
           #pragma omp section
               path36(_bf27, &_bf36, &_bf54);
           #pragma omp section
               path39(_bf11, &_bf50, &_bf59);
           #pragma omp section
               path42(_bf12, _bf10, &a, &_bf15);
           #pragma omp section
               path43(_bf28, _bf26, &b, &_bf31);
           #pragma omp section
               path44(_bf34, &_bf1);
           #pragma omp section
               path46(_bf35, &_bf9);
           #pragma omp section
               path50(_bf44, &_bf21);
           #pragma omp section
               path53(_bf29, &_bf30);
           #pragma omp section
               path57(_bf60, &_bf48);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path7(_bf9, _bf36, &_bf37);
           #pragma omp section
               path13(_bf50, _bf30, &_bf52);
           #pragma omp section
               path16(_bf59, _bf48, &_bf61);
           #pragma omp section
               path38(_bf31, &_bf45, &_bf63);
           #pragma omp section
               path40(_bf15, &_bf53, &_bf62);
           #pragma omp section
               path45(_bf1, &_bf5);
           #pragma omp section
               path48(_bf43, &_bf14);
           #pragma omp section
               path51(_bf21, &_bf25);
           #pragma omp section
               path55(_bf54, &_bf39);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path9(_bf5, _bf37, &_bf40);
           #pragma omp section
               path11(_bf25, _bf45, &_bf46);
           #pragma omp section
               path14(_bf53, _bf39, &_bf55);
           #pragma omp section
               path17(_bf62, _bf63, &_bf64);
           #pragma omp section
               path49(_bf14, &_bf17);
           #pragma omp section
               path54(_bf52, &_bf38);
           #pragma omp section
               path58(_bf61, &_bf56);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path12(_bf17, _bf46, &_bf49);
           #pragma omp section
               path15(_bf38, _bf55, &_bf58);
           #pragma omp section
               path18(_bf56, _bf64, &_bf67);
           #pragma omp section
               path20(_bf68, c, _bf40, &_bf72);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path22(_bf73, _bf72, _bf49, &_bf77);
           #pragma omp section
               path56(_bf58, &_bf47);
           #pragma omp section
               path59(_bf67, &_bf57);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path25(_bf78, _bf77, _bf47, &_bf82);
           #pragma omp section
               path60(_bf57, &_bf65);
       }
       path27(_bf83, _bf82, _bf65, &c);

    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
           cout << "\na: ";
       for(int i = 0; i < 4 * DATA_SIZE; i++) {
           cout << a_arr[i] << " ";
       }
       cout << "\nb: ";
       for(int i = 0; i < 4 * DATA_SIZE; i++) {
           cout << b_arr[i] << " ";
       }
       cout << "\nc: ";
       for(int i = 0; i < 4 * DATA_SIZE; i++) {
           cout << c_arr[i] << " ";
       }
    }
}