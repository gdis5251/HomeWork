#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
** 本程序用来对初阶指针课件代码的练习
** 郭文峰
** 2018/12/7
*/

//1. 指针就是内存单元，用来存指向变量的地址
//int main(void)
//{
//	int a = 10;
//	int *p = &a;
//
//	printf("%d\n", *p);
//
//	system("pause");
//	return 0;
//}

//2. 指针类型决定，在指针进行加减整数的时候，指针向前或向后走多大距离
int main(void)
{
	int n = 0;
	char *pc = (char*)&n;
	int *pi = &n;

	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);


	system("pause");
	return 0;
}