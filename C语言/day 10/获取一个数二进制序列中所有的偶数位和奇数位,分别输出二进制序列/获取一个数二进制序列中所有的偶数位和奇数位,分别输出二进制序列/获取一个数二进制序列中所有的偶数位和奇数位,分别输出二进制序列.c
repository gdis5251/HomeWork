#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* ��ȡһ�������������������е�ż��λ������λ�� 
  �ֱ�������������С� 
* ���ķ�
* 2018/10/22 
*/

int ji[16] = { 0 };
int ou[16] = { 0 };

void one_to_two(int d)
{
	int i = 0;
	int j = 0;
	//��һ���ܹؼ������û����һ������һ��ѭ����ı�d��ֵ
	//���ڶ���ѭ����ʱ��d��ֵ���Ѿ�����ԭ����ֵ��
	int d1 = d;

	for (i = 0; i < 16; i++)
	{
		ou[15 - i] = d & 1;
		d >>= 2;
	}

	for (i = 0; i < 16; i++)
	{
		ji[15 - i] = (d1 & 2) / 2;
		d1 >>= 2;
	}
}

int main(void)
{
	int i = 0;
	int d = 0;

	scanf("%d", &d);

	one_to_two(d);

	printf("��������������Ϊ��");
	for (i = 0; i < 16; i++)
	{
		printf("%d  ", ji[i]);
	}
	printf("\n");

	printf("ż������������Ϊ��");
	for (i = 0; i < 16; i++)
	{
		printf("%d  ", ou[i]);
	}
	printf("\n");

	system("pause");
	return 0;

}