#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>

typedef int SLTDataType;

typedef struct SList
{
	int value;
	struct SList *next;
}	SList;




//初始化
void SListInit(SList **first);
//销毁
void SListDestory(SList **first);


//开辟一个新结点
static SList *BuySlistNode(SLTDataType value);

//插入
//头插
void SListPushFront(SList **first, SLTDataType value);
//尾插
void SListPushBack(SList **first, SLTDataType value);
//在下标为pos后面进行插入
void SListInsertAfter(SList **pos, SLTDataType value);

//查找
SList *SListFind(SList **finder, SLTDataType value);

//删除
//头删
void SListPopFront(SList **first);
//尾删
void SListPopBack(SList **first);
//删除值为value的第一个结点
void SListRemove(SList **first, SLTDataType value);




//打印
void SListPrint(SList **first);