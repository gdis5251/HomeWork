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

void  count_one_bits(unsigned int d)
{
	int i = 0;

	for (i = 0; i < 32; i++)
	{
		if ((d & 1) == 1)
		{
			count++;
		}
		d = d >> 1;
	}
}

int main(void)
{
	int d = 0;
	
	scanf("%d", &d);

	//������������Ϊ���������ȼ��Ϸ���Ϊ��1
	

	count_one_bits(d);

	printf("%d \n", count);

	system("pause");
	return 0;
		
		

}