#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* 获取一个数二进制序列中所有的偶数位和奇数位， 
  分别输出二进制序列。 
* 郭文峰
* 2018/10/22 
*/

int ji[16] = { 0 };
int ou[16] = { 0 };

void one_to_two(int d)
{
	int i = 0;
	int j = 0;
	//这一步很关键！如果没有这一步，第一个循环会改变d的值
	//到第二个循环的时候d的值就已经不是原来的值了
	int d1 = d;

	for (i = 0; i < 16; i++)
	{
		ou[15 - i] = d & 1;
		d >>= 2;
	}

	for (i = 0; i < 16; i++)
	{
		ji[15 - i] = (d1 & 2) / 2;
		d1 >>= 2;
	}
}

int main(void)
{
	int i = 0;
	int d = 0;

	scanf("%d", &d);

	one_to_two(d);

	printf("奇数二进制序列为：");
	for (i = 0; i < 16; i++)
	{
		printf("%d  ", ji[i]);
	}
	printf("\n");

	printf("偶数二进制序列为：");
	for (i = 0; i < 16; i++)
	{
		printf("%d  ", ou[i]);
	}
	printf("\n");

	system("pause");
	return 0;

}