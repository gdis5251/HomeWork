#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
* ���ķ�
* 2018/10/15
*/

void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d  ", n % 10);
}

int main(void)
{
	int n = 0;

	scanf("%d", &n);

	print(n);

	system("pause");
	return 0;
}