#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* ����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
  ��20Ԫ�����Զ�����ˮ��
  ���ʵ�֡�
* ���ķ�
* 2018/11/5
*/

int main(void)
{
	int money = 20;
	int bottle = 0;
	int count = 0;

	//������Ǯʱ������
	while (money)
	{
		money--;
		bottle++;
		count++;

		//��������ƿ��ʱ�������ٻ�һƿ
		if (2 == bottle)
		{
			bottle -= 2;
			count++;
			bottle++;
		}


	}

	printf("�ܹ����Ժ�%dƿ���ϣ�\n", count);

	system("pause");
	return 0;
}