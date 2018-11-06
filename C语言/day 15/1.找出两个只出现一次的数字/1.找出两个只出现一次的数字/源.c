#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>

/*
* 一个数组中只有两个数字是出现一次，
  其他所有数字都出现了两次。
  找出这两个数字，编程实现。
* 郭文峰
* 2018/11/5
*/

int main(void)
{
	int stack[100] = { 0 };
	int n = 0;
	int top = 0;
	int i = 0;

	//确定有多少个数字
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &stack[top]);
		if (stack[top] == stack[top - 1])
		{
			//将两个相同的数字置零
			stack[top] = 0;
			stack[top - 1] = 0;

			top -= 2;
		}
		top++;
	}
	top--;
	
	////遍历一遍栈找出不等于0的数字打印
	//for (i = 0; i < n; i++)
	//{
	//	if (stack[i] != 0)
	//		printf("%d  ", stack[i]);
	//}

	//只有两个数字是单独的，只需要打印两个数字即可
	//这样减少了时间复杂度
	printf("%d ", stack[top]);
	printf("%d ", stack[top - 1]);

	printf("\n");

	system("pause");
	return 0;
}