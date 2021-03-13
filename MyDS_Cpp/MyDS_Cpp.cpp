#include <iostream>
#include "Include/seq_list.h"
#include <vector>

int main()
{
    MyDS::SeqList<int> mySeqList = {1,2};
    MyDS::SeqList<int> s(11, 2);
    std::cout << mySeqList.At(0) << "\n";
    std::cout << MyDS::SeqList<int>::MAX_SIZE << "\n";
    std::cout << "This is an attempt for me to learn data structure and review for postgraduate entrance examination.\n";
    return 0;
}

