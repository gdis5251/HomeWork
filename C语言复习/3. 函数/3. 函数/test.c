#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
** ������������ϰC���Ե����½ں����е�һЩ��ϰ����
** ���ķ�
** 2018/12/6
*/

//1. дһ�������ҳ��������е����ֵ

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

//2. дһ�����������������ε�����
//
//void swap(int *x, int *y)
//{
//	//���ֲ�������ʱ�����Ľ���������һ�ֺ���Ҫ�ķ���
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

//3. дһ��������ɶ��ֲ���

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

//4. дһ��������ÿ����һ��num��ֵ�ͼ�1
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

//5. ����һ������1234����˳���ӡÿһλ
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

//6. ����������ʱ�������ַ�������
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