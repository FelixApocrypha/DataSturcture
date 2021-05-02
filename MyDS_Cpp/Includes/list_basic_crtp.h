/*-------------------------------------------------------------------
 @list_basic_crtp.h Ver0.1

 @Author: SnowyLake
 @Creation Time: 2021/5/3
 @Abstract:
	Use CRTP to define the base classes for SeqList and LinkList.
-------------------------------------------------------------------*/ 
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
template<typename Child, typename T>
class ListBasic
{
public:
	using Val_t = T;
	using Ref_t = T&;
	using Size_t = SIZE_TYPE;
	using Index_t = INDEX_TYPE;
	using Index_Ret_Val_t = INDEX_RET_VAL_TYPE;

	//��Ԫ��
	Ref_t front() { Derived()->front(); }
	//βԪ��
	Ref_t back() { Derived()->front(); }

	//�ж��Ƿ�Ϊ�ձ�
	bool IsEmpty()const { Derived()->IsEmpty(); }
	//�����
	Size_t Size()const { Derived()->Size(); }
	//��ձ�
	void Clear() { Derived()->Clear(); }
	//��ȡ�̶�λ�õ�����
	Ref_t At(const Index_t& n) { Derived()->At(n); }
	//��ȡ�̶�λ�õ�ֵ
	Val_t Get(const Index_t& n)const { Derived()->Get(n); }
	//���Ĺ̶�λ�õ�ֵ, ��ǰֵ�����ֵ��ͬʱ����false;
	bool Set(const Index_t& n, const Val_t& v) { Derived()->Set(n, v); }
	//����Ԫ�ز�������λ��
	Index_Ret_Val_t Find(const Val_t& v)const { Derived()->Find(v); }
	//����Ԫ�ز�������ǰ��Ԫ��λ��
	Index_Ret_Val_t FindValuePrior(const Val_t& v)const { Derived()->FindValuePrior(v); }
	//����Ԫ�ز���������Ԫ��λ��
	Index_Ret_Val_t FindValueNext(const Val_t& v)const { Derived()->FindValueNext(v); }
	//����
	bool Insert(const Index_t& n, const Val_t& v) { Derived()->Insert(n, v); }
	//ɾ��
	bool Erase(const Index_t& n) { Derived()->Erase(n); }
	//β������
	bool PushBack(const Val_t& v) { Derived()->PushBack(v); }
	//β��ɾ��
	bool PopBack() { Derived()->PopBack(); }
	//����������FΪ�Զ��庯��
	template<typename F>
	void Foreach(const F& f) { Derived()->Foreach(f); }

private:
	inline Child* Derived() { return static_cast<Child*>(this); }
};
MyDS_END