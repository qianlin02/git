#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n, m;
	int i,j;
	int* a;
	int temp;
	scanf("%d %d", &n,&m);
	a = (int*)calloc(n, sizeof(int));
	if (a == NULL)
	{
		printf("%s", strerror(errno));
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++)
	{
		temp = a[0];
		for (j = 1; j < n; j++)
		{
			a[j - 1] = a[j];
		}
		a[n-1] = temp;
	}
	for (i = 0; i < n; i++)
	{

		printf("%d", a[i]);
		if (i < n - 1)
			printf(" ");
	}
	return 0;
}