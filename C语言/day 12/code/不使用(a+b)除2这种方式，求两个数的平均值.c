#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 不使用（a+b）/2这种方式，求两个数的平均值。 
* 郭文峰
* 2018/10/28
*/

double average(double num1, double num2)
{
	return num1 - (num1 - num2)/2;
}

int main(void)
{
	double num1 = 0;
	double num2 = 0;

	//先输入两个数
	scanf("%lf%lf", &num1, &num2);

	//用链式访问来求两个数的平均数并输出
	printf("%.2lf", average(num1, num2));

	system("pause");
	return 0; 
}