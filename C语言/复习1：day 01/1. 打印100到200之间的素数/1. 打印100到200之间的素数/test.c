#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <math.h>

/*
** 本程序再次实现打印素数
** 郭文峰
** 2018/12/3
*/

int isPrime(int num)
{
	int i_ = 0;

	//if the number isn't prime , return 0
	for (i_ = 2; i_ <= sqrt(num); i_++)
	{
		if (0 == num % i_)
			return 0;
	}

	return 1;
}

int main(void)
{
	int i = 100;
	int flag = 0;
	int count = 0;

	for (i = 100; i <= 200; i++)
	{
		flag = isPrime(i);

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