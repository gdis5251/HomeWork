#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* дһ�������ж�һ�����Ƿ�Ϊ����
* ���ķ�
* 2018/10/14
*/

int is_prime(int x)
{
	int n = sqrt(x);
	int i = 0;

	for (i = 2; i <= n; i++)
	{
		if (x % i == 0)
		{
			return -1;
		}
	}
	return 1;
	
}

int main(void)
{
	int num = 0;
	int a = 0;
	
	scanf("%d", &num);

	a = is_prime(num);

	if (1 == a)
	{
		printf("%dΪ������\n", num);

	}
	else
	{
		printf("%d����������\n", num);
	}

	system("pause");
	return 0;
}