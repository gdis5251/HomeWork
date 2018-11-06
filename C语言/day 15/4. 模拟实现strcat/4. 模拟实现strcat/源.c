#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* 模拟实现strcat
* 郭文峰
* 2018/11/6
*/

char *my_strcat(char *dest, const char *src)
{
	assert(dest && src);
	int i = 0;

	//让指针指向dest的\0
	while (*dest++)//当*dest等于0的时候，循环跳出前又++了一次
	{
		;
	}
	//所以这里要--，让*dest等于第一个\0
	dest--;

	//将*src赋值给*dest
	while (*dest++ = *src++)
	{
		;
	}

	return dest;
}


int main(void)
{
	char dest[100] = { "hello! " };
	char src[10] = { "Gerald!" };

	*my_strcat(dest, src);

	printf("%s\n", dest);

	system("pause");
	return 0;

}