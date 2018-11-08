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

	int flag = 0;
	char *p = NULL;
	int i = 0; 

	//循环试图判断str2是否是str1的子串
	while (*str2)
	{
		//如果str2已经有元素跟str1相同但是后面的元素却不同返回0
		if (flag == 1 && *str1 != *str2)
		{
			return NULL;
		}

		//如果str2开始有元素与str1相同，先让p存下当前地址
		if (*str1 == *str2)
		{
			flag = 1;
			i++;
			if (i == 1)
			{
				p = str1;
			}
			str1++;
			str2++;
		}
		else
			str1++;
		
		//str2比较完，如果全部相同则返回第一个相同元素的地址
		if (flag == 1 && *str2 == NUL)
		{
			return p;
		}
				
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