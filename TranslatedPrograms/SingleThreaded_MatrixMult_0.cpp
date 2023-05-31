
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>


using namespace std;


int main(int argc, char** argv)
{
    bool onlyTimeOutput = [&]() {
        if (argc < 2) return false;

        if (std::string(argv[1]) == "--onlytime")
            return true;
        else
            return false;
    }();

    int* a = new int[4];
    memset(a, 0, 4 * sizeof(int));
    int* b = new int[4];
    memset(b, 0, 4 * sizeof(int));
    int* c = new int[4];
    memset(c, 0, 4 * sizeof(int));
    auto start = chrono::steady_clock::now();
    int _bf0 = 0;
    int _bf12 = 3;
    int _bf16 = 0;
    int _bf20 = 1;
    int _bf24 = 2;
    int _bf28 = 3;
    int _bf4 = 1;
    int _bf68 = 0;
    int _bf73 = 1;
    int _bf78 = 2;
    int _bf8 = 2;
    int _bf83 = 3;
    int _bf19 = b[_bf16];
    int* _bf18 = b;
    int _bf3 = a[_bf0];
    int* _bf2 = a;
    int _bf23 = _bf18[_bf20];
    int* _bf22 = _bf18;
    int _bf32 = _bf3;
    int _bf41 = _bf3;
    int _bf33 = _bf19;
    int _bf51 = _bf19;
    int _bf7 = _bf2[_bf4];
    int* _bf6 = _bf2;
    int _bf34 = _bf32 * _bf33;
    int _bf11 = _bf6[_bf8];
    int* _bf10 = _bf6;
    int _bf27 = _bf22[_bf24];
    int* _bf26 = _bf22;
    int _bf35 = _bf7;
    int _bf44 = _bf7;
    int _bf42 = _bf23;
    int _bf60 = _bf23;
    int _bf13 = _bf41;
    int _bf29 = _bf51;
    int _bf43 = _bf13 * _bf42;
    int _bf36 = _bf27;
    int _bf54 = _bf27;
    int _bf50 = _bf11;
    int _bf59 = _bf11;
    int _bf15 = _bf10[_bf12];
    a = _bf10;
    int _bf31 = _bf26[_bf28];
    b = _bf26;
    int _bf1 = _bf34;
    int _bf9 = _bf35;
    int _bf21 = _bf44;
    int _bf30 = _bf29;
    int _bf48 = _bf60;
    int _bf37 = _bf9 * _bf36;
    int _bf52 = _bf50 * _bf30;
    int _bf61 = _bf59 * _bf48;
    int _bf45 = _bf31;
    int _bf63 = _bf31;
    int _bf53 = _bf15;
    int _bf62 = _bf15;
    int _bf5 = _bf1;
    int _bf14 = _bf43;
    int _bf25 = _bf21;
    int _bf39 = _bf54;
    int _bf40 = _bf5 + _bf37;
    int _bf46 = _bf25 * _bf45;
    int _bf55 = _bf53 * _bf39;
    int _bf64 = _bf62 * _bf63;
    int _bf17 = _bf14;
    int _bf38 = _bf52;
    int _bf56 = _bf61;
    int _bf49 = _bf17 + _bf46;
    int _bf58 = _bf38 + _bf55;
    int _bf67 = _bf56 + _bf64;
    c[_bf68] = _bf40;
    int* _bf72 = c;
    _bf72[_bf73] = _bf49;
    int* _bf77 = _bf72;
    int _bf47 = _bf58;
    int _bf57 = _bf67;
    _bf77[_bf78] = _bf47;
    int* _bf82 = _bf77;
    int _bf65 = _bf57;
    _bf82[_bf83] = _bf65;
    c = _bf82;
    auto end = chrono::steady_clock::now();
    delete a;
    delete b;
    delete c;

    if (!onlyTimeOutput)
       std::cout << std::endl;

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    return 0;
}