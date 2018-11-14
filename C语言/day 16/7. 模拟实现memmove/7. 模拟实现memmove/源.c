#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <assert.h>

/*
* 本程序模拟实现库函数memmove
* 郭文峰
* 2018/11/14
*/
typedef unsigned int size_t;

void* MyMemmove(void* dest, const void* src, size_t n)
{
	assert(dest && src);

	char* s = (char*)dest;

	//(char*)dest >= ((char*)src + n)
	//这个判断条件加不加都可以使函数正确
	//可以如果加了可以少else里的两句赋值
	if (dest <= src || (char*)dest >= ((char*)src + n))
	{
		while (n--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dest = (char*)dest + n - 1;
		src = (char*)src + n - 1;
		while (n--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}

	return s;
}

int main(void)
{

	char s1[60] = "Golden Global View";
	char s2[60] = "1234567891011121314151617181920";


	//memmove(s1 + 7, s1, strlen(s1) + 1);
	//printf("%s\n", s1); //Golden Golden Global View
	
	//MyMemmove(s1 + 7, s1, strlen(s1) + 1);
	MyMemmove(s1, s2, strlen(s2) + 1);

	printf("%s\n", s1);



	system("pause");
	return 0;
}