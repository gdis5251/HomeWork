#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��дһ������ʵ��n^k,ʹ�õݹ�ʵ��
* ���ķ�
* 2018/10/15
*/

int ping_fang(int x, int y)
{
	if (y == 0)
	{
		return 0;
	}
	else if (y == 1)
	{
		return x;
	}
	else
	{
		return x * ping_fang(x, y - 1);
	}
}

int main(void)
{
	int n = 0;
	int k = 0;


	//��������n�Լ�����k�η�
	scanf("%d%d", &n, &k);


	printf("result = %d\n", ping_fang(n, k));

	system("pause");
	return 0;
}