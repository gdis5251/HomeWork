#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

#define NUL '\0'

/*
* ������ģ��ʵ�ֿ⺯��strncat
* ���ķ�
* 2018/11/21
*/
typedef unsigned int size_t;
void *MyStrncat(char *dest, const char *src, size_t count)
{
	assert(dest && src);

	char *cp = dest; //����һ��ָ���������������

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