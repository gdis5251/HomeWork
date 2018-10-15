#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 递归和非递归分别实现求n的阶乘 
* 郭文峰
* 2018/10/15
*/

int jc_d(int n)
{
	if (n <= 1)
	{
		return 1;

	}
	else if (n >= 2)
	{
		return n * jc_d(n - 1);
	}
}

int jc_f(int n)
{
	int sum = 1;

	if (n == 0)
	{
		return 0;
	}

	while (n)
	{
		sum *= n;
		n--;
	}
	return sum;
}

int main(void)
{
	int n = 0;
	int a = 0;
	int b = 0;

	scanf("%d", &n);

	//递归
	a = jc_d(n);

	//非递归
	b = jc_f(n);

	printf("%d   %d \n", a, b);

	system("pause");
	return 0;
}