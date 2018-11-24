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

}

void DeleteContacts(struct AddressList *p)
{
	//p->name = NUL;
	//p->sex = NUL;
	
}