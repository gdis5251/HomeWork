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



void print(unsigned int data_)
{
	unsigned int flag_ = 0x80000000; //10000000000000000000000000000000
	//因为是从左往右打印，所以这样初始化
	printf("偶数Bits： ");
	while (flag_)
	{
		if (data_ & flag_)
		{
			printf("1 ");
		}
		else
			printf("0 ");
		flag_ >>= 2;
	}
	printf("\n");

	printf("奇数Bits： ");
	flag_ = 0x40000000;//01000000000000000000000000000000

	while (flag_)
	{
		if (data_ & flag_)
		{
			printf("1 ");
		}
		else
			printf("0 ");

		flag_ >>= 2;
	}
	printf("\n");

}

int main(void)
{
	unsigned int data = 0;
	printf("Please enter data:");
	scanf("%d", &data);

	print(data);

	system("pause");
	return 0;

}