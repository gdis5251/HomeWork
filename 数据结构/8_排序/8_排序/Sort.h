#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ӡ����
void PrintArray(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", array[i]);
	}
}




//ֱ�Ӳ�������
//����һ����memmove���ƶ����Ƚ��鷳
void InsertSort1(int *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int k = array[i];	//��k����¼��ʱarray[i]��ֵ���Ա��ں����ƶ�

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

		//���j = -1 ˵����ʱ��array[i]��ǰ����κ�һ������С
		if (j == -1)
		{
			memmove(array + j + 2, array + j + 1, (i - j - 1) * sizeof(int));
			array[j + 1] = k;
		}
	}
}




//��������
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




//ֱ�Ӳ��������Ž���
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




//��Gap�����Ĳ�������
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




//ϣ������
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




//�����ӿ�
void Swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}




//ѡ������
void SelectSort(int *array, int size)
{
	//ÿ���ҵ�һ���������ַŵ����
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




//������
//���µ���
void AdjustDown(int *array, int root, int size)
{
	//�ȼ��root����Ƿ���Ҷ�ӽ��
	if (root * 2 + 1 >= size)
		return;

	//���ҳ�root���ĺ��ӽ�㣬���root������һ�����Ӵ�ֹͣ
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




//����
void CreateHeap(int *array, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
		AdjustDown(array, i, size);
}




//������
void HeapSort(int *array, int size)
{
	CreateHeap(array, size);

	for (int i = 0; i < size - 1; i++)
	{
		Swap(array + 0, array + size - 1 - i);

		AdjustDown(array, 0, size - 1 - i);
	}
}