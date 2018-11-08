#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* ģ��ʵ��strchr����
* ���ķ�
* 2018/11/8
*/

//�⺯��strchr��̷�ʽ
char *K_strchr(char *str, char val)
{
	while (*str != '\0' && *str != val)
	{
		str++;
	}
	return *str == val ? str : NULL;
}

char *my_strchr(char *str, char val)
{
	assert(str);// �ж�str���ǿ�ָ��

	while (*str++)
	{
		if (val == *(str - 1))//����ҵ��ַ���һ�γ��ֵ�λ�ã��򷵻����ĵ�ַ
			return str - 1;
	}

	return NULL;
}

int main(void)
{
	char *str = "It's my life! My decision it!";
	char *p = NULL;

	p = my_strchr(str, 'm');

	if (p != NULL)
	{
		printf("%p\n", p);
		printf("%s\n", str);
		while (*str)
		{
			printf("%p\n", str);
			str++;
		}
	}
	else
		printf("Not Found!");

	system("pause");
	return 0;
}