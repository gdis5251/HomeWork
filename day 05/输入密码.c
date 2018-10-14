#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
* 模拟三次密码输入的场景
  最多能输入三次密码，密码正确，提示“登录成功”,密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
* 郭文峰
* 2018/9/28
*/

int main(void)
{
	int i = 0;
	char *p = "123456";
	char arr[10];
	for (i = 0; i < 3;i++)
	{
		printf("请输入密码:");
		scanf("%s",arr);
		if (strcmp(p,arr)==0)
		{
			break;
		}
		else
		{
			printf("密码错误!\n");
		}
	}
	if (i==3)
	{
		printf("三次密码输入错误，将退出程序\n");
	}
	else if (i<3)
	{
		printf("恭喜你登录成功！\n");
	
	}

	system("pause");
	return 0;
}


