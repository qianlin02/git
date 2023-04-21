#include"sqList.h"
//初始化顺序表
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	if (L == NULL)
	{
		printf("L:%s\n", strerror(errno));
		return NULL;
	}
	L->Data=(ElementType*)calloc(DEFAULT_sz,sizeof(ElementType));
	L->Count = 0;
	if (L->Data == NULL)
	{
		printf("Make失败：%s\n", strerror(errno));
	}
	L->capacity = DEFAULT_sz;
	return L;
}

int Find(List L, ElementType X)
{
	int i = 0;
	while (i<=L->Count&&L->Data[i]!=X)//找到X的位置        ****************有歧义
		i++;
	if (i > L->Count)
		return ERROR;
	else
		return i;//返回X的位置		
}

void Add(List L)
{
		ElementType* ptr = (ElementType*)realloc(L->Data, (L->capacity + add)*sizeof(ElementType));//增容
		if (ptr == NULL)
		{
			printf("add增添失败：%s/n", strerror(errno));
		}
		else
		{
			L->Data = ptr;
			L->capacity = L->capacity + add;
		}
}
bool InsertData(List L, ElementType X, int i)//i表示插入到第几个数//i-1是表示数组中的位置
{
	if (L->Count == L->capacity)
		Add(L);                  //增容
	if(i<1||i>=L->capacity)
	{
		printf("位序不合法");
		return false;
	}
	else
	{
		int j = 0;
		for (j = L->Count - 1; j >= i; j--)
			L->Data[j] = L->Data[j + 1];
		L->Data[i - 1] = X;
		L->Count++;
		return true;
	}
}
bool Delete(List L, int i)
{
	if (L->Count == 0)
	{
		printf("表为空");
			return false;
	}
	if (i<1 || i>L->capacity)
	{
		printf("位序%d不存在",i);
		return false;
	}
	int j = 0;
	for (j = i; j <= L->Count; j++)//删除第i位，数据前移1位,共i次
	{
		L->Data[j - 1] = L->Data[j];
	}
	L->Count--;
	return true;
}
bool Change(List L, ElementType X, int i)
{
	if (i < 1 || i >= L->capacity)//i表示第几个数
	{
		printf("位序不存在");
		return false;
	}
	else
	{
	L->Data[i - 1] = X;
	return true;
	}
}
void Show(List L)
{
	int i = 0;
	for (i = 0; i < L->Count; i++)
	printf("%d ", L->Data[i]);
	printf("\n");
}