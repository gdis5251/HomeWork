#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* ��������������ˮ�ɻ���
  ��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ�������
  �磻153��1��5��3?����153��һ����ˮ�ɻ�������
* ���ķ�
* 2018/9/25
*/

int main()
{
	int i = 0;
	int num = 0;
	int a = 0, b = 0, c = 0;
	int sum;

	printf("����Ϊ0~999֮���ˮ�ɻ�����\n");
	
	for (i = 100; i <= 999; i++)
	{
		num = i;      
		a = num % 10;		//����λ����ÿһλ�ֱ�ֵ�� a b c 
		num = i / 10;
		b = num % 10;
		num = i / 100;
		c = num;


		sum = pow(a, 3) + pow(b, 3) + pow(c, 3);   // ����λ���ֱ����������

		if (i == sum)
		{
			printf("%d   ", i);

		}
		

	}
	printf("\n");

	system("pause");
	return 0;
}