#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* 喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
  给20元，可以多少汽水。
  编程实现。
* 郭文峰
* 2018/11/5
*/

int main(void)
{
	int money = 20;
	int bottle = 0;
	int count = 0;

	//当还有钱时，继续
	while (money)
	{
		money--;
		bottle++;
		count++;

		//当有两个瓶子时，可以再换一瓶
		if (2 == bottle)
		{
			bottle -= 2;
			count++;
			bottle++;
		}


	}

	printf("总共可以喝%d瓶饮料！\n", count);

	system("pause");
	return 0;
}