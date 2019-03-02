#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//打印数组
void PrintArray(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", array[i]);
	}
}


//直接插入排序
//方法一：用memmove来移动，比较麻烦
void InsertSort1(int *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int k = array[i];	//用k来记录此时array[i]的值，以便在后面移动

		int j = 0;
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] <= array[i])
			{
				memmove(array + j + 2, array + j + 1, (i - j - 1) * sizeof(int));
				array[j + 1] = k;
				break;
			}
		}

		//如果j = -1 说明此时的array[i]比前面的任何一个数都小
		if (j == -1)
		{
			memmove(array + j + 2, array + j + 1, (i - j - 1) * sizeof(int));
			array[j + 1] = k;
		}
	}
}
//方法二：
void InsertSort2(int *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int k = array[i];
		int j = 0;
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] <= k)
				break;
			else
				array[j + 1] = array[j];
		}

		array[j + 1] = k;
	}
}