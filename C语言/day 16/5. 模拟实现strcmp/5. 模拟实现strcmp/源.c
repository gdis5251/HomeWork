#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <string.h>

/*
* ģ��ʵ��strcmp����
* ���ķ�
* 2018/11/8
*/

int my_strcmp(const char *s1, const char *s2)
{
	assert(s1 && s2);
	unsigned int count1 = 0;
	unsigned int count2 = 0;

	do
	{
		count1 = *s1;
		count2 = *s2;

		//���s1���������������
		//1 �����ַ�����ȣ���ô���᷵��0
		//2 s1С��s2����ô����ĸ�ֵ��count1����õ�һ��0,��count2����õ�һ����ֵ
		//���Խ��᷵�ظ���
		if (*s1 == '\0')
			return count1 - count2;

		s1++;
		s2++;
	} while (count1 == count2);

	//����Ҳ��ֻ�����������
	//1 count1С��count2
	//2 count1����count2
	return count1 - count2;
	
}

int main(void)
{
	char *str1 = "Gerald is cool guy!";
	char *str2 = "Gerald is cool guy!";
	char *str3 = "Gerald is cool guy! HAHAHA!";
	char *str4 = "Gerald";

		//str1��str2�Ƚ�
	if ((my_strcmp(str1, str2)) == 0)
		printf("str1 == str2\n");
	else if ((my_strcmp(str1, str2)) > 0)
		printf("str1 > str2\n");
	else
		printf("str1 < str2\n");

	//str1��str3�Ƚ�
	if ((my_strcmp(str1, str3)) == 0)
		printf("str1 == str3\n");
	else if ((my_strcmp(str1, str3)) > 0)
		printf("str1 > str3\n");
	else
		printf("str1 < str3\n");

	//str1��str4�Ƚ�
	if ((my_strcmp(str1, str4)) == 0)
		printf("str1 == str4\n");
	else if ((my_strcmp(str1, str4)) > 0)
		printf("str1 > str4\n");
	else
		printf("str1 < str4\n");

	system("pause");
	return 0;
}