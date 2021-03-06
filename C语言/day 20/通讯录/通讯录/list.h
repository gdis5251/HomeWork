#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>


#define NUL '\0'


struct AddressList
{
	char name[20];
	char sex[5];
	int  age;
	char phnum[12];
	char addr[50];
}al[1000];


void AddContacts(struct AddressList *p);
void DeleteContacts(struct AddressList *p);
void SearchContacts(struct AddressList *p, int n);
void ModifyContacts(struct AddressList *p, int n);
void ShowAllContacts(struct AddressList *p, int n);
void DeleteAllContacts(struct AddressList *p, int n);
void SortAllContacts(struct AddressList *p, int n);
void SaveContactsToFile(struct AddressList *p, int n);
int LoadContacts(struct AddressList *p, int n);


#endif //__LIST_H_