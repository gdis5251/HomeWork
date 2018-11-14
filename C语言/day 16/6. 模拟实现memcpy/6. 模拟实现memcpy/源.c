#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

#define NUL '\0'

/*
* 本程序模拟实现memcpy库函数
* 郭文峰
* 2018/11/14
*/
typedef unsigned int size_t;

//类型定义为void* 这样传参时可以穿任何类型的参数
void* MyMemcpy(void* dest, const void* src, size_t n)
{
	assert(dest && src);

	char* p = (char*)dest;

	//按字节覆盖
	while (n)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
		n--;
	}

	return p;
}

int main(void)
{
	char s1[100] = "Hello";
	char s2[10] = "Gerald";
	int a1[6] = { 1, 2, 3, 4 };
	int a2[5] = { 7, 8, 9 };

	MyMemcpy(s1, s2, strlen(s2) + 1);
	printf("%s\n", s1);

	MyMemcpy(a1, a2, sizeof(a2[0]) + sizeof(a2[1]) + sizeof(a2[2]));
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", a1[i]);
	}

	system("pause");
	return 0;
}
