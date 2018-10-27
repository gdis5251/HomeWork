#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[10] ;
	int i = 0, j = 0;
	int temp;
	for (i = 0; i < 3; i++)
		scanf("%d", &arr[i]);
	for (i=0; i < 2; i++)
	{
		for (j=0; j < 2; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 3;i++)
		printf("%d   ", arr[i]);
	system("pause ");
	return 0;
}