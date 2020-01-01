#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;
typedef struct SeqList
{
	ElemType* elem;
	int length;
}SeqList;

void InitList(SeqList& L)//初始化
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
	{
		exit(-1);
	}
	L.length = 0;
}

void CreatList(SeqList& L)//创建顺序表，赋值
{
	cout << "请定义顺序表长度，其长度不得大于" << MAXSIZE << "." << endl;
	int n;//顺序表长度
	cin >> n;
	if (n > MAXSIZE || n < 0)
	{
		cout << "长度定义失败,请重新定义." << endl;
		cin >> n;
	}
	cout << "请依次输入顺序表要存储的" << n << "个元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> L.elem[i];    //输入数组元素
		L.length++;
	}
	cout << "存储成功." << endl;
}

void ListInsert(SeqList& L)//插入
{
	if (L.length==MAXSIZE)
	{
		cout << "该表已满，无法插入." << endl;
		exit(-1);
	}
	int j;//插入位置
	cout << "请输入要插入的位置：";
	cin >> j;
	while(j<0 || j>L.length)
	{
		cout << "无效位置，请重新输入：";
		cin >> j;
	}
	ElemType e;
	cout << "请输入要插入的元素：";
	cin >> e;
	for (size_t i = L.length-1; i >= j-1; i--)
	{
		L.elem[i + 1] = L.elem[i];
	}
	L.elem[j - 1] = e;
	L.length++;
	cout << "插入成功." << endl;
}
void ListTraverse(SeqList L)
{
	for(int i=0;i<=L.length-1;i++)
	{
		cout << L.elem[i] << endl;
	}
}

int main()
{
	SeqList L;
	InitList(L);
	CreatList(L);
	ListTraverse(L);
	ListInsert(L);
	ListTraverse(L);
	return 0;
}

