#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"
/*
* ʵ��һ��ͨѶ¼
  ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
  �������Ա����䡢�绰��סַ
  �����ö�̬����
* ���ķ�
* 2018/11/24
*/


void menu()
{
	printf("*****************************************\n");
	printf("***       1. �����ϵ����Ϣ           ***\n");
	printf("***       2. ɾ��ָ����ϵ����Ϣ       ***\n");
	printf("***       3. ����ָ����ϵ����Ϣ       ***\n");
	printf("***       4. �޸�ָ����ϵ����Ϣ       ***\n");
	printf("***       5. ��ʾ������ϵ����Ϣ       ***\n");
	printf("***       6. ���������ϵ��           ***\n");
	printf("***       7. ����������������ϵ��     ***\n");
	printf("***       8. ������ϵ�˵��ļ�         ***\n");
	printf("***       9. ������ϵ��               ***\n");
	printf("***       0. �˳�                     ***\n");
	printf("*****************************************\n");
}


int main(void)
{
	int input = 1;
	int count = 0; 
	struct AddressList al[1000] = { 0 };
	
	while (input)
	{
		menu();
		printf("Please Input Option:> ");
		scanf("%d", &input);

		switch (input)
		{
			case 0:
				printf("Exit!Bye!\n");
				break;
			case 1:
				AddContacts(&al[count]);
				count++;
				break;
			case 2:
				//printf("Please input the number which you like to delete:>");
				//int num = -1;
				//scanf("%d", &num);
				//DeleteContacts(&al[num]);
				break;
			case 3:
				//SearchContacts();
				count++;
				break;
			case 4:
				//ModifyContacts();
				count++;
				break;
			case 5:
				//ShowAllContacts();
				count++;
				break;
			case 6:
				//DeleteAllContacts();
				count++;
				break;
			case 7:
				//SortAllContacts();
				count++;
				break;
			case 8:
				//SaveContactsToFile();
				count++;
				break;
			case 9:
				//LoadContacts();
				count++;
				break;
			default:
				printf("Input Error!\n");
				break;
		}

	}


	system("pause");
	return 0;
}
