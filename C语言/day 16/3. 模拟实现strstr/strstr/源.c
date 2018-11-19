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

	char* cp = (char*)str1;
	char* s1 = (char*)str1;
	char* s2 = (char*)str2;

	while (*cp)
	{
		//ÿ��ѭ����ʼǰ������s1 s2��λ
		s1 = cp;
		s2 = (char*)str2;

		while (*s1 == *s2 && *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == NUL)
		{
			return cp;
		}
		
		//��str1�ַ��������һλ����������
		cp++;
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