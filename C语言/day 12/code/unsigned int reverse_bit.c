#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* 1.��д������ 
  unsigned int reverse_bit(unsigned int value); 
  ��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ�� 

  �磺 
  ��32λ������25���ֵ�������и�λ�� 
  00000000000000000000000000011001 
  ��ת�󣺣�2550136832�� 
  10011000000000000000000000000000 
  ���������أ� 
  2550136832
* ���ķ�
* 2018/10/27
*/
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int j = 0;
	long long int d = 0;
	int change[32] = { 0 };

	//��value�Ķ�����ֵ�����з���
	for (i = 0; i < 32; i++)
	{
		change[i] = value & 1;
		value >>= 1;
	}
	
	//��������������������Ӧ��ʮ������
	for (i = 0; i < 32; i++)
	{
		d += change[32 - i - 1] * (long long int)pow(2, i);
	}

	return d;
}

int main(void)
{
	unsigned int num = 0;
	long long int change_num = 0;
	//����һ���޷�������
	scanf("%d", &num);

	//����ʽ����ֱ�Ӵ�ӡ
	printf("%u\n", reverse_bit(num));

	//��change_num��ס�������ص�ֵ���ٴ�ӡ
	change_num = reverse_bit(num);
	printf("%u\n", change_num);

	system("pause");
	return 0;
}