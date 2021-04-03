#include <iostream>
#include "Examples/seqlist_ex.h"

auto FuncL = [](auto n) { std::cout << n << "\n"; };

int main()
{
    MyDS::Ex::SeqListEx SeqL_Ex;
    SeqL_Ex.Example();

    //std::cout << "This is My Data Sturcture of Cpp.\n";
    return 0;
}

