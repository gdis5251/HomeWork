#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

/*
* 一个数组中只有两个数字是出现一次，
  其他所有数字都出现了两次。
  找出这两个数字，编程实现。
* 郭文峰
* 2018/11/5
*/
typedef unsigned int size_t;

void FindDiffer(int *p, int size)
{
	int i_ = 0;
	int flag_ = 1;
	int x = 0;

	//先让所有数字抑或
	//最后得到的一个数字就是两个只出现一次的数字的抑或
	for (; i_ < size; i_++)
	{
		x ^= p[i_];
	}

	//找出两个数字第一个不同的比特位
	while (!(x & flag_))
	{
		flag_ <<= 1;
	}
	

	//根据找出的比特位，将这个数组划分成两个组
	//那两个不一样的数字一定不在同一组
	int sin1 = 0;
	int sin2 = 0;
	for (i_ = 0; i_ < size; i_++)
	{
		if (0 == (p[i_] & flag_))
			sin1 ^= p[i_];
		else if (0 != (p[i_] & flag_))
			sin2 ^= p[i_];
	}

	printf("%d : %d\n", sin1, sin2);

}




int main(void)
{
	int arr[] = { 1, 2, 2, 4, 5, 6, 6, 4 };
	size_t size = sizeof(arr)/sizeof(arr[0]);

	FindDiffer(arr, size);

	

	system("pause");
	return 0;
}