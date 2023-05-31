#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int* _bf1) { 
    *_bf1 = 2;
}
void path1(int _bf0, int _bf1, int* _bf2) { 
    *_bf2 = _bf0 * _bf1;
}
void path2(int* _bf4) { 
    *_bf4 = 3;
}
void path3(int _bf3, int _bf4, int* _bf5) { 
    *_bf5 = _bf3 * _bf4;
}
void path4(int _bf7, int _bf6, int* c) { 
    *c = _bf7 + _bf6;
}
void path5(int a, int* _bf0, int* _bf3) { 
    *_bf0 = a;
    *_bf3 = a;
}
void path6(int _bf2, int* _bf6, int* b) { 
    *_bf6 = _bf2;
    *b = _bf2;
}
void path7(int _bf5, int* _bf7) { 
    *_bf7 = _bf5;
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


    int* inputs = new int[DATA_SIZE * 1 ]; 
    memset(inputs, 0, 1 * DATA_SIZE * sizeof(int));
    int* outputs = new int[DATA_SIZE * 2 ]; 
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int a = inputs[i * 1 + 0];
       int _bf1;
       int _bf4;
       int _bf0;
       int _bf3;
       int _bf2;
       int _bf5;
       int _bf6;
       int b;
       int _bf7;
       int c;

       #pragma omp parallel sections
       {
           #pragma omp section
               path0(&_bf1);
           #pragma omp section
               path2(&_bf4);
           #pragma omp section
               path5(a, &_bf0, &_bf3);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf0, _bf1, &_bf2);
           #pragma omp section
               path3(_bf3, _bf4, &_bf5);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path6(_bf2, &_bf6, &b);
           #pragma omp section
               path7(_bf5, &_bf7);
       }
       path4(_bf7, _bf6, &c);

       outputs[i * 2 + 0] = b;
       outputs[i * 2 + 1] = c;
    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
        printf("b: %i, c: %i", outputs[0], outputs[1]);
    }
}