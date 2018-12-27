#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int DLDataType; //����������ֵ������

//������ʵ��
typedef struct DListNode
{
	DLDataType value;				//�������ֵ
	struct DListNode *prev;		//������һ�����
	struct DListNode *next;		//������һ�����
}	DListNode;

//ͷ���ʵ��
typedef struct DList
{
	struct DListNode *head;
}	DList;



//��ʼ��
void DListInit(DList *dlist);

//����
void DListClear(DList *dlist);
//����
void DListDestory(DList *dlist);


//����
//ͷ��
void DListPushFront(DList *dlist, DLDataType value);
//β��
void DListPushBack(DList *dlist, DLDataType value);
//��posǰ����
void DListInsertFront(DListNode *pos, DLDataType value);
//��pos�����
void DListInsertBack(DListNode *pos, DLDataType value);


//����
//�ҵ�һ��ֵΪvalue�Ľ�㣬���ҵ�����pos�ĵ�ַ����û���ҵ�����NULL
DListNode *DListSearch(DList *dlist, DLDataType value);



//ɾ��
//ͷɾ
void DListPopFront(DList *dlist);
//βɾ
void DListPopBack(DList *dlist);
//ɾ��pos��Ľ��
void DListEreasePos(DListNode *pos);
//ɾ������ֵΪvalue�Ľ��
void DListRemoveAll(DList *dlist, DLDataType value);

//��ӡ
void DListPrint(DList *dlist);