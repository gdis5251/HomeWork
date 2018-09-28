#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 本程序是用来在一个有序数组中，找到一个数字，并返回其下标
* 郭文峰
* 2018/9/28
*/

int search(int arr[], int left, int right, int key)
{
	int mid = 0;
	
	while (left <= right)
	{
		mid = (right - left) / 2 + left;
		
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (mid > key)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	//如果没找到那么left必定大于right
	if (left > right)
	{
		return -1;
	}
}

int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = 0;
	int i = 0;
	int mid = 0;
	int len = sizeof(arr) / sizeof(arr[0]); //将数组的长度赋值给len
	int judge = 0;
	int key = 0;

	printf("请输入将要查找的数字：");
	scanf("%d", &key);

	right = len - 1;
	judge = search(arr, left, right, key);

	//根据函数的返回值判断是否找到需要找的数字
	if (judge > 0)
	{
		printf("找到了，该数字的下标为%d\n", judge);
	}
	else if (-1 == judge)
	{
		printf("没找到！\n");
	}

	system("pause");
	return 0;
}