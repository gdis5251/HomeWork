#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 创建一个数组，
  实现函数init()初始化数组、
  实现empty()清空数组、
  实现reverse()函数完成数组元素的逆置。
  要求：自己设计函数的参数，返回值。
* 郭文峰
* 2018/10/14
*/

void init(int arr[], int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void reverse(int arr[], int n)
{
	int arr1[10];
	int i = 0;

	for (i = 0; i < n; i++)
	{
		arr1[i] = arr[n - i - 1];
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = arr1[i];
	}

}

void empty(int arr[], int n)
{
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
}

int main(void)
{
	int arr[10];
	int i = 0;

	//实现函数init()初始化数组
	init(arr, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	//实现reverse()函数完成数组元素的逆置。
	reverse(arr, 10);
	
	for (i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	//实现empty()清空数组
	empty(arr, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");



	system("pause");
	return 0;
}