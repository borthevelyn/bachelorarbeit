
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

    int w_1;
    int w_2;
    int w_3;
    int x_0;
    int x_1;
    int x_2;
    int x_3;
    int x_4;
    int x_5;
    int x_6;
    int x_7;
    auto start = chrono::steady_clock::now();
    int _bf0 = x_0;
    int _bf12 = x_0;
    int _bf1 = x_4;
    int _bf13 = x_4;
    int _bf10 = x_7;
    int _bf27 = x_7;
    int _bf20 = w_2;
    int _bf123 = w_2;
    int _bf3 = x_1;
    int _bf16 = x_1;
    int _bf4 = x_5;
    int _bf17 = x_5;
    int _bf6 = x_2;
    int _bf21 = x_2;
    int _bf7 = x_6;
    int _bf22 = x_6;
    int _bf9 = x_3;
    int _bf26 = x_3;
    int _bf11 = _bf9 + _bf10;
    int _bf14 = _bf12 - _bf13;
    int _bf18 = _bf16 - _bf17;
    int _bf2 = _bf0 + _bf1;
    int _bf23 = _bf21 - _bf22;
    int _bf28 = _bf26 - _bf27;
    int _bf5 = _bf3 + _bf4;
    int _bf8 = _bf6 + _bf7;
    int _bf39 = _bf123;
    int _bf65 = _bf123;
    int _bf15 = _bf20;
    int _bf19 = w_1 * _bf18;
    int _bf24 = _bf15 * _bf23;
    int _bf29 = w_3 * _bf28;
    int _bf30 = _bf2;
    int _bf36 = _bf2;
    int _bf31 = _bf8;
    int _bf37 = _bf8;
    int _bf33 = _bf5;
    int _bf40 = _bf5;
    int _bf34 = _bf11;
    int _bf41 = _bf11;
    int _bf56 = _bf14;
    int _bf62 = _bf14;
    int _bf25 = _bf39;
    int _bf75 = _bf65;
    int _bf32 = _bf30 + _bf31;
    int _bf35 = _bf33 + _bf34;
    int _bf38 = _bf36 - _bf37;
    int _bf42 = _bf40 - _bf41;
    int _bf57 = _bf24;
    int _bf63 = _bf24;
    int _bf59 = _bf19;
    int _bf66 = _bf19;
    int _bf60 = _bf29;
    int _bf67 = _bf29;
    int _bf46 = _bf25;
    int _bf55 = _bf56;
    int _bf72 = _bf62;
    int _bf78 = _bf75;
    int _bf43 = _bf46 * _bf42;
    int _bf58 = _bf55 + _bf57;
    int _bf61 = _bf59 + _bf60;
    int _bf64 = _bf72 - _bf63;
    int _bf68 = _bf66 - _bf67;
    int _bf44 = _bf32;
    int _bf47 = _bf32;
    int _bf45 = _bf35;
    int _bf48 = _bf35;
    int _bf50 = _bf38;
    int _bf53 = _bf38;
    int _bf81 = _bf78;
    int y_0 = _bf44 + _bf45;
    int y_4 = _bf47 - _bf48;
    int _bf69 = _bf81 * _bf68;
    int _bf51 = _bf43;
    int _bf54 = _bf43;
    int _bf70 = _bf58;
    int _bf73 = _bf58;
    int _bf71 = _bf61;
    int _bf74 = _bf61;
    int _bf76 = _bf64;
    int _bf79 = _bf64;
    int _bf49 = _bf50;
    int _bf52 = _bf53;
    int y_2 = _bf49 + _bf51;
    int y_6 = _bf52 - _bf54;
    int y_1 = _bf70 + _bf71;
    int y_5 = _bf73 - _bf74;
    int _bf77 = _bf69;
    int _bf80 = _bf69;
    int _bf82 = _bf76;
    int _bf83 = _bf79;
    int y_3 = _bf82 + _bf77;
    int y_7 = _bf83 - _bf80;
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
       std::cout << "y_0: " << y_0 << "y_1: " << y_1 << "y_2: " << y_2 << "y_3: " << y_3 << "y_4: " << y_4 << "y_5: " << y_5 << "y_6: " << y_6 << "y_7: " << y_7 << std::endl;

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    return 0;
}