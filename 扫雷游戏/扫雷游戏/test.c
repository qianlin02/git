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
	char mine[ROWS][COLS] = {0};//�������׵���Ϣ
	char show[ROWS][COLS] = {0};//����Ų��׵���Ϣ
	//��ʼ������Ϊָ������
	//mine�����ʼ��Ϊ0
	InitBoard( mine,ROWS,COLS, '0');
	//show�����ʼ��Ϊ*
	InitBoard(show, ROWS, COLS, '*');

	
	DisplayBorad(show, ROW, COL);//չʾ�����
	SetplayBorad(mine, ROW, COL);//����
	//�Ų���
	//DisplayBorad(mine, ROW, COL);//�������
	Findmine(mine,show, ROW, COL);
}
int main()
{
	int input = 0;
	//������������������
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳�ɨ��\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	} while (input);

	return 0;
}