#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 实现一个函数，可以左旋字符串中的k个字符。
  ABCD左旋一个字符得到BCDA
  ABCD左旋两个字符得到CDAB
* 郭文峰
* 2018/11/2
*/
void left_handed(char* p, int n, int size)
{
	int i = 0;

	//例如n==1，将第一个字符移到最后一个
	//ABCDA
	for (i = 0; i < n; i++)
	{
		*(p + size + i) = *(p + i);
	}

	//再将所有元素向前移n个位置，覆盖被移的位置的元素
	//BCDA
	for (i = 0; i <= size; i++)
	{
		*(p + i) = *(p + n + i);
	}
}

int main(void)
{
	int n = 0;
	int size = 0;
	char arr[8] = "ABCD";

	scanf("%d", &n);

	size = strlen(arr);

	left_handed(arr, n, size);
	//printf("%d\n", size);
	printf("%s\n", arr);
	
	system("pause");
	return 0;

}