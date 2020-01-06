#define MAXSIZE 100
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct SeqStack
{
    ElemType* base;//栈顶指针
    ElemType* top;//栈底指针
    int stackSize;//栈可用的最大容量
}SeqStack;

void InitStack(SeqStack& S)//初始化
{
    S.base = new ElemType[MAXSIZE];
    if (!S.base)
    {
        exit(-1);
    }
    S.top = S.base;
    S.stackSize = MAXSIZE;
}

void Push(SeqStack& S, ElemType e)//入栈
{
    if (S.top-S.base==S.stackSize)
    {
        cout << "栈满。" << endl;
    }
    *S.top++ = e;
}

void Pop(SeqStack& S, ElemType& e)//出栈
{
    if (S.base==S.top)
    {
        cout << "栈空。" << endl;
    }
    e = *S.top--;
}

ElemType GetTop(SeqStack S)//取栈顶元素
{
    if (S.top!=S.base)
    {
        return *(S.top - 1);
    }
}
int main()
{
    return 0;
}
