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

	printf("\n");
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

//时间复杂度
//最好：O(N) (已经有序)
//平均：O(N^2)
//最坏：O(N^2)  (已经有序是逆序)

//空间复杂度
//O(1)
void InsertSort2(int *array, int size)
{
	//外面的循环实现减治过程
	//一次取一个数，插入到前面的有序区间内
	for (int i = 1; i < size; i++)
	{
		int k = array[i];
		
		//内部循环实现插入过程
		//从[0,i)
		//如果array[j] > k ,往后搬
		//如果array[j] <= k ,跳出循环（保证稳定性）
		int j = 0;
		for (j = i - 1; j >= 0 && array[j] > k; j--)
		{
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
		
		for (j = i - 1; j >= 0 && array[j] < k; j--)
		{
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
		for (j = i - gap; j >= 0 && array[j] > k; j -= gap)
		{
			array[j + gap] = array[j];
		}

		array[j + gap] = k;
	}
}




//希尔排序
//时间复杂度
//最好 O(N)
//平均 O(N^1.2) - O(N^1.3)
//最差 O(N^2)

//空间复杂度
//O(1)

//不稳定，分组很难保证相同的数分到一个组里
void ShellSort(int *array, int size)
{
	int gap = size;

	while (1)
	{
		gap = gap / 3 + 1; //工程做法，没有具体理论
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
//时间复杂度
//最好 平均 最坏 都是 O(N^2)

//空间复杂度
//O(1)

//不稳定
void SelectSort(int *array, int size)
{
	//每次找到一个最大的数字放到最后
	for (int i = 0; i < size - 1; i++)
	{
		int max = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (array[j] > array[max])
				max = j;
		}

		Swap(&array[max], &array[size - i - 1]);
	}
}




//堆排序
//向下调整
//时间复杂度
//O(logN)
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
//时间复杂度
//O(N) or O(N*LogN)
void CreateHeap(int *array, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
		AdjustDown(array, i, size);
}




//堆排序
//时间复杂度
//O(N*LogN)

//空间复杂度
//O(1)

//不稳定
void HeapSort(int *array, int size)
{
	CreateHeap(array, size);

	for (int i = 0; i < size - 1; i++)
	{
		Swap(array + 0, array + size - 1 - i);

		AdjustDown(array, 0, size - 1 - i);
	}
}


void AdjustDown2(int *array, int size, int root)
{
	//检查此时是否是叶子结点
	if (root * 2 + 1 >= size)
		return;

	int left = root * 2 + 1;
	int right = root * 2 + 2;
	int max = left;
	//先判断是否有右结点，并找到最大的孩子
	if (right < size && array[right] > array[left])
		max = right;

	//在判断此时结点是否大于最大的叶子结点
	if (array[root] >= array[max])
		return;

	Swap(&array[root], &array[max]);

	AdjustDown2(array, size, max);
}

//建堆
void CreateHeap2(int *array, int size)
{
	//从最后的一个非叶子结点开始
	//向下调整
	//直到跟结点向下调整完
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown2(array, size, i);
	}
}

//堆排序
void HeapSort2(int *array, int size)
{
	CreateHeap2(array, size);
	//每次将第一个元素放到最后面
	//然后进行减治
	for (int i = 0; i < size - 1; i++)
	{
		Swap(&array[0], &array[size - i - 1]);
		
		//这里的size参数，因为已经交换了，所以总大小size 要减1
		AdjustDown2(array, size - i - 1, 0);
	}
}




//冒泡排序
void BubbleSort(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
				Swap(&array[j], &array[j + 1]);
		}
	}
}




//1.在要排序的区间内选择一个基数
//2.遍历整的区间做数据交换，比基数小的数放到基数左侧，比基数大的数，放到基数右边
//3.分治算法(把一个问题变成两个小问题)
//终止条件
//1.分出来的size==0
//2.分出来的小区间已经有序 （区间的size == 1）


//时间复杂度
//最好 | 平均 O(N * logN)

//空间复杂度
//二叉树的深度
int Parition(int *array, int left, int right)
{
	int div = left;
	int i = left;
	int j = right;

	while (i < j)
	{
		while (array[j] >= array[div] && i < j)
			j--;

		while (array[i] <= array[div] && i < j)
			i++;

		if (i < j)
			Swap(&array[i], &array[j]);
	}

	//if (i == j)
		Swap(&array[i], &array[div]);
	
	return i;
}
void _QuickSort(int *array, int left, int right)
{
	//终止条件
	if (left >= right)
		return;

	int div;
	div = Parition(array, left, right);

	_QuickSort(array, left, div - 1);
	_QuickSort(array, div + 1, right);
}

void QuickSort(int *array, int size)
{
	_QuickSort(array, 0, size - 1);
}