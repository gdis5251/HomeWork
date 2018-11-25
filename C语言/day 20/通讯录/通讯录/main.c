#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"
/*
* 实现一个通讯录
  通讯录可以用来存储1000个人的信息，每个人的信息包括：
  姓名、性别、年龄、电话、住址
  不能用动态创建
* 郭文峰
* 2018/11/24
*/


void menu()
{
	printf("*****************************************\n");
	printf("***       1. 添加联系人信息           ***\n");
	printf("***       2. 删除指定联系人信息       ***\n");
	printf("***       3. 查找指定联系人信息       ***\n");
	printf("***       4. 修改指定联系人信息       ***\n");
	printf("***       5. 显示所有联系人信息       ***\n");
	printf("***       6. 清空所有联系人           ***\n");
	printf("***       7. 以名字排序所有联系人     ***\n");
	printf("***       8. 保存联系人到文件         ***\n");
	printf("***       9. 加载联系人               ***\n");
	printf("***       0. 退出                     ***\n");
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

		//按照用户输入的选项进行函数调用
		switch (input)
		{
			case 0:
				printf("Exit!Bye!\n");
				break;
			case 1:
				//先将该结构体内所有元素置零
				memset(al[number].name, NUL, sizeof(al[number].name));
				memset(al[number].sex, NUL, sizeof(al[number].sex));
				al[number].age = 0;
				memset(al[number].phnum, NUL, sizeof(al[number].phnum));
				memset(al[number].addr, NUL, sizeof(al[number].addr));

				AddContacts(&al[number]);
				number++;
				
				break;
			case 2:
				ShowAllContacts(al, number);//先给出所有联系人的名单
				printf("Please input the number which you like to delete:> ");
				int num = 0;
				scanf("%d", &num);
				
				if (num > 0 && num < number)//在进行调用函数前先判断一下输入的数字是否存在
				{
					DeleteContacts(&al[num]);
					printf("Delete Success !\n");
					ShowAllContacts(al, number);
				}
				else
					printf("Sorry! Didn't find!\n");
	
				//删除该联系人后将会出现空位，则将该联系人后面的联系人都往前移一位
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
				
				//在所有已经保存的联系人里寻找是否有名字为name的联系人
				for (i = 0; i < number; i++)
				{
					if (strcmp(al[i].name, name) == 0)
					{
						printf("\tName\tSex\tAge\tPhoneNumber\tAddress\n");
						SearchContacts(&al[i], i);
						flag = 1;//只要找到一个就把flag改为1
					}
				}
				if (0 == flag)//若没有找到，则打印提示信息
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
				//如果没有联系人，直接break
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
