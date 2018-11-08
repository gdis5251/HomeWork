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
	unsigned int count1 = 0;
	unsigned int count2 = 0;

	do
	{
		count1 = *s1;
		count2 = *s2;

		//如果s1结束，有两种情况
		//1 两个字符串相等，那么将会返回0
		//2 s1小于s2，那么上面的赋值，count1将会得到一个0,而count2将会得到一个正值
		//所以将会返回负数
		if (*s1 == '\0')
			return count1 - count2;

		s1++;
		s2++;
	} while (count1 == count2);

	//这里也是只存在两种情况
	//1 count1小于count2
	//2 count1大于count2
	return count1 - count2;
	
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