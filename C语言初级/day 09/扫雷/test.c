#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

/*
* ʵ��ɨ����Ϸ�Ĳ���
* Ҫ��
* 1����һ������ը��
* 2���㿪һ���������ף������չ��һƬ
* ���ķ�
* 2018/10/19
*/

void menu()
{
	printf("***********************************\n");
	printf("*******        1. play      *******\n");
	printf("*******        0. exit      *******\n");
	printf("***********************************\n");
}

void game()
{
	int is = 0;

	//mine ����洢�׵�λ�� 0 Ϊ�գ�1 Ϊ��
	char mine[ROWS][COLS] = { 0 };
	//show ����洢��Ϸ�̣�������ÿ�ε������ʾ��Χ�׵ĸ���
	char show[ROWS][COLS] = { 0 };
	
	//��ʼ��mine ��������Ԫ��Ϊ'0',show ��������Ԫ��Ϊ'*'
	//Init(mine, show, ROWS, COLS);
	Init(mine, ROWS, COLS, '0');
	Init(show, ROWS, COLS, '*');

	//���õ���
	setMine(mine, ROWS, COLS);

	//��ӡmine ����
	DisplayBoard(mine, ROWS, COLS);

	printf("\n");
	printf("-------------------------\n");
	printf("\n");

	//��ӡ��Ϸ���
	DisplayBoard(show, ROWS, COLS);
	//��һ������ը��
	SafeMove(mine, show, ROWS, COLS);

	//��������ʣ�µ�'*' ����׵�������ͬʱ�����Ӯ
	if (CountShow(show, ROWS, COLS) == EASY_MODE)
	{
		printf("-------------------------\n");
		DisplayBoard(mine, ROWS, COLS);
		printf("��ϲ�㣡��Ӯ�ˣ�\n");
		return;
	}
	
	/*DisplayBoard(mine, ROWS, COLS);
	printf("\n");
	printf("-------------------------\n");
	printf("\n");*/
	DisplayBoard(show, ROWS, COLS);
	

	while (1)
	{
		//�ж����ѡ��������ǲ��ǵ��ף������򷵻�1����������չ������������Ϣ
		is = FindMine(mine, show, ROWS, COLS);
		//��������ʣ�µ�'*' ����׵�������ͬʱ�����Ӯ
		if (CountShow(show, ROWS, COLS) == EASY_MODE)
		{
			printf("-------------------------\n");
			DisplayBoard(mine, ROWS, COLS);
			printf("��ϲ��!��Ӯ�ˣ�\n");
			break;
		}
		
		if (is == 1)
		{
			printf("BOOM!!!!!!!!!!\n");
			printf("���ź����㱻ը����!\n");
			DisplayBoard(mine, ROWS, COLS);
			break;
		}

	/*	DisplayBoard(mine, ROWS, COLS);
		printf("\n");
		printf("-------------------------\n");
		printf("\n");*/
		DisplayBoard(show, ROWS, COLS);

	}
}


int main(void)
{
	int i = 0;
	int j = 0;
	int input = 0;

	srand((unsigned int)time(NULL));

	//���ò˵���������ӡ��Ϸ�˵�
	menu();

	do
	{
		printf("��������Ҫѡ��ѡ�");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ��\n");
				break;
			default:
				printf("����������������룡\n");
				break;
		}

	} while (input);

	system("pause");
	return 0;
}