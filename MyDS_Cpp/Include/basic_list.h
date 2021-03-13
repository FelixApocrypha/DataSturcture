#pragma once
namespace MyDS
{
template<typename T>
class BasicList
{
public:
	using Val_t = T;
	using Ref_t = T&;
	using Size_t = int;

	virtual Ref_t front() = 0;	//��Ԫ��
	virtual Ref_t back() = 0;	//βԪ��

	//�ж��Ƿ�Ϊ�ձ�
	virtual bool IsEmpty()const = 0;
	//���
	virtual Size_t Size()const = 0;
	//��ձ�
	virtual void Clear() = 0;
	//��ȡ�̶�λ�õ�����
	virtual Ref_t At(Size_t n) = 0;
	//��ȡ�̶�λ�õ�ֵ
	virtual Val_t Get(Size_t n)const = 0;
	//���Ĺ̶�λ�õ�ֵ
	virtual bool Set(Size_t n, const Val_t& v) = 0;
	//����Ԫ�ز�������λ��
	virtual Size_t Find(const Val_t& v)const = 0;
	//����Ԫ�ز�������ǰ��Ԫ��λ��
	virtual Size_t FindValuePrior(const Val_t& v)const = 0;
	//����Ԫ�ز���������Ԫ��λ��
	virtual Size_t FindValueNext(const Val_t& v)const = 0;
	//����
	virtual bool Insert(Size_t n, const Val_t& v) = 0;
	//ɾ��
	virtual bool Erase(const Size_t& v) = 0;
	//β������
	virtual bool push_back(const Val_t& v) = 0;
	//β��ɾ��
	virtual bool pop_back(const Val_t& v) = 0;
	//����������FΪ�Զ��庯��
	//template<typename F>
	//virtual void Foreach(const F& f) = 0;
};
}