#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* ���������ڴӱ�׼�����ȡCԴ���룬����֤���еĻ����Ŷ���ȷ�ĳɶԳ��֡� 
* ���ķ�
* 2018/9/25 
*/

int main()
{
	char ch[10000] = { 0 };
	int i = 0;
	int left = 0;
	int right = 0;

	scanf("%s", ch);//�ñ�׼�����ȡһ��C��Դ����

	for (i = 0; i <= strlen(ch) - 1; i++)
	{
		if ('{' == ch[i])
			left++;
		if ('}' == ch[i])
			right++;
	}

	if (left == right)
		printf("�����ųɶԳ��֣�\n");
	else
		printf("�����Ų��ɶԳ��֣�\n");

	system("pause");
	return 0;
}