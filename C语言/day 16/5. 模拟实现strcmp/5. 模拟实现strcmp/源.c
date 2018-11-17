#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <string.h>

/*
* 模拟实现strcmp函数
* 郭文峰
* 2018/11/8
*/

int my_strcmp(const char *s1, const char *s2)
{
	assert(s1 && s2);

	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
        //find the differ str or they are same
	if (*s1 == *s2)
	{
		return 0;
	}
	else if (*s1 > *s2)
	{
		return 1;
	}
	else
	{
		return -1;
	}

	
}

int main(void)
{
	char *str1 = "Gerald is cool guy!";
	char *str2 = "Gerald is cool guy!";
	char *str3 = "Gerald is cool guy! HAHAHA!";
	char *str4 = "Gerald";

		//str1与str2比较
	if ((my_strcmp(str1, str2)) == 0)
		printf("str1 == str2\n");
	else if ((my_strcmp(str1, str2)) > 0)
		printf("str1 > str2\n");
	else
		printf("str1 < str2\n");

	//str1与str3比较
	if ((my_strcmp(str1, str3)) == 0)
		printf("str1 == str3\n");
	else if ((my_strcmp(str1, str3)) > 0)
		printf("str1 > str3\n");
	else
		printf("str1 < str3\n");

	//str1与str4比较
	if ((my_strcmp(str1, str4)) == 0)
		printf("str1 == str4\n");
	else if ((my_strcmp(str1, str4)) > 0)
		printf("str1 > str4\n");
	else
		printf("str1 < str4\n");

	system("pause");
	return 0;
}
