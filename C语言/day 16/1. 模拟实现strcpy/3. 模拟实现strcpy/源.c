#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

/*
* 模拟实现strcpy
* 郭文峰
* 2018/11/6
*/

char *my_strcpy(char *dest, const char *res)
{
	assert(dest && res);

	while (*dest++ = *res++)//赋值表达式返回左操作数
		;

	return dest;
}

int main(void)
{
	char dest[100] = { 0 };
	char res[10] = { 'a', 'b', 'c', 'd' };

	*my_strcpy(dest, res);

	printf("%s\n", dest);

	system("pause");
	return 0;
}
