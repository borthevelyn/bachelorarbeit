
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

    int* x = new int[16];
    memset(x, 0, 16 * sizeof(int));
    auto start = chrono::steady_clock::now();
    int _bf0 = 0;
    int _bf12 = 3;
    int _bf16 = 4;
    int _bf20 = 5;
    int _bf24 = 6;
    int _bf28 = 7;
    int _bf32 = 8;
    int _bf36 = 9;
    int _bf4 = 1;
    int _bf40 = 10;
    int _bf44 = 11;
    int _bf48 = 12;
    int _bf52 = 13;
    int _bf56 = 14;
    int _bf60 = 15;
    int _bf8 = 2;
    int _bf3 = x[_bf0];
    int* _bf2 = x;
    int _bf7 = _bf2[_bf4];
    int* _bf6 = _bf2;
    int _bf45 = _bf3;
    int _bf66 = _bf45 + _bf7;
    int _bf11 = _bf6[_bf8];
    int* _bf10 = _bf6;
    int _bf15 = _bf10[_bf12];
    int* _bf14 = _bf10;
    int _bf33 = _bf11;
    int _bf62 = _bf66;
    int _bf69 = _bf33 + _bf15;
    int _bf19 = _bf14[_bf16];
    int* _bf18 = _bf14;
    int _bf64 = _bf62;
    int _bf90 = _bf64 + _bf69;
    int _bf23 = _bf18[_bf20];
    int* _bf22 = _bf18;
    int _bf37 = _bf19;
    int _bf72 = _bf37 + _bf23;
    int _bf27 = _bf22[_bf24];
    int* _bf26 = _bf22;
    int _bf74 = _bf90;
    int _bf31 = _bf26[_bf28];
    int* _bf30 = _bf26;
    int _bf41 = _bf27;
    int _bf65 = _bf72;
    int _bf76 = _bf74;
    int _bf75 = _bf41 + _bf31;
    int _bf35 = _bf30[_bf32];
    int* _bf34 = _bf30;
    int _bf67 = _bf65;
    int _bf77 = _bf76;
    int _bf93 = _bf67 + _bf75;
    int _bf39 = _bf34[_bf36];
    int* _bf38 = _bf34;
    int _bf49 = _bf35;
    int _bf79 = _bf77;
    int _bf102 = _bf79 + _bf93;
    int _bf78 = _bf49 + _bf39;
    int _bf43 = _bf38[_bf40];
    int* _bf42 = _bf38;
    int _bf47 = _bf42[_bf44];
    int* _bf46 = _bf42;
    int _bf1 = _bf102;
    int _bf53 = _bf43;
    int _bf68 = _bf78;
    int _bf81 = _bf53 + _bf47;
    int _bf51 = _bf46[_bf48];
    int* _bf50 = _bf46;
    int _bf5 = _bf1;
    int _bf70 = _bf68;
    int _bf96 = _bf70 + _bf81;
    int _bf55 = _bf50[_bf52];
    int* _bf54 = _bf50;
    int _bf9 = _bf5;
    int _bf57 = _bf51;
    int _bf84 = _bf57 + _bf55;
    int _bf59 = _bf54[_bf56];
    int* _bf58 = _bf54;
    int _bf13 = _bf9;
    int _bf80 = _bf96;
    int _bf63 = _bf58[_bf60];
    x = _bf58;
    int _bf17 = _bf13;
    int _bf61 = _bf59;
    int _bf71 = _bf84;
    int _bf82 = _bf80;
    int _bf87 = _bf61 + _bf63;
    int _bf21 = _bf17;
    int _bf73 = _bf71;
    int _bf83 = _bf82;
    int _bf99 = _bf73 + _bf87;
    int _bf25 = _bf21;
    int _bf85 = _bf83;
    int _bf105 = _bf85 + _bf99;
    int _bf29 = _bf25;
    int z = _bf29 + _bf105;
    auto end = chrono::steady_clock::now();
    delete x;

    if (!onlyTimeOutput)
       std::cout << "z: " << z << std::endl;

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    return 0;
}