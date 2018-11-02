#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ����һ�����飬
  ʵ�ֺ���init()��ʼ�����顢
  ʵ��empty()������顢
  ʵ��reverse()�����������Ԫ�ص����á�
  Ҫ���Լ���ƺ����Ĳ���������ֵ��
* ���ķ�
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

	//ʵ�ֺ���init()��ʼ������
	init(arr, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	//ʵ��reverse()�����������Ԫ�ص����á�
	reverse(arr, 10);
	
	for (i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	//ʵ��empty()�������
	empty(arr, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");



	system("pause");
	return 0;
}