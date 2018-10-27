#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 递归和非递归分别实现求第n个斐波那契数
* 郭文峰
* 2018/10/14
*/

int fib_d(int n)
{
	
	//if条件包括n=1或2的情况
	if (n <= 2 && n > 0)
	{
		return 1;

	}
	//递归计算n>2的情况
	if (n > 2)
	{
		return fib_d(n - 1) + fib_d(n - 2);
	}

	return 0;
	
	
}

int fib_f(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;

	if (n <= 2 && n > 0)
	{
		return 1;
	}
	
	while (n > 2)
	{
		n--;
		c = a + b;
		a = b;
		b = c;
	}
	
	return c;
}



int main(void)
{
	int a = 0;
	int b = 0;
	int n = 0;

	scanf("%d", &n);

	//分别调用递归和非递归的函数求第n个斐波那契数
	a = fib_d(n);
	b = fib_f(n);
	printf("递归:>%d, 非递归:>%d \n", a, b);

	system("pause");
	return 0;
}