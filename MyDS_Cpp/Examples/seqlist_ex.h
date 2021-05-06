/*----------------------------------------------------------------------------
 Copyright(c) 2019-2021 SnowyLake
 All rights reserved.

 @File:  seqlist_ex.h
 @State: Finished
 @Version: 0.2

 @Author: SnowyLake
 @E-mail: Felix2000@foxmail.com

 @Creation Time:  2021/03/18
 @Abstract:
	The example for SeqList.

 @Finished Time:  2021/05/05


 @Change History:
 ========================================================================
  <Date>		| <Version> | <Author>		| <Description>
 ========================================================================
  2021/03/18	| 0.1       | SnowyLake		| Create file
 ------------------------------------------------------------------------
  2021/05/05	| 0.2       | SnowyLake		| Finished
 ========================================================================
----------------------------------------------------------------------------*/
#pragma once
#include <iostream>
#include "../Examples/myds_ex_basic.h"
#include "../Includes/seq_list.h"
using namespace MyDS::Ex;

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
	ExLOG << "----------------------------------------------\n"
		  << "This is Example for MyDS::SeqList<T>\t"
		  << "T: " << typeid(MyDS::Ex::SeqListEx::Ex_t).name() <<'\n'
		  << "----------------------------------------------\n";
	ExLOG_BL;

	//��ʼ��ʱ
	auto start = TIME_NOW;

	//��ʼ��
	ExLOG << "---------------------Ex_1---------------------\n";
	ExLOG << "��ʼ��" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	//Ĭ�ϳ�ʼ��
	ExLOG << "Ĭ�ϳ�ʼ��: MyDS::SeqList<int> sq1;\n";
	ExSL sq1;
	// ֱ�ӳ�ʼ��
	ExLOG << "ֱ�ӳ�ʼ��: MyDS::SeqList<int> sq2(5, 1);\n";
	ExSL sq2(5, 1);
	// �б��ʼ��
	ExLOG << "�б��ʼ��: MyDS::SeqList<int> sq3 = {1,1,1,1,1};\n";
	ExSL sq3 = {1,2,3,4,5};
	// ������ʼ��
	ExLOG << "������ʼ��: MyDS::SeqList<int> sq4 = sq3;\n";
	ExSL sq4 = sq3;		// ExSL sq4(sq3), �ȼ�;
	ExLOG_BL;
	ExLOG << "����sq2��sq3��sq4: " << ExLOG_NL;
	for(size_t i = 0; i < sq2.Size(); ++i)
	{
		ExLOG << "i==" << i << ExLOG_TAB;
		ExLOG << "sq2:" << sq2.At(i) << ExLOG_TAB;
		ExLOG << "sq3:" << sq3.At(i) << ExLOG_TAB;
		ExLOG << "sq4:" << sq4.At(i) << ExLOG_NL;
	}
	ExLOG_BL;

	// ���ͷ����β
	ExLOG << "---------------------Ex_2---------------------\n";
	ExLOG << "���ͷ����" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "���ͷ: sq3.Front();\n";
	ExLOG << sq3.Front() << ExLOG_NL;
	ExLOG << "���β: sq3.Back();\n";
	ExLOG << sq3.Back() << ExLOG_NL;
	ExLOG_BL;

	// �ж��Ƿ�ձ�
	ExLOG << "---------------------Ex_3---------------------\n";
	ExLOG << "�ж��Ƿ�ձ�" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "�ж��Ƿ�ձ�: sq1.IsEmpty();\n";
	ExLOG << std::boolalpha << sq1.IsEmpty() << ExLOG_NL;
	ExLOG << "�ж��Ƿ�ձ�: sq2.IsEmpty();\n";
	ExLOG << std::boolalpha << sq2.IsEmpty() << ExLOG_NL;
	ExLOG_BL;

	// ��������������, β����ջ����ջ
	ExLOG << "---------------------Ex_4---------------------\n";
	ExLOG << "��������������, β����ջ����ջ" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "���: sq2.Size(); ���������: sq2.Capapcity();\n";
	ExLOG << sq2.Size() << ExLOG_NL;
	ExLOG << sq2.Capacity() << ExLOG_NL;
	ExLOG << "β����ջ: sq2.PushBack(2);\n";
	sq2.PushBack(2);
	ExLOG << "���: sq2.Size(); ���������: sq2.Capapcity();\n";
	ExLOG << sq2.Size() << ExLOG_NL;
	ExLOG << sq2.Capacity() << ExLOG_NL;	// ÿ����������+10
	ExLOG << "β����ջ: sq2.PopBack();\n";
	sq2.PopBack();
	ExLOG << "���: sq2.Size(); ���������: sq2.Capapcity();\n";
	ExLOG << sq2.Size() << ExLOG_NL;
	ExLOG << sq2.Capacity() << ExLOG_NL;
	ExLOG_BL;

	// ��ձ�
	ExLOG << "---------------------Ex_5---------------------\n";
	ExLOG << "��ձ�" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "���ǰ���: sq3.Size();\n";
	ExLOG << sq3.Size() << ExLOG_NL;
	ExLOG << "��ձ�: sq3.Clear(); ���: sq3.Size();\n";
	sq3.Clear();
	ExLOG << sq3.Size() << ExLOG_NL;
	ExLOG << "��պ��Է���, �׳��쳣: \n";
	try		// �±�Խ�磬����ʧ�ܣ������쳣
	{
		ExLOG << sq3.Get(0) << ExLOG_NL;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG_BL;

	// ָ��λ��Ԫ�ط���
	ExLOG << "---------------------Ex_6---------------------\n";
	ExLOG << "ָ��λ��Ԫ�ط���" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "ֻ������: sq2.Get(0);" << ExLOG_NL;
	ExLOG << "sq2[0]: " << sq2.Get(0) << ExLOG_NL;
	ExLOG << "ֻд����: sq2.Set(0, 9);" << ExLOG_NL;
	sq2.Set(0, 9);
	ExLOG << "sq2[0]: " << sq2.Get(0) << ExLOG_NL;
	ExLOG << "�ɶ�д����(��ȡ): sq2.At(0);" << ExLOG_NL;
	ExLOG << "sq2[0]: " << sq2.At(0) << ExLOG_NL;
	ExLOG << "�ɶ�д����(д��): sq2.At(0) = 1;" << ExLOG_NL;
	sq2.At(0) = 1;
	ExLOG << "sq2[0]: " << sq2.At(0) << ExLOG_NL;
	ExLOG_BL;

	// ForEach()
	ExLOG << "---------------------Ex_7---------------------\n";
	ExLOG << "ForEach()" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "ʹ��ForEach()����: sq2.ForEach([](auto&& x) { std::cout << x << ' '; });" << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "ʹ��ForEach()ʹÿ��Ԫ��+1: sq2.ForEach([](auto&& x) { x += 1; });" << ExLOG_NL;
	sq2.ForEach([](auto&& x) { x += 1; });
	ExLOG << "�ٴα���: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG_BL;
	// ����
	ExLOG << "---------------------Ex_8---------------------\n";
	ExLOG << "����" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "����sq4: " << ExLOG_NL;
	sq4.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "��sq4�в���'3'���±�: sq4.Find(3).value();" << ExLOG_NL;
	ExLOG << sq4.Find(3).value() << ExLOG_NL;
	ExLOG << "��sq4�в���'9'���±�, ������, �׳��쳣: " << ExLOG_NL;
	try		// ����ʧ�ܣ������쳣
	{
		ExLOG << sq4.Find(9).value() << ExLOG_NL;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG_BL;
	ExLOG << "��sq4�в���'3'��ǰ��Ԫ�ص��±�: sq4.FindValuePrior(3).value();" << ExLOG_NL;
	ExLOG << sq4.FindValuePrior(3).value() << ExLOG_NL;
	ExLOG << "��sq4�в���'1'��ǰ��Ԫ�ص��±�, ������, �׳��쳣: " << ExLOG_NL;
	try		// ����ʧ�ܣ������쳣
	{
		ExLOG << sq4.FindValuePrior(1).value() << ExLOG_NL;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG_BL;
	ExLOG << "��sq4�в���'3'�ĺ��Ԫ�ص��±�: sq4.FindValueNext(3).value();" << ExLOG_NL;
	ExLOG << sq4.FindValueNext(3).value() << ExLOG_NL;
	ExLOG << "��sq4�в���'5'�ĺ��Ԫ�ص��±�, ������, �׳��쳣: " << ExLOG_NL;
	try		// ����ʧ�ܣ������쳣
	{
		ExLOG << sq4.FindValueNext(5).value() << ExLOG_NL;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG_BL;

	// ����, ɾ��
	ExLOG << "---------------------Ex_9---------------------\n";
	ExLOG << "����, ɾ��" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "����sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "���±�Ϊ2��λ�ò���Ԫ��'0': sq2.Insert(2, 0);" << ExLOG_NL;
	sq2.Insert(2, 0);
	ExLOG << "����sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "���±�Ϊ7��λ�ò���Ԫ��, �±�Խ��, �׳��쳣: " << ExLOG_NL;
	try
	{
		sq2.Insert(7, 0);
	} 	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG << "����sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "���±�Ϊ2��λ��ɾ��Ԫ��: sq2.Erase(2);" << ExLOG_NL;
	sq2.Erase(2);
	ExLOG << "����sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "���±�Ϊ6��λ��ɾ��Ԫ��, �±�Խ��, �׳��쳣: " << ExLOG_NL;
	try
	{
		sq2.Erase(6);
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG << "����sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG_BL;

	// '=='�Ƚ�
	ExLOG << "---------------------Ex_9---------------------\n";
	ExLOG << "'=='�Ƚ�" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "�Ƚ�: "
		  << "\tsqA = {1,2,3,4,5,6};\n"
		  << "\tsqB = {1,2,3,4,5,6};\n" << ExLOG_NL;
	MyDS::SeqList<int> sqA = {1,2,3,4,5,6};
	MyDS::SeqList<int> sqB = {1,2,3,4,5,6};
	ExLOG << "\tExLOG << std::boolalpha << (sqA == sqB) << ExLOG_NL;" << ExLOG_NL;
	ExLOG << std::boolalpha << (sqA == sqB) << ExLOG_NL;
	ExLOG_BL;
	ExLOG << "�Ƚ�: "
		  << "\tsqC = {\"A\",\"B\",\"C\"};\n"
		  << "\tsqD = {\"A\",\"B\",\"D\"};\n"
		  << "\tsqD = {\"A\",\"B\"};\n"
		  << "\tsqF;  // Ĭ�ϳ�ʼ�� \n" << ExLOG_NL;
	MyDS::SeqList<std::string> sqC = {"A","B","C"};
	MyDS::SeqList<std::string> sqD = {"A","B","D"}; 
	MyDS::SeqList<std::string> sqE = {"A","B"};
	MyDS::SeqList<std::string> sqF;
	ExLOG << "\tExLOG << std::boolalpha << (sqC == sqD) << ExLOG_NL;" << ExLOG_NL;
	ExLOG << std::boolalpha << (sqC == sqD) << ExLOG_NL;
	ExLOG << "\tExLOG << std::boolalpha << (sqC == sqE) << ExLOG_NL;" << ExLOG_NL;
	ExLOG << std::boolalpha << (sqC == sqE) << ExLOG_NL;
	ExLOG << "\tExLOG << std::boolalpha << (sqE == sqF) << ExLOG_NL;" << ExLOG_NL;
	ExLOG << std::boolalpha << (sqE == sqF) << ExLOG_NL;
	ExLOG << "" << ExLOG_NL;
	ExLOG_BL;

	//��ʱ����
	auto end = TIME_NOW;
	std::chrono::duration<double> elapsed = end - start;
	ExLOG << "----------------------------------------------\n"
		  << "                   The End.\n"
		  << "              Elapsed: " << elapsed.count() <<"s\n"
		  << "----------------------------------------------\n";
}
MyDS_Ex_END