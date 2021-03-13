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

//SeqList���캯������������
public:
	SeqList(Size_t m = 0);
	SeqList(Size_t m, const T& val = T());
	SeqList(std::initializer_list<Val_t> vList);
	/*
	ʹ��ģ��䳤����ʵ�ֵĹ��캯��������SeqList(Size_t n, const T& val = T())��ͻ��
	����������ΪSeqList(std::initializer_list<Val_t> vList)ʵ�֡�
	���룺
		template<typename ...Vals_t>
		SeqList(Vals_t... vals) :vals {vals...}
		{ size = sizeof...(Vals_t); }
	*/
	~SeqList() {};

//�ֶ�
private:
	Val_t* vals;
	Size_t size;
	Size_t capacity;

//����
public:
	Ref_t front();	//��Ԫ��
	Ref_t back();	//βԪ��

	//�ж��Ƿ�Ϊ�ձ�
	bool IsEmpty()const;
	//���
	Size_t Size()const;
	//��ձ�
	void Clear();
	//��ȡ�̶�λ�õ�����
	Ref_t At(Size_t n);
	//��ȡ�̶�λ�õ�ֵ
	Val_t Get(Size_t n)const;
	//���Ĺ̶�λ�õ�ֵ
	bool Set(Size_t n, const Val_t& v);
	//����Ԫ�ز�������λ��
	Size_t Find(const Val_t& v)const;
	//����Ԫ�ز�������ǰ��Ԫ��λ��
	Size_t FindValuePrior(const Val_t& v)const;
	//����Ԫ�ز���������Ԫ��λ��
	Size_t FindValueNext(const Val_t& v)const;
	//����
	bool Insert(Size_t n, const Val_t& v);
	//ɾ��
	bool Erase(const Size_t& v);
	//β������
	bool push_back(const Val_t& v);
	//β��ɾ��
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

//�ж��Ƿ�Ϊ�ձ�
template<typename Val_t>
bool MyDS::SeqList<Val_t>::IsEmpty()const{}
//���
template<typename Val_t>
SIZE_TYPE MyDS::SeqList<Val_t>::Size()const{}
//��ձ�
template<typename Val_t>
void MyDS::SeqList<Val_t>::Clear(){}
//��ȡ�̶�λ�õ�����
template<typename Val_t>
Val_t& MyDS::SeqList<Val_t>::At(Size_t n){}
//��ȡ�̶�λ�õ�ֵ
template<typename Val_t>
Val_t MyDS::SeqList<Val_t>::Get(Size_t n)const{}
//���Ĺ̶�λ�õ�ֵ
template<typename Val_t>
bool MyDS::SeqList<Val_t>::Set(Size_t n, const Val_t& v){}
//����Ԫ�ز�������λ��
template<typename Val_t>
SIZE_TYPE MyDS::SeqList<Val_t>::Find(const Val_t& v)const{}
//����Ԫ�ز�������ǰ��Ԫ��λ��
template<typename Val_t>
SIZE_TYPE MyDS::SeqList<Val_t>::FindValuePrior(const Val_t& v)const{}
//����Ԫ�ز���������Ԫ��λ��
template<typename Val_t>
SIZE_TYPE MyDS::SeqList<Val_t>::FindValueNext(const Val_t& v)const{}
//����
template<typename Val_t>
bool MyDS::SeqList<Val_t>::Insert(Size_t n, const Val_t& v){}
//ɾ��
template<typename Val_t>
bool MyDS::SeqList<Val_t>::Erase(const Size_t& v){}
//β������
template<typename Val_t>
bool MyDS::SeqList<Val_t>::push_back(const Val_t& v){}
//β��ɾ��
template<typename Val_t>
bool MyDS::SeqList<Val_t>::pop_back(const Val_t& v){}