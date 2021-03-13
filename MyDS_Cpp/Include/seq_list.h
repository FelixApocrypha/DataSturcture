#pragma once
#define SIZE_TYPE int

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
	using Size_t = int;

//SeqList构造函数、析构函数
public:
	SeqList(Size_t m = 0);
	SeqList(Size_t m, const T& val = T());
	SeqList(std::initializer_list<Val_t> vList);
	/*
	使用模板变长参数实现的构造函数，因与SeqList(Size_t n, const T& val = T())冲突，
	故舍弃，改为SeqList(std::initializer_list<Val_t> vList)实现。
	代码：
		template<typename ...Vals_t>
		SeqList(Vals_t... vals) :vals {vals...}
		{ size = sizeof...(Vals_t); }
	*/
	~SeqList() {};

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
	Ref_t At(Size_t n);
	//获取固定位置的值
	Val_t Get(Size_t n)const;
	//更改固定位置的值
	bool Set(Size_t n, const Val_t& v);
	//查找元素并返回其位置
	Size_t Find(const Val_t& v)const;
	//查找元素并返回其前驱元素位置
	Size_t FindValuePrior(const Val_t& v)const;
	//查找元素并返回其后继元素位置
	Size_t FindValueNext(const Val_t& v)const;
	//插入
	bool Insert(Size_t n, const Val_t& v);
	//删除
	bool Erase(const Size_t& v);
	//尾部插入
	bool push_back(const Val_t& v);
	//尾部删除
	bool pop_back(const Val_t& v);
};
}
template<typename T>
MyDS::SeqList<T>::SeqList(Size_t m) :capacity(m)
{
	size = 0;
	if(m == 0)
		vals = nullptr;
	else
		vals = new T[m];
}
template<typename T>
MyDS::SeqList<T>::SeqList(Size_t m, const T& val) :size(m), capacity(m)
{
	if(m == 0)
		vals = nullptr;
	else
		vals = new T[m];

	for(Size_t i = 0; i < m; ++i)
		vals[i] = val;
}
//
//template<typename Val_t>
//MyDS::SeqList<Val_t>::SeqList(std::initializer_list<Val_t> vList)
//{
//	THROW_OUT_OF_RANGE_IF(!(vList.size() < MAX_SIZE), "SeqList<T> maximum capacity is 100.");
//	std::copy(vList.begin(), vList.end(), vals);
//	size = vList.size();
//}
//
//template<typename Val_t>
//Val_t MyDS::SeqList<Val_t>::At(size_t n) 
//{
//	THROW_OUT_OF_RANGE_IF(!(n < size), "SeqList<T>::At() subscript out of range.");
//	return vals[n];
//}
//
//template<typename Val_t>
//size_t MyDS::SeqList<Val_t>::Size() { return this->size; }

//判断是否为空表
template<typename Val_t>
bool MyDS::SeqList<Val_t>::IsEmpty()const{}
//求表长
template<typename Val_t>
SIZE_TYPE MyDS::SeqList<Val_t>::Size()const{}
//清空表
template<typename Val_t>
void MyDS::SeqList<Val_t>::Clear(){}
//获取固定位置的引用
template<typename Val_t>
Val_t& MyDS::SeqList<Val_t>::At(Size_t n){}
//获取固定位置的值
template<typename Val_t>
Val_t MyDS::SeqList<Val_t>::Get(Size_t n)const{}
//更改固定位置的值
template<typename Val_t>
bool MyDS::SeqList<Val_t>::Set(Size_t n, const Val_t& v){}
//查找元素并返回其位置
template<typename Val_t>
SIZE_TYPE MyDS::SeqList<Val_t>::Find(const Val_t& v)const{}
//查找元素并返回其前驱元素位置
template<typename Val_t>
SIZE_TYPE MyDS::SeqList<Val_t>::FindValuePrior(const Val_t& v)const{}
//查找元素并返回其后继元素位置
template<typename Val_t>
SIZE_TYPE MyDS::SeqList<Val_t>::FindValueNext(const Val_t& v)const{}
//插入
template<typename Val_t>
bool MyDS::SeqList<Val_t>::Insert(Size_t n, const Val_t& v){}
//删除
template<typename Val_t>
bool MyDS::SeqList<Val_t>::Erase(const Size_t& v){}
//尾部插入
template<typename Val_t>
bool MyDS::SeqList<Val_t>::push_back(const Val_t& v){}
//尾部删除
template<typename Val_t>
bool MyDS::SeqList<Val_t>::pop_back(const Val_t& v){}