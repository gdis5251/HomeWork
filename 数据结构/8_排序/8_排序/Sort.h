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