#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void)
{
	printf("*****************************************************\n");
	printf("****************         1.play       ***************\n");
	printf("****************         0.exit       ***************\n");
	printf("*****************************************************\n");

}

void game(void)
{
	
	int rnum = rand() % 100 + 1;

	while (1)
	{
		printf("������µ����֣�");
		int num;
		scanf("%d", &num);

		if (num == rnum)
		{
			printf("�¶��ˣ�\n");
			break;
		}
		else if (num > rnum)
		{
			printf("�´��ˣ�\n");

		}
		else
		{
			printf("��С�ˣ�\n");
		}

	}
}

int main(void)
{
	int i = 0;
	int input = 0;

	srand((unsigned int)time(NULL));


	//ѡ���Ƿ�Ҫ������Ϸ
	do
	{
		menu();

		printf("��ѡ��");

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			input = 0;
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
}