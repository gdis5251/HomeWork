#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
** 本程序为动态内存管理专题课件代码练习
** 郭文峰
** 2018/11/26
*/

struct FleArr
{
	int i;
	char a[0];//柔性数组成员
};

int main(void)
{
	int i = 0;
	struct FleArr *p = (struct FleArr*)malloc(sizeof(struct FleArr), 100 * sizeof(char));

	if (!p)
	{
		exit(EXIT_FAILURE);
	}

	p->i = 100;
	for (i = 0; i < 100; i++)
	{
		p->a[i] = 'a';
	}

	free(p);
	p = NULL;
	
	//printf("%d\n", sizeof(struct FleArr));
	/*int *ptr = (int *)malloc(100);

	if (!ptr)
	{
		printf("ERROR!\n");
		exit(EXIT_FAILURE);
	}
*/
	//情况一
	/*ptr = realloc(ptr, 1000);
	if (!ptr)
	{
		printf("ERROR!\n");
		exit(EXIT_FAILURE);
	}

	free(ptr);
	ptr = NULL;
*/
	//情况二

	//int *p = realloc(ptr, 1000);
	//if (!p)
	//{
	//	printf("ERROR!\n");
	//	exit(EXIT_FAILURE);
	//}

	//ptr = p;

	//free(ptr);
	//ptr = NULL;



	system("pause");
	return 0;


	/*int *p = calloc(10, sizeof(int));

	if (!p)
	{
		printf("Can't get memory!\n");
		exit(EXIT_FAILURE);
	}

	free(p);
	p = NULL;*/

	
	//int n = 0;
	//scanf("%d", &n);
	//int *ptr = (int *)malloc(n * sizeof(int));

	//if (!ptr)
	//{
	//	printf("Can't get memory.");
	//	exit(EXIT_FAILURE);
	//}

	//int i = 0;
	//for (; i < n; i++)
	//{
	//	ptr[i] = 0;
	//}

	//free(ptr);
	//printf("%p\n", ptr);

	//ptr = NULL;//这一步是否重要？？？

	
}