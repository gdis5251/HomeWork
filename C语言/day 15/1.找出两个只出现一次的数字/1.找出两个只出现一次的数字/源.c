#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

/*
* һ��������ֻ�����������ǳ���һ�Σ�
  �����������ֶ����������Ρ�
  �ҳ����������֣����ʵ�֡�
* ���ķ�
* 2018/11/5
*/
typedef unsigned int size_t;

void FindDiffer(int *p, int size)
{
	int i_ = 0;
	int flag_ = 1;
	int x = 0;

	//�������������ֻ�
	//���õ���һ�����־�������ֻ����һ�ε����ֵ��ֻ�
	for (; i_ < size; i_++)
	{
		x ^= p[i_];
	}

	//�ҳ��������ֵ�һ����ͬ�ı���λ
	while (!(x & flag_))
	{
		flag_ <<= 1;
	}
	

	//�����ҳ��ı���λ����������黮�ֳ�������
	//��������һ��������һ������ͬһ��
	int sin1 = 0;
	int sin2 = 0;
	for (i_ = 0; i_ < size; i_++)
	{
		if (0 == (p[i_] & flag_))
			sin1 ^= p[i_];
		else if (0 != (p[i_] & flag_))
			sin2 ^= p[i_];
	}

	printf("%d : %d\n", sin1, sin2);

}




int main(void)
{
	int arr[] = { 1, 2, 2, 4, 5, 6, 6, 4 };
	size_t size = sizeof(arr)/sizeof(arr[0]);

	FindDiffer(arr, size);

	

	system("pause");
	return 0;
}