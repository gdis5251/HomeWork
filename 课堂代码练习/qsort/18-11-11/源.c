#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

/*
* ����qsort�������ص�����
* ���ķ�
* 2018/11/11
*/

int char_cmp(const void* x, const void* y)
{
	assert(x && y);

	//��Ϊ�����������ַ����ĵ�ַ������Ҫǿ������ת����(char **)
	//Ȼ���ٽ�����һ�²����ַ����ĵ�ַ
	return strcmp(*(char**)x, *(char**)y);
	
}

void swap(void* x, void* y, int size)
{

	int i = 0;

	for (i = 0; i < size; i++)
	{
		*((char*)x + i) ^= *((char*)y + i);
		*((char*)y + i) ^= *((char*)x + i);
		*((char*)x + i) ^= *((char*)y + i);
	}
}

//��ð������ģ��ʵ��Qsort����
void MyQsort(void* base, int count, \
	int size, int(*compare)(const void*, const void*))
{
	int i = 0;
	int j = 0;

	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (compare((char*)base + j*size, (char*)base + (j + 1)*size) > 0)
			{
				swap((char*)base + j*size, (char*)base + (j + 1)*size, size);
			}
		}
	}
}

int main(void)
{
	char *arr[] = {"dddd", "bbbb", "cccc", "aaaa", "eeee"};
	int i = 0;

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	//���ÿ⺯��������
	//��Ϊ�ַ����������汣��Ķ���ָ��
	//����size�ڴ��ε�ʱ��Ҫ��ָ��Ĵ�С
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char* ), char_cmp);

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	MyQsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char*), char_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}