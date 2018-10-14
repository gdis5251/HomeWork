#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* 本程序是用于求水仙花数
  “水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身
  如；153＝1＋5＋3?，则153是一个“水仙花数”。
* 郭文峰
* 2018/9/25
*/

int main()
{
	int i = 0;
	int num = 0;
	int a = 0, b = 0, c = 0;
	int sum;

	printf("下列为0~999之间的水仙花数！\n");
	
	for (i = 100; i <= 999; i++)
	{
		num = i;      
		a = num % 10;		//将三位数的每一位分别赋值给 a b c 
		num = i / 10;
		b = num % 10;
		num = i / 100;
		c = num;


		sum = pow(a, 3) + pow(b, 3) + pow(c, 3);   // 将三位数分别求立方求和

		if (i == sum)
		{
			printf("%d   ", i);

		}
		

	}
	printf("\n");

	system("pause");
	return 0;
}