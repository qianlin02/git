//�����ջ
//�����ջ������Push�������������Stack Full�����ҷ���false����������ǿյģ�
//��Pop�������������Stack Empty�������ҷ���ERROR
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
typedef struct SNode* PtrToSNode;
struct SNode {
    ElementType* Data;  /* �洢Ԫ�ص����� */
    Position Top;       /* ջ��ָ��       */
    int MaxSize;        /* ��ջ�������   */
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    S->Top = 0;
    S->MaxSize = MaxSize;
    return S;
}

bool Push(Stack S, ElementType X);
ElementType Pop(Stack S);

Operation GetOp();          /* ����ʵ�֣�ϸ�ڲ��� */
void PrintStack(Stack S); /* ����ʵ�֣�ϸ�ڲ��� */

int main()
{
    ElementType X;
    Stack S;
    int N, done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
        case push:
            scanf("%d", &X);
            Push(S, X);
            break;
        case pop:
            X = Pop(S);
            if (X != ERROR) printf("%d is out\n", X);
            break;
        case end:
            PrintStack(S);
            done = 1;
            break;
        }
    }
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */

//
//�����ջ�Ƕ�ջ��������� Top��ָ��λ�ñ�һ���������
//

bool Push(Stack S, ElementType X)
{
    if (S->Top == S->MaxSize)//Top���㿪ʼ�ģ�ջ������λ��ΪMaxSize
    {
        printf("Stack Full\n");
        return false;
    }
    else
    {
        S->Data[S->Top] = X;
        S->Top++;
        return true;
    }
}
ElementType Pop(Stack S)
{
    if (S->Top == 0)
    {
        printf("Stack Empty\n");
        return ERROR;
    }
    else {
        S->Top--;            //�ȶ�Top��λ�øı�
        ElementType p = S->Data[S->Top];
        return p;
    }
}