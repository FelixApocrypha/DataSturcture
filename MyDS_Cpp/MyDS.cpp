#include <iostream>
#include "Examples/seqlist_ex.h"
int main()
{
    MyDS::Ex::SeqListEx SeqL_Ex;
    //SeqL_Ex.Example();

    MyDS::SeqList<int> sq1 = {1, 2, 3};
    sq1.ForEach([](auto n)
    {
        std::cout << n << "\n";
    });

    //std::cout << "This is My Data Sturcture of Cpp.\n";
    return 0;
}

