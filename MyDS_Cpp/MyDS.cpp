#include <iostream>
#include "Includes/seq_list.h"
#include <vector>
int main()
{
    MyDS::SeqList<std::vector<int>> seq(3);
    seq.PushBack(std::vector<int>(2, 1));
    ++seq.At(3).at(0);
    ++seq.Get(3).at(0);
    std::cout << seq.At(3).at(0) << "\n";

    std::cout << "This is My Data Sturcture of Cpp.\n";
    return 0;
}

