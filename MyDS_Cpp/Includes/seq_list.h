#pragma once
//#include "list_basic.h"
#include "list_basic_crtp.h"
MyDS_BEGIN

//ForEach()
#if _MSVC_LANG <= 201703L
/*CXX17*/
//SFINAE base enable_if for ForEach(lambda(T))
template<typename F, typename T, typename = void>
struct IsForEachFunc :std::false_type {};
template<typename F, typename T>
struct IsForEachFunc<F, T, std::void_t<decltype(std::declval<F>()(std::declval<T&>()))>> :std::true_type {};
#else	//concept/require is great!
/*CXX20*/
//SFINAE base concept/require for ForEach(lambda(T))
template<typename F, typename T>
concept IsForEachFunc = requires(F func, T val) { func(val); };
#endif // _MSVC_LANG <= 201703L

template<typename T>
class SeqList : public ListBasic<SeqList<T>, T>
{
public:
	using Val_t = T;
	using Ref_t = T&;
	using Size_t = SIZE_TYPE;
	using Index_t = INDEX_TYPE;
	using Index_Ret_Val_t = INDEX_RET_VAL_TYPE;
	
//���캯������������
public:
	explicit SeqList(const Size_t& m = 0, const T& val = T());

	SeqList(const SeqList<T>& rSeqL);
	SeqList(const std::initializer_list<T>& vList);

	SeqList<T>& operator=(const SeqList<T>& rSeqL);
	SeqList<T>& operator=(const std::initializer_list<T>& vList);

	~SeqList();

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
	//���������
	Size_t Capacity()const;
	//��ձ�
	void Clear();
	//��ȡ�̶�λ�õ�����
	Ref_t At(const Index_t& n);
	//��ȡ�̶�λ�õ�ֵ
	Val_t Get(const Index_t& n)const;
	//���Ĺ̶�λ�õ�ֵ, ��ǰֵ�����ֵ��ͬʱ����false;
	bool Set(const Index_t& n, const Val_t& v);
	//����Ԫ�ز�������λ��
	Index_Ret_Val_t Find(const Val_t& v)const;
	//����Ԫ�ز�������ǰ��Ԫ��λ��
	Index_Ret_Val_t FindValuePrior(const Val_t& v)const;
	//����Ԫ�ز���������Ԫ��λ��
	Index_Ret_Val_t FindValueNext(const Val_t& v)const;
	//����
	bool Insert(const Index_t& n, const Val_t& v);
	//ɾ��
	bool Erase(const Index_t& n);
	//β������
	bool PushBack(const Val_t& v);
	//β��ɾ��
	bool PopBack();

	//����==�����
	bool operator==(const SeqList<Val_t>& rSeqL);

	//����
	template<typename F>	/*CXX17 or CXX20*/
	void ForEach(const F& func);
};
MyDS_END

template<typename T>
inline MyDS::SeqList<T>::SeqList(const Size_t& m, const T& val) :size(m), capacity(m)
{
	if(m == 0)
		this->vals = nullptr;
	else
		this->vals = new T[m];
	for(Size_t i = 0; i < m; ++i)
		this->vals[i] = val;
}
template<typename T>
inline MyDS::SeqList<T>::SeqList(const SeqList<T>& rSeqL)
{
	this->size = rSeqL.size;
	this->capacity = rSeqL.capacity;
	this->vals = new Val_t[size];

	Val_t* vPtr = rSeqL.vals;
	for(size_t i = 0; i < rSeqL.size; ++i)
		this->vals[i] = *(vPtr++);
}
template<typename T>
inline MyDS::SeqList<T>::SeqList(const std::initializer_list<T>& vList) :size(vList.size()), capacity(vList.size())
{
	this->vals = new T[vList.size() + 1];
	int n = 0;
	for(auto& i : vList)
		this->vals[n++] = i;
}
template<typename T>
inline MyDS::SeqList<T>& MyDS::SeqList<T>::operator=(const MyDS::SeqList<T>& rSeqL)
{
	if(this != &rSeqL)
	{
		this->size = rSeqL.size;
		this->capacity = rSeqL.capacity;
		this->vals = new Val_t[size];

		Val_t* vPtr = rSeqL.vals;
		for(size_t i = 0; i < rSeqL.size; ++i)
			this->vals[i] = *(vPtr++);
	}
	return *this;
}
template<typename T>
inline MyDS::SeqList<T>& MyDS::SeqList<T>::operator=(const std::initializer_list<T>&vList)
{
	this->size = vList.size();
	this->capacity = vList.size();

	this->vals = new T[vList.size() + 1];
	int n = 0;
	for(auto& i : vList)
		this->vals[n++] = i;
	return *this;
}
template<typename T>
inline MyDS::SeqList<T>::~SeqList()
{ delete[]vals; }

//ȡ��ͷ
template<typename Val_t>
inline Val_t& MyDS::SeqList<Val_t>::front()
{
	THROW_OUT_OF_RANGE_IF(IsEmpty(), "SeqList<T> is empty.");
	return this->vals[0];
}
//ȡ��β
template<typename Val_t>
Val_t& MyDS::SeqList<Val_t>::back()
{
	THROW_OUT_OF_RANGE_IF(IsEmpty(), "SeqList<T> is empty.");
	return this->vals[size - 1];
}

//�ж��Ƿ�Ϊ�ձ�
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::IsEmpty()const
{ return this->size == 0 ? true : false; }
//���
template<typename Val_t>
inline SIZE_TYPE MyDS::SeqList<Val_t>::Size()const
{ return this->size; }
//���������
template<typename Val_t>
inline SIZE_TYPE MyDS::SeqList<Val_t>::Capacity() const
{ return this->capacity; }
//��ձ�
template<typename Val_t>
inline void MyDS::SeqList<Val_t>::Clear()
{ this->size = 0; }
//��ȡ�̶�λ�õ�����
template<typename Val_t>
inline Val_t& MyDS::SeqList<Val_t>::At(const Index_t& n)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::At() subscript out of range.");
	return this->vals[n];
}
//��ȡ�̶�λ�õ�ֵ
template<typename Val_t>
inline Val_t MyDS::SeqList<Val_t>::Get(const Index_t& n)const
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Get() subscript out of range.");
	return this->vals[n];
}
//���Ĺ̶�λ�õ�ֵ, ��ǰֵ�����ֵ��ͬʱ����false;
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::Set(const Index_t& n, const Val_t& v)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Set() subscript out of range.");
	if(v == this->vals[n])
		return false;
	else
	{
		this->vals[n] = v;
		return true;
	}
}
//����Ԫ�ز�������λ��
template<typename Val_t>
inline INDEX_RET_VAL_TYPE MyDS::SeqList<Val_t>::Find(const Val_t& v)const
{
	Val_t* p = this->vals;
	INDEX_TYPE i = 0;
	while(i < this->size && *p != v)
	{
		++p;
		++i;
	}
	if(i < this->size)
		return MAKE_INDEX_RET_VAL(i);
	return INDEX_RET_ERROR_VAL;
}
//����Ԫ�ز�������ǰ��Ԫ��λ��
template<typename Val_t>
inline INDEX_RET_VAL_TYPE MyDS::SeqList<Val_t>::FindValuePrior(const Val_t& v)const
{ 
	auto opt = Find(v);
	return opt == 0 || opt == INDEX_RET_ERROR_VAL ? INDEX_RET_ERROR_VAL : MAKE_INDEX_RET_VAL(--opt.value());
}
//����Ԫ�ز���������Ԫ��λ��
template<typename Val_t>
inline INDEX_RET_VAL_TYPE MyDS::SeqList<Val_t>::FindValueNext(const Val_t& v)const
{ 
	auto opt = Find(v);
	return opt == this->size - 1 || opt == INDEX_RET_ERROR_VAL ? INDEX_RET_ERROR_VAL : MAKE_INDEX_RET_VAL(++opt.value());
}
//����
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::Insert(const Index_t& n, const Val_t& v)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Insert() subscript out of range.");
	if(this->size >= this->capacity)
	{
		Val_t* tmp = new Val_t[this->capacity + 10];
		if(tmp == nullptr)
			return false;
		for(size_t i = 0; i < this->size; ++i)
			tmp[i] = this->vals[i];
		delete[] this->vals;
		this->vals = tmp;
		tmp = nullptr;
		this->capacity += 10;
	}
	Val_t* pos = &this->vals[n];
	for(Val_t* ptr = &this->vals[this->size - 1]; ptr >= pos; --ptr)
		*(ptr + 1) = *ptr;
	*pos = v;
	++this->size;
	return true;
}
//ɾ��
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::Erase(const Index_t& n)
{
	THROW_OUT_OF_RANGE_IF((n < 0 || n >= size), "SeqList<T>::Erase() subscript out of range.");
	Val_t* end = this->vals + this->size - 1;
	for(Val_t* ptr = &this->vals[n + 1]; ptr <= end; ++ptr)
		*(ptr - 1) = *ptr;
	--this->size;
	return true;
}
//β������
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::PushBack(const Val_t& v)
{
	if(this->size >= this->capacity)
	{
		Val_t* tmp = new Val_t[this->capacity + 10];
		if(tmp == nullptr)
			return false;
		for(size_t i = 0; i < this->size; ++i)
			tmp[i] = this->vals[i];
		delete[] this->vals;
		this->vals = tmp;
		tmp = nullptr;
		this->capacity += 10;
	}
	this->vals[this->size++] = v;
	return true;
}
//β��ɾ��
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::PopBack()
{
	THROW_OUT_OF_RANGE_IF(IsEmpty(), "SeqList<T>::Insert() is empty.");
	this->size -= 1;
	return true;
}
//����==�����
template<typename Val_t>
inline bool MyDS::SeqList<Val_t>::operator==(const SeqList<Val_t>& rSeqL)
{
	if(this->size != rSeqL.size)
		return false;
	for(int i = 0; i < this->size; ++i)
	{
		if(this->vals[i] != rSeqL.Get(i))
			return false;
	}
	return true;
}
//��������
#if _MSVC_LANG <= 201703L	//constexpr if is great!

template<typename Val_t>/*CXX17*/
template<typename F/*,	
		 typename std::enable_if_t<!IsForEachFunc<F, Val_t>::value, int> = 0*/>
inline void MyDS::SeqList<Val_t>::ForEach(const F& func)
{
	if constexpr(IsForEachFunc<F, Val_t>::value)
	{
		Val_t* ptr = this->vals;
		for(size_t i = 0; i < this->size; ++i)
			func(*ptr++);
		ptr = nullptr;
	} else
	{
		std::cout << "SFINAE: �����Ƿ�" << '\n';
	}
}
//template<typename F,	/*CXX17*/
//		   typename std::enable_if_t<!IsForEachFunc<F, Val_t>::value, int> = 0>
//inline void ForEach(const F& func)
//{ std::cout << "SFINAE: �����Ƿ�" << '\n'; }
#else
template<typename Val_t>
template<typename F>	/*CXX20*/
inline void MyDS::SeqList<Val_t>::ForEach(const F& func) //requires IsForEachFunc<F, Val_t>
{
	if constexpr(IsForEachFunc<F, Val_t>)
	{
		Val_t* ptr = this->vals;
		for(size_t i = 0; i < this->size; ++i)
			func(*ptr++);
		ptr = nullptr;
	} else
	{
		std::cout << "SFINAE: �����Ƿ�" << '\n';
	}
}
//template<typename F>	/*CXX20*/
//inline void ForEach(const F& func) requires !IsForEachFunc<F, Val_t>
//{ std::cout << "SFINAE: �����Ƿ�" << '\n'; }

#endif // _MSVC_LANG <= 201703L