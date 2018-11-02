#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 输入一个整数数组，实现一个函数，
  来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
  所有偶数位于数组的后半部分。
* 郭文峰
* 2018/10/29
*/
void adjust_arr(int *arr, int sz)
{
	int i = 0;
	int j = 0;
	int b[10] = { 0 };

	//先将所有的奇数拿出来放到b数组里
	for (i = 0; i < sz; i++)
	{
		if (*arr % 2 != 0)
		{
			b[j] = *arr;
			j++;
		}
		arr++;

	}

	//将arr移到首地址处
	arr = arr - 10;
	//再将所有的偶数放入b数组
	for (i = 0; i < sz; i++)
	{
		if (*arr % 2 == 0)
		{
			b[j] = *arr;
			j++;
		}
		arr++;

	}

	//将arr移到首地址处
	arr = arr - 10;
	//将b赋给arr
	for (i = 0; i < sz; i++)
	{
		*arr = b[i];
		arr++;
	}


}

int main(void)
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	
	//改变前先输出作比对
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	adjust_arr(arr, sz);

	//打印改变后的数组
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}