#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("********************************************\n");
	printf("*** 1. add                      2.delete ***\n");
	printf("*** 3. search                   4.update ***\n");
	printf("*** 5. list                     6.empty  ***\n");
	printf("*** 7. sort                     0.exit   ***\n");
	printf("********************************************\n");

	printf("Please input your option:> ");
}




int main(void)
{
	int input = 1;
	contact_p ct = initContact();
	people_p cp = ct->people;
	int d_flag = EXIT_FAILURE;
	int f_flag = EXIT_FAILURE;
	int u_flag = EXIT_FAILURE;
	int l_flag = EXIT_FAILURE;



	while (input)
	{
		menu();
		scanf("%d", &input);


		switch (input)
		{
			case 0:
				printf("Bye Bye!\n");
				
				break;
			case 1:
				cp = cp + (ct->size);//让柔性数组可以持续写入，消除数据覆盖的情况
				addPeople(ct, cp);
				
				cp = ct->people;//让数组下标回归0

				break;
			case 2:
				d_flag = deletePeople(ct, cp);
				if (EXIT_FAILURE == d_flag)//如果用户输入错误重新输入
				{
					break;
				}

				cp = ct->people;//让数组下标回归0
				
				break;
			case 3:
				f_flag = searchPeople(ct, cp);
				if (EXIT_FAILURE == f_flag)
				{
					break;
				}
				
				cp = ct->people;//让数组下标回归0


				break;
			case 4:
				u_flag = updatePeople(ct, cp);
				if (EXIT_FAILURE == u_flag)
				{
					break;
				}

				cp = ct->people;//让数组下标回归0

				break;
			case 5:
				l_flag = listContact(ct, cp);
				if (EXIT_FAILURE == l_flag)
					break;
				
				cp = ct->people;//让数组下标回归0

				break;
			case 6:
				emptyContact(ct);
				break;
			case 7:
				sortContact(ct, cp);
				break;
			default:
				printf("Error Input! One More Try!\n");
				break;
		}

	}

	//free
	destoryContact(ct);
	ct = NULL;


	system("pause");
	return 0;
}