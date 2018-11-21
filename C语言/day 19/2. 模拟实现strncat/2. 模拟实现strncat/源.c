#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

#define NUL '\0'

/*
* 本程序模拟实现库函数strncat
* 郭文峰
* 2018/11/21
*/
typedef unsigned int size_t;
void *MyStrncat(char *dest, const char *src, size_t count)
{
	assert(dest && src);

	char *cp = dest; //定义一个指针变量后面做返回

	while (*dest)
	{
		dest++;
	}

	while (count)
	{
		*dest++ = *src++;
		
		count--;
	}

	*dest = NUL;

	return cp;

}


int main(void)
{
	char dest[54] = "Hey Girl!";
	char *src = "You are my girlfriend!";

	//strncat(dest, src, strlen(src));
	//printf("%s\n", dest);

	MyStrncat(dest, src, strlen(src));
	printf("%s\n", dest);

	system("pause");
	return 0;
}