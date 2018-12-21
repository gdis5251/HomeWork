#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define CAP 100 //��ʼ����Ϊ100

typedef int SDataType;
typedef unsigned int size_t;

typedef struct SeqList
{
	SDataType *array;//����һ���ڴ��������һ��˳���
	int size;		 //������¼˳���ĳ���
					 //˳��Ҳ���Ա�ʾ��һ�β������ݵ��±�
	int cap;		 //�����޶�˳��������
} SeqList;

//��ʼ��
//������capΪ100��sizeΪ0����array����cap���ڴ浥Ԫ
void SeqListInit(SeqList *seqlist);

//����
void SeqListDestory(SeqList *seqlist);

//����
void CheckCapacity(SeqList *seqlist);

//����
//ͷ��
void SeqListPushFornt(SeqList *seqlist, SDataType x);
//β��
void SeqListPushBack(SeqList *seqlist, SDataType x);
//�м����
void SeqListInsert(SeqList *seqlist, SDataType x, size_t pos);

//ɾ��
//ͷɾ
void SeqListPopFront(SeqList *seqlist);
//βɾ
void SeqListPopBack(SeqList *seqlist);
//ɾ��ָ���±�Ԫ��
void SeqListErase(SeqList *seqlist, size_t pos);
//ɾ����һ��������ָ��Ԫ��
void SeqListRemove(SeqList *seqlist, SDataType x);
//ɾ������Ԫ��
void SeqListRemoveAll(SeqList *seqlist);

//����
//���ҵ�һ��������ָ��Ԫ�أ����ҵ������±꣬���򷵻�-1
int SeqListFind(SeqList *seqlist, SDataType x);
//���ַ�����
//Ҫ��ʱ�临�Ӷȣ�O(N);�ռ临�Ӷ�O(1)
int SeqListBinaryFind(SeqList *seqlist, SDataType x);

//�޸�
void SeqListModify(SeqList *seqlist, SDataType x, size_t pos);

//��ӡ
void SeqListPrint(SeqList *seqlist);

//����
//�˴�ʹ��ð������
void SeqListBubbleSort(SeqList *seqlist);

