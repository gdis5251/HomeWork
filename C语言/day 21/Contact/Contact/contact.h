#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>
#include <string.h>


#define NAME_SIZE 32
#define TEL_SIZE 16
#define ADDR_SIZE 128

#define INIT 8

#define NUL '\0'




typedef struct people
{
	char name[NAME_SIZE];
	char sex;
	unsigned char age;
	char tel[TEL_SIZE];
	char addr[ADDR_SIZE];
}people_t, *people_p, **people_pp;

typedef struct contact
{
	int cap;
	int size;
	people_t people[0];
}contact_t, *contact_p, **contact_pp;





contact_p initContact();
contact_p getMemory(contact_p ct);
contact_p loadContact(contact_p ct);
void addPeople(contact_p ct, people_p cp);
int deletePeople(contact_p ct, people_p cp);
int searchPeople(contact_p ct, people_p cp);
int updatePeople(contact_p ct, people_p cp);
int listContact(contact_p ct, people_p cp);
void emptyContact(contact_p ct);
void sortContact(contact_p ct, people_p cp);
void writeFile(contact_p ct, people_p cp);
void destoryContact(contact_p ct);






#endif //_CONTACT_H_