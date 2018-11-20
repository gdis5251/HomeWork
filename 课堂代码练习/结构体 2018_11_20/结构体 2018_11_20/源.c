#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* 本程序是对结构体、位段、联合和枚举的课件代码练习
* 郭文峰
* 2018/11/20
*/

//struct NODE 
//{
//	int i;
//	int c;
//}node;
//
//struct s1
//{
//	char c1;
//	int i;
//	char c2;
//};//12
//
//struct s2
//{
//	char c1;
//	char c2;
//	int i;
//};//8
//
//struct s3
//{
//	double d;
//	char c;
//	int i;
//};//16
//
//struct s4
//{
//	char c;
//	struct s3 s3;//对齐数是8，大小是16
//	double d;
//};//32

//#pragma pack(4)
//
//struct s1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//
//#pragma pack(1)
//
//struct s2
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//#pragma pack()
struct s1
{
	char a[1024 * 1024];
};

//void fun(struct s1 a)
//{
//   传参时如果传结构体，就可能产生栈溢出
//}

//void fun(struct s1 *a)
//{
//
//}

//struct s	//位段
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};

//enum day
//{
//	MON,
//	TUES,
//	WED,
//	THUR,
//	FRI,
//	SAT,
//	SUN
//};

//判断当前计算机大小端存储

union a
{
	char c;
	int i;
}un;//小端

int main(void)
{
	un.i = 1;
	printf("%d\n", un.c);


	//printf("%d\n", MON);
	//printf("%d\n", SUN);
	/*struct s s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
*/
	/*int i = 0;
	struct s1 a;
	for (; i < 10240; i++)
	{
		fun(&a);
	}
*/


	/*printf("%d\n", sizeof(struct s1));
	printf("%d\n", sizeof(struct s2));*/

	/*printf("%d\n", sizeof(struct s1));
	printf("%d\n", sizeof(struct s2));
	printf("%d\n", sizeof(struct s3));
	printf("%d\n", sizeof(struct s4));*/

	//struct NODE a = { 3, 4 };//初始化

	//printf("%d\n", sizeof(node));


	system("pause");
	return 0;
}