#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
  ���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19 
* ���ķ�
* 2018/10/15
*/
int sum = 0;

int DigitSum(int n)
{
	

	if (n > 9)
	{
		DigitSum(n / 10);
	}
	
	return sum += n % 10;
}

int main(void)
{
	int result = 0;
	int n = 0;
	int flag = 0;

	printf("������һ���Ǹ������֣�");

	do
	{
		scanf("%d", &n);

		result = DigitSum(n);

		if (-1 == result)
		{
			printf("�������\n����������һ���Ǹ�������:");
			flag = 1;
		}
		else
		{
			printf("%d\n", result);
			flag = 0;
		}
	} while (flag);

	system("pause");
	return 0;
}