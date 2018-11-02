#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 写一个函数判断year是否为闰年
* 郭文峰
* 2018/10/14
*/

int is_leap_year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main(void)
{
	int year = 0;
	int a = 0;

	scanf("%d", &year);

	a = is_leap_year(year);

	if (1 == a)
	{
		printf("%d年为闰年！\n", year);
	}
	else
	{
		printf("%d年不是闰年!\n", year);
	}
	system("pause");
	return 0;
}