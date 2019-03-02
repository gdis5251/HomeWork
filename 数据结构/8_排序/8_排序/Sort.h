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




//直接插入排序，排降序
void InsertSortDown(int *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = 0;
		int k = array[i];
		
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] > k)
				break;
			else
				array[j + 1] = array[j];
		}

		array[j + 1] = k;
	}
}




//带Gap参数的插入排序
void InsertSortWithGap(int *array, int size, int gap)
{
	for (int i = gap; i < size; i++)
	{
		int k = array[i];
		int j = 0;
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (array[j] < k)
				break;
			else
				array[j + gap] = array[j];
		}

		array[j + gap] = k;
	}
}




//希尔排序
void ShellSort(int *array, int size)
{
	int gap = size;

	while (1)
	{
		gap = gap / 3 + 1;
		InsertSortWithGap(array, size, gap);

		if (gap == 1)
			break;
	}
}




//交换接口
void Swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}




//选择排序
void SelectSort(int *array, int size)
{
	//每次找到一个最大的数字放到最后
	for (int i = 0; i < size; i++)
	{
		int max = 0;
		for (int j = 0; j < size - i; j++)
		{
			if (array[j] > array[max])
				max = j;
		}

		Swap(&array[max], &array[size - i - 1]);
	}
}




//堆排序
//向下调整
void AdjustDown(int *array, int root, int size)
{
	//先检查root结点是否是叶子结点
	if (root * 2 + 1 >= size)
		return;

	//在找出root最大的孩子结点，如果root比任意一个孩子大，停止
	int left = root * 2 + 1;
	int max = left;
	int right = root * 2 + 2;
	if (right < size && array[right] > array[left])
		max = right;

	if (array[root] >= array[max])
		return;

	Swap(array + max, array + root);

	AdjustDown(array, max, size);

}




//建堆
void CreateHeap(int *array, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
		AdjustDown(array, i, size);
}




//堆排序
void HeapSort(int *array, int size)
{
	CreateHeap(array, size);

	for (int i = 0; i < size - 1; i++)
	{
		Swap(array + 0, array + size - 1 - i);

		AdjustDown(array, 0, size - 1 - i);
	}
}