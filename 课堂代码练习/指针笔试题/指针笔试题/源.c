#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* 8��ָ�������
* ���ķ�
* 2018/11/16
*/

int main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	printf("%d %d", *(a + 1), *(ptr - 1));//2 5
	//&a ��ʾ��������ĵ�ַ��&a + 1��ָ��5�����Ԫ�صĵ�ַ
	//��ǿתΪ���������- 1 ��������ĸ��ֽ�ָ��5

	system("pause");
	return 0;
}