#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ����һ���������飬ʵ��һ��������
  �����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
  ����ż��λ������ĺ�벿�֡�
* ���ķ�
* 2018/10/29
*/
void adjust_arr(int *arr, int sz)
{
	int i = 0;
	int j = 0;
	int b[10] = { 0 };

	//�Ƚ����е������ó����ŵ�b������
	for (i = 0; i < sz; i++)
	{
		if (*arr % 2 != 0)
		{
			b[j] = *arr;
			j++;
		}
		arr++;

	}

	//��arr�Ƶ��׵�ַ��
	arr = arr - 10;
	//�ٽ����е�ż������b����
	for (i = 0; i < sz; i++)
	{
		if (*arr % 2 == 0)
		{
			b[j] = *arr;
			j++;
		}
		arr++;

	}

	//��arr�Ƶ��׵�ַ��
	arr = arr - 10;
	//��b����arr
	for (i = 0; i < sz; i++)
	{
		*arr = b[i];
		arr++;
	}


}

int main(void)
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	
	//�ı�ǰ��������ȶ�
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	adjust_arr(arr, sz);

	//��ӡ�ı�������
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}