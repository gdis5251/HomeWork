#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* 模拟实现strchr函数
* 郭文峰
* 2018/11/8
*/

//库函数strchr编程方式
char *K_strchr(char *str, char val)
{
	while (*str != '\0' && *str != val)
	{
		str++;
	}
	return *str == val ? str : NULL;
}

char *my_strchr(char *str, char val)
{
	assert(str);// 判定str不是空指针

	while (*str++)
	{
		if (val == *(str - 1))//如果找到字符第一次出现的位置，则返回它的地址
			return str - 1;
	}

	return NULL;
}

int main(void)
{
	char *str = "It's my life! My decision it!";
	char *p = NULL;

	p = my_strchr(str, 'm');

	if (p != NULL)
	{
		printf("%p\n", p);
		printf("%s\n", str);
		while (*str)
		{
			printf("%p\n", str);
			str++;
		}
	}
	else
		printf("Not Found!");

	system("pause");
	return 0;
}