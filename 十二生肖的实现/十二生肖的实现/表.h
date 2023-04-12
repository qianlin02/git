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


List MakeEmpty();        //建空表 
bool Insert(List L, ElementType x, int i);//加入内容 
int Find(List L, ElementType x);//按值查找 
bool Delete(List L, int i);//删除数据 
void Destroy(List L);//销毁表 
void Display(List L); //打印表
