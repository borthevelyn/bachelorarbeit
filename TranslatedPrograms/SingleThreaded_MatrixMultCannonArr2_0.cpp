
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
    int _bf104 = 0;
    int _bf109 = 1;
    int _bf114 = 2;
    int _bf119 = 3;
    int _bf12 = 2;
    int _bf24 = 2;
    int _bf28 = 1;
    int _bf36 = 0;
    int _bf4 = 1;
    int _bf54 = 0;
    int _bf72 = 0;
    int _bf90 = 0;
    int _bf27 = b[_bf24];
    int* _bf26 = b;
    int _bf7 = a[_bf4];
    int* _bf6 = a;
    int _bf32 = _bf27;
    int _bf41 = _bf27;
    int _bf34 = _bf7;
    int _bf43 = _bf7;
    int _bf15 = _bf6[_bf12];
    a = _bf6;
    int _bf31 = _bf26[_bf28];
    b = _bf26;
    int _bf39 = _bf34 * _bf32;
    int _bf46 = _bf43;
    int _bf139 = _bf43;
    int _bf47 = _bf41;
    int _bf134 = _bf41;
    int _bf50 = _bf31;
    int _bf59 = _bf31;
    int _bf70 = _bf15;
    int _bf79 = _bf15;
    int _bf40 = _bf36 + _bf39;
    int _bf48 = _bf46 * _bf47;
    int _bf52 = _bf139;
    int _bf61 = _bf139;
    int _bf65 = _bf59;
    int _bf128 = _bf59;
    int _bf68 = _bf134;
    int _bf77 = _bf134;
    int _bf82 = _bf79;
    int _bf127 = _bf79;
    int _bf3 = _bf50;
    int _bf8 = _bf70;
    int _bf49 = _bf40 + _bf48;
    int _bf57 = _bf52 * _bf3;
    int _bf66 = _bf61 * _bf65;
    int _bf75 = _bf8 * _bf68;
    int _bf84 = _bf82 * _bf77;
    int _bf86 = _bf128;
    int _bf95 = _bf128;
    int _bf88 = _bf127;
    int _bf97 = _bf127;
    int _bf102 = _bf97 * _bf95;
    c[_bf104] = _bf49;
    int* _bf108 = c;
    int _bf58 = _bf54 + _bf57;
    int _bf76 = _bf72 + _bf75;
    int _bf93 = _bf88 * _bf86;
    int _bf5 = _bf66;
    int _bf9 = _bf84;
    int _bf67 = _bf58 + _bf5;
    int _bf85 = _bf76 + _bf9;
    int _bf94 = _bf90 + _bf93;
    int _bf0 = _bf102;
    int* _bf2 = _bf108;
    int _bf103 = _bf94 + _bf0;
    _bf2[_bf109] = _bf67;
    int* _bf113 = _bf2;
    int _bf10 = _bf85;
    _bf113[_bf114] = _bf10;
    int* _bf118 = _bf113;
    int _bf1 = _bf103;
    _bf118[_bf119] = _bf1;
    c = _bf118;
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