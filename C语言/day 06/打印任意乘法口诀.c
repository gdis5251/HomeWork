#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ����������ʵ�ִ�ӡ����n*n�ĳ˷��ھ�
* ���ķ�
* 2018/10/14
*/

cheng_fa(int n)
{
	int i = 0;
	int j = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d   ", i, j, i*j);
		}
		printf("\n");
	}
}

int main()
{
	//������������׼���뽫Ҫ��ӡ�ĳ˷��ھ���ʽ
	int n = 0;
	scanf("%d", &n);

	cheng_fa(n);

	system("pause");

	return 0;
}