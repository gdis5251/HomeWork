#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 编写一个函数实现n^k,使用递归实现
* 郭文峰
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


	//输入数字n以及它的k次方
	scanf("%d%d", &n, &k);


	printf("result = %d\n", ping_fang(n, k));

	system("pause");
	return 0;
}