#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf42, int* a, int* _bf17, int* _bf32, int** _bf2) { 
    int _bf0 = 0;
    int _bf3 = a[_bf0];
    *_bf2 = a;
    *_bf32 = _bf3;
    int _bf41 = _bf3;
    int _bf13 = _bf41;
    int _bf43 = _bf13 * _bf42;
    int _bf14 = _bf43;
    *_bf17 = _bf14;
}
void path1(int _bf38, int _bf39, int* _bf10, int* _bf47, int* _bf62, int** a) { 
    int _bf12 = 3;
    int _bf15 = _bf10[_bf12];
    *a = _bf10;
    int _bf53 = _bf15;
    *_bf62 = _bf15;
    int _bf55 = _bf53 * _bf39;
    int _bf58 = _bf38 + _bf55;
    *_bf47 = _bf58;
}
void path2(int* b, int* _bf19, int** _bf18) { 
    int _bf16 = 0;
    *_bf19 = b[_bf16];
    *_bf18 = b;
}
void path3(int* _bf18, int* _bf48, int* _bf42, int** _bf22) { 
    int _bf20 = 1;
    int _bf23 = _bf18[_bf20];
    *_bf22 = _bf18;
    *_bf42 = _bf23;
    int _bf60 = _bf23;
    *_bf48 = _bf60;
}
void path4(int* _bf22, int* _bf39, int* _bf36, int** _bf26) { 
    int _bf24 = 2;
    int _bf27 = _bf22[_bf24];
    *_bf26 = _bf22;
    *_bf36 = _bf27;
    int _bf54 = _bf27;
    *_bf39 = _bf54;
}
void path5(int _bf56, int _bf62, int* _bf26, int* _bf65, int* _bf45, int** b) { 
    int _bf28 = 3;
    int _bf31 = _bf26[_bf28];
    *b = _bf26;
    *_bf45 = _bf31;
    int _bf63 = _bf31;
    int _bf64 = _bf62 * _bf63;
    int _bf67 = _bf56 + _bf64;
    int _bf57 = _bf67;
    *_bf65 = _bf57;
}
void path6(int _bf37, int _bf33, int _bf32, int* _bf40) { 
    int _bf34 = _bf32 * _bf33;
    int _bf1 = _bf34;
    int _bf5 = _bf1;
    *_bf40 = _bf5 + _bf37;
}
void path7(int _bf36, int* _bf2, int* _bf37, int* _bf44, int** _bf6) { 
    int _bf4 = 1;
    int _bf7 = _bf2[_bf4];
    *_bf6 = _bf2;
    int _bf35 = _bf7;
    *_bf44 = _bf7;
    int _bf9 = _bf35;
    *_bf37 = _bf9 * _bf36;
}
void path8(int _bf40, int* c, int** _bf72) { 
    int _bf68 = 0;
    c[_bf68] = _bf40;
    *_bf72 = c;
}
void path9(int* _bf73) { 
    *_bf73 = 1;
}
void path10(int* _bf78) { 
    *_bf78 = 2;
}
void path11(int _bf48, int* _bf6, int* _bf56, int* _bf50, int** _bf10) { 
    int _bf8 = 2;
    int _bf11 = _bf6[_bf8];
    *_bf10 = _bf6;
    *_bf50 = _bf11;
    int _bf59 = _bf11;
    int _bf61 = _bf59 * _bf48;
    *_bf56 = _bf61;
}
void path12(int* _bf83) { 
    *_bf83 = 3;
}
void path13(int _bf50, int _bf19, int* _bf38, int* _bf33) { 
    *_bf33 = _bf19;
    int _bf51 = _bf19;
    int _bf29 = _bf51;
    int _bf30 = _bf29;
    int _bf52 = _bf50 * _bf30;
    *_bf38 = _bf52;
}
void path14(int _bf65, int _bf83, int _bf47, int _bf78, int* _bf72, int _bf73, int _bf17, int _bf45, int _bf44, int** c) { 
    int _bf21 = _bf44;
    int _bf25 = _bf21;
    int _bf46 = _bf25 * _bf45;
    int _bf49 = _bf17 + _bf46;
    _bf72[_bf73] = _bf49;
    int* _bf77 = _bf72;
    _bf77[_bf78] = _bf47;
    int* _bf82 = _bf77;
    _bf82[_bf83] = _bf65;
    *c = _bf82;
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
       int _bf19;
       int* _bf18;
       int _bf73;
       int _bf78;
       int _bf83;
       int _bf48;
       int _bf42;
       int* _bf22;
       int _bf17;
       int _bf32;
       int* _bf2;
       int _bf39;
       int _bf36;
       int* _bf26;
       int _bf37;
       int _bf44;
       int* _bf6;
       int _bf56;
       int _bf50;
       int* _bf10;
       int _bf38;
       int _bf33;
       int _bf47;
       int _bf62;
       int* a = a_arr + i * 4;
       int _bf40;
       int _bf65;
       int _bf45;
       int* b = b_arr + i * 4;
       int* _bf72;
       int* c = c_arr + i * 4;

       #pragma omp parallel sections
       {
           #pragma omp section
               path2(b, &_bf19, &_bf18);
           #pragma omp section
               path9(&_bf73);
           #pragma omp section
               path10(&_bf78);
           #pragma omp section
               path12(&_bf83);
       }
       path3(_bf18, &_bf48, &_bf42, &_bf22);
       #pragma omp parallel sections
       {
           #pragma omp section
               path0(_bf42, a, &_bf17, &_bf32, &_bf2);
           #pragma omp section
               path4(_bf22, &_bf39, &_bf36, &_bf26);
       }
       path7(_bf36, _bf2, &_bf37, &_bf44, &_bf6);
       path11(_bf48, _bf6, &_bf56, &_bf50, &_bf10);
       path13(_bf50, _bf19, &_bf38, &_bf33);
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf38, _bf39, _bf10, &_bf47, &_bf62, &a);
           #pragma omp section
               path6(_bf37, _bf33, _bf32, &_bf40);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path5(_bf56, _bf62, _bf26, &_bf65, &_bf45, &b);
           #pragma omp section
               path8(_bf40, c, &_bf72);
       }
       path14(_bf65, _bf83, _bf47, _bf78, _bf72, _bf73, _bf17, _bf45, _bf44, &c);

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