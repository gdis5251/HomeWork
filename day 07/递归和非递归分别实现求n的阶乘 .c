#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳� 
* ���ķ�
* 2018/10/15
*/

int jc_d(int n)
{
	if (n <= 1)
	{
		return 1;

	}
	else if (n >= 2)
	{
		return n * jc_d(n - 1);
	}
}

int jc_f(int n)
{
	int sum = 1;

	if (n == 0)
	{
		return 0;
	}

	while (n)
	{
		sum *= n;
		n--;
	}
	return sum;
}

int main(void)
{
	int n = 0;
	int a = 0;
	int b = 0;

	scanf("%d", &n);

	//�ݹ�
	a = jc_d(n);

	//�ǵݹ�
	b = jc_f(n);

	printf("%d   %d \n", a, b);

	system("pause");
	return 0;
}