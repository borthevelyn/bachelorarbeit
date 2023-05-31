#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf97, int _bf95, int* _bf102) { 
    *_bf102 = _bf97 * _bf95;
}
void path1(int _bf94, int _bf0, int* _bf103) { 
    *_bf103 = _bf94 + _bf0;
}
void path2(int* _bf104) { 
    *_bf104 = 0;
}
void path3(int _bf104, int* c, int _bf49, int** _bf108) { 
    c[_bf104] = _bf49;
    *_bf108 = c;
}
void path4(int* _bf109) { 
    *_bf109 = 1;
}
void path5(int _bf109, int* _bf2, int _bf67, int** _bf113) { 
    _bf2[_bf109] = _bf67;
    *_bf113 = _bf2;
}
void path6(int* _bf114) { 
    *_bf114 = 2;
}
void path7(int _bf114, int* _bf113, int _bf10, int** _bf118) { 
    _bf113[_bf114] = _bf10;
    *_bf118 = _bf113;
}
void path8(int* _bf119) { 
    *_bf119 = 3;
}
void path9(int* _bf12) { 
    *_bf12 = 2;
}
void path10(int* _bf24) { 
    *_bf24 = 2;
}
void path11(int* _bf28) { 
    *_bf28 = 1;
}
void path12(int* _bf36) { 
    *_bf36 = 0;
}
void path13(int _bf34, int _bf32, int* _bf39) { 
    *_bf39 = _bf34 * _bf32;
}
void path14(int* _bf4) { 
    *_bf4 = 1;
}
void path15(int _bf36, int _bf39, int* _bf40) { 
    *_bf40 = _bf36 + _bf39;
}
void path16(int _bf46, int _bf47, int* _bf48) { 
    *_bf48 = _bf46 * _bf47;
}
void path17(int _bf40, int _bf48, int* _bf49) { 
    *_bf49 = _bf40 + _bf48;
}
void path18(int* _bf54) { 
    *_bf54 = 0;
}
void path19(int _bf52, int _bf3, int* _bf57) { 
    *_bf57 = _bf52 * _bf3;
}
void path20(int _bf54, int _bf57, int* _bf58) { 
    *_bf58 = _bf54 + _bf57;
}
void path21(int _bf61, int _bf65, int* _bf66) { 
    *_bf66 = _bf61 * _bf65;
}
void path22(int _bf58, int _bf5, int* _bf67) { 
    *_bf67 = _bf58 + _bf5;
}
void path23(int* _bf72) { 
    *_bf72 = 0;
}
void path24(int _bf8, int _bf68, int* _bf75) { 
    *_bf75 = _bf8 * _bf68;
}
void path25(int _bf72, int _bf75, int* _bf76) { 
    *_bf76 = _bf72 + _bf75;
}
void path26(int _bf82, int _bf77, int* _bf84) { 
    *_bf84 = _bf82 * _bf77;
}
void path27(int _bf76, int _bf9, int* _bf85) { 
    *_bf85 = _bf76 + _bf9;
}
void path28(int* _bf90) { 
    *_bf90 = 0;
}
void path29(int _bf88, int _bf86, int* _bf93) { 
    *_bf93 = _bf88 * _bf86;
}
void path30(int _bf90, int _bf93, int* _bf94) { 
    *_bf94 = _bf90 + _bf93;
}
void path31(int _bf119, int* _bf118, int _bf1, int** c) { 
    _bf118[_bf119] = _bf1;
    *c = _bf118;
}
void path32(int _bf24, int* b, int** _bf26, int* _bf27) { 
    *_bf27 = b[_bf24];
    *_bf26 = b;
}
void path33(int _bf27, int* _bf32, int* _bf41) { 
    *_bf32 = _bf27;
    *_bf41 = _bf27;
}
void path34(int _bf7, int* _bf34, int* _bf43) { 
    *_bf34 = _bf7;
    *_bf43 = _bf7;
}
void path35(int _bf43, int* _bf46, int* _bf139) { 
    *_bf46 = _bf43;
    *_bf139 = _bf43;
}
void path36(int _bf41, int* _bf47, int* _bf134) { 
    *_bf47 = _bf41;
    *_bf134 = _bf41;
}
void path37(int _bf31, int* _bf50, int* _bf59) { 
    *_bf50 = _bf31;
    *_bf59 = _bf31;
}
void path38(int _bf139, int* _bf52, int* _bf61) { 
    *_bf52 = _bf139;
    *_bf61 = _bf139;
}
void path39(int _bf4, int* a, int** _bf6, int* _bf7) { 
    *_bf7 = a[_bf4];
    *_bf6 = a;
}
void path40(int _bf59, int* _bf65, int* _bf128) { 
    *_bf65 = _bf59;
    *_bf128 = _bf59;
}
void path41(int _bf134, int* _bf68, int* _bf77) { 
    *_bf68 = _bf134;
    *_bf77 = _bf134;
}
void path42(int _bf15, int* _bf70, int* _bf79) { 
    *_bf70 = _bf15;
    *_bf79 = _bf15;
}
void path43(int _bf79, int* _bf82, int* _bf127) { 
    *_bf82 = _bf79;
    *_bf127 = _bf79;
}
void path44(int _bf128, int* _bf86, int* _bf95) { 
    *_bf86 = _bf128;
    *_bf95 = _bf128;
}
void path45(int _bf127, int* _bf88, int* _bf97) { 
    *_bf88 = _bf127;
    *_bf97 = _bf127;
}
void path46(int _bf12, int* _bf6, int** a, int* _bf15) { 
    *_bf15 = _bf6[_bf12];
    *a = _bf6;
}
void path47(int _bf28, int* _bf26, int** b, int* _bf31) { 
    *_bf31 = _bf26[_bf28];
    *b = _bf26;
}
void path48(int _bf102, int* _bf0) { 
    *_bf0 = _bf102;
}
void path49(int _bf103, int* _bf1) { 
    *_bf1 = _bf103;
}
void path50(int* _bf108, int** _bf2) { 
    *_bf2 = _bf108;
}
void path51(int _bf50, int* _bf3) { 
    *_bf3 = _bf50;
}
void path52(int _bf66, int* _bf5) { 
    *_bf5 = _bf66;
}
void path53(int _bf70, int* _bf8) { 
    *_bf8 = _bf70;
}
void path54(int _bf84, int* _bf9) { 
    *_bf9 = _bf84;
}
void path55(int _bf85, int* _bf10) { 
    *_bf10 = _bf85;
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
       int _bf104;
       int _bf109;
       int _bf114;
       int _bf119;
       int _bf12;
       int _bf24;
       int _bf28;
       int _bf36;
       int _bf4;
       int _bf54;
       int _bf72;
       int _bf90;
       int* _bf26;
       int _bf27;
       int* _bf6;
       int _bf7;
       int _bf32;
       int _bf41;
       int _bf34;
       int _bf43;
       int* a = a_arr + i * 4;
       int _bf15;
       int* b = b_arr + i * 4;
       int _bf31;
       int _bf39;
       int _bf46;
       int _bf139;
       int _bf47;
       int _bf134;
       int _bf50;
       int _bf59;
       int _bf70;
       int _bf79;
       int _bf40;
       int _bf48;
       int _bf52;
       int _bf61;
       int _bf65;
       int _bf128;
       int _bf68;
       int _bf77;
       int _bf82;
       int _bf127;
       int _bf3;
       int _bf8;
       int _bf49;
       int _bf57;
       int _bf66;
       int _bf75;
       int _bf84;
       int _bf86;
       int _bf95;
       int _bf88;
       int _bf97;
       int _bf102;
       int* _bf108;
       int _bf58;
       int _bf76;
       int _bf93;
       int _bf5;
       int _bf9;
       int _bf67;
       int _bf85;
       int _bf94;
       int _bf0;
       int* _bf2;
       int _bf103;
       int* _bf113;
       int _bf10;
       int* _bf118;
       int _bf1;
       int* c = c_arr + i * 4;

       #pragma omp parallel sections
       {
           #pragma omp section
               path2(&_bf104);
           #pragma omp section
               path4(&_bf109);
           #pragma omp section
               path6(&_bf114);
           #pragma omp section
               path8(&_bf119);
           #pragma omp section
               path9(&_bf12);
           #pragma omp section
               path10(&_bf24);
           #pragma omp section
               path11(&_bf28);
           #pragma omp section
               path12(&_bf36);
           #pragma omp section
               path14(&_bf4);
           #pragma omp section
               path18(&_bf54);
           #pragma omp section
               path23(&_bf72);
           #pragma omp section
               path28(&_bf90);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path32(_bf24, b, &_bf26, &_bf27);
           #pragma omp section
               path39(_bf4, a, &_bf6, &_bf7);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path33(_bf27, &_bf32, &_bf41);
           #pragma omp section
               path34(_bf7, &_bf34, &_bf43);
           #pragma omp section
               path46(_bf12, _bf6, &a, &_bf15);
           #pragma omp section
               path47(_bf28, _bf26, &b, &_bf31);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path13(_bf34, _bf32, &_bf39);
           #pragma omp section
               path35(_bf43, &_bf46, &_bf139);
           #pragma omp section
               path36(_bf41, &_bf47, &_bf134);
           #pragma omp section
               path37(_bf31, &_bf50, &_bf59);
           #pragma omp section
               path42(_bf15, &_bf70, &_bf79);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path15(_bf36, _bf39, &_bf40);
           #pragma omp section
               path16(_bf46, _bf47, &_bf48);
           #pragma omp section
               path38(_bf139, &_bf52, &_bf61);
           #pragma omp section
               path40(_bf59, &_bf65, &_bf128);
           #pragma omp section
               path41(_bf134, &_bf68, &_bf77);
           #pragma omp section
               path43(_bf79, &_bf82, &_bf127);
           #pragma omp section
               path51(_bf50, &_bf3);
           #pragma omp section
               path53(_bf70, &_bf8);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path17(_bf40, _bf48, &_bf49);
           #pragma omp section
               path19(_bf52, _bf3, &_bf57);
           #pragma omp section
               path21(_bf61, _bf65, &_bf66);
           #pragma omp section
               path24(_bf8, _bf68, &_bf75);
           #pragma omp section
               path26(_bf82, _bf77, &_bf84);
           #pragma omp section
               path44(_bf128, &_bf86, &_bf95);
           #pragma omp section
               path45(_bf127, &_bf88, &_bf97);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path0(_bf97, _bf95, &_bf102);
           #pragma omp section
               path3(_bf104, c, _bf49, &_bf108);
           #pragma omp section
               path20(_bf54, _bf57, &_bf58);
           #pragma omp section
               path25(_bf72, _bf75, &_bf76);
           #pragma omp section
               path29(_bf88, _bf86, &_bf93);
           #pragma omp section
               path52(_bf66, &_bf5);
           #pragma omp section
               path54(_bf84, &_bf9);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path22(_bf58, _bf5, &_bf67);
           #pragma omp section
               path27(_bf76, _bf9, &_bf85);
           #pragma omp section
               path30(_bf90, _bf93, &_bf94);
           #pragma omp section
               path48(_bf102, &_bf0);
           #pragma omp section
               path50(_bf108, &_bf2);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf94, _bf0, &_bf103);
           #pragma omp section
               path5(_bf109, _bf2, _bf67, &_bf113);
           #pragma omp section
               path55(_bf85, &_bf10);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path7(_bf114, _bf113, _bf10, &_bf118);
           #pragma omp section
               path49(_bf103, &_bf1);
       }
       path31(_bf119, _bf118, _bf1, &c);

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