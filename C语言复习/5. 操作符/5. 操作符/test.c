#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
** 本程序用来进行操作符详解章节的代码练习
** 郭文峰
** 2018/12/6
*/

//1. 统计一个整数二进制1的个数
int main(void)
{
	int num = 0;
	int count = 0;

	scanf("%d", &num);

	while (num)
	{	
		count++;
		num &= (num - 1);
	}

	printf("%d\n", count);

	system("pause");
	return 0;
}