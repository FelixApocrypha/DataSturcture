/*----------------------------------------------------------------------------
 Copyright(c) 2019-2021 SnowyLake
 All rights reserved.

 @File:  exception_info.h
 @State: Finished
 @Version: 0.2

 @Author: SnowyLake
 @E-mail: Felix2000@foxmail.com

 @Creation Time:  2021/03/13
 @Abstract:
	The base classes for SeqList and LinkList.

 @Finished Time:  2021/05/03


 @Change History:
 ========================================================================
  <Date>		| <Version> | <Author>		| <Description>
 ========================================================================
  2021/03/13	| 0.1		| SnowyLake		| Create file
 ------------------------------------------------------------------------
  2021/05/05	| 0.2		| SnowyLake		| Add MYDS_DEBUG
 ========================================================================
----------------------------------------------------------------------------*/
#pragma once
#include "myds_basic.h"
#include <stdexcept>
#include <cassert>

MyDS_BEGIN
#define MYDS_DEBUG(expr) \
  assert(expr) 

#define THROW_LENGTH_ERROR_IF(expr, what) \
  if ((expr)) throw std::length_error(what)

#define THROW_OUT_OF_RANGE_IF(expr, what) \
  if ((expr)) throw std::out_of_range(what)

#define THROW_RUNTIME_ERROR_IF(expr, what) \
  if ((expr)) throw std::runtime_error(what)
MyDS_END