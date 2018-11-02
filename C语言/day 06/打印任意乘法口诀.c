#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序用于实现打印任意n*n的乘法口诀
* 郭文峰
* 2018/10/14
*/

cheng_fa(int n)
{
	int i = 0;
	int j = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d   ", i, j, i*j);
		}
		printf("\n");
	}
}

int main()
{
	//创建变量并标准输入将要打印的乘法口诀形式
	int n = 0;
	scanf("%d", &n);

	cheng_fa(n);

	system("pause");

	return 0;
}