#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i = 0;
	float sum = 0;
	for (i = 1; i <= 100; i++)
	{
		sum += pow(-1, (i - 1))*(1.0 / i);
	}
	printf("sum = %f\n", sum);
	system("pause");
	return 0;
}