#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int yueShu;
	int t;
	int min;
	int num1, num2;
	printf("please input two numbers:");
	scanf("%d%d", &num1, &num2);
	if (num1 > num2)
	{
		t = num1;
		num1 = num2;
		num2 = t;

	}
	min = num1;
	for (int i = min; i >= 1; i--)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			yueShu = i;
			break;
		}
	}
	printf("最大公约数为%d\n", yueShu);
	system("pause");
	return 0;
}