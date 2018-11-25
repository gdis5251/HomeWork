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
	int number = 1; 
	struct AddressList al[1000] = { 0 };
	struct AddressList *p = al;
	
	while (input)
	{
		menu();
		printf("Please Input Option:> ");
		scanf("%d", &input);

		//�����û������ѡ����к�������
		switch (input)
		{
			case 0:
				printf("Exit!Bye!\n");
				break;
			case 1:
				//�Ƚ��ýṹ��������Ԫ������
				memset(al[number].name, NUL, sizeof(al[number].name));
				memset(al[number].sex, NUL, sizeof(al[number].sex));
				al[number].age = 0;
				memset(al[number].phnum, NUL, sizeof(al[number].phnum));
				memset(al[number].addr, NUL, sizeof(al[number].addr));

				AddContacts(&al[number]);
				number++;
				
				break;
			case 2:
				ShowAllContacts(al, number);//�ȸ���������ϵ�˵�����
				printf("Please input the number which you like to delete:> ");
				int num = 0;
				scanf("%d", &num);
				
				if (num > 0 && num < number)//�ڽ��е��ú���ǰ���ж�һ������������Ƿ����
				{
					DeleteContacts(&al[num]);
					printf("Delete Success !\n");
					ShowAllContacts(al, number);
				}
				else
					printf("Sorry! Didn't find!\n");
	
				//ɾ������ϵ�˺󽫻���ֿ�λ���򽫸���ϵ�˺������ϵ�˶���ǰ��һλ
				int i = 0;
				for (i = num; i < number - 1; i++)
				{
					strncpy(al[i].name, al[i + 1].name, strlen(al[i + 1].name) + 1);
					strncpy(al[i].sex, al[i + 1].sex, strlen(al[i + 1].sex) + 1);
					al[i].age = al[i + 1].age;
					strncpy(al[i].phnum, al[i + 1].phnum, strlen(al[i + 1].phnum) + 1);
					strncpy(al[i].addr, al[i + 1].addr, strlen(al[i + 1].addr) + 1);
				}
				number--;

				break;
			case 3:
				printf("Please input the name which you like to search:> ");
				char name[20] = {NUL};
				scanf("%s", &name);
				int flag = 0;
				
				//�������Ѿ��������ϵ����Ѱ���Ƿ�������Ϊname����ϵ��
				for (i = 0; i < number; i++)
				{
					if (strcmp(al[i].name, name) == 0)
					{
						printf("\tName\tSex\tAge\tPhoneNumber\tAddress\n");
						SearchContacts(&al[i], i);
						flag = 1;//ֻҪ�ҵ�һ���Ͱ�flag��Ϊ1
					}
				}
				if (0 == flag)//��û���ҵ������ӡ��ʾ��Ϣ
					printf("Sorry! Didn't find!\n");
				
				break;
			case 4:
				ShowAllContacts(al, number);
				printf("Please input the number which you like to modify:> ");
				num = 0;
				scanf("%d", &num);
				if (num > 0 && num < number)
				{
					ModifyContacts(&al[num], num);
					
				}
				else
					printf("Sorry! Didn't find!\n");

				break;
			case 5:
				//���û����ϵ�ˣ�ֱ��break
				if (0 == number)
				{
					printf("No Contacts!\n");
					break;
				}
				printf("\tName\tSex\tAge\tPhoneNumber\tAddress\n");
				ShowAllContacts(al, number);
				
				break;
			case 6:
				DeleteAllContacts(al, number);
				number = 0;
				printf("Delete Success!\n");
				
				break;
			case 7:
				SortAllContacts(al, number);
				printf("Sort Success!\n");
				ShowAllContacts(al, number);

				break;
			case 8:
				SaveContactsToFile(al, number);
				
				break;
			case 9:
				LoadContacts(al, number);
				
				break;
			default:
				printf("Input Error!\n");
				break;
		}

	}

	system("pause");
	return 0;
}
