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

	//开始计时
	auto start = TIME_NOW;

	//初始化
	ExLOG << "---------------------Ex_1---------------------\n";
	ExLOG << "初始化" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	//默认初始化
	ExLOG << "默认初始化: MyDS::SeqList<int> sq1;\n";
	ExSL sq1;
	// 直接初始化
	ExLOG << "直接初始化: MyDS::SeqList<int> sq2(5, 1);\n";
	ExSL sq2(5, 1);
	// 列表初始化
	ExLOG << "列表初始化: MyDS::SeqList<int> sq3 = {1,1,1,1,1};\n";
	ExSL sq3 = {1,2,3,4,5};
	// 拷贝初始化
	ExLOG << "拷贝初始化: MyDS::SeqList<int> sq4 = sq3;\n";
	ExSL sq4 = sq3;		// ExSL sq4(sq3), 等价;
	ExLOG_BL;
	ExLOG << "遍历sq2、sq3、sq4: " << ExLOG_NL;
	for(size_t i = 0; i < sq2.Size(); ++i)
	{
		ExLOG << "i==" << i << ExLOG_TAB;
		ExLOG << "sq2:" << sq2.At(i) << ExLOG_TAB;
		ExLOG << "sq3:" << sq3.At(i) << ExLOG_TAB;
		ExLOG << "sq4:" << sq4.At(i) << ExLOG_NL;
	}
	ExLOG_BL;

	// 求表头、表尾
	ExLOG << "---------------------Ex_2---------------------\n";
	ExLOG << "求表头、表" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "求表头: sq3.Front();\n";
	ExLOG << sq3.Front() << ExLOG_NL;
	ExLOG << "求表尾: sq3.Back();\n";
	ExLOG << sq3.Back() << ExLOG_NL;
	ExLOG_BL;

	// 判断是否空表
	ExLOG << "---------------------Ex_3---------------------\n";
	ExLOG << "判断是否空表" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "判断是否空表: sq1.IsEmpty();\n";
	ExLOG << std::boolalpha << sq1.IsEmpty() << ExLOG_NL;
	ExLOG << "判断是否空表: sq2.IsEmpty();\n";
	ExLOG << std::boolalpha << sq2.IsEmpty() << ExLOG_NL;
	ExLOG_BL;

	// 求表长、求最大容量, 尾部入栈、出栈
	ExLOG << "---------------------Ex_4---------------------\n";
	ExLOG << "求表长、求最大容量, 尾部入栈、出栈" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "求表长: sq2.Size(); 求最大容量: sq2.Capapcity();\n";
	ExLOG << sq2.Size() << ExLOG_NL;
	ExLOG << sq2.Capacity() << ExLOG_NL;
	ExLOG << "尾部入栈: sq2.PushBack(2);\n";
	sq2.PushBack(2);
	ExLOG << "求表长: sq2.Size(); 求最大容量: sq2.Capapcity();\n";
	ExLOG << sq2.Size() << ExLOG_NL;
	ExLOG << sq2.Capacity() << ExLOG_NL;	// 每次扩容容量+10
	ExLOG << "尾部出栈: sq2.PopBack();\n";
	sq2.PopBack();
	ExLOG << "求表长: sq2.Size(); 求最大容量: sq2.Capapcity();\n";
	ExLOG << sq2.Size() << ExLOG_NL;
	ExLOG << sq2.Capacity() << ExLOG_NL;
	ExLOG_BL;

	// 清空表
	ExLOG << "---------------------Ex_5---------------------\n";
	ExLOG << "清空表" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "清空前求表长: sq3.Size();\n";
	ExLOG << sq3.Size() << ExLOG_NL;
	ExLOG << "清空表: sq3.Clear(); 求表长: sq3.Size();\n";
	sq3.Clear();
	ExLOG << sq3.Size() << ExLOG_NL;
	ExLOG << "清空后尝试访问, 抛出异常: \n";
	try		// 下标越界，访问失败，捕获异常
	{
		ExLOG << sq3.Get(0) << ExLOG_NL;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG_BL;

	// 指定位置元素访问
	ExLOG << "---------------------Ex_6---------------------\n";
	ExLOG << "指定位置元素访问" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "只读访问: sq2.Get(0);" << ExLOG_NL;
	ExLOG << "sq2[0]: " << sq2.Get(0) << ExLOG_NL;
	ExLOG << "只写访问: sq2.Set(0, 9);" << ExLOG_NL;
	sq2.Set(0, 9);
	ExLOG << "sq2[0]: " << sq2.Get(0) << ExLOG_NL;
	ExLOG << "可读写访问(读取): sq2.At(0);" << ExLOG_NL;
	ExLOG << "sq2[0]: " << sq2.At(0) << ExLOG_NL;
	ExLOG << "可读写访问(写入): sq2.At(0) = 1;" << ExLOG_NL;
	sq2.At(0) = 1;
	ExLOG << "sq2[0]: " << sq2.At(0) << ExLOG_NL;
	ExLOG_BL;

	// ForEach()
	ExLOG << "---------------------Ex_7---------------------\n";
	ExLOG << "ForEach()" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "使用ForEach()遍历: sq2.ForEach([](auto&& x) { std::cout << x << ' '; });" << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "使用ForEach()使每个元素+1: sq2.ForEach([](auto&& x) { x += 1; });" << ExLOG_NL;
	sq2.ForEach([](auto&& x) { x += 1; });
	ExLOG << "再次遍历: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG_BL;
	// 查找
	ExLOG << "---------------------Ex_8---------------------\n";
	ExLOG << "查找" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "遍历sq4: " << ExLOG_NL;
	sq4.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "在sq4中查找'3'的下标: sq4.Find(3).value();" << ExLOG_NL;
	ExLOG << sq4.Find(3).value() << ExLOG_NL;
	ExLOG << "在sq4中查找'9'的下标, 不存在, 抛出异常: " << ExLOG_NL;
	try		// 查找失败，捕获异常
	{
		ExLOG << sq4.Find(9).value() << ExLOG_NL;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG_BL;
	ExLOG << "在sq4中查找'3'的前驱元素的下标: sq4.FindValuePrior(3).value();" << ExLOG_NL;
	ExLOG << sq4.FindValuePrior(3).value() << ExLOG_NL;
	ExLOG << "在sq4中查找'1'的前驱元素的下标, 不存在, 抛出异常: " << ExLOG_NL;
	try		// 查找失败，捕获异常
	{
		ExLOG << sq4.FindValuePrior(1).value() << ExLOG_NL;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG_BL;
	ExLOG << "在sq4中查找'3'的后继元素的下标: sq4.FindValueNext(3).value();" << ExLOG_NL;
	ExLOG << sq4.FindValueNext(3).value() << ExLOG_NL;
	ExLOG << "在sq4中查找'5'的后继元素的下标, 不存在, 抛出异常: " << ExLOG_NL;
	try		// 查找失败，捕获异常
	{
		ExLOG << sq4.FindValueNext(5).value() << ExLOG_NL;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG_BL;

	// 插入, 删除
	ExLOG << "---------------------Ex_9---------------------\n";
	ExLOG << "插入, 删除" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "遍历sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "在下标为2的位置插入元素'0': sq2.Insert(2, 0);" << ExLOG_NL;
	sq2.Insert(2, 0);
	ExLOG << "遍历sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "在下标为7的位置插入元素, 下标越界, 抛出异常: " << ExLOG_NL;
	try
	{
		sq2.Insert(7, 0);
	} 	catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG << "遍历sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "在下标为2的位置删除元素: sq2.Erase(2);" << ExLOG_NL;
	sq2.Erase(2);
	ExLOG << "遍历sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG << "在下标为6的位置删除元素, 下标越界, 抛出异常: " << ExLOG_NL;
	try
	{
		sq2.Erase(6);
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << ExLOG_NL;
	}
	ExLOG << "遍历sq2: " << ExLOG_NL;
	sq2.ForEach([](auto&& x) { ExLOG << x << ' '; });
	ExLOG_BL;
	ExLOG_BL;

	// '=='比较
	ExLOG << "---------------------Ex_9---------------------\n";
	ExLOG << "'=='比较" << ExLOG_NL;
	ExLOG << "----------------------------------------------\n";
	ExLOG << "比较: "
		  << "\tsqA = {1,2,3,4,5,6};\n"
		  << "\tsqB = {1,2,3,4,5,6};\n" << ExLOG_NL;
	MyDS::SeqList<int> sqA = {1,2,3,4,5,6};
	MyDS::SeqList<int> sqB = {1,2,3,4,5,6};
	ExLOG << "\tExLOG << std::boolalpha << (sqA == sqB) << ExLOG_NL;" << ExLOG_NL;
	ExLOG << std::boolalpha << (sqA == sqB) << ExLOG_NL;
	ExLOG_BL;
	ExLOG << "比较: "
		  << "\tsqC = {\"A\",\"B\",\"C\"};\n"
		  << "\tsqD = {\"A\",\"B\",\"D\"};\n"
		  << "\tsqD = {\"A\",\"B\"};\n"
		  << "\tsqF;  // 默认初始化 \n" << ExLOG_NL;
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

	//计时结束
	auto end = TIME_NOW;
	std::chrono::duration<double> elapsed = end - start;
	ExLOG << "----------------------------------------------\n"
		  << "                   The End.\n"
		  << "              Elapsed: " << elapsed.count() <<"s\n"
		  << "----------------------------------------------\n";
}
MyDS_Ex_END