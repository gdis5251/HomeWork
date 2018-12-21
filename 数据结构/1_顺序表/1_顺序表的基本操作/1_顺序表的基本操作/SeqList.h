#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define CAP 100 //起始容量为100

typedef int SDataType;
typedef unsigned int size_t;

typedef struct SeqList
{
	SDataType *array;//开辟一块内存用来存放一个顺序表
	int size;		 //用来记录顺序表的长度
					 //顺便也可以表示下一次插入数据的下标
	int cap;		 //用来限定顺序表的容量
} SeqList;

//初始化
//令容量cap为100，size为0，给array开辟cap个内存单元
void SeqListInit(SeqList *seqlist);

//销毁
void SeqListDestory(SeqList *seqlist);

//扩容
void CheckCapacity(SeqList *seqlist);

//增加
//头插
void SeqListPushFornt(SeqList *seqlist, SDataType x);
//尾插
void SeqListPushBack(SeqList *seqlist, SDataType x);
//中间插入
void SeqListInsert(SeqList *seqlist, SDataType x, size_t pos);

//删除
//头删
void SeqListPopFront(SeqList *seqlist);
//尾删
void SeqListPopBack(SeqList *seqlist);
//删除指定下标元素
void SeqListErase(SeqList *seqlist, size_t pos);
//删除第一个遇到的指定元素
void SeqListRemove(SeqList *seqlist, SDataType x);
//删除所有元素
void SeqListRemoveAll(SeqList *seqlist);

//查找
//查找第一个遇到的指定元素，若找到返回下标，否则返回-1
int SeqListFind(SeqList *seqlist, SDataType x);
//二分法查找
//要求：时间复杂度：O(N);空间复杂度O(1)
int SeqListBinaryFind(SeqList *seqlist, SDataType x);

//修改
void SeqListModify(SeqList *seqlist, SDataType x, size_t pos);

//打印
void SeqListPrint(SeqList *seqlist);

//排序
//此处使用冒泡排序
void SeqListBubbleSort(SeqList *seqlist);

