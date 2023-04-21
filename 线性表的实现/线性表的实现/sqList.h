#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define DEFAULT_sz 100
#define add 5
#define ERROR -1


typedef int ElementType;

struct LNode
{
	ElementType* Data;//存放信息
	int Count;//当前顺序表中的个数
	int capacity;//当前顺序表所能存的容量
};

typedef struct LNode* List;

//增删查改

List MakeEmpty();//创建链表
bool InsertData(List L, ElementType X, int i);//插入数据
void Add(List L);//增容
int Find(List L, ElementType X);//查找
bool Delete(List L, int i);//删除
bool Change(List L,ElementType X,int i);//更改
void Show(List L);//显示