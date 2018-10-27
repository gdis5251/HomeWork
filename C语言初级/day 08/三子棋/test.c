#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

/*
* ���Գ�����Ҫ�������������������
* ���ķ�
* 2018/10/18
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
	//����һ����ά�������洢����
	char board[ROW][COL] = { 0 };
	int i = 0;
	int j = 0;
	int ch = 0;
	//InitBoard����������ʼ��board���飬����ȫ����ʼ��Ϊ�� �����ո�
	InitBoard(board, ROW, COL);
	//DisplayBoard����������ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		
		//�û�ѡ��һ�����꣬�����б��
		PlayerMove(board, ROW, COL);
		//�ж��Ƿ�Ӯ����Ϸ
		ch = IsWin(board, ROW, COL);
		if (ch == 'X')
		{
			printf("��ϲ�㣡��Ӯ�ˣ�\n");
			DisplayBoard(board, ROW, COL);
			break;
		}
		else if (ch == 'Q')
		{
			printf("�ܾ��գ���ƽ�֣�\n");
			DisplayBoard(board, ROW, COL);
			break;
		}
		else if (ch == '0')
		{
			printf("�ܱ�Ǹ�����Ի�ʤ��\n");
			DisplayBoard(board, ROW, COL);
			break;
		}
		
		DisplayBoard(board, ROW, COL);
		printf("               \n");
		printf("---------------\n");
		printf("               \n");

		//�������ѡ��һ��������б��
		ComputerMove(board, ROW, COL);
		ch = IsWin(board, ROW, COL);
		if (ch == 'X')
		{
			printf("��ϲ�㣡��Ӯ�ˣ�\n");
			DisplayBoard(board, ROW, COL);
			break;
		}
		else if (ch == '0')
		{
			printf("�ܱ�Ǹ�����Ի�ʤ��\n");
			DisplayBoard(board, ROW, COL);

			break;
		}
		else if (ch == 'Q')
		{
			printf("�ܾ��գ���ƽ�֣�\n");
			DisplayBoard(board, ROW, COL);
			break;
		}

		DisplayBoard(board, ROW, COL);
		

	}



}

int main(void)
{
	int input = 0;
	
	srand((unsigned int)time(NULL));
	//�˵���������ӡ��Ϸ��ʼ�˵�
	menu();
	
	do{
		printf("��������Ҫѡ��ѡ�");
		//�����û�ѡ���ѡ��
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