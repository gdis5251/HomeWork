#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#define NUL '\0'

/*
* strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ���
  ����ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��
* ���ķ�
* 2018/11/7
*/

char *my_strstr(const char *str1, const char *str2)
{
	assert(str1 && str2);

	int flag = 0;
	char *p = NULL;
	int i = 0; 

	//ѭ����ͼ�ж�str2�Ƿ���str1���Ӵ�
	while (*str2)
	{
		//���str2�Ѿ���Ԫ�ظ�str1��ͬ���Ǻ����Ԫ��ȴ��ͬ����0
		if (flag == 1 && *str1 != *str2)
		{
			return NULL;
		}

		//���str2��ʼ��Ԫ����str1��ͬ������p���µ�ǰ��ַ
		if (*str1 == *str2)
		{
			flag = 1;
			i++;
			if (i == 1)
			{
				p = str1;
			}
			str1++;
			str2++;
		}
		else
			str1++;
		
		//str2�Ƚ��꣬���ȫ����ͬ�򷵻ص�һ����ͬԪ�صĵ�ַ
		if (flag == 1 && *str2 == NUL)
		{
			return p;
		}
				
	}

	return NULL;
}

int main(void)
{
	//char str1[20] = { "ABCDEFGH" };
	//char str2[10] = { "CDE" };
	char *str1 = "ABCDE";
	char *str2 = "BC";
	char *p = my_strstr(str1, str2);


	if (p != NULL)
	{
		printf("%p\n", p);
		printf("%s\n", p);
	}
	else
	{
		printf("str2����str1���Ӵ�\n");
	}

	system("pause");
	return 0;
}