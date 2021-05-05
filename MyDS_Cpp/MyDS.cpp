/*----------------------------------------------------------------------------
 Copyright(c) 2019-2021 SnowyLake
 All rights reserved.

 @File:   MyDS.cpp

 @Author: SnowyLake
 @E-mail: Felix2000@foxmail.com

 @Abstract:
    Realization of basic data structure based on C++17 or C++20.
    This project is an attempt for me to learn data structure and review
    for postgraduate entrance examination.
----------------------------------------------------------------------------*/

#include <iostream>
#include "Examples/seqlist_ex.h"
int main()
{
    std::cout << "This is My Data Sturcture of Cpp.\n"
              << "---------------------------------\n"
              << '\n';

    MyDS::Ex::SeqListEx SqL_Ex;
    SqL_Ex.Example();
    
    return 0;
}

