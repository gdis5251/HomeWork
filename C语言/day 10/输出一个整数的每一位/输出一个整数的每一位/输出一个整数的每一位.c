#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 输出一个整数的每一位
* 郭文峰
* 2018/10/22
*/



void PrintBinData(int data_)
{
	unsigned int flag_ = 0x80000000;

	while (flag_)
	{
		if (flag_ & data_)
			printf("1");
		else
			printf("0");
		flag_ >>= 1;
	}
	printf("\n");
}
int main(void)
{
	int data = 0;
	printf("Please enter data: ");
	scanf("%d", &data);

	PrintBinData(data);

	system("pause");
	return 0;
}