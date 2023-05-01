#include"game.h"
void menu()
{
	printf("************************\n");
	printf("*****    1.play    *****\n");
	printf("*****    0.exit    *****\n");
	printf("************************\n");
}
void game()
{
	char mine[ROWS][COLS] = {0};//存放埋好雷的信息
	char show[ROWS][COLS] = {0};//存放排查雷的信息
	//初始化数组为指定内容
	//mine数组初始化为0
	InitBoard( mine,ROWS,COLS, '0');
	//show数组初始化为*
	InitBoard(show, ROWS, COLS, '*');

	
	DisplayBorad(show, ROW, COL);//展示给玩家
	SetplayBorad(mine, ROW, COL);//埋雷
	//排查雷
	//DisplayBorad(mine, ROW, COL);//埋雷情况
	Findmine(mine,show, ROW, COL);
}
int main()
{
	int input = 0;
	//设置随机生成数的起点
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出扫雷\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}