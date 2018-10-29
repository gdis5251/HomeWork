#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0
#define N 3

/*
* //���Ͼ��� 
  ��һ����ά����. 
  �����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
  �������������в���һ�������Ƿ���ڡ� 
  ʱ�临�Ӷ�С��O(N); 

  ���飺 
  1 2 3 
  2 3 4 
  3 4 5 


  1 3 4 
  2 4 5 
  4 5 6 

  1 2 3 
  4 5 6 
  7 8 9
* ���ķ�
* 2018/10/29
*/

int yang_search(int yang_arr[][N], int n, int key, int* p1, int* p2)
{
	int row = 0;
	int col = n - 1;


	//�ж�key�Ƿ���������
	if (key < yang_arr[0][0] || key > yang_arr[n - 1][n - 1])
	{
		*p1 = row;
		*p2 = col;
		return FALSE;
	}

	while (row < n && col >= 0)
	{
		if (key == yang_arr[row][col])
		{
			*p1 = row;
			*p2 = col;
			return TURE;
		}
		else if (key < yang_arr[row][col])
		{
			col--;
		}
		else if (key > yang_arr[row][col])
		{
			row++;
		}
	}
	return FALSE;

}

int main(void)
{
	int yang_arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int key = 0;
	int i = -1;
	int j = -1;

	scanf("%d", &key);
	
	int b = yang_search(yang_arr, N, key, &i, &j);

	if (b)
	{
		printf("�ҵ���%d��λ���ǣ�%d��%d��\n", key, i, j);
	}
	else
	{
		printf("û�ҵ���\n");
	}

	system("pause");
	return 0;
}
