#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAXSIZE 12
#define ERROR -1
typedef struct shengxiao ElementType;
typedef struct LNode * List;
struct shengxiao {
	int index;
	char dizhi[10];
	char name[10];
};

struct LNode {
	ElementType Data[MAXSIZE];
	int last;
};


List MakeEmpty();        //���ձ� 
bool Insert(List L, ElementType x, int i);//�������� 
int Find(List L, ElementType x);//��ֵ���� 
bool Delete(List L, int i);//ɾ������ 
void Destroy(List L);//���ٱ� 
void Display(List L); //��ӡ��
