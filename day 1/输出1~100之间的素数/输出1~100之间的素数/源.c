#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main()
{
	printf("1~100之间的素数为：\n1\t2\t3\t");
	int i = 4;
	int count = 3;
	int n;
	int j;
	for (i = 4; i <= 100; i++)
	{
		n = sqrt(i);
		for (j = 2; j <= n; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j > n)
		{
			printf("%d\t", i);
			count++;
		}
		if (count % 5 == 0)
			printf("\n");
	}
	system("pause");
	return 0;
}