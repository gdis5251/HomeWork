#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>


/*
* 本程序模拟实现库函数strncmp
* 郭文峰
* 2018/11/21
*/

typedef unsigned int size_t;

int MyStrncmp(const char *str1, const char *str2, size_t count)
{
	assert(str1 && str2);

	while (count)
	{
		//If there are different characters, compare and return 
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;

		str1++, str2++;
		count--;

	}

	return 0;
}

int main(void)
{
	char *str1 = "Who am i?";
	char *str2 = "Who am i? I am Gerald Kwok.";


	int issm = MyStrncmp(str1, str2, 9);
	printf("%d\n", issm);


	issm = MyStrncmp(str1, str2, strlen(str2));
	printf("%d\n", issm);

	system("pause");
	return 0;
}
