#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ�� 
* ���ķ�
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

	//������������
	scanf("%lf%lf", &num1, &num2);

	//����ʽ����������������ƽ���������
	printf("%.2lf", average(num1, num2));

	system("pause");
	return 0; 
}