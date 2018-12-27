#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int DLDataType; //代表链表中值的类型

//链表结点实体
typedef struct DListNode
{
	DLDataType value;				//链表结点的值
	struct DListNode *prev;		//代表上一个结点
	struct DListNode *next;		//代表下一个结点
}	DListNode;

//头结点实体
typedef struct DList
{
	struct DListNode *head;
}	DList;



//初始化
void DListInit(DList *dlist);

//清零
void DListClear(DList *dlist);
//销毁
void DListDestory(DList *dlist);


//插入
//头插
void DListPushFront(DList *dlist, DLDataType value);
//尾插
void DListPushBack(DList *dlist, DLDataType value);
//在pos前插入
void DListInsertFront(DListNode *pos, DLDataType value);
//在pos后插入
void DListInsertBack(DListNode *pos, DLDataType value);


//查找
//找第一个值为value的结点，若找到返回pos的地址，若没有找到返回NULL
DListNode *DListSearch(DList *dlist, DLDataType value);



//删除
//头删
void DListPopFront(DList *dlist);
//尾删
void DListPopBack(DList *dlist);
//删除pos后的结点
void DListEreasePos(DListNode *pos);
//删除所有值为value的结点
void DListRemoveAll(DList *dlist, DLDataType value);

//打印
void DListPrint(DList *dlist);