#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

/*
* 测试程序需要测试三子棋的正常运行
* 郭文峰
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
	//创建一个二维数组来存储棋盘
	char board[ROW][COL] = { 0 };
	int i = 0;
	int j = 0;
	int ch = 0;
	//InitBoard函数用来初始化board数组，并且全部初始化为‘ ’（空格）
	InitBoard(board, ROW, COL);
	//DisplayBoard函数用来打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		
		//用户选择一个坐标，并进行标记
		PlayerMove(board, ROW, COL);
		//判断是否赢得游戏
		ch = IsWin(board, ROW, COL);
		if (ch == 'X')
		{
			printf("恭喜你！你赢了！\n");
			DisplayBoard(board, ROW, COL);
			break;
		}
		else if (ch == 'Q')
		{
			printf("很惊险！是平局！\n");
			DisplayBoard(board, ROW, COL);
			break;
		}
		else if (ch == '0')
		{
			printf("很抱歉！电脑获胜！\n");
			DisplayBoard(board, ROW, COL);
			break;
		}
		
		DisplayBoard(board, ROW, COL);
		printf("               \n");
		printf("---------------\n");
		printf("               \n");

		//电脑随机选择一个坐标进行标记
		ComputerMove(board, ROW, COL);
		ch = IsWin(board, ROW, COL);
		if (ch == 'X')
		{
			printf("恭喜你！你赢了！\n");
			DisplayBoard(board, ROW, COL);
			break;
		}
		else if (ch == '0')
		{
			printf("很抱歉！电脑获胜！\n");
			DisplayBoard(board, ROW, COL);

			break;
		}
		else if (ch == 'Q')
		{
			printf("很惊险！是平局！\n");
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
	//菜单函数，打印游戏开始菜单
	menu();
	
	do{
		printf("请输入您要选的选项：");
		//接收用户选择的选项
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误！请重新输入！\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
}