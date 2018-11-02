#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* 1.编写函数： 
  unsigned int reverse_bit(unsigned int value); 
  这个函数的返回值value的二进制位模式从左到右翻转后的值。 

  如： 
  在32位机器上25这个值包含下列各位： 
  00000000000000000000000000011001 
  翻转后：（2550136832） 
  10011000000000000000000000000000 
  程序结果返回： 
  2550136832
* 郭文峰
* 2018/10/27
*/
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int j = 0;
	long long int d = 0;
	int change[32] = { 0 };

	//将value的二进制值，进行反序
	for (i = 0; i < 32; i++)
	{
		change[i] = value & 1;
		value >>= 1;
	}
	
	//将反序过来的数，算出相应的十进制数
	for (i = 0; i < 32; i++)
	{
		d += change[32 - i - 1] * (long long int)pow(2, i);
	}

	return d;
}

int main(void)
{
	unsigned int num = 0;
	long long int change_num = 0;
	//输入一个无符号整数
	scanf("%d", &num);

	//用链式访问直接打印
	printf("%u\n", reverse_bit(num));

	//用change_num接住函数返回的值，再打印
	change_num = reverse_bit(num);
	printf("%u\n", change_num);

	system("pause");
	return 0;
}