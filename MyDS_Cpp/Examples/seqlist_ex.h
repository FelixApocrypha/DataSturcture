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
	//初始化
	//默认初始化
	ExLOG << "默认初始化: MyDS::SeqList<int> sq1;\n";
	ExSL sq1;
	//直接初始化
	ExLOG << "直接初始化: MyDS::SeqList<int> sq2(5, 1);\n";
	ExSL sq2(5, 1);
	//列表初始化
	ExLOG << "列表初始化: MyDS::SeqList<int> sq3 = {1,1,1,1,1};\n";
	ExSL sq3 = {1,1,1,1,1};
	//拷贝初始化
	ExLOG << "拷贝初始化: MyDS::SeqList<int> sq4 = sq3;\n";
	ExSL sq4 = sq3;
	//ExSL sq4(sq3), 等价;
	ExLOG_BL
	ExLOG << "遍历sq2、sq3、sq4: "<< ExLOG_NL
	for(size_t i = 0; i < sq2.Size(); ++i)
	{
		ExLOG << "i==" << i << ExLOG_TAB
		ExLOG << "sq2:" << sq2.At(i) << ExLOG_TAB
		ExLOG << "sq3:" << sq3.At(i) << ExLOG_TAB
		ExLOG << "sq4:" << sq4.At(i) << ExLOG_NL
	}
}
MyDS_Ex_END