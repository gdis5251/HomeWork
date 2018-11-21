#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int isprime(int num)
{
	int i = 0;
	for (i = 2; i <= sqrt(num); i++)
	{
		if (0 == num % i)
			return 1;
	}
	return 0;
}

int main()
{
	printf("The prime between 1 to 100:");

	int i = 0;
	int count = 0;

	for (i = 2; i < 101; i++)
	{
		if (0 == isprime(i))
		{
			printf("%d ", i);
			count++;
		}

	}
	printf("\n");
	printf("There are %d prime!\n", count);
	system("pause");
	return 0;
}