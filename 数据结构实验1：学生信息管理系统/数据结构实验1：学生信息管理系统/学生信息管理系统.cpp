/* 
   数据结构实验1：学生信息管理系统.
   实验内容:
   定义一个包含学生信息(学号，姓名，成绩)的的顺序表和链表，使其具有如下功能:
	(1)根据指定学生个数，逐个输入学生信息;
	(2)逐个显示学生表中所有学生的相关信息;
	(3)根据姓名进行查找，返回此学生的学号和成绩;
	(4)根据指定的位置可返回相应的学生信息(学号，姓名，成绩);
	(5)给定一个学生信息，插入到表中指定的位置;
	(6)删除指定位置的学生记录;
	(7)统计表中学生个数.
*/
#include<iostream>

using namespace std;

#define MAXSIZE 100
typedef int DataType_0;
typedef float DataType_1;

typedef struct Student//学生信息类型定义
{
	DataType_0 no = 0;//学号
	string name;//姓名
	DataType_1 price = 0;//成绩
}Student;

typedef struct SeqList//学生信息管理系统类型定义
{
	Student* elem;
	DataType_0 length;
}SeqList;

istream& operator >>(istream& in, Student& Stu)// 重载输入运算符
{
	cout << "学号：";
	in >> Stu.no;
	cout << "姓名：";
	in >> Stu.name;
	cout << "成绩：";
	in >> Stu.price;
	return in;
}

ostream& operator <<(ostream& out, Student& Stu)// 重载输出运算符
{
	out << "学号：" <<Stu.no <<" "<<"姓名：" <<Stu.name<< " "<< "成绩：" << Stu.price << endl;
	return out;
}

void InitList(SeqList& L)//初始化
{
	L.elem = new Student[MAXSIZE];
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
}

void CreatList(SeqList& L,DataType_0 allNum)//根据指定学生个数，逐个输入学生信息
{
	
	if (allNum > MAXSIZE) 
	{
		cout << "人数上限，请重新定义." << endl;
	    cin >> allNum;
	}
	if (allNum < 0)
	{
		cout << "人数无法小于0，请重新定义." << endl;
		cin >> allNum;
	}
	for (int i = 1; i <= allNum; i++)
	{
		cout << "请输入第" << i << "个学生的信息：" << endl;
		cin >> L.elem[i - 1];
	}
	L.length = allNum;
	cout << "创建成功！" << endl;
}

void GetElem(SeqList L)//逐个显示学生表中所有学生的相关信息
{
	cout << "此时该系统内有以下学生信息：" << endl;
	for (int i = 1; i <= L.length; i++)
	{
		cout << i << ". " << L.elem[i - 1];
	}
}

void LocateName(SeqList L, string name)//根据姓名进行查找，返回此学生的学号和成绩
{
	for (int i = 1; i <= L.length; i++)
	{
		if (name == L.elem[i - 1].name)
		{
			cout << "学号:" << L.elem[i - 1].no << endl;
			cout << "成绩:" << L.elem[i - 1].price << endl;
		}
	}
}

void LocateElem(SeqList L, DataType_0 LocateNum)//根据指定的位置可返回相应的学生信息(学号，姓名，成绩)
{


	if (LocateNum <= 0 || LocateNum > L.length)
	{
		cout << "无效的位置，请重新输入：";
		cin >> LocateNum;
	}
	cout << L.elem[LocateNum - 1];
}

void ListInsert(SeqList& L, DataType_0 insertNum, Student insertElem)//给定一个学生信息，插入到表中指定的位置
{
	if (L.length == MAXSIZE) cout << "内存不足，插入失败." << endl;
	for (int i = L.length; i >= insertNum; i--)
	{
		L.elem[i] = L.elem[i - 1];
	}
	L.elem[insertNum-1] = insertElem;
	L.length++;
	cout << "插入成功！" << endl;
}

void ListDelete(SeqList& L, DataType_0 deleteNum)//删除指定位置的学生记录
{
	if (L.length == 0) cout << "当前无可删除数据." << endl;
	for (int i = deleteNum; i <= L.length; i++)
	{
		L.elem[i - 1] = L.elem[i];
	}
	L.length--;
	cout << "删除成功！" << endl;
}

int GetAllNum(SeqList L)//统计表中学生个数
{
	return L.length;
}

int main()
{
	//定义学生信息管理系统L
	SeqList	L;
	//初始化L
	InitList(L);
	//创建L
	DataType_0 allNum = 0;
	cout << "请定义学生人数:";
	cin >> allNum;
	CreatList(L,allNum);
	//遍历L
	GetElem(L);
	//根据姓名查询学号和成绩
	string name;
	cout << "请输入要查询的同学的姓名:" ;
	cin >> name;
	LocateName(L, name);
	//根据编号查找学号、姓名和成绩
	DataType_0 LocateNum = 0;
	cout << "请输入要查询的同学的编号:" ;
	cin >> LocateNum;
	LocateElem(L, LocateNum);
	//在任意位置插入元素
	DataType_0 insertNum = 0;
	Student insertElem;
	cout << "请输入要插入的学生信息："<<endl;
	cin >> insertElem;
	cout << "请输入想要插入的位置编号：";
	cin >> insertNum;
	ListInsert(L, insertNum, insertElem);
	//遍历L
	GetElem(L);
	//返回该系统学生数
	cout << "此时该系统共有学生" << GetAllNum(L) << "人." << endl;
	//删除任意位置元素
	DataType_0 DeleteNum = 0;
	cout << "请输入想要删除的位置编号：";
	cin >> DeleteNum;
	ListDelete(L, DeleteNum);
	//遍历L
	GetElem(L);
	//返回该系统学生数
	cout << "此时该系统共有学生" << GetAllNum(L) << "人." << endl;

	return 0;
}
