#pragma once
#include <optional>
#include "myds_basic.h"
#include "exception_info.h"

#define SIZE_TYPE size_t
#define INDEX_TYPE size_t
#define INDEX_RET_VAL_TYPE std::optional<INDEX_TYPE>
#define INDEX_RET_ERROR_VAL std::nullopt
#define MAKE_INDEX_RET_VAL(val) std::make_optional<INDEX_TYPE>(val)

MyDS_BEGIN
template<typename T>
class BasicList
{
public:
	using Val_t = T;
	using Ref_t = T&;
	using Size_t = SIZE_TYPE;
	using Index_t = INDEX_TYPE;
	using Index_Ret_Val_t = INDEX_RET_VAL_TYPE;

	virtual Ref_t front() = 0;	//首元素
	virtual Ref_t back() = 0;	//尾元素

	//判断是否为空表
	virtual bool IsEmpty()const = 0;
	//求表长
	virtual Size_t Size()const = 0;
	//清空表
	virtual void Clear() = 0;
	//获取固定位置的引用
	virtual Ref_t At(const Index_t& n) = 0;
	//获取固定位置的值
	virtual Val_t Get(const Index_t& n)const = 0;
	//更改固定位置的值, 当前值与更改值相同时返回false;
	virtual bool Set(const Index_t& n, const Val_t& v) = 0;
	//查找元素并返回其位置
	virtual Index_Ret_Val_t Find(const Val_t& v)const = 0;
	//查找元素并返回其前驱元素位置
	virtual Index_Ret_Val_t FindValuePrior(const Val_t& v)const = 0;
	//查找元素并返回其后继元素位置
	virtual Index_Ret_Val_t FindValueNext(const Val_t& v)const = 0;
	//插入
	virtual bool Insert(const Index_t& n, const Val_t& v) = 0;
	//删除
	virtual bool Erase(const Index_t& n) = 0;
	//尾部插入
	virtual bool PushBack(const Val_t& v) = 0;
	//尾部删除
	virtual bool PopBack() = 0;
	//遍历操作，F为自定义函数
	//template<typename F>
	//virtual void Foreach(const F& f) = 0;
};
MyDS_END