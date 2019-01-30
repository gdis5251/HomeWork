#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
向下调整 大堆
每次只调整一个结点
array是堆的顺序表结构
size是堆的大小
root是传进来要调整的结点
*/
void AdjustDown(int array[], int size, int root)
{

	while (1)
	{
		//判断root是否是叶子节点
		int left = root * 2 + 1;
		if (left >= size)
		{
			return;
		}

		//如果存在左子树，那么判断是否有右子树
		int right = root * 2 + 2;
		int min = left;				//先默认最小的是左子树
		if (right < size && array[left] < array[right])//如果存在右子树且右子树比左子树小，那么修改默认
			min = right;

		if (array[root] >= array[min])
			return;

		//走到这里说明root的值比孩子结点的最小值还小
		//交换
		int t = array[root];
		array[root] = array[min];
		array[min] = t;

		root = min;//继续向下调整
	}

}




//创建堆
void CreateHeap(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}




//打印堆
void PrintHeap(int array[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}




//测试堆的创建
void TestCreateHeap()
{
	int array[] = { 24, 45, 78, 6, 4, 52, 31, 19 };
	int size = sizeof(array) / sizeof(int);
	
	CreateHeap(array, size);
	PrintHeap(array, size);
}




//向上调整 大堆
//停下来的条件
//1. 结点已经是根节点
//2. 结点比双亲结点小
void AdjustUp(int array[], int size, int child)
{
	while (child != 0)
	{
		int par = (child - 1) / 2;
		if (array[par] >= array[child])
			return;

		int t = array[par];
		array[par] = array[child];
		array[child] = t;

		child = par;
	}
}





//堆排序
//建大堆 排升序
void HeapSort(int array[], int size)
{
	CreateHeap(array, size);

	//每次把堆顶和最后一个结点交换，然后在向下调整
	for (int i = 0; i < size - 1; i++)
	{
		int t = array[0];
		array[0] = array[size - i - 1];
		array[size - i - 1] = t;

		AdjustDown(array, size - i - 1, 0);
	}
}


//测试堆排序
void TestHeapSort()
{
	int array[] = { 24, 51, 94, 61, 6, 78, 96, 55, 66, 21 };
	int size = sizeof(array) / sizeof(int);

	HeapSort(array, size);
	PrintHeap(array, size);
}