#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ���ʵ�֣� 
  ����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
  ��������: 
  1999 2299 
  �������:7	
* ���ķ�
* 2018/10/22
*/



//00000000000000000000000000001111
//00000000000000000001110000001111
//00000000000000000001110000000000
//�����������ֻ�Ȼ����ͳ��1�ĸ���

int count = 0;

int DiffBit (unsigned int x_, unsigned int y_)
{
	int i_ = x_ ^ y_;
	int count_ = 0;
	unsigned int flag_ = 1;
	while (flag_)
	{
		if (flag_ & i_)
			count_++;
		flag_ <<= 1;
	}
	return count_;
}

int main(void)
{
	unsigned int d_ = 0;
	unsigned int d1_ = 0;
	unsigned int d2_ = 0;
	
	scanf("%d%d", &d1_, &d2_);

	

	d_ = DiffBit(d1_, d2_);

	printf("%d \n", d_);

	system("pause");
	return 0;


}