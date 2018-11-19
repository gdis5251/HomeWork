#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* 本程序是关系内存对齐的测试
* 郭文峰
* 2018/11/19
*/

struct s1
{
	char c1;	//从起始偏移量为0的位置开始存
	int i;		//从起始偏移量为4的位置开始存
	char c2;	//从起始偏移量为8的位置开始存
};//最后结构体的大小扩展至最大对齐数4的整数倍为12

struct s2
{
	char c1;	//从起始偏移量为0的位置开始存
	char c2;	//从起始偏移量为1的位置开始存
	int i;		//从起始偏移量为4的位置开始存
};//最后结构体的大小扩展至最大对齐数4的整数倍为8

struct s3
{
	double d;	//从起始偏移量为0的位置开始存
	char c;		//从起始偏移量为8的位置开始存
	int i;		//从起始偏移量为12的位置开始存
};//最后结构体的大小扩展至最大对齐数8的整数倍为16

struct s4
{
	char c1;		//从起始偏移量为0的位置开始存
	struct s3 s3;	//从起始偏移量为8的位置开始存
	double d;		//从起始偏移量为24的位置开始存
};//最后结构体的大小扩展至最大对齐数8的整数倍为32

int main(void)
{
	printf("%d\n", sizeof(struct s1));
	printf("%d\n", sizeof(struct s2));
	printf("%d\n", sizeof(struct s3));
	printf("%d\n", sizeof(struct s4));



	system("pause");
	return;
}
