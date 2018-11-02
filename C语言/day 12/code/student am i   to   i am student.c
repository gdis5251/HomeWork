#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 有一个字符数组的内容为:"student a am i", 
  请你将数组的内容改为"i am a student". 
  要求： 
  不能使用库函数。 
  只能开辟有限个空间（空间个数和字符串的长度无关）。 
* 郭文峰
* 2018/10/28
*/


int main(void)
{
	char arr[50] = { "student am i" };
	char arr_3[3][10] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;

	//改变前打印作对比
	printf("%s\n", arr);

	//用一个二维数组，分别存放初始字符串的每一个单词
	for (i = 0; i < 3; i++)
	{
		
		for (j = 0; j < 10; j++)
		{
			if (arr[k] != ' ')
				arr_3[i][j] = arr[k];
			else if (arr[k] == ' ')
				break;
			else if (arr[k] == '\0')
				break;
			k++;
		}
		k++;
		
	}

	//倒着打印，就可以得到需求
	for (i = 2; i >= 0; i--)
	{
		printf("%s ", arr_3[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}