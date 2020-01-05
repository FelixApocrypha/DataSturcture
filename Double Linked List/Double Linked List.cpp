#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct DuLNode
{
	ElemType data;//数据域
	DuLNode* prior;//直接前驱
	DuLNode* next;//直接后继
}DuLNode,*DuLinkList;

int main()
{
}
