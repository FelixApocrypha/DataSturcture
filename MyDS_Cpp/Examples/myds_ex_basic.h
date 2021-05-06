/*----------------------------------------------------------------------------
 Copyright(c) 2019-2021 SnowyLake
 All rights reserved.

 @File:  myds_ex_basic.h
 @State: Developing
 @Version: 0.1

 @Author: SnowyLake
 @E-mail: Felix2000@foxmail.com

 @Creation Time:  2021/03/18
 @Abstract:
    Some macros in example classes.

 @Finished Time:


 @Change History:
 ========================================================================
  <Date>		| <Version> | <Author>		| <Description>
 ========================================================================
  2021/03/18	| 0.1		| SnowyLake		| Create file
 ------------------------------------------------------------------------
            	|   		|       		|
 ========================================================================
----------------------------------------------------------------------------*/

#pragma once
#include <iostream>
#include <chrono>
#include "Includes/myds_basic.h"

MyDS_Ex_BEGIN
//debug log
#define ExLOG std::cout
#define ExLOG_BL std::cout << "\n"
#define ExLOG_NL "\n"
#define ExLOG_TAB "\t"

//clock
#define TIME_NOW std::chrono::system_clock::now()
MyDS_Ex_END