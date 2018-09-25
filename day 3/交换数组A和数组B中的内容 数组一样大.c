#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 4, 5, 6 };

	printf("arr1= ");

	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\narr2= ");

	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr2[i]);
	}

	for (i = 0; i < 3; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;

	}

	printf("\narr1= ");

	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\narr2= ");

	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr2[i]);
	}

	printf("\n");

	system("pause");
	return 0;
}