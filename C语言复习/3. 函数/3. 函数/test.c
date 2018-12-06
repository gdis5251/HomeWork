#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
** 本程序用来复习C语言第三章节函数中的一些练习代码
** 郭文峰
** 2018/12/6
*/

//1. 写一个函数找出两个数中的最大值

//int maxNum(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int main(void)
//{
//	int num1 = 0;
//	int num2 = 0;
//	int max = 0;
//	
//	printf("Please input two different numbers:> "); 
//	scanf("%d%d", &num1, &num2);
//
//	max = maxNum(num1, num2);
//
//	printf("%d bigger than %d\n", max, num1 + num2 - max);
//
//	system("pause");
//	return 0;
//}

//2. 写一个函数交换两个整形的内容
//
//void swap(int *x, int *y)
//{
//	//这种不定义临时变量的交换方法是一种很重要的方法
//	*x ^= *y;
//	*y ^= *x;
//	*x ^= *y;
//}
//
//int main(void)
//{
//	int num1 = 0;
//	int num2 = 0;
//		
//	printf("Please input two different numbers:> "); 
//	scanf("%d%d", &num1, &num2);
//	printf("Before   num1: %d, num2: %d\n", num1, num2);
//
//	swap(&num1, &num2);
//
//	printf("After    num1: %d, num2: %d\n", num1, num2);
//
//	system("pause");
//	return 0;
//}

//3. 写一个函数完成二分查找

//int binSeh(int *arr, int key, int left, int  right)
//{
//	assert(arr);
//
//	int mid = (left + right) / 2;
//
//	while (arr[mid] != key && left <= right)
//	{
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//			mid = (left + right) / 2;
//		}
//		else
//		{
//			left = mid + 1;
//			mid = (left + right) / 2;
//		}
//	}
//
//	if (left > right)
//		return -1;
//	else
//		return mid;
//}
//
//int main(void)
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int key = 1;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int res = -1;
//
//	res = binSeh(arr, key, left, right);
//
//	if (res >= 0)
//		printf("The index is %d\n", res);
//	else
//		exit(EXIT_FAILURE);
//
//	system("pause");
//	return 0;
//}

//4. 写一个函数，每调用一次num的值就加1
//void test(int *num)
//{
//	assert(num);
//
//	(*num)++;
//}
//
//int main(void)
//{
//	int num = 0;
//	int i = 0;
//	for (; i < 10; i++)
//		test(&num);
//
//	printf("%d\n", num);
//
//	system("pause");
//	return 0;
//}

//5. 输入一个整型1234，按顺序打印每一位
//void printEach(int n)
//{
//	if (n > 9)
//	{
//		printEach(n / 10);
//	}
//
//	printf("%d ", n % 10);
//}
//
//int main(void)
//{
//	int num = 1234;
//
//	printEach(num);
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

//6. 不允许创建临时变量求字符串长度
int MyStrlen(const char *str)
{
	assert(str);
	
	if (*str == '\0')
		return 0;
	else
		return 1 + MyStrlen(str + 1);
}

int main(void)
{
	char *str = "Xiao Zhu Hu Yue";
	int len = 0;

	len = MyStrlen(str);

	printf("%d\n", len);

	system("pause");
	return 0;
}