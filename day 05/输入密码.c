#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
* ģ��������������ĳ���
  ����������������룬������ȷ����ʾ����¼�ɹ���,������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����
* ���ķ�
* 2018/9/28
*/

int main(void)
{
	int i = 0;
	char *p = "123456";
	char arr[10];
	for (i = 0; i < 3;i++)
	{
		printf("����������:");
		scanf("%s",arr);
		if (strcmp(p,arr)==0)
		{
			break;
		}
		else
		{
			printf("�������!\n");
		}
	}
	if (i==3)
	{
		printf("��������������󣬽��˳�����\n");
	}
	else if (i<3)
	{
		printf("��ϲ���¼�ɹ���\n");
	
	}

	system("pause");
	return 0;
}


