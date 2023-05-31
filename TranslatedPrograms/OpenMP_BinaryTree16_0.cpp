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
void path1(int _bf79, int _bf93, int* _bf102) { 
    *_bf102 = _bf79 + _bf93;
}
void path2(int _bf85, int _bf99, int* _bf105) { 
    *_bf105 = _bf85 + _bf99;
}
void path3(int _bf29, int _bf105, int* z) { 
    *z = _bf29 + _bf105;
}
void path4(int* _bf12) { 
    *_bf12 = 3;
}
void path5(int* _bf16) { 
    *_bf16 = 4;
}
void path6(int* _bf20) { 
    *_bf20 = 5;
}
void path7(int* _bf24) { 
    *_bf24 = 6;
}
void path8(int* _bf28) { 
    *_bf28 = 7;
}
void path9(int* _bf32) { 
    *_bf32 = 8;
}
void path10(int* _bf36) { 
    *_bf36 = 9;
}
void path11(int* _bf4) { 
    *_bf4 = 1;
}
void path12(int* _bf40) { 
    *_bf40 = 10;
}
void path13(int* _bf44) { 
    *_bf44 = 11;
}
void path14(int* _bf48) { 
    *_bf48 = 12;
}
void path15(int* _bf52) { 
    *_bf52 = 13;
}
void path16(int* _bf56) { 
    *_bf56 = 14;
}
void path17(int* _bf60) { 
    *_bf60 = 15;
}
void path18(int _bf45, int _bf7, int* _bf66) { 
    *_bf66 = _bf45 + _bf7;
}
void path19(int _bf33, int _bf15, int* _bf69) { 
    *_bf69 = _bf33 + _bf15;
}
void path20(int _bf37, int _bf23, int* _bf72) { 
    *_bf72 = _bf37 + _bf23;
}
void path21(int _bf41, int _bf31, int* _bf75) { 
    *_bf75 = _bf41 + _bf31;
}
void path22(int _bf49, int _bf39, int* _bf78) { 
    *_bf78 = _bf49 + _bf39;
}
void path23(int* _bf8) { 
    *_bf8 = 2;
}
void path24(int _bf53, int _bf47, int* _bf81) { 
    *_bf81 = _bf53 + _bf47;
}
void path25(int _bf57, int _bf55, int* _bf84) { 
    *_bf84 = _bf57 + _bf55;
}
void path26(int _bf61, int _bf63, int* _bf87) { 
    *_bf87 = _bf61 + _bf63;
}
void path27(int _bf64, int _bf69, int* _bf90) { 
    *_bf90 = _bf64 + _bf69;
}
void path28(int _bf67, int _bf75, int* _bf93) { 
    *_bf93 = _bf67 + _bf75;
}
void path29(int _bf70, int _bf81, int* _bf96) { 
    *_bf96 = _bf70 + _bf81;
}
void path30(int _bf73, int _bf87, int* _bf99) { 
    *_bf99 = _bf73 + _bf87;
}
void path31(int _bf8, int* _bf6, int** _bf10, int* _bf11) { 
    *_bf11 = _bf6[_bf8];
    *_bf10 = _bf6;
}
void path32(int _bf12, int* _bf10, int** _bf14, int* _bf15) { 
    *_bf15 = _bf10[_bf12];
    *_bf14 = _bf10;
}
void path33(int _bf16, int* _bf14, int** _bf18, int* _bf19) { 
    *_bf19 = _bf14[_bf16];
    *_bf18 = _bf14;
}
void path34(int _bf0, int* x, int** _bf2, int* _bf3) { 
    *_bf3 = x[_bf0];
    *_bf2 = x;
}
void path35(int _bf20, int* _bf18, int** _bf22, int* _bf23) { 
    *_bf23 = _bf18[_bf20];
    *_bf22 = _bf18;
}
void path36(int _bf24, int* _bf22, int** _bf26, int* _bf27) { 
    *_bf27 = _bf22[_bf24];
    *_bf26 = _bf22;
}
void path37(int _bf28, int* _bf26, int** _bf30, int* _bf31) { 
    *_bf31 = _bf26[_bf28];
    *_bf30 = _bf26;
}
void path38(int _bf32, int* _bf30, int** _bf34, int* _bf35) { 
    *_bf35 = _bf30[_bf32];
    *_bf34 = _bf30;
}
void path39(int _bf36, int* _bf34, int** _bf38, int* _bf39) { 
    *_bf39 = _bf34[_bf36];
    *_bf38 = _bf34;
}
void path40(int _bf40, int* _bf38, int** _bf42, int* _bf43) { 
    *_bf43 = _bf38[_bf40];
    *_bf42 = _bf38;
}
void path41(int _bf44, int* _bf42, int** _bf46, int* _bf47) { 
    *_bf47 = _bf42[_bf44];
    *_bf46 = _bf42;
}
void path42(int _bf48, int* _bf46, int** _bf50, int* _bf51) { 
    *_bf51 = _bf46[_bf48];
    *_bf50 = _bf46;
}
void path43(int _bf52, int* _bf50, int** _bf54, int* _bf55) { 
    *_bf55 = _bf50[_bf52];
    *_bf54 = _bf50;
}
void path44(int _bf56, int* _bf54, int** _bf58, int* _bf59) { 
    *_bf59 = _bf54[_bf56];
    *_bf58 = _bf54;
}
void path45(int _bf4, int* _bf2, int** _bf6, int* _bf7) { 
    *_bf7 = _bf2[_bf4];
    *_bf6 = _bf2;
}
void path46(int _bf60, int* _bf58, int** x, int* _bf63) { 
    *_bf63 = _bf58[_bf60];
    *x = _bf58;
}
void path47(int _bf102, int* _bf1) { 
    *_bf1 = _bf102;
}
void path48(int _bf1, int* _bf5) { 
    *_bf5 = _bf1;
}
void path49(int _bf5, int* _bf9) { 
    *_bf9 = _bf5;
}
void path50(int _bf9, int* _bf13) { 
    *_bf13 = _bf9;
}
void path51(int _bf13, int* _bf17) { 
    *_bf17 = _bf13;
}
void path52(int _bf17, int* _bf21) { 
    *_bf21 = _bf17;
}
void path53(int _bf21, int* _bf25) { 
    *_bf25 = _bf21;
}
void path54(int _bf25, int* _bf29) { 
    *_bf29 = _bf25;
}
void path55(int _bf11, int* _bf33) { 
    *_bf33 = _bf11;
}
void path56(int _bf19, int* _bf37) { 
    *_bf37 = _bf19;
}
void path57(int _bf27, int* _bf41) { 
    *_bf41 = _bf27;
}
void path58(int _bf3, int* _bf45) { 
    *_bf45 = _bf3;
}
void path59(int _bf35, int* _bf49) { 
    *_bf49 = _bf35;
}
void path60(int _bf43, int* _bf53) { 
    *_bf53 = _bf43;
}
void path61(int _bf51, int* _bf57) { 
    *_bf57 = _bf51;
}
void path62(int _bf59, int* _bf61) { 
    *_bf61 = _bf59;
}
void path63(int _bf66, int* _bf62) { 
    *_bf62 = _bf66;
}
void path64(int _bf62, int* _bf64) { 
    *_bf64 = _bf62;
}
void path65(int _bf72, int* _bf65) { 
    *_bf65 = _bf72;
}
void path66(int _bf65, int* _bf67) { 
    *_bf67 = _bf65;
}
void path67(int _bf78, int* _bf68) { 
    *_bf68 = _bf78;
}
void path68(int _bf68, int* _bf70) { 
    *_bf70 = _bf68;
}
void path69(int _bf84, int* _bf71) { 
    *_bf71 = _bf84;
}
void path70(int _bf71, int* _bf73) { 
    *_bf73 = _bf71;
}
void path71(int _bf90, int* _bf74) { 
    *_bf74 = _bf90;
}
void path72(int _bf74, int* _bf76) { 
    *_bf76 = _bf74;
}
void path73(int _bf76, int* _bf77) { 
    *_bf77 = _bf76;
}
void path74(int _bf77, int* _bf79) { 
    *_bf79 = _bf77;
}
void path75(int _bf96, int* _bf80) { 
    *_bf80 = _bf96;
}
void path76(int _bf80, int* _bf82) { 
    *_bf82 = _bf80;
}
void path77(int _bf82, int* _bf83) { 
    *_bf83 = _bf82;
}
void path78(int _bf83, int* _bf85) { 
    *_bf85 = _bf83;
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


    int* outputs = new int[DATA_SIZE * 1 ]; 
    int* x_arr = new int[16 * DATA_SIZE];
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int _bf0;
       int _bf12;
       int _bf16;
       int _bf20;
       int _bf24;
       int _bf28;
       int _bf32;
       int _bf36;
       int _bf4;
       int _bf40;
       int _bf44;
       int _bf48;
       int _bf52;
       int _bf56;
       int _bf60;
       int _bf8;
       int* _bf2;
       int _bf3;
       int* _bf6;
       int _bf7;
       int _bf45;
       int _bf66;
       int* _bf10;
       int _bf11;
       int* _bf14;
       int _bf15;
       int _bf33;
       int _bf62;
       int _bf69;
       int* _bf18;
       int _bf19;
       int _bf64;
       int _bf90;
       int* _bf22;
       int _bf23;
       int _bf37;
       int _bf72;
       int* _bf26;
       int _bf27;
       int _bf74;
       int* _bf30;
       int _bf31;
       int _bf41;
       int _bf65;
       int _bf76;
       int _bf75;
       int* _bf34;
       int _bf35;
       int _bf67;
       int _bf77;
       int _bf93;
       int* _bf38;
       int _bf39;
       int _bf49;
       int _bf79;
       int _bf102;
       int _bf78;
       int* _bf42;
       int _bf43;
       int* _bf46;
       int _bf47;
       int _bf1;
       int _bf53;
       int _bf68;
       int _bf81;
       int* _bf50;
       int _bf51;
       int _bf5;
       int _bf70;
       int _bf96;
       int* _bf54;
       int _bf55;
       int _bf9;
       int _bf57;
       int _bf84;
       int* _bf58;
       int _bf59;
       int _bf13;
       int _bf80;
       int* x = x_arr + i * 16;
       int _bf63;
       int _bf17;
       int _bf61;
       int _bf71;
       int _bf82;
       int _bf87;
       int _bf21;
       int _bf73;
       int _bf83;
       int _bf99;
       int _bf25;
       int _bf85;
       int _bf105;
       int _bf29;
       int z;

       #pragma omp parallel sections
       {
           #pragma omp section
               path0(&_bf0);
           #pragma omp section
               path4(&_bf12);
           #pragma omp section
               path5(&_bf16);
           #pragma omp section
               path6(&_bf20);
           #pragma omp section
               path7(&_bf24);
           #pragma omp section
               path8(&_bf28);
           #pragma omp section
               path9(&_bf32);
           #pragma omp section
               path10(&_bf36);
           #pragma omp section
               path11(&_bf4);
           #pragma omp section
               path12(&_bf40);
           #pragma omp section
               path13(&_bf44);
           #pragma omp section
               path14(&_bf48);
           #pragma omp section
               path15(&_bf52);
           #pragma omp section
               path16(&_bf56);
           #pragma omp section
               path17(&_bf60);
           #pragma omp section
               path23(&_bf8);
       }
       path34(_bf0, x, &_bf2, &_bf3);
       #pragma omp parallel sections
       {
           #pragma omp section
               path45(_bf4, _bf2, &_bf6, &_bf7);
           #pragma omp section
               path58(_bf3, &_bf45);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path18(_bf45, _bf7, &_bf66);
           #pragma omp section
               path31(_bf8, _bf6, &_bf10, &_bf11);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path32(_bf12, _bf10, &_bf14, &_bf15);
           #pragma omp section
               path55(_bf11, &_bf33);
           #pragma omp section
               path63(_bf66, &_bf62);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path19(_bf33, _bf15, &_bf69);
           #pragma omp section
               path33(_bf16, _bf14, &_bf18, &_bf19);
           #pragma omp section
               path64(_bf62, &_bf64);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path27(_bf64, _bf69, &_bf90);
           #pragma omp section
               path35(_bf20, _bf18, &_bf22, &_bf23);
           #pragma omp section
               path56(_bf19, &_bf37);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path20(_bf37, _bf23, &_bf72);
           #pragma omp section
               path36(_bf24, _bf22, &_bf26, &_bf27);
           #pragma omp section
               path71(_bf90, &_bf74);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path37(_bf28, _bf26, &_bf30, &_bf31);
           #pragma omp section
               path57(_bf27, &_bf41);
           #pragma omp section
               path65(_bf72, &_bf65);
           #pragma omp section
               path72(_bf74, &_bf76);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path21(_bf41, _bf31, &_bf75);
           #pragma omp section
               path38(_bf32, _bf30, &_bf34, &_bf35);
           #pragma omp section
               path66(_bf65, &_bf67);
           #pragma omp section
               path73(_bf76, &_bf77);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path28(_bf67, _bf75, &_bf93);
           #pragma omp section
               path39(_bf36, _bf34, &_bf38, &_bf39);
           #pragma omp section
               path59(_bf35, &_bf49);
           #pragma omp section
               path74(_bf77, &_bf79);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf79, _bf93, &_bf102);
           #pragma omp section
               path22(_bf49, _bf39, &_bf78);
           #pragma omp section
               path40(_bf40, _bf38, &_bf42, &_bf43);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path41(_bf44, _bf42, &_bf46, &_bf47);
           #pragma omp section
               path47(_bf102, &_bf1);
           #pragma omp section
               path60(_bf43, &_bf53);
           #pragma omp section
               path67(_bf78, &_bf68);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path24(_bf53, _bf47, &_bf81);
           #pragma omp section
               path42(_bf48, _bf46, &_bf50, &_bf51);
           #pragma omp section
               path48(_bf1, &_bf5);
           #pragma omp section
               path68(_bf68, &_bf70);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path29(_bf70, _bf81, &_bf96);
           #pragma omp section
               path43(_bf52, _bf50, &_bf54, &_bf55);
           #pragma omp section
               path49(_bf5, &_bf9);
           #pragma omp section
               path61(_bf51, &_bf57);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path25(_bf57, _bf55, &_bf84);
           #pragma omp section
               path44(_bf56, _bf54, &_bf58, &_bf59);
           #pragma omp section
               path50(_bf9, &_bf13);
           #pragma omp section
               path75(_bf96, &_bf80);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path46(_bf60, _bf58, &x, &_bf63);
           #pragma omp section
               path51(_bf13, &_bf17);
           #pragma omp section
               path62(_bf59, &_bf61);
           #pragma omp section
               path69(_bf84, &_bf71);
           #pragma omp section
               path76(_bf80, &_bf82);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path26(_bf61, _bf63, &_bf87);
           #pragma omp section
               path52(_bf17, &_bf21);
           #pragma omp section
               path70(_bf71, &_bf73);
           #pragma omp section
               path77(_bf82, &_bf83);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path30(_bf73, _bf87, &_bf99);
           #pragma omp section
               path53(_bf21, &_bf25);
           #pragma omp section
               path78(_bf83, &_bf85);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path2(_bf85, _bf99, &_bf105);
           #pragma omp section
               path54(_bf25, &_bf29);
       }
       path3(_bf29, _bf105, &z);

       outputs[i * 1 + 0] = z;
    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
        printf("z: %i", outputs[0]);
       cout << "\nx: ";
       for(int i = 0; i < 16 * DATA_SIZE; i++) {
           cout << x_arr[i] << " ";
       }
    }
}