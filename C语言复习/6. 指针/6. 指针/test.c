#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
** �����������Գ���ָ��μ��������ϰ
** ���ķ�
** 2018/12/7
*/

//1. ָ������ڴ浥Ԫ��������ָ������ĵ�ַ
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

//2. ָ�����;�������ָ����мӼ�������ʱ��ָ����ǰ������߶�����
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