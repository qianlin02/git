#pragma once


typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode List;


//���
int Length(List L);