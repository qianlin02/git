#define _CRT_SECURE_NO_WARNINGS
#include "±í.h"
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
		case 1:strcpy(Data.dizhi, "×Ó");
			strcpy(Data.name, "Êó");
			Insert(L, Data, i);
			break;
		case 2:strcpy(Data.dizhi, "³ó");
			strcpy(Data.name, "Å£");
			Insert(L, Data, i);
			break;
		case 3:strcpy(Data.dizhi, "Òú");
			strcpy(Data.name, "»¢");
			Insert(L, Data, i);
			break;
		case 4:strcpy(Data.dizhi, "Ã®");
			strcpy(Data.name, "ÍÃ");
			Insert(L, Data, i);
			break;
		case 5:strcpy(Data.dizhi, "³½");
			strcpy(Data.name, "Áú");
			Insert(L, Data, i);
			break;
		case 6:strcpy(Data.dizhi, "ËÈ");
			strcpy(Data.name, "Éß");
			Insert(L, Data, i);
			break;
		case 7:strcpy(Data.dizhi, "Îç");
			strcpy(Data.name, "Âí");
			Insert(L, Data, i);
			break;
		case 8:strcpy(Data.dizhi, "Î´");
			strcpy(Data.name, "Ñò");
			Insert(L, Data, i);
			break;
		case 9:strcpy(Data.dizhi, "Éê");
			strcpy(Data.name, "ºï");
			Insert(L, Data, i);
			break;
		case 10:strcpy(Data.dizhi, "ÓÏ");
			strcpy(Data.name, "¼¦");
			Insert(L, Data, i);
			break;
		case 11:strcpy(Data.dizhi, "Ðç");
			strcpy(Data.name, "¹·");
			Insert(L, Data, i);
			break;
		case 12:strcpy(Data.dizhi, "º¥");
			strcpy(Data.name, "Öí");
			Insert(L, Data, i);
			break;
		default:
			break;
		}

	}
	int input;
	do {
		menu();
		printf("ÇëÑ¡Ôñ:>");
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
			printf("ÍË³öÊ®¶þÉúÐ¤²éÑ¯±í\n"); break;
		default:
			printf("Ñ¡Ôñ´íÎó\n"); break;
		}
	} while (input);

;

	return 0;
}