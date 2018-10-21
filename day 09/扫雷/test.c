#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

/*
* 实现扫雷游戏的测试
* 要求：
* 1、第一步不能炸死
* 2、点开一个若不是雷，则可以展开一片
* 郭文峰
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

	//mine 数组存储雷的位置 0 为空，1 为雷
	char mine[ROWS][COLS] = { 0 };
	//show 数组存储游戏盘，并且在每次点击后显示周围雷的个数
	char show[ROWS][COLS] = { 0 };
	
	//初始化mine 数组所有元素为'0',show 数组所有元素为'*'
	//Init(mine, show, ROWS, COLS);
	Init(mine, ROWS, COLS, '0');
	Init(show, ROWS, COLS, '*');

	//设置地雷
	setMine(mine, ROWS, COLS);

	//打印mine 数组
	DisplayBoard(mine, ROWS, COLS);

	printf("\n");
	printf("-------------------------\n");
	printf("\n");

	//打印游戏面板
	DisplayBoard(show, ROWS, COLS);
	//第一步不被炸死
	SafeMove(mine, show, ROWS, COLS);

	//如果面板上剩下的'*' 与地雷的总数相同时，玩家赢
	if (CountShow(show, ROWS, COLS) == EASY_MODE)
	{
		printf("-------------------------\n");
		DisplayBoard(mine, ROWS, COLS);
		printf("恭喜你！你赢了！\n");
		return;
	}
	
	/*DisplayBoard(mine, ROWS, COLS);
	printf("\n");
	printf("-------------------------\n");
	printf("\n");*/
	DisplayBoard(show, ROWS, COLS);
	

	while (1)
	{
		//判断玩家选择的坐标是不是地雷，若是则返回1，若不是则展开附近地雷信息
		is = FindMine(mine, show, ROWS, COLS);
		//如果面板上剩下的'*' 与地雷的总数相同时，玩家赢
		if (CountShow(show, ROWS, COLS) == EASY_MODE)
		{
			printf("-------------------------\n");
			DisplayBoard(mine, ROWS, COLS);
			printf("恭喜你!你赢了！\n");
			break;
		}
		
		if (is == 1)
		{
			printf("BOOM!!!!!!!!!!\n");
			printf("很遗憾，你被炸死了!\n");
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

	//调用菜单函数，打印游戏菜单
	menu();

	do
	{
		printf("请输入您要选的选项：");
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