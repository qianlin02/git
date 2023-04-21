#include"sqList.h"
int main()
{
	List L = MakeEmpty();
	int i,X = 0;
	for (i = 1,X=0; i <= 16; i++,X++)
	{
		InsertData( L,  X, i);
	}
	int t = Find (L,  2);

	Show(L);

	/*printf("%d\n", L->Data[t]);
	int x1 = 3;
	int x2 = 2;
	 Change(L,  x1,  x2);
	 Delete(L, i);
	 Show(L);*/
	return 0;
}