#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* �������ǹ�ϵ�ڴ����Ĳ���
* ���ķ�
* 2018/11/19
*/

struct s1
{
	char c1;	//����ʼƫ����Ϊ0��λ�ÿ�ʼ��
	int i;		//����ʼƫ����Ϊ4��λ�ÿ�ʼ��
	char c2;	//����ʼƫ����Ϊ8��λ�ÿ�ʼ��
};//���ṹ��Ĵ�С��չ����������4��������Ϊ12

struct s2
{
	char c1;	//����ʼƫ����Ϊ0��λ�ÿ�ʼ��
	char c2;	//����ʼƫ����Ϊ1��λ�ÿ�ʼ��
	int i;		//����ʼƫ����Ϊ4��λ�ÿ�ʼ��
};//���ṹ��Ĵ�С��չ����������4��������Ϊ8

struct s3
{
	double d;	//����ʼƫ����Ϊ0��λ�ÿ�ʼ��
	char c;		//����ʼƫ����Ϊ8��λ�ÿ�ʼ��
	int i;		//����ʼƫ����Ϊ12��λ�ÿ�ʼ��
};//���ṹ��Ĵ�С��չ����������8��������Ϊ16

struct s4
{
	char c1;		//����ʼƫ����Ϊ0��λ�ÿ�ʼ��
	struct s3 s3;	//����ʼƫ����Ϊ8��λ�ÿ�ʼ��
	double d;		//����ʼƫ����Ϊ24��λ�ÿ�ʼ��
};//���ṹ��Ĵ�С��չ����������8��������Ϊ32

int main(void)
{
	printf("%d\n", sizeof(struct s1));
	printf("%d\n", sizeof(struct s2));
	printf("%d\n", sizeof(struct s3));
	printf("%d\n", sizeof(struct s4));



	system("pause");
	return;
}
