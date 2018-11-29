#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"



//初始化结构体
contact_p initContact()
{
	contact_p ct = (contact_p)malloc(sizeof(contact_t) +INIT * sizeof(people_t));

	if (!ct)
	{
		perror("malloc");
		return NULL;
	}

	ct->cap = INIT;
	ct->size = 0;

	return ct;
}






//如果内存不够需要进行扩容
contact_p getMemory(contact_p ct)
{
	contact_p p_ = realloc(ct, sizeof(contact_t) + sizeof(people_t) * INIT * (ct->size / INIT + 1));
	if (!p_)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	return p_;

}


//将文件里保存过得联系人，载入进来
contact_p loadContact(contact_p ct)
{
	assert(ct);

	unsigned int re_code_ = 0;
	unsigned int n_ = 0;
	
	FILE *fp = fopen("Contacts.txt", "rb");
	
	if (NULL != fp)
	{

		fseek(fp, 0, SEEK_END);
		ct->size = ftell(fp) / sizeof(people_t);
		rewind(fp);

		ct->cap = INIT - (ct->size);

		if (ct->size > INIT)
		{
			
			ct = getMemory(ct);
			ct->cap = INIT - (ct->size % INIT);//容量还剩下 INIT - (ct->size % INIT)
		}


		if (0 < ct->size)
		{
			re_code_ = fread(ct->people, sizeof(people_t), ct->size, fp);
			if (ct->size == re_code_)//判断读完文件后，是不是正常退出
			{
				printf("Loading Success!\n");
			}
			else
			{
				if (feof(fp))
				{
					printf("Error reading Contacts.txt bin: unexpected end of file\n");
				}
				else if (ferror(fp))
				{
					printf("Error reading Contacts.txt\n");
				}
			}

		}

		fclose(fp);

	}

	return ct;
}




//添加联系人
void addPeople(contact_p ct, people_p cp)
{
	assert(ct && cp);

	cp = cp + (ct->size);//让柔性数组可以持续写入，消除数据覆盖的情况

	

	printf("Please input name :> ");
	scanf("%s", cp->name);
	printf("please input sex(M or F) :> ");
	scanf(" %c", &cp->sex);
	printf("please input age :> ");
	scanf("%d", &cp->age);
	printf("please input telephone number :> ");
	scanf("%s", cp->tel);
	printf("please input address :> ");
	scanf("%s", cp->addr);

	
	ct->cap--;
	ct->size++;

	printf("Add Success!\n");

}





//删除某个联系人，先列出所有联系人，在供用户来选择删除哪个
int deletePeople(contact_p ct, people_p cp)
{
	assert(ct && cp);

	int num_ = 0;
	
	listContact(ct, cp);
	
	printf("Please choose the number which you like to delete:> ");
	scanf("%d", &num_);

	if (num_ < 1 || num_ > ct->size)
	{
		printf("Error Input! One More Try!");
		return EXIT_FAILURE;
	}
	else if (num_ != ct->size)//交换用户要删除的联系人和最后一个联系人
	{
		people_t tmp = *(cp + num_ - 1);
		*(cp + num_ - 1) = *(cp + ct->size - 1);
		*(cp + ct->size - 1) = tmp;
	}

	ct->size--;//直接让最后一个联系人失去意义

	printf("Delete Success!\n");

	return 0;
}






//查找某个联系人，用唯一标识电话来选择删除谁
int searchPeople(contact_p ct, people_p cp)
{
	assert(ct && cp);

	char tel[TEL_SIZE] = { NUL };
	int i_ = 0;

	printf("Please input the telephone number while you like to search:> ");
	scanf("%s", tel);

	for (i_ = 1; i_ <= ct->size; i_++)
	{
		if (0 == strcmp(tel, cp->tel))
		{
			printf("\tname     \tsex\tage\ttelephone_number\taddress\n");
			printf("No.%d\t%s     \t%c\t%d\t%s     \t%s\n", i_, cp->name, cp->sex, \
				cp->age, cp->tel, cp->addr);

			return 0;

		}
		cp++;
	}

	printf("Error input! One More Try!\n");

	return 1;
}






//更新某个联系人，先列出所有联系人，用户选择完毕后
//再让用户选择需要更改哪个属性
int updatePeople(contact_p ct, people_p cp)
{
	assert(ct && cp);

	int num_ = 0;
	int ch_ = 1;
	int quit_ = 1;

	listContact(ct, cp);

	printf("Please choose the number which you like to update:> ");
	scanf("%d", &num_);

	if (num_ < 1 || num_ > ct->size)
	{
		printf("Error Input! One More Try!");
		return EXIT_FAILURE;
	}
	
	cp = cp + num_ - 1;//将cp定位到需要修改的元素

	while (quit_)
	{	
		printf("######################################\n");
		printf("### 1. name    2. sex              ###\n");
		printf("### 3. age     4. telephone number ###\n");
		printf("### 5. address 0. do nothing       ###\n");
		printf("######################################\n");

		printf("Please choose property which you like to update:> ");
		scanf("%d", &ch_);

		if (ch_ > 0 && ch_ < 6)
			printf("Please input the value after update:> ");


		switch (ch_)
		{
			case 0:
				printf("Back Menu!\n");
				quit_ = 0;
				break;
			case 1:
				scanf("%s", cp->name);
				quit_ = 0;
				
				break;
			case 2:
				scanf("%c", &cp->sex);
				quit_ = 0;

				break;
			case 3:
				scanf("%d", &cp->age);
				quit_ = 0;

				break;
			case 4:
				scanf("%s", cp->tel);
				quit_ = 0;

				break;
			case 5:
				scanf("%s", cp->addr);
				quit_ = 0;

				break;
			default:
				printf("Error Input! One More Try!\n");
				break;
				
		}

	}

	if (ch_)
	{
		printf("Update Success!\n");
	}

	return 0;

}






//列出所有联系人
int listContact(contact_p ct, people_p cp)
{
	assert(ct && cp);

	int i_ = 0;

	if (0 == ct->size)
	{
		printf("Empty Contact!\n");
		return EXIT_FAILURE;
	}
	
	
	printf("\tname     \tsex\tage\ttelephone_number\taddress\n");
	for (i_ = 1; i_ <= ct->size; i_++)
	{
		printf("No.%d\t%s     \t%c\t%d\t%s     \t%s\n", i_, cp->name, cp->sex, \
			cp->age, cp->tel, cp->addr);

		cp++;
	}
	
	return 0;

}






//清空所有联系人
void emptyContact(contact_p ct)
{
	assert(ct);

	ct->size = 0;
	printf("Empty Contacts Success!\n");
}




//用qsort排序联系人，以名字排序
int strCmp(const void *x, const void *y)
{
	assert(x && y);


	return strcmp((char*)x,(char*)y);
}

void sortContact(contact_p ct, people_p cp)
{
	assert(ct && cp);

	//cp是一个结构体数组，所以在qsort的第三个参数要传结构体的大小
	qsort(cp, ct->size, sizeof(people_t), strCmp);

	listContact(ct, cp);
	
}




//将通讯录里的信息写入到文件中
void writeFile(contact_p ct, people_p cp)
{
	assert(ct && cp);

	FILE *fp = fopen("Contacts.txt", "wb");

	if (!fp)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	fwrite(cp, sizeof(people_t), ct->size, fp);

	fclose(fp);
}






//释放动态创建的内存
void destoryContact(contact_p ct)
{
	assert(ct);

	free(ct);
}
