#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* дһ���������ز����������� 1 �ĸ��� 
  ���磺 15 0000 1111 4 �� 1 
  ����ԭ�ͣ� 
  int count_one_bits(unsigned int value) 
  { 
  // ���� 1��λ�� 
  }
* ���ķ�
* 2018/10/22
*/
int count = 0;

//��λ��1���������1����count++
void  count_one_bits(unsigned int d)
{
	int i = 0;

	for (i = 0; i < 32; i++)
	{
		if ((d & 1) == 1)
		{
			count++;
		}
		//����������
		//ͬʱҲ������1����
		d = d >> 1;
	}
}

//�������㷨����ÿ��ѭ���������һ�����λ��1
//���ֻҪͳ��ѭ���˶��ٴμ���

void CountBits(unsigned int x_)
{
	while (x_)
	{
		x_ = x_ & (x_ - 1);
		count++;
	}
}

int main(void)
{
	unsigned int d = 0;
	
	scanf("%d", &d);

	//count_one_bits(d);
	CountBits(d);

	printf("%d \n", count);

	system("pause");
	return 0;
		
		

}