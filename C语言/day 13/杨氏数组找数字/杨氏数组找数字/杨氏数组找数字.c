#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0
#define N 3

/*
* //杨氏矩阵 
  有一个二维数组. 
  数组的每行从左到右是递增的，每列从上到下是递增的. 
  在这样的数组中查找一个数字是否存在。 
  时间复杂度小于O(N); 

  数组： 
  1 2 3 
  2 3 4 
  3 4 5 


  1 3 4 
  2 4 5 
  4 5 6 

  1 2 3 
  4 5 6 
  7 8 9
* 郭文峰
* 2018/10/29
*/

int yang_search(int yang_arr[][N], int n, int key, int* p1, int* p2)
{
	int row = 0;
	int col = n - 1;


	//判断key是否在数组内
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
		printf("找到了%d的位置是（%d，%d）\n", key, i, j);
	}
	else
	{
		printf("没找到！\n");
	}

	system("pause");
	return 0;
}
