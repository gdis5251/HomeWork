#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ������������Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2+22+222+2222+22222 
* ���ķ�
* 2018/9/25
*/

int main()
{
	int i = 0;
	int sum = 0;
	int num = 0;
	int num1 = 0;

	scanf("%d", &num);// ��ȡһ������

	num1 = num;
	sum = num;

	for (i = 1; i < 5; i++)
	{
		num = num * 10 + num1;
		sum += num;
	}

	printf("%d\n", sum);

	system("pause");
	return 0;
}