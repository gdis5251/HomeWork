#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* ������Ϊ����һֱ���ռ����ַ�
  �����Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ�
  �������Ӧ��Сд�ַ�����������ֲ������
* ���ķ�
* 2018/9/28
*/


int main(void)
{

	int ch = 0;

	while (ch != EOF)
	{
		ch = getchar();
		if (ch >= 'a'&& ch <= 'z')
		{ 
			ch -= 32;			
			printf("%c\n", ch);
		}		
		else if (ch >= 'A'&& ch <= 'Z')
		{
			ch += 32;			
			printf("%c\n", ch); 
		}

	

		
	}
 

	system("pause");

	return 0;
}