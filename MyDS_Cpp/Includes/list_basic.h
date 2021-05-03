/*----------------------------------------------------------------------------
 Copyright(c) 2019-2021 SnowyLake
 All rights reserved.

 @File:  list_basic.h
 @State: Finished
 @Version: 0.2

 @Author: SnowyLake
 @E-mail: Felix2000@foxmail.com

 @Creation Time:  2021/04/06
 @Abstract:
	The base classes for SeqList and LinkList.

 @Finished Time:  2021/05/03


 @Change History:
  <Date>      | <Version> | <Author>       | <Description>
 ---------------------------------------------------------------------
  2021/04/06  | 0.1       | SnowyLake      | Create file
 ---------------------------------------------------------------------
  2014/05/03  | 0.2       | SnowyLake      | Use CRTP for ForEach()
----------------------------------------------------------------------------*/
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
template<typename Derived, typename T>
class ListBasic
{
public:
	using Val_t = T;
	using Ref_t = T&;
	using Size_t = SIZE_TYPE;
	using Index_t = INDEX_TYPE;
	using Index_Ret_Val_t = INDEX_RET_VAL_TYPE;

	virtual Ref_t front() = 0;	//��Ԫ��
	virtual Ref_t back() = 0;	//βԪ��

	//�ж��Ƿ�Ϊ�ձ�
	virtual bool IsEmpty()const = 0;
	//���
	virtual Size_t Size()const = 0;
	//��ձ�
	virtual void Clear() = 0;
	//��ȡ�̶�λ�õ�����
	virtual Ref_t At(const Index_t& n) = 0;
	//��ȡ�̶�λ�õ�ֵ
	virtual Val_t Get(const Index_t& n)const = 0;
	//���Ĺ̶�λ�õ�ֵ, ��ǰֵ�����ֵ��ͬʱ����false;
	virtual bool Set(const Index_t& n, const Val_t& v) = 0;
	//����Ԫ�ز�������λ��
	virtual Index_Ret_Val_t Find(const Val_t& v)const = 0;
	//����Ԫ�ز�������ǰ��Ԫ��λ��
	virtual Index_Ret_Val_t FindValuePrior(const Val_t& v)const = 0;
	//����Ԫ�ز���������Ԫ��λ��
	virtual Index_Ret_Val_t FindValueNext(const Val_t& v)const = 0;
	//����
	virtual bool Insert(const Index_t& n, const Val_t& v) = 0;
	//ɾ��
	virtual bool Erase(const Index_t& n) = 0;
	//β������
	virtual bool PushBack(const Val_t& v) = 0;
	//β��ɾ��
	virtual bool PopBack() = 0;
	//����������FΪ�Զ��庯��
	template<typename F>
	void Foreach(const F& f) { static_cast<Derived*>(this)->Foreach(f); }
};
MyDS_END