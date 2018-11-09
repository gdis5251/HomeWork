#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 在屏幕上打印杨辉三角。 
  1 
  1 1 
  1 2 1 
  1 3 3 1 
* 郭文峰
* 2018/10/23
*/
void Yang(int n)
{
	int **p = (int **)malloc(sizeof(int *) * n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		p[i] = (int *)malloc(sizeof(int) * n);
	}

	for (i = 0; i < n; i++)
	{
		p[i][0] = 1;
		p[i][i] = 1;
	}

	i = 2;
	for (; i < n; i++)
	{
		int j = 1;
		for (; j < i; j++)
		{
			p[i][j] = p[i - 1][j] + p[i - 1][j - 1];
		}
	}

	

	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (; j < n - i; j++)
			printf(" ");
		for (j = 0; j <= i; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; i++)
	{
		free(p[i]);
	}
	free(p);
}

int main(void)
{
	int i = 0;
	int j = 0;
	int n = 0;
	int a[100][100] = { 0 };
	printf("Please Enter:");
	scanf("%d", &n);


	for (i = 1; i <= n; i++)
	{
		for (j = 1; j < n - i + 1; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= i; j++)
		{
			if (j == 1 || j == i)
			{
				a[i][j] = 1;
				printf("%  d", a[i][j]);
			}
			else
			{
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
				printf("%  d", a[i][j]);
			}
		}
		printf("\n");
	}

	Yang(n);

	system("pause");
	return 0;
}