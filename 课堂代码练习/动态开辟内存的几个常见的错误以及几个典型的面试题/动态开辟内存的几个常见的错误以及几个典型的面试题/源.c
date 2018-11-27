#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*
** 本程序是对动态内存管理的几个常见错误的罗列，以及几个经典的面试题的罗列
** 郭文峰
** 2018/11/27
*/


//void *GetMemory(char *p)
//{
//	p = (char*)malloc(100);
//	return p;
//}

//char *GetMemory(void)
//{
//	char p[] = "hello";
//	return p;
//}

//void GetMemory(char **p, int num)
//{
//	*p = (char*)malloc(num);
//}

int main(void)
{
	char *str = (char*)malloc(100);

	strcpy(str, "hello");
	free(str);

	if (str != NULL)
	{
		strcpy(str, "world");
		printf("%s\n", str);
	}

	system("pause");
	return 0;







	/*char *str = NULL;
	
	GetMemory(&str, 100);
	
	strcpy(str, "hello");
	printf("%s\n", str);

	system("pause");
	return 0;

*/



	/*char *str = NULL;
	str = GetMemory();
	printf("%s\n", str);

	system("pause");
	return 0;

*/







	/*char *str = NULL;

	str = (char*)GetMemory(str);

	if (!str)
	{
		exit(EXIT_FAILURE);
	}

	strcpy(str, "hello");
	printf("%s\n", str);

	free(str);

	system("pause");
	return 0;
	*/











	/*int *p = (int *)malloc(sizeof(int) * 10);

	if (!p)
	{
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;


*/




	/*int *p = (int *)malloc(sizeof(int));

	if (!p)
	{
		exit(EXIT_FAILURE);
	}

	free(p);
	free(p);

	system("pause");
	return 0;


*/


	/*int *p = (int *)malloc(10 * sizeof(int));
	
	if (!p)
	{
		exit(EXIT_FAILURE);
	}

	p++;
	free(p);

	system("pause");
	return 0;
*/




	/*int a = 10;
	int *p = &a;
	free(p);

	system("pause");
	return 0;*/





	//int *p = (int *)malloc(10 * sizeof(int));
	//if (!p)
	//{
	//	exit(EXIT_FAILURE);
	//}

	//int i = 0;
	//for (i = 0; i <= 10; i++)
	//{
	//	p[i] = i;
	//}

	//printf("%d:%s\n", errno, strerror(errno));
	//free(p);
	//p = NULL;
	//
	





	//int *p = (int *)malloc(sizeof(int));

	//*p = 20;	//这里没有判断返回值
	//			//如果返回值为NULL则会出现错误
	//free(p);

	
}