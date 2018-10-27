#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 写一个函数返回参数二进制中 1 的个数 
  比如： 15 0000 1111 4 个 1 
  程序原型： 
  int count_one_bits(unsigned int value) 
  { 
  // 返回 1的位数 
  }
* 郭文峰
* 2018/10/22
*/
int count = 0;

void  count_one_bits(unsigned int d)
{
	int i = 0;

	for (i = 0; i < 32; i++)
	{
		if ((d & 1) == 1)
		{
			count++;
		}
		d = d >> 1;
	}
}

int main(void)
{
	int d = 0;
	
	scanf("%d", &d);

	//如果输入的数字为负数，则先加上符号为的1
	

	count_one_bits(d);

	printf("%d \n", count);

	system("pause");
	return 0;
		
		

}