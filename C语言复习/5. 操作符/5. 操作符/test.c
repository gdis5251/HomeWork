#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
** �������������в���������½ڵĴ�����ϰ
** ���ķ�
** 2018/12/6
*/

//1. ͳ��һ������������1�ĸ���
int main(void)
{
	int num = 0;
	int count = 0;

	scanf("%d", &num);

	while (num)
	{	
		count++;
		num &= (num - 1);
	}

	printf("%d\n", count);

	system("pause");
	return 0;
}