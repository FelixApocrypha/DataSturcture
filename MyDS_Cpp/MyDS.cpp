#include <iostream>
#include "Includes/seq_list.h"
#include <vector>
int main()
{
    MyDS::SeqList<int> sq1 = {1,2,3};
    MyDS::SeqList<int> sq2(sq1);
    std::cout << sq1.At(2) << "\n";
    std::cout << sq2.At(2) << "\n";

    std::cout << "This is My Data Sturcture of Cpp.\n";
    return 0;
}

