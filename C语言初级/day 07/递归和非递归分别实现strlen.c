#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 递归和非递归分别实现strlen 
* 郭文峰
* 2018/10/15
*/
int count = 0;

int my_d_strlen(char *s)
{
	
	if (*s == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_d_strlen(s + 1);//递归调用自己，将s+1传进去
	}

}

int my_fd_strlen(char *s)
{
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return count;
}

int main(void)
{
	char s[] = "abcde";
	int a = 0;
	int b = 0;

	a = my_d_strlen(s);
	b = my_fd_strlen(s);

	printf("%d   %d\n", a, b);

	system("pause");
	return 0;
}