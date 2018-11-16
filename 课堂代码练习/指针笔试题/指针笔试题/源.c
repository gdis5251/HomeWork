#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* 8道指针笔试题
* 郭文峰
* 2018/11/16
*/

int main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	printf("%d %d", *(a + 1), *(ptr - 1));//2 5
	//&a 表示整个数组的地址，&a + 1，指向5后面的元素的地址
	//在强转为整形数组后，- 1 ，向后退四个字节指向5

	system("pause");
	return 0;
}