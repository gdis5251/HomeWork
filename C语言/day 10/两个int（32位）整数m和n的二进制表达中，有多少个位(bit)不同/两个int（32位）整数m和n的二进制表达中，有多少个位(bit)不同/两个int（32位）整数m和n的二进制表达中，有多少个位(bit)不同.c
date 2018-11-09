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

int DiffBit (unsigned int x_, unsigned int y_)
{
	int i_ = x_ ^ y_;
	int count_ = 0;
	unsigned int flag_ = 1;
	while (flag_)
	{
		if (flag_ & i_)
			count_++;
		flag_ <<= 1;
	}
	return count_;
}

int main(void)
{
	unsigned int d_ = 0;
	unsigned int d1_ = 0;
	unsigned int d2_ = 0;
	
	scanf("%d%d", &d1_, &d2_);

	

	d_ = DiffBit(d1_, d2_);

	printf("%d \n", d_);

	system("pause");
	return 0;


}