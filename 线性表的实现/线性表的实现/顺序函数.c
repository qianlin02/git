#include"sqList.h"
//��ʼ��˳���
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
		printf("Makeʧ�ܣ�%s\n", strerror(errno));
	}
	L->capacity = DEFAULT_sz;
	return L;
}

int Find(List L, ElementType X)
{
	int i = 0;
	while (i<=L->Count&&L->Data[i]!=X)//�ҵ�X��λ��        ****************������
		i++;
	if (i > L->Count)
		return ERROR;
	else
		return i;//����X��λ��		
}

void Add(List L)
{
		ElementType* ptr = (ElementType*)realloc(L->Data, (L->capacity + add)*sizeof(ElementType));//����
		if (ptr == NULL)
		{
			printf("add����ʧ�ܣ�%s/n", strerror(errno));
		}
		else
		{
			L->Data = ptr;
			L->capacity = L->capacity + add;
		}
}
bool InsertData(List L, ElementType X, int i)//i��ʾ���뵽�ڼ�����//i-1�Ǳ�ʾ�����е�λ��
{
	if (L->Count == L->capacity)
		Add(L);                  //����
	if(i<1||i>=L->capacity)
	{
		printf("λ�򲻺Ϸ�");
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
		printf("��Ϊ��");
			return false;
	}
	if (i<1 || i>L->capacity)
	{
		printf("λ��%d������",i);
		return false;
	}
	int j = 0;
	for (j = i; j <= L->Count; j++)//ɾ����iλ������ǰ��1λ,��i��
	{
		L->Data[j - 1] = L->Data[j];
	}
	L->Count--;
	return true;
}
bool Change(List L, ElementType X, int i)
{
	if (i < 1 || i >= L->capacity)//i��ʾ�ڼ�����
	{
		printf("λ�򲻴���");
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