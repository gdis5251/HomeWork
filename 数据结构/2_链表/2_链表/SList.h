#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>

typedef int SLTDataType;

typedef struct SList
{
	int value;
	struct SList *next;
}	SList;




//��ʼ��
void SListInit(SList **first);
//����
void SListDestory(SList **first);


//����һ���½��
static SList *BuySlistNode(SLTDataType value);

//����
//ͷ��
void SListPushFront(SList **first, SLTDataType value);
//β��
void SListPushBack(SList **first, SLTDataType value);
//���±�Ϊpos������в���
void SListInsertAfter(SList **pos, SLTDataType value);

//����
SList *SListFind(SList **finder, SLTDataType value);

//ɾ��
//ͷɾ
void SListPopFront(SList **first);
//βɾ
void SListPopBack(SList **first);
//ɾ��ֵΪvalue�ĵ�һ�����
void SListRemove(SList **first, SLTDataType value);




//��ӡ
void SListPrint(SList **first);