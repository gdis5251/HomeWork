#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序用于求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，例如：2+22+222+2222+22222 
* 郭文峰
* 2018/9/25
*/

int main()
{
	int i = 0;
	int sum = 0;
	int num = 0;
	int num1 = 0;

	scanf("%d", &num);// 读取一个数字

	num1 = num;
	sum = num;

	for (i = 1; i < 5; i++)
	{
		num = num * 10 + num1;
		sum += num;
	}

	printf("%d\n", sum);

	system("pause");
	return 0;
}