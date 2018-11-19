#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#define NUL '\0'

/*
* strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。
  如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
* 郭文峰
* 2018/11/7
*/

char *my_strstr(const char *str1, const char *str2)
{
	assert(str1 && str2);

	char* cp = (char*)str1;
	char* s1 = (char*)str1;
	char* s2 = (char*)str2;

	while (*cp)
	{
		//每次循环开始前，先让s1 s2归位
		s1 = cp;
		s2 = (char*)str2;

		while (*s1 == *s2 && *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == NUL)
		{
			return cp;
		}
		
		//让str1字符串向后走一位，继续查找
		cp++;
	}

	return NULL;



	
}

int main(void)
{
	//char str1[20] = { "ABCDEFGH" };
	//char str2[10] = { "CDE" };
	char *str1 = "ABCDE";
	char *str2 = "BC";
	char *p = my_strstr(str1, str2);


	if (p != NULL)
	{
		printf("%p\n", p);
		printf("%s\n", p);
	}
	else
	{
		printf("str2不是str1的子串\n");
	}

	system("pause");
	return 0;
}