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
	int d_flag = EXIT_FAILURE;
	int f_flag = EXIT_FAILURE;
	int u_flag = EXIT_FAILURE;
	int l_flag = EXIT_FAILURE;
	int w_flag = 0; //后面用来判断是否要写入文件


	ct = loadContact(ct);//利用return 将开辟的地址传回来，不然会造成得不到地址（函数调用结束释放栈帧）
	people_p cp = ct->people;


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
				if (0 == ct->cap)
				{
					ct = getMemory(ct);
					cp = ct->people; 
					

					ct->cap = INIT;
				}

				addPeople(ct, cp);				
				w_flag = 1;

				cp = ct->people;//让数组下标回归0

				break;
			case 2:
				d_flag = deletePeople(ct, cp);
				if (EXIT_FAILURE == d_flag)//如果用户输入错误重新输入
				{
					break;
				}

				w_flag = 1;
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

				w_flag = 1;

				break;
			case 5:
				l_flag = listContact(ct, cp);
				if (EXIT_FAILURE == l_flag)
					break;
				
				cp = ct->people;//让数组下标回归0

				break;
			case 6:
				emptyContact(ct);
				
				w_flag = 1;

				break;
			case 7:
				sortContact(ct, cp);
				w_flag = 1;

				break;
			default:
				printf("Error Input! One More Try!\n");
				break;
		}

	}

	
	if (1 == w_flag)
		writeFile(ct, cp);

	//free
	destoryContact(ct);
	ct = NULL;


	system("pause");
	return 0;
}
