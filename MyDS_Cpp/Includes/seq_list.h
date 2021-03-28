#pragma once
#include "basic_list.h"
MyDS_BEGIN
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
	SeqList(const SeqList<T>& rSeqL);
	SeqList(const Size_t& m = 0, const T& val = T());
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
	//求最大容量
	Size_t Capacity()const;
	//清空表
	void Clear();
	//获取固定位置的引用
	Ref_t At(const Index_t& n);
	//获取固定位置的值
	Val_t Get(const Index_t& n)const;
	//更改固定位置的值, 当前值与更改值相同时返回false;
	bool Set(const Index_t& n, const Val_t& v);
	//查找元素并返回其位置
	Index_Ret_Val_t Find(const Val_t& v)const;
	//查找元素并返回其前驱元素位置
	Index_Ret_Val_t FindValuePrior(const Val_t& v)const;
	//查找元素并返回其后继元素位置
	Index_Ret_Val_t FindValueNext(const Val_t& v)const;
	//插入
	bool Insert(const Index_t& n, const Val_t& v);
	//删除
	bool Erase(const Index_t& n);
	//尾部插入
	bool PushBack(const Val_t& v);
	//尾部删除
	bool PopBack();

	//重载==运算符
	bool operator==(const SeqList<Val_t>& rSeqL);
};
MyDS_END

template<typename T>
inline MyDS::SeqList<T>::SeqList(const SeqList<T>& rSeqL)
{
	size = rSeqL.size;
	capacity = rSeqL.capacity;
	vals = new Val_t[size];

	Val_t* vPtr = rSeqL.vals;
	for(int i = 0; i < rSeqL.size; ++i)
		vals[i] = *(vPtr++);
}
template<typename T>
inline MyDS::SeqList<T>::SeqList(const Size_t& m, const T& val) :size(m), capacity(m)
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

//取表头
template<typename Val_t>
inline Val_t& MyDS::SeqList<Val_t>::front()
{
	THROW_OUT_OF_RANGE_IF(IsEmpty(), "SeqList<T> is empty.");
	return vals[0];
}
//取表尾
template<typename Val_t>
Val_t& MyDS::SeqList<Val_t>::back()
{
	THROW_OUT_OF_RANGE_IF(IsEmpty(), "SeqList<T> is empty.");
	return vals[size - 1];
}

//判断是否为空表
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::IsEmpty()const
{ return size == 0 ? true : false; }
//求表长
template<typename Val_t>
inline SIZE_TYPE MyDS::SeqList<Val_t>::Size()const
{ return size; }
//求最大容量
template<typename T>
inline SIZE_TYPE MyDS::SeqList<T>::Capacity() const
{ return capacity; }
//清空表
template<typename Val_t>
inline void MyDS::SeqList<Val_t>::Clear()
{ size = 0; }
//获取固定位置的引用
template<typename Val_t>
inline Val_t& MyDS::SeqList<Val_t>::At(const Index_t& n)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::At() subscript out of range.");
	return vals[n];
}
//获取固定位置的值
template<typename Val_t>
inline Val_t MyDS::SeqList<Val_t>::Get(const Index_t& n)const
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Get() subscript out of range.");
	return vals[n];
}
//更改固定位置的值, 当前值与更改值相同时返回false;
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::Set(const Index_t& n, const Val_t& v)
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
		return MAKE_INDEX_RET_VAL(i);
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
inline bool MyDS::SeqList<Val_t>::Insert(const Index_t& n, const Val_t& v)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Insert() subscript out of range.");
	if(size >= capacity)
	{
		Val_t* tmp = new Val_t[capacity + 10];
		if(tmp == nullptr)
			return false;
		for(size_t i = 0; i < size; ++i)
			tmp[i] = vals[i];
		delete[] vals;
		vals = tmp;
		tmp = nullptr;
		capacity += 10;
	}
	Val_t* pos = &vals[n];
	for(Val_t* ptr = &vals[size - 1]; ptr >= pos; --ptr)
		*(ptr + 1) = *ptr;
	*pos = v;
	++size;
	return true;
}
//删除
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::Erase(const Index_t& n)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Erase() subscript out of range.");
	Val_t* end = vals + size - 1;
	for(Val_t* ptr = &vals[n + 1]; ptr <= end; ++ptr)
		*(ptr - 1) = *ptr;
	--size;
	return true;
}
//尾部插入
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::PushBack(const Val_t& v)
{
	if(size >= capacity)
	{
		Val_t* tmp = new Val_t[capacity + 10];
		if(tmp == nullptr)
			return false;
		for(size_t i = 0; i < size; ++i)
			tmp[i] = vals[i];
		delete[] vals;
		vals = tmp;
		tmp = nullptr;
		capacity += 10;
	}
	vals[size++] = v;
	return true;
}
//尾部删除
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::PopBack()
{
	THROW_OUT_OF_RANGE_IF(IsEmpty(), "SeqList<T>::Insert() is empty.");
	size -= 1;
	return true;
}

template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::operator==(const SeqList<Val_t>& rSeqL)
{
	if(this->size != rSeqL.Size())
		return false;
	for(int i = 0; i < size; ++i)
	{
		if(vals[i] != rSeqL.Get(i))
			return false;
	}
	return true;
}
