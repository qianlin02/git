#include "表.h"
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	if (L != NULL)
	{
	L->last = -1;
	}
	else
	{
		;
	}
	return L;
}
bool Insert(List L, ElementType x, int i)
{
	int j;
	if (L->last == MAXSIZE - 1)
	{
		printf("表已满");
		return false;
	}
	if (i<1 || i>L->last + 2)
	{
		printf("不合法");
		return false;
	}
	for (j = L->last; j <= i - 2; j++)
	{
		L->Data[i - 1] = x;
		L->last++;
	}
	return true;
}
int Find(List L, ElementType x)
{
	int i = 0;
	while (i <= L->last && strcmp(L->Data[i].name, x.name) != 0)
	{
		i++;
	}
	if (i > L->last)
		return ERROR;
	else
		return i + 1;
}
bool Delete(List L, int i)
{
	int j=0;
	if (L->last == -1)
	{
		printf("表空");
		return false;
	}
	if (i<1 || i>L->last + 2)
	{

		printf("不合法");
		return false;
	}
	for ( j = i; j <= L->last; j++)
	{
		L->Data[j - 1] = L->Data[j];
	}
	L->last--;
	return true;
}
void Display(List L)
{
	int i = 0;
	for (i = 0; i <= L->last; i++)
	{
		printf("%d-%s-%s\n", L->Data[i].index, L->Data[i].dizhi, L->Data[i].name);
	}
	printf("\n");
}
void Destroy(List L)
{
	if (L)
	{
		free(L);
	}
}