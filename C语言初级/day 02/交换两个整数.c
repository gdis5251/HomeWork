#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j;
	scanf("%d%d", &i, &j);
	printf("交换前：");
	printf("i=%d, j=%d\n", i, j);
	printf("交换后：");
	i = i + j;
	j = i - j;
	i = i - j;
	printf("i=%d, j=%d\n", i, j);
	system("pause");
	return 0;
}