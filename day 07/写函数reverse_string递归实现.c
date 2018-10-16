#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 编写一个函数reverse_string(char * string)（递归实现） 
  实现：将参数字符串中的字符反向排列。 
  要求：不能使用C函数库中 
  的字符串操作函数。
* 郭文峰
* 2018/10/15
*/


void reverse_string(char *string)
{

	/*if (*string == '\0')
	{
		printf("%c ", *string);


	}
	else
	{
		reverse_string(string + 1);
		printf("%c ", *(--string));
	}*/
	
	if (*string++)
	{
		reverse_string(string);
		printf("%c", *(--string));
	}
}

int main(void)
{
	char string[] = "abcde";

	reverse_string(string);

	system("pause");
	return 0;
}