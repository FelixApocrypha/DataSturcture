#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	int length;
	LNode* next;
}LNode, *LinkList;

void InitList(LinkList& L)//初始化
{
	L = new LNode;
	L->next = NULL;
	LNode* r = new LNode;
	r = L;
	cout << "请定义单链表长度：";
	cin >> L->length;
	for (size_t i = 0; i < L->length; i++)
	{
		LNode* p = new LNode;
		cout << "请输入第" << i + 1 << "个节点的数据：";
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

void ListInsert(LinkList& L)//插入
{
	int insert_Location;
	ElemType insert_Data;
	cout << "请输入插入位置：";
	cin >> insert_Location;
	if (insert_Location <= 0 || insert_Location > L->length)
	{
		cout << "无效位置，请重新输入插入位置：";
		cin >> insert_Location;
	}
	cout << "请输入插入数据：";
	cin >> insert_Data;

	int i = 1;
	LNode* p = new LNode;
	p = L;
	while (p && i <= insert_Location - 1)
	{
		p = p->next;
		i++;
	}
	LNode* s = new LNode;
	s->data = insert_Data;
	if (p)
	{
		s->next = p->next;
		p->next = s;
		L->length++;
	}
	cout << "插入成功。" << endl;
}

void ListDelete(LinkList& L)//删除
{
	int delete_Location;
	cout << "请输入要删除节点的位置：";
	cin >> delete_Location;
	if (delete_Location <= 0 || delete_Location > L->length)
	{
		cout << "无效位置，请重新输入删除位置：";
		cin >> delete_Location;
	}
	LNode* p = new LNode;
	p = L;
	int i = 1;
	while (p && i <= delete_Location - 1)
	{
		p = p->next;
		i++;
	}
	LNode* q = new LNode;
	if (q && p)
	{
		q = p->next;
		p->next = q->next;
		L->length--;
	}
	delete q;
	cout << "删除成功。" << endl;
}

void RewriteElem(LinkList& L)//修改
{
	int elem_Location;
	cout << "请输入修改节点的位置：";
	cin >> elem_Location;
	if (elem_Location <= 0 || elem_Location > L->length)
	{
		cout << "无效位置，请重新输入插入位置：";
		cin >> elem_Location;
	}
	int elem_Rewrite;
	cout << "请输入修改后的该节点数值：";
	cin >> elem_Rewrite;
	LNode* p = new LNode;
	p = L;
	int i = 1;
	while (p && i <= elem_Location)
	{
		p = p->next;
		i++;
	}
	if (p)
	{
		p->data = elem_Rewrite;
	}
}

ElemType LocateElem(LinkList L)//查找
{
	int elem_Location;
	cout << "请输入要查找节点的位置：";
	cin >> elem_Location;
	if (elem_Location <= 0 || elem_Location > L->length)
	{
		cout << "无效位置，请重新输入插入位置：";
		cin >> elem_Location;
	}
	LNode* p = new LNode;
	p = L;
	int i = 1;
	while (p && i <= elem_Location)
	{
		p = p->next;
		i++;
	}
	if (p)
	{
		return p->data;
	}
	return -1;
}

void ListTraverse(LinkList L)//遍历
{
	LNode* p = new LNode;
	p = L;
	for (size_t i = 0; i < L->length; i++)
	{
		cout << p->next->data << endl;
		p = p->next;
	}
}

int main()
{
	LinkList L;
	InitList(L);//初始化
	ListTraverse(L);//遍历
	cout << LocateElem(L) << endl;//查找
	ListInsert(L);//插入
	ListTraverse(L);//遍历
	ListDelete(L);//删除
	ListTraverse(L);//遍历
	RewriteElem(L);//修改
	ListTraverse(L);//遍历

	return 0;
}
