
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

    int a_0_1;
    int a_1_1;
    int b_1_0;
    int b_1_1;
    int c_0_0;
    int c_0_1;
    int c_1_0;
    int c_1_1;
    auto start = chrono::steady_clock::now();
    int _bf0 = b_1_0;
    int _bf9 = b_1_0;
    int _bf19 = b_1_1;
    int _bf28 = b_1_1;
    int _bf2 = a_0_1;
    int _bf11 = a_0_1;
    int _bf40 = a_1_1;
    int _bf49 = a_1_1;
    int _bf7 = _bf2 * _bf0;
    int _bf14 = _bf11;
    int _bf18 = _bf11;
    int _bf52 = _bf49;
    int _bf56 = _bf49;
    int _bf91 = _bf28;
    int b_0_1 = _bf28;
    int _bf96 = _bf9;
    int b_0_0 = _bf9;
    int _bf3 = _bf19;
    int _bf12 = _bf40;
    int _bf8 = c_0_0 + _bf7;
    int _bf15 = _bf96;
    int _bf90 = _bf96;
    int _bf34 = _bf91;
    int _bf86 = _bf91;
    int _bf85 = _bf56;
    int a_1_0 = _bf56;
    int _bf93 = _bf18;
    int a_0_0 = _bf18;
    int _bf1 = _bf14;
    int _bf4 = _bf3;
    int _bf13 = _bf12;
    int _bf20 = _bf52;
    int _bf16 = _bf1 * _bf15;
    int _bf21 = _bf93;
    int _bf30 = _bf93;
    int _bf38 = _bf90;
    int _bf47 = _bf90;
    int _bf57 = _bf86;
    int _bf66 = _bf86;
    int _bf59 = _bf85;
    int _bf68 = _bf85;
    int _bf5 = _bf4;
    int _bf6 = _bf34;
    int _bf17 = _bf13;
    int _bf22 = _bf20;
    int _bf24 = _bf8;
    c_0_0 = _bf24 + _bf16;
    int _bf26 = _bf21 * _bf5;
    int _bf45 = _bf17 * _bf38;
    int _bf64 = _bf59 * _bf57;
    int _bf33 = _bf30;
    a_0_1 = _bf30;
    int _bf53 = _bf47;
    b_1_0 = _bf47;
    int _bf71 = _bf68;
    a_1_1 = _bf68;
    int _bf72 = _bf66;
    b_1_1 = _bf66;
    int _bf10 = _bf6;
    int _bf23 = _bf22;
    int _bf27 = c_0_1 + _bf26;
    int _bf35 = _bf33 * _bf10;
    int _bf46 = c_1_0 + _bf45;
    int _bf54 = _bf23 * _bf53;
    int _bf65 = c_1_1 + _bf64;
    int _bf73 = _bf71 * _bf72;
    c_0_1 = _bf27 + _bf35;
    c_1_0 = _bf46 + _bf54;
    c_1_1 = _bf65 + _bf73;
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
       std::cout << "a_0_0: " << a_0_0 << "a_0_1: " << a_0_1 << "a_1_0: " << a_1_0 << "a_1_1: " << a_1_1 << "b_0_0: " << b_0_0 << "b_0_1: " << b_0_1 << "b_1_0: " << b_1_0 << "b_1_1: " << b_1_1 << "c_0_0: " << c_0_0 << "c_0_1: " << c_0_1 << "c_1_0: " << c_1_0 << "c_1_1: " << c_1_1 << std::endl;

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    return 0;
}