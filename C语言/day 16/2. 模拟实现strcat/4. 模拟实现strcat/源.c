#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* ģ��ʵ��strcat
* ���ķ�
* 2018/11/6
*/

char *my_strcat(char *dest, const char *src)
{
	assert(dest && src);
	int i = 0;

	//��ָ��ָ��dest��\0
	while (*dest++)//��*dest����0��ʱ��ѭ������ǰ��++��һ��
	{
		;
	}
	//��������Ҫ--����*dest���ڵ�һ��\0
	dest--;

	//��*src��ֵ��*dest
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