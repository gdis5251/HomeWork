#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>


/*
* 本程序是对指针的进阶的部分课件上的代码进行实现
* 郭文峰
* 2018/11/12
*/

//void print1(int arr[][5], int row, int col)
//{
//	int i_ = 0;
//	for (i_ = 0; i_ < row; i_++)
//	{
//		int j_ = 0;
//		for (j_ = 0; j_ <col; j_++)
//		{
//			printf("%3d ", arr[i_][j_]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void print2(int(*arr)[5], int row, int col)
//{
//	int i_ = 0;
//	for (i_ = 0; i_ < row; i_++)
//	{
//		int j_ = 0;
//		for (j_ = 0; j_ <col; j_++)
//		{
//			printf("%3d ", arr[i_][j_]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

void menu()
{
	printf("*****************************\n");
	printf("***  1. add      2. sub  ****\n");
	printf("***  3. mul      4. div  ****\n");
	printf("***              0. exit ****\n");
	printf("*****************************\n");
	printf("Please Enter:");

}

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div_(int x, int y)
{
	if (y == 0)
		exit(-1);
	return x / y;
}


int main(void)
{
	int x;
	int y;
	int input = -1;
	int ret = 0;
	int (*pfun[5])(int x, int y) = { 0, add, sub, mul, div_ };

	while (input)
	{
		menu();
		scanf("%d", &input);

		switch (input)
		{
		case 0:
			printf("ByeBye!\n");
			break;
		case 1:
			printf("Please Enter Numbers:");
			scanf("%d%d", &x, &y);
			ret = (*pfun[1])(x, y);
			break;
		case 2:
			printf("Please Enter Numbers:");
			scanf("%d%d", &x, &y);
			ret = (*pfun[2])(x, y);
			break;
		case 3:
			printf("Please Enter Numbers:");
			scanf("%d%d", &x, &y);
			ret = (*pfun[3])(x, y);
			break;
		case 4:
			printf("Please Enter Numbers:");
			scanf("%d%d", &x, &y);
			ret = (*pfun[4])(x, y);
			break;
		default:
			printf("ERROR!\n");
			break;

		}
		if (input == 0)
			break;
		printf("Result -> %d\n", ret);
	}








//	printf("%p\n", test);
//	printf("%p\n", &test);
//
	/*
	int arr[10] = { 0 };
	int* arr2[10] = { 0 };
	int a[2][3] = { 0 };
	test(a);*/
	//test(arr);
	//test2(arr2);
	//int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//print1(arr, 3, 5);
	///*数组名arr，表示首元素的地址
	//而二维数组的首元素是第一行的地址
	//所以这里传递arr，可以用数组指针来接收*/
	//print2(arr, 3, 5);




	/*int arr[10] = { 0 };
	printf("arr + 1 -> %p\n", arr);
	printf("&arr + 1 -> %p\n", &arr);

	printf("arr+1 -> %p\n", arr + 1);
	printf("&arr+1 -> %p\n", &arr + 1);
	*/
	
	
	//char str1[] = "hello Gerald!";
	//char str2[] = "hello Gerald!";
	//char* str3 = "hello Gerald!";
	//char* str4 = "hello Gerald!";

	//if (str1 == str2) //此处比较的是首元素的地址
	//	printf("str1 and str2 are same !\n"); /*若要比较两个字符串的内容需要引用库 函数，或者自己编写函数。*/										 
	//else
	//	printf("str1 and str2 are not same !\n");

	//if (str3 == str4)
	//	printf("str3 and str4 are same !\n");
	//else
	//	printf("str3 and str4 are not same !\n");

	system("pause");
	return 0;
}