#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(bool _bf7, int _bf92, int _bf93, int* _bf10) { 
    if ( _bf7 ) {
        *_bf10 = _bf92;
    } else  { 
        *_bf10 = _bf93;
    } 
}
void path1(int _bf11, int _bf12, bool* _bf13) { 
    *_bf13 = _bf11 < _bf12;
}
void path2(bool _bf14, int _bf50, int _bf54, int* _bf17) { 
    if ( _bf14 ) {
        *_bf17 = _bf50;
    } else  { 
        *_bf17 = _bf54;
    } 
}
void path3(int _bf0, int _bf1, bool* _bf2) { 
    *_bf2 = _bf0 < _bf1;
}
void path4(bool _bf18, int _bf61, int _bf65, int* _bf21) { 
    if ( _bf18 ) {
        *_bf21 = _bf61;
    } else  { 
        *_bf21 = _bf65;
    } 
}
void path5(int _bf22, int _bf23, bool* _bf24) { 
    *_bf24 = _bf22 < _bf23;
}
void path6(bool _bf25, int _bf66, int _bf69, int* _bf28) { 
    if ( _bf25 ) {
        *_bf28 = _bf66;
    } else  { 
        *_bf28 = _bf69;
    } 
}
void path7(bool _bf29, int _bf70, int _bf71, int* _bf32) { 
    if ( _bf29 ) {
        *_bf32 = _bf70;
    } else  { 
        *_bf32 = _bf71;
    } 
}
void path8(int _bf33, int _bf34, bool* _bf35) { 
    *_bf35 = _bf33 < _bf34;
}
void path9(bool _bf36, int _bf72, int _bf75, int* _bf39) { 
    if ( _bf36 ) {
        *_bf39 = _bf72;
    } else  { 
        *_bf39 = _bf75;
    } 
}
void path10(bool _bf40, int _bf77, int _bf78, int* _bf43) { 
    if ( _bf40 ) {
        *_bf43 = _bf77;
    } else  { 
        *_bf43 = _bf78;
    } 
}
void path11(int _bf44, int _bf45, bool* _bf46) { 
    *_bf46 = _bf44 < _bf45;
}
void path12(int _bf55, int _bf56, bool* _bf57) { 
    *_bf57 = _bf55 < _bf56;
}
void path13(bool _bf3, int _bf76, int _bf83, int* _bf6) { 
    if ( _bf3 ) {
        *_bf6 = _bf76;
    } else  { 
        *_bf6 = _bf83;
    } 
}
void path14(bool _bf47, int _bf79, int _bf80, int* x_0_3) { 
    if ( _bf47 ) {
        *x_0_3 = _bf79;
    } else  { 
        *x_0_3 = _bf80;
    } 
}
void path15(bool _bf51, int _bf84, int _bf85, int* x_1_3) { 
    if ( _bf51 ) {
        *x_1_3 = _bf84;
    } else  { 
        *x_1_3 = _bf85;
    } 
}
void path16(bool _bf62, int _bf88, int _bf91, int* x_2_3) { 
    if ( _bf62 ) {
        *x_2_3 = _bf88;
    } else  { 
        *x_2_3 = _bf91;
    } 
}
void path17(bool _bf58, int _bf86, int _bf87, int* x_3_3) { 
    if ( _bf58 ) {
        *x_3_3 = _bf86;
    } else  { 
        *x_3_3 = _bf87;
    } 
}
void path18(int x_0_0, int* _bf0, int* _bf105) { 
    *_bf0 = x_0_0;
    *_bf105 = x_0_0;
}
void path19(int x_1_0, int* _bf1, int* _bf106) { 
    *_bf1 = x_1_0;
    *_bf106 = x_1_0;
}
void path20(int x_2_0, int* _bf11, int* _bf97) { 
    *_bf11 = x_2_0;
    *_bf97 = x_2_0;
}
void path21(int x_3_0, int* _bf12, int* _bf98) { 
    *_bf12 = x_3_0;
    *_bf98 = x_3_0;
}
void path22(bool _bf13, bool* _bf14, bool* _bf18) { 
    *_bf14 = _bf13;
    *_bf18 = _bf13;
}
void path23(int _bf97, int* _bf15, int* _bf20) { 
    *_bf15 = _bf97;
    *_bf20 = _bf97;
}
void path24(int _bf98, int* _bf16, int* _bf19) { 
    *_bf16 = _bf98;
    *_bf19 = _bf98;
}
void path25(int _bf6, int* _bf22, int* _bf89) { 
    *_bf22 = _bf6;
    *_bf89 = _bf6;
}
void path26(int _bf21, int* _bf23, int* _bf90) { 
    *_bf23 = _bf21;
    *_bf90 = _bf21;
}
void path27(bool _bf24, bool* _bf25, bool* _bf29) { 
    *_bf25 = _bf24;
    *_bf29 = _bf24;
}
void path28(int _bf89, int* _bf26, int* _bf31) { 
    *_bf26 = _bf89;
    *_bf31 = _bf89;
}
void path29(int _bf90, int* _bf27, int* _bf30) { 
    *_bf27 = _bf90;
    *_bf30 = _bf90;
}
void path30(bool _bf2, bool* _bf3, bool* _bf7) { 
    *_bf3 = _bf2;
    *_bf7 = _bf2;
}
void path31(int _bf10, int* _bf33, int* _bf81) { 
    *_bf33 = _bf10;
    *_bf81 = _bf10;
}
void path32(int _bf17, int* _bf34, int* _bf82) { 
    *_bf34 = _bf17;
    *_bf82 = _bf17;
}
void path33(bool _bf35, bool* _bf36, bool* _bf40) { 
    *_bf36 = _bf35;
    *_bf40 = _bf35;
}
void path34(int _bf81, int* _bf37, int* _bf42) { 
    *_bf37 = _bf81;
    *_bf42 = _bf81;
}
void path35(int _bf82, int* _bf38, int* _bf41) { 
    *_bf38 = _bf82;
    *_bf41 = _bf82;
}
void path36(int _bf105, int* _bf4, int* _bf9) { 
    *_bf4 = _bf105;
    *_bf9 = _bf105;
}
void path37(int _bf28, int* _bf44, int* _bf73) { 
    *_bf44 = _bf28;
    *_bf73 = _bf28;
}
void path38(int _bf39, int* _bf45, int* _bf74) { 
    *_bf45 = _bf39;
    *_bf74 = _bf39;
}
void path39(bool _bf46, bool* _bf47, bool* _bf51) { 
    *_bf47 = _bf46;
    *_bf51 = _bf46;
}
void path40(int _bf73, int* _bf48, int* _bf53) { 
    *_bf48 = _bf73;
    *_bf53 = _bf73;
}
void path41(int _bf74, int* _bf49, int* _bf52) { 
    *_bf49 = _bf74;
    *_bf52 = _bf74;
}
void path42(int _bf106, int* _bf5, int* _bf8) { 
    *_bf5 = _bf106;
    *_bf8 = _bf106;
}
void path43(int _bf32, int* _bf55, int* _bf68) { 
    *_bf55 = _bf32;
    *_bf68 = _bf32;
}
void path44(int _bf43, int* _bf56, int* _bf67) { 
    *_bf56 = _bf43;
    *_bf67 = _bf43;
}
void path45(bool _bf57, bool* _bf58, bool* _bf62) { 
    *_bf58 = _bf57;
    *_bf62 = _bf57;
}
void path46(int _bf68, int* _bf59, int* _bf64) { 
    *_bf59 = _bf68;
    *_bf64 = _bf68;
}
void path47(int _bf67, int* _bf60, int* _bf63) { 
    *_bf60 = _bf67;
    *_bf63 = _bf67;
}
void path48(int _bf15, int* _bf50) { 
    *_bf50 = _bf15;
}
void path49(int _bf16, int* _bf54) { 
    *_bf54 = _bf16;
}
void path50(int _bf19, int* _bf61) { 
    *_bf61 = _bf19;
}
void path51(int _bf20, int* _bf65) { 
    *_bf65 = _bf20;
}
void path52(int _bf26, int* _bf66) { 
    *_bf66 = _bf26;
}
void path53(int _bf27, int* _bf69) { 
    *_bf69 = _bf27;
}
void path54(int _bf30, int* _bf70) { 
    *_bf70 = _bf30;
}
void path55(int _bf31, int* _bf71) { 
    *_bf71 = _bf31;
}
void path56(int _bf37, int* _bf72) { 
    *_bf72 = _bf37;
}
void path57(int _bf38, int* _bf75) { 
    *_bf75 = _bf38;
}
void path58(int _bf4, int* _bf76) { 
    *_bf76 = _bf4;
}
void path59(int _bf41, int* _bf77) { 
    *_bf77 = _bf41;
}
void path60(int _bf42, int* _bf78) { 
    *_bf78 = _bf42;
}
void path61(int _bf48, int* _bf79) { 
    *_bf79 = _bf48;
}
void path62(int _bf49, int* _bf80) { 
    *_bf80 = _bf49;
}
void path63(int _bf5, int* _bf83) { 
    *_bf83 = _bf5;
}
void path64(int _bf52, int* _bf84) { 
    *_bf84 = _bf52;
}
void path65(int _bf53, int* _bf85) { 
    *_bf85 = _bf53;
}
void path66(int _bf59, int* _bf86) { 
    *_bf86 = _bf59;
}
void path67(int _bf60, int* _bf87) { 
    *_bf87 = _bf60;
}
void path68(int _bf63, int* _bf88) { 
    *_bf88 = _bf63;
}
void path69(int _bf64, int* _bf91) { 
    *_bf91 = _bf64;
}
void path70(int _bf8, int* _bf92) { 
    *_bf92 = _bf8;
}
void path71(int _bf9, int* _bf93) { 
    *_bf93 = _bf9;
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


    int* inputs = new int[DATA_SIZE * 4 ]; 
    memset(inputs, 0, 4 * DATA_SIZE * sizeof(int));
    int* outputs = new int[DATA_SIZE * 4 ]; 
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int x_0_0 = inputs[i * 4 + 0];
       int x_1_0 = inputs[i * 4 + 1];
       int x_2_0 = inputs[i * 4 + 2];
       int x_3_0 = inputs[i * 4 + 3];
       int _bf0;
       int _bf105;
       int _bf1;
       int _bf106;
       int _bf11;
       int _bf97;
       int _bf12;
       int _bf98;
       bool _bf13;
       bool _bf2;
       int _bf15;
       int _bf20;
       int _bf16;
       int _bf19;
       int _bf4;
       int _bf9;
       int _bf5;
       int _bf8;
       bool _bf14;
       bool _bf18;
       bool _bf3;
       bool _bf7;
       int _bf50;
       int _bf54;
       int _bf61;
       int _bf65;
       int _bf76;
       int _bf83;
       int _bf92;
       int _bf93;
       int _bf10;
       int _bf17;
       int _bf21;
       int _bf6;
       int _bf22;
       int _bf89;
       int _bf23;
       int _bf90;
       int _bf33;
       int _bf81;
       int _bf34;
       int _bf82;
       bool _bf24;
       bool _bf35;
       int _bf26;
       int _bf31;
       int _bf27;
       int _bf30;
       int _bf37;
       int _bf42;
       int _bf38;
       int _bf41;
       bool _bf25;
       bool _bf29;
       bool _bf36;
       bool _bf40;
       int _bf66;
       int _bf69;
       int _bf70;
       int _bf71;
       int _bf72;
       int _bf75;
       int _bf77;
       int _bf78;
       int _bf28;
       int _bf32;
       int _bf39;
       int _bf43;
       int _bf44;
       int _bf73;
       int _bf45;
       int _bf74;
       int _bf55;
       int _bf68;
       int _bf56;
       int _bf67;
       bool _bf46;
       bool _bf57;
       int _bf48;
       int _bf53;
       int _bf49;
       int _bf52;
       int _bf59;
       int _bf64;
       int _bf60;
       int _bf63;
       bool _bf47;
       bool _bf51;
       bool _bf58;
       bool _bf62;
       int _bf79;
       int _bf80;
       int _bf84;
       int _bf85;
       int _bf86;
       int _bf87;
       int _bf88;
       int _bf91;
       int x_0_3;
       int x_1_3;
       int x_2_3;
       int x_3_3;

       #pragma omp parallel sections
       {
           #pragma omp section
               path18(x_0_0, &_bf0, &_bf105);
           #pragma omp section
               path19(x_1_0, &_bf1, &_bf106);
           #pragma omp section
               path20(x_2_0, &_bf11, &_bf97);
           #pragma omp section
               path21(x_3_0, &_bf12, &_bf98);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf11, _bf12, &_bf13);
           #pragma omp section
               path3(_bf0, _bf1, &_bf2);
           #pragma omp section
               path23(_bf97, &_bf15, &_bf20);
           #pragma omp section
               path24(_bf98, &_bf16, &_bf19);
           #pragma omp section
               path36(_bf105, &_bf4, &_bf9);
           #pragma omp section
               path42(_bf106, &_bf5, &_bf8);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path22(_bf13, &_bf14, &_bf18);
           #pragma omp section
               path30(_bf2, &_bf3, &_bf7);
           #pragma omp section
               path48(_bf15, &_bf50);
           #pragma omp section
               path49(_bf16, &_bf54);
           #pragma omp section
               path50(_bf19, &_bf61);
           #pragma omp section
               path51(_bf20, &_bf65);
           #pragma omp section
               path58(_bf4, &_bf76);
           #pragma omp section
               path63(_bf5, &_bf83);
           #pragma omp section
               path70(_bf8, &_bf92);
           #pragma omp section
               path71(_bf9, &_bf93);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path0(_bf7, _bf92, _bf93, &_bf10);
           #pragma omp section
               path2(_bf14, _bf50, _bf54, &_bf17);
           #pragma omp section
               path4(_bf18, _bf61, _bf65, &_bf21);
           #pragma omp section
               path13(_bf3, _bf76, _bf83, &_bf6);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path25(_bf6, &_bf22, &_bf89);
           #pragma omp section
               path26(_bf21, &_bf23, &_bf90);
           #pragma omp section
               path31(_bf10, &_bf33, &_bf81);
           #pragma omp section
               path32(_bf17, &_bf34, &_bf82);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path5(_bf22, _bf23, &_bf24);
           #pragma omp section
               path8(_bf33, _bf34, &_bf35);
           #pragma omp section
               path28(_bf89, &_bf26, &_bf31);
           #pragma omp section
               path29(_bf90, &_bf27, &_bf30);
           #pragma omp section
               path34(_bf81, &_bf37, &_bf42);
           #pragma omp section
               path35(_bf82, &_bf38, &_bf41);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path27(_bf24, &_bf25, &_bf29);
           #pragma omp section
               path33(_bf35, &_bf36, &_bf40);
           #pragma omp section
               path52(_bf26, &_bf66);
           #pragma omp section
               path53(_bf27, &_bf69);
           #pragma omp section
               path54(_bf30, &_bf70);
           #pragma omp section
               path55(_bf31, &_bf71);
           #pragma omp section
               path56(_bf37, &_bf72);
           #pragma omp section
               path57(_bf38, &_bf75);
           #pragma omp section
               path59(_bf41, &_bf77);
           #pragma omp section
               path60(_bf42, &_bf78);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path6(_bf25, _bf66, _bf69, &_bf28);
           #pragma omp section
               path7(_bf29, _bf70, _bf71, &_bf32);
           #pragma omp section
               path9(_bf36, _bf72, _bf75, &_bf39);
           #pragma omp section
               path10(_bf40, _bf77, _bf78, &_bf43);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path37(_bf28, &_bf44, &_bf73);
           #pragma omp section
               path38(_bf39, &_bf45, &_bf74);
           #pragma omp section
               path43(_bf32, &_bf55, &_bf68);
           #pragma omp section
               path44(_bf43, &_bf56, &_bf67);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path11(_bf44, _bf45, &_bf46);
           #pragma omp section
               path12(_bf55, _bf56, &_bf57);
           #pragma omp section
               path40(_bf73, &_bf48, &_bf53);
           #pragma omp section
               path41(_bf74, &_bf49, &_bf52);
           #pragma omp section
               path46(_bf68, &_bf59, &_bf64);
           #pragma omp section
               path47(_bf67, &_bf60, &_bf63);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path39(_bf46, &_bf47, &_bf51);
           #pragma omp section
               path45(_bf57, &_bf58, &_bf62);
           #pragma omp section
               path61(_bf48, &_bf79);
           #pragma omp section
               path62(_bf49, &_bf80);
           #pragma omp section
               path64(_bf52, &_bf84);
           #pragma omp section
               path65(_bf53, &_bf85);
           #pragma omp section
               path66(_bf59, &_bf86);
           #pragma omp section
               path67(_bf60, &_bf87);
           #pragma omp section
               path68(_bf63, &_bf88);
           #pragma omp section
               path69(_bf64, &_bf91);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path14(_bf47, _bf79, _bf80, &x_0_3);
           #pragma omp section
               path15(_bf51, _bf84, _bf85, &x_1_3);
           #pragma omp section
               path16(_bf62, _bf88, _bf91, &x_2_3);
           #pragma omp section
               path17(_bf58, _bf86, _bf87, &x_3_3);
       }

       outputs[i * 4 + 0] = x_0_3;
       outputs[i * 4 + 1] = x_1_3;
       outputs[i * 4 + 2] = x_2_3;
       outputs[i * 4 + 3] = x_3_3;
    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
        printf("x_0_3: %i, x_1_3: %i, x_2_3: %i, x_3_3: %i", outputs[0], outputs[1], outputs[2], outputs[3]);
    }
}