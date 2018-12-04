#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
** 本程序用来判断1000年---2000年之间的闰年
   判断闰年的条件是：不能被4或100整除、或者不能被400整除
** 郭文峰
** 2018/12/3
*/

int isLeapYear(int year)
{
	if (((0 == year % 4) && (0 != year % 100)) || 0 == year % 400)
		return 1;
	
	return 0;
}

int main(void)
{
	int i = 0;
	int flag = 0;
	int count = 0;

	printf("The leap between 1000 to 2000 is :> ");
	
	for (i = 1000; i <= 2000; i++)
	{
		flag = isLeapYear(i);

		if (flag)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("%d\n", count);


	system("pause");
	return 0;
}