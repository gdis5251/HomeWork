#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 不使用（a+b）/2这种方式，求两个数的平均值。
* 郭文峰
* 2018/10/28
*/

int average(int num1, int num2)
{
	//return num1 - (num1 - num2)/2;
	//00000100 
	//00000110

	//00000100
	//00000010 >> 1  == 00000001
	//00000101
	return (num1 & num2) + ((num1 ^ num2) >> 1);
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	//先输入两个数
	scanf("%d%d", &num1, &num2);

	//用链式访问来求两个数的平均数并输出
	printf("%d", average(num1, num2));

	system("pause");
	return 0; 
}