#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��һ���ַ����������Ϊ:"student a am i", 
  ���㽫��������ݸ�Ϊ"i am a student". 
  Ҫ�� 
  ����ʹ�ÿ⺯���� 
  ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ��� 
* ���ķ�
* 2018/10/28
*/


int main(void)
{
	char arr[50] = { "student am i" };
	char arr_3[3][10] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;

	//�ı�ǰ��ӡ���Ա�
	printf("%s\n", arr);

	//��һ����ά���飬�ֱ��ų�ʼ�ַ�����ÿһ������
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

	//���Ŵ�ӡ���Ϳ��Եõ�����
	for (i = 2; i >= 0; i--)
	{
		printf("%s ", arr_3[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}