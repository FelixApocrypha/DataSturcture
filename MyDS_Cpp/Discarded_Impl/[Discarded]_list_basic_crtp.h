/*----------------------------------------------------------------------------
 Copyright(c) 2019-2021 SnowyLake
 All rights reserved.

 @File:  list_basic_crtp.h
 @State: Discarded
 @Version: 0.2

 @Author: SnowyLake
 @E-mail: Felix2000@foxmail.com

 @Creation Time:  2021/05/02
 @Abstract:
	Use CRTP to define the base classes for SeqList and LinkList.

 @Discarded Time: 2021/05/03
 @Reasons for Discarded：
	CRTP cannot Constraint the implementation of a subclass's
	function like pure virtual function.
	So only use it in ForEach().


 @Change History:
  <Date>      | <Version> | <Author>       | <Description>
 ---------------------------------------------------------------
  2021/05/02  | 0.1       | SnowyLake      | Create file
 ---------------------------------------------------------------
  2014/05/03  | 0.2       | SnowyLake      | Discarded
----------------------------------------------------------------------------*/
#pragma once
#include <optional>
#include "../Includes/myds_basic.h"
#include "../Includes/exception_info.h"

#define SIZE_TYPE size_t
#define INDEX_TYPE size_t
#define INDEX_RET_VAL_TYPE std::optional<INDEX_TYPE>
#define INDEX_RET_ERROR_VAL std::nullopt
#define MAKE_INDEX_RET_VAL(val) std::make_optional<INDEX_TYPE>(val)

MyDS_BEGIN
template<typename Child, typename T>
class ListBasic
{
public:
	using Val_t = T;
	using Ref_t = T&;
	using Size_t = SIZE_TYPE;
	using Index_t = INDEX_TYPE;
	using Index_Ret_Val_t = INDEX_RET_VAL_TYPE;

	//首元素
	Ref_t front() { Derived()->front(); }
	//尾元素
	Ref_t back() { Derived()->front(); }

	//判断是否为空表
	bool IsEmpty()const { Derived()->IsEmpty(); }
	//求表长
	Size_t Size()const { Derived()->Size(); }
	//清空表
	void Clear() { Derived()->Clear(); }
	//获取固定位置的引用
	Ref_t At(const Index_t& n) { Derived()->At(n); }
	//获取固定位置的值
	Val_t Get(const Index_t& n)const { Derived()->Get(n); }
	//更改固定位置的值, 当前值与更改值相同时返回false;
	bool Set(const Index_t& n, const Val_t& v) { Derived()->Set(n, v); }
	//查找元素并返回其位置
	Index_Ret_Val_t Find(const Val_t& v)const { Derived()->Find(v); }
	//查找元素并返回其前驱元素位置
	Index_Ret_Val_t FindValuePrior(const Val_t& v)const { Derived()->FindValuePrior(v); }
	//查找元素并返回其后继元素位置
	Index_Ret_Val_t FindValueNext(const Val_t& v)const { Derived()->FindValueNext(v); }
	//插入
	bool Insert(const Index_t& n, const Val_t& v) { Derived()->Insert(n, v); }
	//删除
	bool Erase(const Index_t& n) { Derived()->Erase(n); }
	//尾部插入
	bool PushBack(const Val_t& v) { Derived()->PushBack(v); }
	//尾部删除
	bool PopBack() { Derived()->PopBack(); }
	//遍历操作，F为自定义函数
	template<typename F>
	void Foreach(const F& f) { Derived()->Foreach(f); }

private:
	inline Child* Derived() { return static_cast<Child*>(this); }
};
MyDS_END