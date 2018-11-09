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

//按位与1，如果等于1，则count++
void  count_one_bits(unsigned int d)
{
	int i = 0;

	for (i = 0; i < 32; i++)
	{
		if ((d & 1) == 1)
		{
			count++;
		}
		//让数据右移
		//同时也可以让1左移
		d = d >> 1;
	}
}

//这样的算法可以每次循环可以清除一个最低位的1
//最后只要统计循环了多少次即可

void CountBits(unsigned int x_)
{
	while (x_)
	{
		x_ = x_ & (x_ - 1);
		count++;
	}
}

int main(void)
{
	unsigned int d = 0;
	
	scanf("%d", &d);

	//count_one_bits(d);
	CountBits(d);

	printf("%d \n", count);

	system("pause");
	return 0;
		
		

}