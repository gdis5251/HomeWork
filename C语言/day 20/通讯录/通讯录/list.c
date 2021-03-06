#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

void AddContacts(struct AddressList *p)
{
	printf("Please input contact name:>");
	scanf("%s", p->name);
	printf("Please input contact sex:>");
	scanf("%s", p->sex);
	printf("Please input contact age:>");
	scanf("%d", &p->age);
	printf("Please input contact phone number:>");
	scanf("%s", p->phnum);
	printf("Please input contact address:>");
	scanf("%s", p->addr);

	printf("Add Success!\n");
}

void DeleteContacts(struct AddressList *p)
{
	*p->name = NUL;
	*p->sex = NUL;
	p->age = 0;
	*p->phnum = NUL;
	*p->addr = NUL;
}

void SearchContacts(struct AddressList *p, int n)
{
	printf("No.%d\t%s\t%s\t%d\t%s\t%s\n", n, p->name, p->sex, p->age, \
		p->phnum, p->addr);
}

void ModifyContacts(struct AddressList *p, int n)
{
	printf("Please input contact name:>");
	scanf("%s", p->name);
	printf("Please input contact sex:>");
	scanf("%s", p->sex);
	printf("Please input contact age:>");
	scanf("%d", &p->age);
	printf("Please input contact phone number:>");
	scanf("%s", p->phnum);
	printf("Please input contact address:>");
	scanf("%s", p->addr);

	printf("\tName\t\tSex\tAge\tPhoneNumber\tAddress\n");
	printf("No.%d\t%s\t%s\t%d\t%s\t%s\n", n, p->name, p->sex, p->age, \
		p->phnum, p->addr);
}

void ShowAllContacts(struct AddressList *p, int n)
{
	int i_ = 0;
	for (i_ = 1; i_ < n; i_++)
	{
		printf("No.%d\t%s\t%s\t%d\t%s\t%s\n", i_, p[i_].name, p[i_].sex,\
			p[i_].age, p[i_].phnum, p[i_].addr);

	}
}

void DeleteAllContacts(struct AddressList *p, int n)
{
	int i = 0;
	for (i = 1; i < n; i++)
	{
		memset(p[i].name, NUL, sizeof(p[i].name));
		memset(p[i].sex, NUL, sizeof(p[i].sex));
		p[i].age = 0;
		memset(p[i].phnum, NUL, sizeof(p[i].phnum));
		memset(p[i].addr, NUL, sizeof(p[i].addr));
	}
}


void SortAllContacts(struct AddressList *p, int n)
{
	int i = 0;
	int j = 0;

	//ð����������
	for (i = 1; i < n - 1; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (strcmp(p[i].name, p[i + 1].name) > 0)
			{
				struct AddressList q = *(p + i);
				*(p + i) = *(p + i + 1);
				*(p + i + 1) = q;
			}
		}
	}
	
}

void SaveContactsToFile(struct AddressList *p, int n)
{
	FILE *pFile = fopen("AddressList.txt", "wb");
	if (pFile != NULL)
	{
		int i = 0;
		for (i = 1; i < n; i++)
		{
			fwrite(p + i, sizeof(struct AddressList), 1, pFile);

		}
		printf("Save Success!\n");
		fclose(pFile);
	}
}

int LoadContacts(struct AddressList *p, int n)
{
	FILE *pFile = fopen("AddressList.txt", "rb");
	if (pFile != NULL)
	{
		fseek(pFile, 0, SEEK_END);
		int size = ftell(pFile);
		rewind(pFile);
		int i = 0;
		int num = size / sizeof(struct AddressList);
		for (i = 1; i <= num; i++)
		{
			fread(p + i, sizeof(struct AddressList), 1, pFile);
		}
		printf("Loading Success!\n");
		printf("\tName\tSex\tAge\tPhoneNumber\tAddress\n");

		ShowAllContacts(p, num + 1);

		fclose(pFile);

		return num;
	}
	
}