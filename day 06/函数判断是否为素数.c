#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* 写一个函数判断一个数是否为素数
* 郭文峰
* 2018/10/14
*/

int is_prime(int x)
{
	int n = sqrt(x);
	int i = 0;

	for (i = 2; i <= n; i++)
	{
		if (x % i == 0)
		{
			return -1;
		}
	}
	return 1;
	
}

int main(void)
{
	int num = 0;
	int a = 0;
	
	scanf("%d", &num);

	a = is_prime(num);

	if (1 == a)
	{
		printf("%d为素数！\n", num);

	}
	else
	{
		printf("%d不是素数！\n", num);
	}

	system("pause");
	return 0;
}