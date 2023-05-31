
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

    int a;
    auto start = chrono::steady_clock::now();
    int _bf1 = 2;
    int _bf4 = 3;
    int _bf0 = a;
    int _bf3 = a;
    int _bf2 = _bf0 * _bf1;
    int _bf5 = _bf3 * _bf4;
    int _bf6 = _bf2;
    int b = _bf2;
    int _bf7 = _bf5;
    int c = _bf7 + _bf6;
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
       std::cout << "b: " << b << "c: " << c << std::endl;

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    return 0;
}