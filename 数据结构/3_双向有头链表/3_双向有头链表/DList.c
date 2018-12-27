#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"


static DListNode *DListBuyNode(DLDataType value)
{
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	if (!node)
	{
		exit(EXIT_FAILURE);
	}

	node->value = value;
	node->prev = NULL;
	node->next = NULL;

	return node;
}




void DListInit(DList *dlist)
{
	dlist->head = DListBuyNode(0);//这里的0没有任何意义
	dlist->head->prev = dlist->head;
	dlist->head->next = dlist->head;

}




//这里将除头结点外其他结点全部free
void DListClear(DList *dlist)
{
	DListNode *cur = dlist->head->next;
	DListNode *next = NULL;

	//将head后的所有结点全部free
	while (cur != dlist->head)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}

	//改为初始状态头结点的next和prev都等于自身
	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}




//这里是将所有结点都销毁包括头结点
void DListDestory(DList *dlist)
{
	DListClear(dlist);

	free(dlist->head);
	dlist->head = NULL;
}




void DListPushFront(DList *dlist, DLDataType value)
{
	DListNode *node = DListBuyNode(value);

	node->next = dlist->head->next;
	node->prev = dlist->head;
	dlist->head->next->prev = node;
	dlist->head->next = node;
}




void DListPushBack(DList *dlist, DLDataType value)
{
	DListNode *node = DListBuyNode(value);

	DListNode *cur = dlist->head->prev;//定义一个cur结点指针来指向最后一个结点

	node->next = cur->next;
	node->prev = cur;
	cur->next = node;
	dlist->head->prev = node;
}




void DListInsertFront(DListNode *pos, DLDataType value)
{
	DListNode *node = DListBuyNode(value);

	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}




void DListInsertBack(DListNode *pos, DLDataType value)
{
	DListNode *node = DListBuyNode(value);

	node->next = pos->next;
	node->prev = pos;
	pos->next->prev = node;
	pos->next = node;
}




void DListPrint(DList *dlist)
{
	if (dlist->head->prev == dlist->head)
	{
		printf("NULL\n");
		return;
	}

	DListNode *cur = dlist->head->next;
	while (cur != dlist->head)
	{
		printf("%d-->", cur->value);
		cur = cur->next;
	}
	printf("head\n");
}




DListNode *DListSearch(DList *dlist, DLDataType value)
{
	DListNode *cur = dlist->head->next;

	while (cur->next != dlist->head)
	{
		if (cur->value == value)
			return cur;

		cur = cur->next;
	}

	//走到这说明没找到
	return NULL;
}




void DListPopFront(DList *dlist)
{
	DListNode *cur = dlist->head->next;

	dlist->head->next->next->prev = dlist->head;
	dlist->head->next = dlist->head->next->next;

	free(cur);
	cur = NULL;
}




void DListPopBack(DList *dlist)
{
	DListNode *cur = dlist->head->prev;

	dlist->head->prev->prev->next = dlist->head;
	dlist->head->prev = dlist->head->prev->prev;

	free(cur);
	cur = NULL;
}




void DListEreasePos(DListNode *pos)
{
	DListNode *cur = pos->next;

	pos->next->next->prev = pos;
	pos->next = pos->next->next;

	free(cur);
	cur = NULL;
}




void DListRemoveAll(DList *dlist, DLDataType value)
{
	DListNode *cur = dlist->head;

	while (cur->next != dlist->head)
	{
		cur = cur->next;

		if (cur->next->value == value)
			DListEreasePos(cur);
		
	}
}