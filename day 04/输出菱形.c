#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int j = 0;

	printf("输出一个菱形！\n");
	//输出上半个菱形
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4 - i; j++)
		{
			printf(" "); //
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//输出下半个菱形
	for (i = 3; i >= 1; i--)
	{
		for (j = 1; j <= 4 - i; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");

	}
	printf("\n");

	system("pause");
	return 0;
}