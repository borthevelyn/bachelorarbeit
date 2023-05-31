#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf7, int _bf0, int* c, int* b) { 
    int _bf1 = 2;
    int _bf2 = _bf0 * _bf1;
    int _bf6 = _bf2;
    *b = _bf2;
    *c = _bf7 + _bf6;
}
void path1(int _bf3, int* _bf7) { 
    int _bf4 = 3;
    int _bf5 = _bf3 * _bf4;
    *_bf7 = _bf5;
}
void path2(int a, int* _bf3, int* _bf0) { 
    *_bf0 = a;
    *_bf3 = a;
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
       int _bf3;
       int _bf0;
       int _bf7;
       int c;
       int b;

       path2(a, &_bf3, &_bf0);
       path1(_bf3, &_bf7);
       path0(_bf7, _bf0, &c, &b);

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