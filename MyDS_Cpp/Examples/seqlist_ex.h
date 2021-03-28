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
	ExLOG << "Ĭ�ϳ�ʼ��: ExSL sq1;\n";
	ExSL sq1;
	//ֱ�ӳ�ʼ��
	ExLOG << "ֱ�ӳ�ʼ��: ExSL sq2(5, 1);\n";
	ExSL sq2(5, 1);
	//�б��ʼ��
	ExLOG << "�б��ʼ��: ExSL sq3 = {1,1,1,1,1};\n";
	ExSL sq3 = {1,1,1,1,1};
	//������ʼ��
	ExLOG << "������ʼ��: ExSL sq4 = sq3;\n";
	ExSL sq4 = sq3;
	//ExSL sq4(sq3), �ȼ�;
	ExLOG_BL
	ExLOG << "����sq2��sq3��sq4: \n";
	for(int i = 0; i < sq2.Size(); ++i)
	{
		ExLOG << "i == " << i << ":\t";
		ExLOG << "sq2: " << sq2.At(i) << "\t";
		ExLOG << "sq3: " << sq3.At(i) << "\t";
		ExLOG << "sq4: " << sq4.At(i) << "\n";
	}

}


MyDS_Ex_END
MyDS_END