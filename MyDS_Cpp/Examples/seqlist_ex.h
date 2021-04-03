#pragma once
#include <iostream>
#include "../Includes/seq_list.h"

MyDS_BEGIN
MyDS_Ex_BEGIN
class SeqListEx
{
public:
	using Ex_t = int;
	using ExSL = MyDS::SeqList<Ex_t>;
public:
	SeqListEx();
	~SeqListEx();

	void Example();
};

SeqListEx::SeqListEx() {}
SeqListEx::~SeqListEx() {}

void MyDS::Ex::SeqListEx::Example()
{
	//��ʼ��
	//Ĭ�ϳ�ʼ��
	ExLOG << "Ĭ�ϳ�ʼ��: MyDS::SeqList<int> sq1;\n";
	ExSL sq1;
	//ֱ�ӳ�ʼ��
	ExLOG << "ֱ�ӳ�ʼ��: MyDS::SeqList<int> sq2(5, 1);\n";
	ExSL sq2(5, 1);
	//�б��ʼ��
	ExLOG << "�б��ʼ��: MyDS::SeqList<int> sq3 = {1,1,1,1,1};\n";
	ExSL sq3 = {1,1,1,1,1};
	//������ʼ��
	ExLOG << "������ʼ��: MyDS::SeqList<int> sq4 = sq3;\n";
	ExSL sq4 = sq3;
	//ExSL sq4(sq3), �ȼ�;
	ExLOG_BL
	ExLOG << "����sq2��sq3��sq4: "<< ExLOG_NL
	for(size_t i = 0; i < sq2.Size(); ++i)
	{
		ExLOG << "i==" << i << ExLOG_TAB
		ExLOG << "sq2:" << sq2.At(i) << ExLOG_TAB
		ExLOG << "sq3:" << sq3.At(i) << ExLOG_TAB
		ExLOG << "sq4:" << sq4.At(i) << ExLOG_NL
	}

}


MyDS_Ex_END
MyDS_END