#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
���µ��� ���
ÿ��ֻ����һ�����
array�Ƕѵ�˳���ṹ
size�ǶѵĴ�С
root�Ǵ�����Ҫ�����Ľ��
*/
void AdjustDown(int array[], int size, int root)
{

	while (1)
	{
		//�ж�root�Ƿ���Ҷ�ӽڵ�
		int left = root * 2 + 1;
		if (left >= size)
		{
			return;
		}

		//�����������������ô�ж��Ƿ���������
		int right = root * 2 + 2;
		int min = left;				//��Ĭ����С����������
		if (right < size && array[left] < array[right])//�����������������������������С����ô�޸�Ĭ��
			min = right;

		if (array[root] >= array[min])
			return;

		//�ߵ�����˵��root��ֵ�Ⱥ��ӽ�����Сֵ��С
		//����
		int t = array[root];
		array[root] = array[min];
		array[min] = t;

		root = min;//�������µ���
	}

}




//������
void CreateHeap(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}




//��ӡ��
void PrintHeap(int array[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}




//���ԶѵĴ���
void TestCreateHeap()
{
	int array[] = { 24, 45, 78, 6, 4, 52, 31, 19 };
	int size = sizeof(array) / sizeof(int);
	
	CreateHeap(array, size);
	PrintHeap(array, size);
}




//���ϵ��� ���
//ͣ����������
//1. ����Ѿ��Ǹ��ڵ�
//2. ����˫�׽��С
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





//������
//����� ������
void HeapSort(int array[], int size)
{
	CreateHeap(array, size);

	//ÿ�ΰѶѶ������һ����㽻����Ȼ�������µ���
	for (int i = 0; i < size - 1; i++)
	{
		int t = array[0];
		array[0] = array[size - i - 1];
		array[size - i - 1] = t;

		AdjustDown(array, size - i - 1, 0);
	}
}


//���Զ�����
void TestHeapSort()
{
	int array[] = { 24, 51, 94, 61, 6, 78, 96, 55, 66, 21 };
	int size = sizeof(array) / sizeof(int);

	HeapSort(array, size);
	PrintHeap(array, size);
}