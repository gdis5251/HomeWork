#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
  例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19 
* 郭文峰
* 2018/10/15
*/
int sum = 0;

int DigitSum(int n)
{
	

	if (n > 9)
	{
		DigitSum(n / 10);
	}
	
	return sum += n % 10;
}

int main(void)
{
	int result = 0;
	int n = 0;
	int flag = 0;

	printf("请输入一个非负的数字：");

	do
	{
		scanf("%d", &n);

		result = DigitSum(n);

		if (-1 == result)
		{
			printf("输入错误！\n请重新输入一个非负的数字:");
			flag = 1;
		}
		else
		{
			printf("%d\n", result);
			flag = 0;
		}
	} while (flag);

	system("pause");
	return 0;
}