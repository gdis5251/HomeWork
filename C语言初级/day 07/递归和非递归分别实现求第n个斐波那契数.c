#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
* ���ķ�
* 2018/10/14
*/

int fib_d(int n)
{
	
	//if��������n=1��2�����
	if (n <= 2 && n > 0)
	{
		return 1;

	}
	//�ݹ����n>2�����
	if (n > 2)
	{
		return fib_d(n - 1) + fib_d(n - 2);
	}

	return 0;
	
	
}

int fib_f(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;

	if (n <= 2 && n > 0)
	{
		return 1;
	}
	
	while (n > 2)
	{
		n--;
		c = a + b;
		a = b;
		b = c;
	}
	
	return c;
}



int main(void)
{
	int a = 0;
	int b = 0;
	int n = 0;

	scanf("%d", &n);

	//�ֱ���õݹ�ͷǵݹ�ĺ������n��쳲�������
	a = fib_d(n);
	b = fib_f(n);
	printf("�ݹ�:>%d, �ǵݹ�:>%d \n", a, b);

	system("pause");
	return 0;
}