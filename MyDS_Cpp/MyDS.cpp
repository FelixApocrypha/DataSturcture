//This is a brench for CPTR

#include <iostream>
#include "Examples/seqlist_ex.h"
#include "Includes/seq_list.h"
int main()
{
    //MyDS::Ex::SeqListEx SeqL_Ex;
    //SeqL_Ex.Example();
    auto a = 1;
    MyDS::SeqList<int> sq1 = {1,2,3};
    sq1.ForEach([](const std::string& x) { std::cout << x << '\n'; });
    sq1.ForEach([=](auto&& x) { x += a; std::cout << x << '\n'; });
    sq1.ForEach([=](auto&& x) { std::cout << x + a << '\n'; });
    //std::cout << "This is My Data Sturcture of Cpp.\n";
    return 0;
}

