#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 编程实现： 
  两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
  输入例子: 
  1999 2299 
  输出例子:7	
* 郭文峰
* 2018/10/22
*/



//00000000000000000000000000001111
//00000000000000000001110000001111
//00000000000000000001110000000000
//先让两个数抑或，然后在统计1的个数

int count = 0;

void count_one_bits(int d)
{
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((d & 1) == 1)
		{
			count++;
		}
		d >>= 1;

	}
}

int main(void)
{
	int d = 0;
	int d1 = 0;
	int d2 = 0;
	
	scanf("%d%d", &d1, &d2);

	d = d1 ^ d2;

	count_one_bits(d);

	printf("%d \n", count);

	system("pause");
	return 0;


}