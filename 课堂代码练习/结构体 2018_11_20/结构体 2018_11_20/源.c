#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* �������ǶԽṹ�塢λ�Ρ����Ϻ�ö�ٵĿμ�������ϰ
* ���ķ�
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
//	struct s3 s3;//��������8����С��16
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
//   ����ʱ������ṹ�壬�Ϳ��ܲ���ջ���
//}

//void fun(struct s1 *a)
//{
//
//}

//struct s	//λ��
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

//�жϵ�ǰ�������С�˴洢

union a
{
	char c;
	int i;
}un;//С��

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

	//struct NODE a = { 3, 4 };//��ʼ��

	//printf("%d\n", sizeof(node));


	system("pause");
	return 0;
}