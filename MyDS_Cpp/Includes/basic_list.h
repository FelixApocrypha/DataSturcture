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
	//template<typename F>
	//virtual void Foreach(const F& f) = 0;
};
MyDS_END