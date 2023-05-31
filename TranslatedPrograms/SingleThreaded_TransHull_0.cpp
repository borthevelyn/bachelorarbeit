
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

    bool m_0_0;
    bool m_0_1;
    bool m_1_0;
    bool m_1_1;
    auto start = chrono::steady_clock::now();
    bool _bf15 = m_0_1;
    bool _bf17 = m_0_1;
    bool _bf21 = m_1_0;
    bool _bf22 = m_1_0;
    bool _bf8 = m_0_0;
    bool _bf11 = m_0_0;
    bool _bf9 = _bf11;
    bool _bf10 = _bf11;
    bool _bf0 = _bf15;
    bool _bf5 = _bf17;
    bool _bf19 = _bf21;
    bool _bf55 = _bf22;
    bool _bf83 = _bf8;
    bool _bf12 = _bf9 && _bf10;
    bool _bf1 = _bf0;
    bool _bf6 = _bf5;
    bool _bf25 = _bf19;
    bool _bf56 = _bf55;
    bool _bf84 = _bf83;
    bool _bf14 = _bf84 || _bf12;
    bool _bf2 = _bf1;
    bool _bf7 = _bf6;
    bool _bf27 = _bf25;
    bool _bf57 = _bf56;
    bool _bf16 = _bf14;
    bool _bf74 = _bf14;
    bool _bf3 = _bf2;
    bool _bf13 = _bf7;
    bool _bf36 = _bf27;
    bool _bf58 = _bf57;
    bool _bf18 = _bf16 && _bf13;
    bool _bf23 = _bf74;
    bool _bf32 = _bf74;
    bool _bf4 = _bf3;
    bool _bf42 = _bf36;
    bool _bf59 = _bf58;
    bool _bf20 = _bf4 || _bf18;
    bool _bf24 = _bf59 && _bf23;
    bool _bf48 = _bf42;
    bool _bf61 = _bf32;
    bool _bf26 = _bf48 || _bf24;
    bool _bf29 = _bf20;
    bool _bf70 = _bf20;
    bool _bf62 = _bf61;
    bool _bf28 = _bf26;
    bool _bf71 = _bf26;
    bool _bf33 = _bf70;
    bool _bf41 = _bf70;
    bool _bf60 = _bf29;
    bool _bf63 = _bf62;
    bool _bf30 = _bf28 && _bf60;
    bool _bf34 = _bf71;
    bool _bf47 = _bf71;
    bool _bf37 = _bf41;
    bool _bf38 = _bf41;
    bool _bf64 = _bf63;
    bool _bf67 = _bf33;
    bool _bf31 = m_1_1 || _bf30;
    bool _bf35 = _bf67 && _bf34;
    bool _bf43 = _bf47;
    bool _bf45 = _bf47;
    bool _bf65 = _bf64;
    bool _bf68 = _bf37;
    bool _bf73 = _bf38;
    bool t_0_0 = _bf65 || _bf35;
    bool _bf39 = _bf31;
    bool _bf66 = _bf31;
    bool _bf69 = _bf68;
    bool _bf75 = _bf73;
    bool _bf76 = _bf43;
    bool _bf79 = _bf45;
    bool _bf40 = _bf75 && _bf39;
    bool _bf44 = _bf66;
    bool _bf54 = _bf66;
    bool _bf72 = _bf69;
    bool _bf77 = _bf76;
    bool _bf80 = _bf79;
    bool t_0_1 = _bf72 || _bf40;
    bool _bf46 = _bf44 && _bf80;
    bool _bf49 = _bf54;
    bool _bf52 = _bf54;
    bool _bf78 = _bf77;
    bool t_1_0 = _bf78 || _bf46;
    bool _bf50 = _bf52;
    bool _bf51 = _bf52;
    bool _bf81 = _bf49;
    bool _bf53 = _bf50 && _bf51;
    bool _bf82 = _bf81;
    bool t_1_1 = _bf82 || _bf53;
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
       std::cout << "t_0_0: " << t_0_0 << "t_0_1: " << t_0_1 << "t_1_0: " << t_1_0 << "t_1_1: " << t_1_1 << std::endl;

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    return 0;
}