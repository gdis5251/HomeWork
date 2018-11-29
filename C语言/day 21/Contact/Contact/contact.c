#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"



//��ʼ���ṹ��
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






//����ڴ治����Ҫ��������
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


//���ļ��ﱣ�������ϵ�ˣ��������
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
			ct->cap = INIT - (ct->size % INIT);//������ʣ�� INIT - (ct->size % INIT)
		}


		if (0 < ct->size)
		{
			re_code_ = fread(ct->people, sizeof(people_t), ct->size, fp);
			if (ct->size == re_code_)//�ж϶����ļ����ǲ��������˳�
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




//�����ϵ��
void addPeople(contact_p ct, people_p cp)
{
	assert(ct && cp);

	cp = cp + (ct->size);//������������Գ���д�룬�������ݸ��ǵ����

	

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





//ɾ��ĳ����ϵ�ˣ����г�������ϵ�ˣ��ڹ��û���ѡ��ɾ���ĸ�
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
	else if (num_ != ct->size)//�����û�Ҫɾ������ϵ�˺����һ����ϵ��
	{
		people_t tmp = *(cp + num_ - 1);
		*(cp + num_ - 1) = *(cp + ct->size - 1);
		*(cp + ct->size - 1) = tmp;
	}

	ct->size--;//ֱ�������һ����ϵ��ʧȥ����

	printf("Delete Success!\n");

	return 0;
}






//����ĳ����ϵ�ˣ���Ψһ��ʶ�绰��ѡ��ɾ��˭
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






//����ĳ����ϵ�ˣ����г�������ϵ�ˣ��û�ѡ����Ϻ�
//�����û�ѡ����Ҫ�����ĸ�����
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
	
	cp = cp + num_ - 1;//��cp��λ����Ҫ�޸ĵ�Ԫ��

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






//�г�������ϵ��
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






//���������ϵ��
void emptyContact(contact_p ct)
{
	assert(ct);

	ct->size = 0;
	printf("Empty Contacts Success!\n");
}




//��qsort������ϵ�ˣ�����������
int strCmp(const void *x, const void *y)
{
	assert(x && y);


	return strcmp((char*)x,(char*)y);
}

void sortContact(contact_p ct, people_p cp)
{
	assert(ct && cp);

	//cp��һ���ṹ�����飬������qsort�ĵ���������Ҫ���ṹ��Ĵ�С
	qsort(cp, ct->size, sizeof(people_t), strCmp);

	listContact(ct, cp);
	
}




//��ͨѶ¼�����Ϣд�뵽�ļ���
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






//�ͷŶ�̬�������ڴ�
void destoryContact(contact_p ct)
{
	assert(ct);

	free(ct);
}
