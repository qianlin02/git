#include"CaList.h"

int Length(List L)
{
	List P;
	int count = 0;
	P = L;
	while (P)
	{
		P = P->Next;
		count++;
	}
	return count;
}