#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <Windows.h>

/*
** 本程序针对复习C语言过程中验证一些感到疑惑的代码
** 郭文峰
** 2018/12/3
*/

//int add(int x, int y)
//{
//	return x + y;
//}

void test(void)
{
	static int i = 0;
	i++;
	printf("%d ", i);
}

int main(void)
{
	int i = 0;
	
	for (i = 0; i < 10; i++)
	{
		test();
	}
	printf("\n");

	system("pause"); 
	return 0;

	/*int a = -1;
	
	a <<= 33;
	
	printf("%d\n", a);
*/

	/*int num1 = 0;
	int num2 = 0;

	printf("Please Enter Two Numbers:> ");
	scanf("%d%d", &num1, &num2);

	printf("%d + %d = %d\n", num1, num2, add(num1, num2));
*/
	system("pause");
	return 0;
}