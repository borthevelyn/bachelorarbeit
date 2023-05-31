
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

    int x_0_0;
    int x_1_0;
    int x_2_0;
    int x_3_0;
    auto start = chrono::steady_clock::now();
    int _bf0 = x_0_0;
    int _bf105 = x_0_0;
    int _bf1 = x_1_0;
    int _bf106 = x_1_0;
    int _bf11 = x_2_0;
    int _bf97 = x_2_0;
    int _bf12 = x_3_0;
    int _bf98 = x_3_0;
    bool _bf13 = _bf11 < _bf12;
    bool _bf2 = _bf0 < _bf1;
    int _bf15 = _bf97;
    int _bf20 = _bf97;
    int _bf16 = _bf98;
    int _bf19 = _bf98;
    int _bf4 = _bf105;
    int _bf9 = _bf105;
    int _bf5 = _bf106;
    int _bf8 = _bf106;
    bool _bf14 = _bf13;
    bool _bf18 = _bf13;
    bool _bf3 = _bf2;
    bool _bf7 = _bf2;
    int _bf50 = _bf15;
    int _bf54 = _bf16;
    int _bf61 = _bf19;
    int _bf65 = _bf20;
    int _bf76 = _bf4;
    int _bf83 = _bf5;
    int _bf92 = _bf8;
    int _bf93 = _bf9;
    int _bf10;
    if ( _bf7 ) {
        _bf10 = _bf92;
    } else  { 
        _bf10 = _bf93;
    } 
    int _bf17;
    if ( _bf14 ) {
        _bf17 = _bf50;
    } else  { 
        _bf17 = _bf54;
    } 
    int _bf21;
    if ( _bf18 ) {
        _bf21 = _bf61;
    } else  { 
        _bf21 = _bf65;
    } 
    int _bf6;
    if ( _bf3 ) {
        _bf6 = _bf76;
    } else  { 
        _bf6 = _bf83;
    } 
    int _bf22 = _bf6;
    int _bf89 = _bf6;
    int _bf23 = _bf21;
    int _bf90 = _bf21;
    int _bf33 = _bf10;
    int _bf81 = _bf10;
    int _bf34 = _bf17;
    int _bf82 = _bf17;
    bool _bf24 = _bf22 < _bf23;
    bool _bf35 = _bf33 < _bf34;
    int _bf26 = _bf89;
    int _bf31 = _bf89;
    int _bf27 = _bf90;
    int _bf30 = _bf90;
    int _bf37 = _bf81;
    int _bf42 = _bf81;
    int _bf38 = _bf82;
    int _bf41 = _bf82;
    bool _bf25 = _bf24;
    bool _bf29 = _bf24;
    bool _bf36 = _bf35;
    bool _bf40 = _bf35;
    int _bf66 = _bf26;
    int _bf69 = _bf27;
    int _bf70 = _bf30;
    int _bf71 = _bf31;
    int _bf72 = _bf37;
    int _bf75 = _bf38;
    int _bf77 = _bf41;
    int _bf78 = _bf42;
    int _bf28;
    if ( _bf25 ) {
        _bf28 = _bf66;
    } else  { 
        _bf28 = _bf69;
    } 
    int _bf32;
    if ( _bf29 ) {
        _bf32 = _bf70;
    } else  { 
        _bf32 = _bf71;
    } 
    int _bf39;
    if ( _bf36 ) {
        _bf39 = _bf72;
    } else  { 
        _bf39 = _bf75;
    } 
    int _bf43;
    if ( _bf40 ) {
        _bf43 = _bf77;
    } else  { 
        _bf43 = _bf78;
    } 
    int _bf44 = _bf28;
    int _bf73 = _bf28;
    int _bf45 = _bf39;
    int _bf74 = _bf39;
    int _bf55 = _bf32;
    int _bf68 = _bf32;
    int _bf56 = _bf43;
    int _bf67 = _bf43;
    bool _bf46 = _bf44 < _bf45;
    bool _bf57 = _bf55 < _bf56;
    int _bf48 = _bf73;
    int _bf53 = _bf73;
    int _bf49 = _bf74;
    int _bf52 = _bf74;
    int _bf59 = _bf68;
    int _bf64 = _bf68;
    int _bf60 = _bf67;
    int _bf63 = _bf67;
    bool _bf47 = _bf46;
    bool _bf51 = _bf46;
    bool _bf58 = _bf57;
    bool _bf62 = _bf57;
    int _bf79 = _bf48;
    int _bf80 = _bf49;
    int _bf84 = _bf52;
    int _bf85 = _bf53;
    int _bf86 = _bf59;
    int _bf87 = _bf60;
    int _bf88 = _bf63;
    int _bf91 = _bf64;
    int x_0_3;
    if ( _bf47 ) {
        x_0_3 = _bf79;
    } else  { 
        x_0_3 = _bf80;
    } 
    int x_1_3;
    if ( _bf51 ) {
        x_1_3 = _bf84;
    } else  { 
        x_1_3 = _bf85;
    } 
    int x_2_3;
    if ( _bf62 ) {
        x_2_3 = _bf88;
    } else  { 
        x_2_3 = _bf91;
    } 
    int x_3_3;
    if ( _bf58 ) {
        x_3_3 = _bf86;
    } else  { 
        x_3_3 = _bf87;
    } 
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
       std::cout << "x_0_3: " << x_0_3 << "x_1_3: " << x_1_3 << "x_2_3: " << x_2_3 << "x_3_3: " << x_3_3 << std::endl;

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    return 0;
}