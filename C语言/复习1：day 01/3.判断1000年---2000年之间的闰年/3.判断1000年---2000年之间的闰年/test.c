#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
** �����������ж�1000��---2000��֮�������
   �ж�����������ǣ����ܱ�4��100���������߲��ܱ�400����
** ���ķ�
** 2018/12/3
*/

int isLeapYear(int year)
{
	if (((0 == year % 4) && (0 != year % 100)) || 0 == year % 400)
		return 1;
	
	return 0;
}

int main(void)
{
	int i = 0;
	int flag = 0;
	int count = 0;

	printf("The leap between 1000 to 2000 is :> ");
	
	for (i = 1000; i <= 2000; i++)
	{
		flag = isLeapYear(i);

		if (flag)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("%d\n", count);


	system("pause");
	return 0;
}