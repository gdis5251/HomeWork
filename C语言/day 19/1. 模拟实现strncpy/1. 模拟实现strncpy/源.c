#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <assert.h>



/*
* 本程序模拟实现一个库函数strncpy
* 郭文峰
* 2018/11/21
*/
typedef unsigned int size_t;

void *MyStrncpy(char *dest, const char *src, size_t count)
{
	assert(dest && src);

	char *cp = dest;

	while (count)
	{
		*dest++ = *src++;

		count--;
	}

	return cp;
}


int main(void)
{
	char dest[26] = "Hello,HuYue!";
	char *src = "My little baby...";

	//strncpy(dest, src, strlen(src) + 1);
	//printf("%s\n", dest);

	MyStrncpy(dest, src, strlen(src) + 1);
	printf("%s\n", dest);


	system("pause");
	return 0;
}