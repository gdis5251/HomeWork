#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
** 本程序用来输出任意规模的乘法口诀表
** 郭文峰
** 2018/12/3
*/

void mulTable(int size)
{
	int i_ = 0;
	int j_ = 0;

	for (i_ = 1; i_ <= size; i_++)
	{
		for (j_ = 1; j_ <= i_; j_++)
		{
			printf("%d * %d = %-3d ", j_, i_, i_*j_);
		}
		printf("\n");
	}
}

int main(void)
{
	int size = 0;
	int i = 0;
	
	printf("Please input size that you like to print:> ");
	scanf("%d", &size);

	mulTable(size);

	system("pause");
	return 0;
}