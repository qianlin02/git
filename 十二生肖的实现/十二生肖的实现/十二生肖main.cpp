#define _CRT_SECURE_NO_WARNINGS
#include "��.h"
void menu()
{
	printf("***********************************\n");
	printf("*****1.Insert           2.Find*****\n");
	printf("*****3.Delete        4.Destroy*****\n");
	printf("*****5.Display                *****\n");
	printf("*****0.exit                   *****\n");
	printf("***********************************\n");
}
int main()
{
	List L = MakeEmpty();
	ElementType Data;
	int i = 1;
	for (i = 1; i <= 12; i++)
	{
		Data.index = i;
		switch (i)
		{
		case 1:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 2:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "ţ");
			Insert(L, Data, i);
			break;
		case 3:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 4:strcpy(Data.dizhi, "î");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 5:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 6:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 7:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 8:strcpy(Data.dizhi, "δ");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 9:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 10:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 11:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		case 12:strcpy(Data.dizhi, "��");
			strcpy(Data.name, "��");
			Insert(L, Data, i);
			break;
		default:
			break;
		}

	}
	int input;
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			bool Insert(List L, ElementType x, int i); break;
		case 2:
			int Find(List L, ElementType x); break;
		case 3:
			bool Delete(List L, int i); break;
		case 4:
			void Destroy(List L); break;
		case 5:
			void Display(List L); break;
		case 0:
			printf("�˳�ʮ����Ф��ѯ��\n"); break;
		default:
			printf("ѡ�����\n"); break;
		}
	} while (input);

;

	return 0;
}