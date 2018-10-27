#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 写一个函数，来交换两个数
* 郭文峰
* 2018/10/14
*/

int swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	return *x, *y;
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	//标准输入将要交换的两个数
	scanf("%d%d", &num1, &num2);

	//交换前
	printf("Before: %d, %d\n", num1, num2);

	swap(&num1, &num2);
	
	//交换后
	printf("After : %d, %d\n", num1, num2);

	system("pause");
	return 0;
}