#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* ��ȡһ�������������������е�ż��λ������λ�� 
  �ֱ�������������С� 
* ���ķ�
* 2018/10/22 
*/



void print(unsigned int data_)
{
	unsigned int flag_ = 0x80000000; //10000000000000000000000000000000
	//��Ϊ�Ǵ������Ҵ�ӡ������������ʼ��
	printf("ż��Bits�� ");
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

	printf("����Bits�� ");
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