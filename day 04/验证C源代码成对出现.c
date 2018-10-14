#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 本程序用于从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。 
* 郭文峰
* 2018/9/25 
*/

int main()
{
	char ch[10000] = { 0 };
	int i = 0;
	int left = 0;
	int right = 0;

	scanf("%s", ch);//用标准输入读取一个C的源代码

	for (i = 0; i <= strlen(ch) - 1; i++)
	{
		if ('{' == ch[i])
			left++;
		if ('}' == ch[i])
			right++;
	}

	if (left == right)
		printf("花括号成对出现！\n");
	else
		printf("花括号不成对出现！\n");

	system("pause");
	return 0;
}