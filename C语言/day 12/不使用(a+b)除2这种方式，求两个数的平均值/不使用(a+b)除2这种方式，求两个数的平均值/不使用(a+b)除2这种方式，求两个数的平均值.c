#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
* ���ķ�
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

	//������������
	scanf("%d%d", &num1, &num2);

	//����ʽ����������������ƽ���������
	printf("%d", average(num1, num2));

	system("pause");
	return 0; 
}