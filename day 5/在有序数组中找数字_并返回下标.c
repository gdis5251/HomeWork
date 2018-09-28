#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* ��������������һ�����������У��ҵ�һ�����֣����������±�
* ���ķ�
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

	//���û�ҵ���ôleft�ض�����right
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
	int len = sizeof(arr) / sizeof(arr[0]); //������ĳ��ȸ�ֵ��len
	int judge = 0;
	int key = 0;

	printf("�����뽫Ҫ���ҵ����֣�");
	scanf("%d", &key);

	right = len - 1;
	judge = search(arr, left, right, key);

	//���ݺ����ķ���ֵ�ж��Ƿ��ҵ���Ҫ�ҵ�����
	if (judge > 0)
	{
		printf("�ҵ��ˣ������ֵ��±�Ϊ%d\n", judge);
	}
	else if (-1 == judge)
	{
		printf("û�ҵ���\n");
	}

	system("pause");
	return 0;
}