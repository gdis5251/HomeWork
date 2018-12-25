#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
#include <assert.h>
#include <stdlib.h>



void SListInit(SList **first)
{
	assert(first);

	*first = NULL;
}




void SListDestory(SList **first)
{
	assert(first);

	SList *next = NULL;
	
	while (first)
	{
		next = (*first)->next;
		free((*first));
		(*first) = next;
	}

	first = NULL;
}




SList *BuySlistNode(SLTDataType value)
{
	SList *node = (SList *)malloc(sizeof(SList));
	if (!node)
	{
		printf("Malloc Node Error!\n");
		exit(EXIT_FAILURE);
	}


	node->value = value;
	node->next = NULL;

	return node;
}




void SListPushFront(SList **first, SLTDataType value)
{

	SList *node = BuySlistNode(value);

	if (!(*first))
	{
		(*first) = node;
		return;
	}

	node->next = (*first);
	(*first) = node;

}




void SListPushBack(SList **first, SLTDataType value)
{
	assert((*first) != NULL);

	SList *end = *first;
	//找到最后一个结点
	while (end->next)
	{
		end = end->next;
	}

	SList *node = BuySlistNode(value);
	end->next = node;
}






void SListPopFront(SList **first)
{
	assert((*first));

	SList *old_first = (*first);//创建一个结点来存储将要删除的结点

	(*first) = (*first)->next;

	free(old_first);
	old_first = NULL;
}




void SListPopBack(SList **first)
{
	assert(first);

	SList *LBO = *first;
	//找到倒数第二个结点
	while (LBO->next->next)
	{
		LBO = LBO->next;
	}

	SList *old_node = LBO->next;

	LBO->next = NULL;

	free(old_node);
	old_node = NULL;
}




void SListRemove(SList **first, SLTDataType value)
{
	assert(first);

	//如果第一个值就是要找的值，调用头删直接删
	if (value == (*first)->value)
	{
		SListPopFront(first);
		return;
	}

	SList *target = *first;

	while (target->next)
	{
		if (value == target->next->value)
		{
			SListPopFront(&target->next);
			return;
		}

		target = target->next;
	}

}




void SListPrint(SList **first)
{
	assert(first);

	SList *node = *first;
	while (node)
	{
		printf("%d ", node->value);

		node = node->next;
	}
	printf("\n");
}




SList *SListFind(SList **first, SLTDataType value)
{
	assert(first);
	assert(*first);

	SList *finder = *first;

	while (finder)
	{
		if (finder->value == value)
			return finder;

		finder = finder->next;
	}

	return NULL;
}




void SListInsertAfter(SList **pos, SLTDataType value)
{
	assert(pos);
	assert(*pos);
	
	SList *loc = *pos;
	SList *node = BuySlistNode(value);

	node->next = loc->next;
	loc->next = node;


}






