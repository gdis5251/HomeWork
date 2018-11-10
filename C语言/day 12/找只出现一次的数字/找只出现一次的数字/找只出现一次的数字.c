#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 编程实现： 
  一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
  请找出这个数字。（使用位运算）
* 郭文峰
* 2018/10/28
*/

int main(void)
{
	int arr[100] = { 0 };
	int n = 0;
	int i = 0;

	scanf("%d", &n);

	//输入一串数字，并且一串数字只有一个数字是单数，其他都是成对出现
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
       //n ^ 0 = n 
	//n ^ n = 0
	//用位操作符让每个数字进行抑或，单数数字会保持自己原有的值
	for (i = 0; i < n - 1; i++)
	{
		arr[i+1] = arr[i] ^ arr[i + 1];
	}

	printf("%d", arr[n - 1]);

	system("pause");
	return 0;
}
