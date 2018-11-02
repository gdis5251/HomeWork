#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 本程序为可以一直接收键盘字符
  如果是小写字符就输出对应的大写字符，如果接收的是大写字符
  就输出对应的小写字符，如果是数字不输出。
* 郭文峰
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