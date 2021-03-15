#pragma once
#include <optional>

#include "exception_info.h"
#include "basic_list.h"
namespace MyDS
{
template<typename T>
class SeqList : BasicList<T>
{
public:
	using Val_t = T;
	using Ref_t = T&;
	using Size_t = SIZE_TYPE;
	using Index_t = INDEX_TYPE;
	using Index_Ret_Val_t = INDEX_RET_VAL_TYPE;
	
//构造函数、析构函数
public:
	SeqList(Size_t m = 0);
	SeqList(const SeqList<T>& rSeqL);
	SeqList(Size_t m, const T& val = T());
	SeqList(const std::initializer_list<Val_t>& vList);
	~SeqList();

//字段
private:
	Val_t* vals;
	Size_t size;
	Size_t capacity;

//方法
public:
	Ref_t front();	//首元素
	Ref_t back();	//尾元素

	//判断是否为空表
	bool IsEmpty()const;
	//求表长
	Size_t Size()const;
	//清空表
	void Clear();
	//获取固定位置的引用
	Ref_t At(Index_t n);
	//获取固定位置的值
	Val_t Get(Index_t n)const;
	//更改固定位置的值, 当前值与更改值相同时返回false;
	bool Set(Index_t n, const Val_t& v);
	//查找元素并返回其位置
	Index_Ret_Val_t Find(const Val_t& v)const;
	//查找元素并返回其前驱元素位置
	Index_Ret_Val_t FindValuePrior(const Val_t& v)const;
	//查找元素并返回其后继元素位置
	Index_Ret_Val_t FindValueNext(const Val_t& v)const;
	//插入
	bool Insert(Index_t n, const Val_t& v);
	//删除
	bool Erase(const Index_t& v);
	//尾部插入
	bool push_back(const Val_t& v);
	//尾部删除
	bool pop_back(const Val_t& v);

//私有方法
private:
	void CopyFrom(const SeqList<T>& rSeqL);
};
}
template<typename T>
inline MyDS::SeqList<T>::SeqList(Size_t m) :capacity(m)
{
	size = 0;
	if(m == 0)
		vals = nullptr;
	else
		vals = new T[m];
}
template<typename T>
inline MyDS::SeqList<T>::SeqList(const SeqList<T>& rSeqL)
{
	size = 0;
	capacity = 0;
	vals = nullptr;
	CopyFrom(rSeqL);
}
template<typename T>
inline MyDS::SeqList<T>::SeqList(Size_t m, const T& val) :size(m), capacity(m)
{
	if(m == 0)
		vals = nullptr;
	else
		vals = new T[m];

	for(Size_t i = 0; i < m; ++i)
		vals[i] = val;
}
template<typename T>
inline MyDS::SeqList<T>::SeqList(const std::initializer_list<Val_t>& vList) :size(vList.size()), capacity(vList.size())
{
	vals = new T[vList.size() + 1];
	int n = 0;
	for(auto& i : vList)
		vals[n++] = i;
}
template<typename T>
inline MyDS::SeqList<T>::~SeqList()
{ delete[]vals; }

template<typename Val_t>
inline Val_t& MyDS::SeqList<Val_t>::front()
{
	THROW_OUT_OF_RANGE_IF(IsEmpty(), "SeqList<T> is empty.");
	return vals[0];
}

template<typename Val_t>
Val_t& MyDS::SeqList<Val_t>::back(){}

//判断是否为空表
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::IsEmpty()const
{ return size == 0 ? true : false; }
//求表长
template<typename Val_t>
inline SIZE_TYPE MyDS::SeqList<Val_t>::Size()const
{ return size; }
//清空表
template<typename Val_t>
inline void MyDS::SeqList<Val_t>::Clear(){}
//获取固定位置的引用
template<typename Val_t>
inline Val_t& MyDS::SeqList<Val_t>::At(Index_t n)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::At() subscript out of range.");
	return vals[n];
}
//获取固定位置的值
template<typename Val_t>
inline Val_t MyDS::SeqList<Val_t>::Get(Index_t n)const
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Get() subscript out of range.");
	return vals[n];
}
//更改固定位置的值, 当前值与更改值相同时返回false;
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::Set(Index_t n, const Val_t& v)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Set() subscript out of range.");
	if(v == vals[n])
		return false;
	else
	{
		vals[n] = v;
		return true;
	}
}
//查找元素并返回其位置
template<typename Val_t>
inline INDEX_RET_VAL_TYPE MyDS::SeqList<Val_t>::Find(const Val_t& v)const
{
	Val_t* p = vals;
	INDEX_TYPE i = 0;
	while(i < size && *p != v)
	{
		++p;
		++i;
	}
	if(i < size)
		return std::make_optional<INDEX_TYPE>(i);
	return INDEX_RET_ERROR_VAL;
}
//查找元素并返回其前驱元素位置
template<typename Val_t>
inline INDEX_RET_VAL_TYPE MyDS::SeqList<Val_t>::FindValuePrior(const Val_t& v)const
{ 
	auto opt = Find(v);
	return opt == 0 || opt == INDEX_RET_ERROR_VAL ? INDEX_RET_ERROR_VAL : MAKE_INDEX_RET_VAL(--opt.value());
}
//查找元素并返回其后继元素位置
template<typename Val_t>
inline INDEX_RET_VAL_TYPE MyDS::SeqList<Val_t>::FindValueNext(const Val_t& v)const
{ 
	auto opt = Find(v);
	return opt == size - 1 || opt == INDEX_RET_ERROR_VAL ? INDEX_RET_ERROR_VAL : MAKE_INDEX_RET_VAL(++opt.value());
}
//插入
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::Insert(Index_t n, const Val_t& v)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Get() subscript out of range.");
}
//删除
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::Erase(const Index_t& v){}
//尾部插入
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::push_back(const Val_t& v){}
//尾部删除
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::pop_back(const Val_t& v){}

//复制
template<typename T>
inline void MyDS::SeqList<T>::CopyFrom(const SeqList<T>& rSeqL)
{

}
