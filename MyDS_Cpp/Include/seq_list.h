#pragma once
#include"exception_info.h"

namespace MyDS
{
	template<typename T>
	class SeqList
	{
		
	public:
		using Val_t = T;
		using Size_t = size_t;
	public:
		static const Size_t MAX_SIZE = 100;

	//SeqList构造函数、析构函数
	public:
		SeqList() {}
		SeqList(Size_t n, const Val_t& val = Val_t());
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
		Val_t vals[MAX_SIZE];
		Size_t size = 0;

	//方法
	public:
		Val_t At(size_t n);
		Size_t Size();
	};
}

template<typename Val_t>
MyDS::SeqList<Val_t>::SeqList(Size_t n, const Val_t& val) :size(n)
{
	THROW_OUT_OF_RANGE_IF(!(n < MAX_SIZE), "SeqList<T> maximum capacity is 100.");
	for(Size_t i = 0; i < n; ++i)
		vals[i] = val;
}

template<typename Val_t>
MyDS::SeqList<Val_t>::SeqList(std::initializer_list<Val_t> vList)
{
	THROW_OUT_OF_RANGE_IF(!(vList.size() < MAX_SIZE), "SeqList<T> maximum capacity is 100.");
	std::copy(vList.begin(), vList.end(), vals);
	size = vList.size();
}

template<typename Val_t>
Val_t MyDS::SeqList<Val_t>::At(size_t n) 
{
	THROW_OUT_OF_RANGE_IF(!(n < size), "SeqList<T>::At() subscript out of range.");
	return vals[n];
}

template<typename Val_t>
size_t MyDS::SeqList<Val_t>::Size() { return this->size; }