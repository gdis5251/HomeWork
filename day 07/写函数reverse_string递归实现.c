#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��дһ������reverse_string(char * string)���ݹ�ʵ�֣� 
  ʵ�֣��������ַ����е��ַ��������С� 
  Ҫ�󣺲���ʹ��C�������� 
  ���ַ�������������
* ���ķ�
* 2018/10/15
*/


void reverse_string(char *string)
{

	/*if (*string == '\0')
	{
		printf("%c ", *string);


	}
	else
	{
		reverse_string(string + 1);
		printf("%c ", *(--string));
	}*/
	
	if (*string++)
	{
		reverse_string(string);
		printf("%c", *(--string));
	}
}

int main(void)
{
	char string[] = "abcde";

	reverse_string(string);

	system("pause");
	return 0;
}