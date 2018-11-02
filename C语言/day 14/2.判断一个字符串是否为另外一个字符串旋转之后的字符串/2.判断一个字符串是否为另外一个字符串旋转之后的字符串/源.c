#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int is_left_handed(char* orig, const char* ch_orig, int size_o, int size_c)
{
	
	int i = 0;

	//如果两个字符串的长度都不相等，那么这两个字符串肯定不是由一个旋转后得到的
	if (size_o != size_c)
		return 0;

	//依次旋转原字符串，对比两个字符串是否相等
	for (i = 1; i < size_o; i++)
	{
		left_handed(orig, i, size_o);
		if (strcmp(orig, ch_orig) == 0)
			return 1;
	}

	return 0;
}



int main(void)
{
	int n = 0;
	int size_o = 0;
	int size_c = 0;
	int is_l = 0;
	char orig[8] = "ABCD";
	char ch_orig[8] = "BCDA";

	size_o = strlen(orig);
	size_c = strlen(ch_orig);

	is_l = is_left_handed(orig, ch_orig, size_o, size_c);

	if (is_l == 1)
	{
		printf("YES!\n");
	}
	else
	{
		printf("NO!\n");
	}

	system("pause");
	return 0;

}