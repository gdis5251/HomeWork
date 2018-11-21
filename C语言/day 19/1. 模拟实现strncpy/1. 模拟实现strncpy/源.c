#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <assert.h>



/*
* ������ģ��ʵ��һ���⺯��strncpy
* ���ķ�
* 2018/11/21
*/

void *MyStrncpy(char *dest, const char *src, int count)
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