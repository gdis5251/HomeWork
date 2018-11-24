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
