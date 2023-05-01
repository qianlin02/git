#include"game.h"



void InitBoard(char board[ROWS][COLS], int rows, int cols,char charater)
{
	int i, j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = charater;
		}
	}
}
void DisplayBorad(char borad[ROWS][COLS], int row, int col)
{
	int i, j = 1;
	printf("------扫雷游戏-------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ",borad[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("------扫雷游戏-------\n");
}
void SetplayBorad(char borad[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x, y = 0;
	while (count)
	{
		x = rand() % row + 1;//1-9
		y = rand() % col + 1;//1-9
		if (borad[x][y] == '0')
		{
			count--;
			borad[x][y] = '1';
		}
	}
}
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x, y = 0;
	int total = ROW * COL - EASY_COUNT;
	while (total)
	{
		printf("请输入排查坐标:>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x < 10 && y>0 && y < 10)
		{
			if (mine[x][y] == '1')
			{
				printf("扫到雷了，游戏结束\n");
				DisplayBorad(mine, ROW, COL);
				break;
			}
			else
			{
				//判断此出周围有几个雷
				int count = Findminelei(mine,x,y);
				if (show[x][y] != '*')
				{
					printf("重复输入，请重新输入\n");
				}
				else
				{
					show[x][y] = count+'0';
					DisplayBorad(show, ROW, COL);
				    total--;
				}
				
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	if (total == 0)
	{
		printf("恭喜你，通关了\n");
		DisplayBorad(mine, ROW, COL);
	}
		
}
int Findminelei(char borad[ROWS][COLS], int x, int y)
{
	int i, j = 0;
	int sum = 0;
	for (i = -1 ; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			sum += borad[x][y];
		}
	}
	return sum - 9 * '0';
}