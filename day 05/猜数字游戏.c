#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* 本程序是用来实现一个猜数字小游戏，目的是更加深入的了解循环和函数的运用
* 郭文峰
* 2018/9/28
*/

void menu(void)
{
	printf("*****************************************************\n");
	printf("****************         1.play       ***************\n");
	printf("****************         0.exit       ***************\n");
	printf("*****************************************************\n");

}

void game(void)
{
	
	int rnum = rand() % 100 + 1;

	while (1)
	{
		printf("请输入猜的数字：");
		int num;
		scanf("%d", &num);

		if (num == rnum)
		{
			printf("猜对了！\n");
			break;
		}
		else if (num > rnum)
		{
			printf("猜大了！\n");

		}
		else
		{
			printf("猜小了！\n");
		}

	}
}

int main(void)
{
	int i = 0;
	int input = 0;

	srand((unsigned int)time(NULL));


	//选择是否要进行游戏
	do
	{
		menu();

		printf("请选择：");

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			input = 0;
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
}
