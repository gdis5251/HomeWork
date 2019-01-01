#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1. 顺序表的头插
struct Vector
{
	int array[100];
	int size;
};

void vectorPushFront(struct Vector *vector, int val)
{
	if (vector->size == 0)
	{
		vector->array[vector->size] = val;
		vector->size++;
	}

	//将所有数据向后移一位
	int i = 1;//i表示空间下标
	for (i = vector->size; i > 0; i--)
	{
		vector->array[i] = vector->array[i - 1];
	}

	//将要插入的数据放到第一位就好
	vector->array[0] = val;
	vector->size++;

}



//2. 链表尾删
struct SListNode {
	int val;
	struct SListNode *next;
};

struct SList {
	struct SListNode *head;
};

void SListPopBack(struct SList *slist)
{
	if (slist->head == NULL)
	{
		return;
	}
	if (slist->head->next = NULL)
	{
		free(slist->head);

		slist->head = NULL;
		return;
	}

	struct SListNode *cur = slist->head;
	struct SListNode *end = NULL;
	
	//找到倒数第二个结点
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}

	end = cur->next;
	cur->next = NULL;

	free(end);
	end = NULL;

}



//3. 链表删除所有Val
struct SListNode* SListRemoveAll(struct SList *slist, int val)
{
	if (slist->head == NULL)
		return NULL;

	struct SListNode *cur = slist->head;
	struct SListNode *prev = NULL;

	while (cur != NULL)
	{
		if (cur->val == val)
		{
			struct SListNode *next = cur->next;

			if (prev == NULL)
			{
				free(cur);
				cur = next;
				slist->head = cur;
			}
			else
			{
				prev->next = next;

				free(cur);
				cur = next;
			}
		}
		else
		{
			prev = cur;
			if (cur != NULL)
				cur = cur->next;
		}
		
	}

	return slist->head;
}


//4. 冒泡排序
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(int array[], int size)
{
	int end = 0;
	int i = 0;

	for (end = size - 1; end > 0; end--)
	{
		for (i = 0; i < end; i++)
		{
			if (array[i] > array[i + 1])
				swap(&array[i], &array[i + 1]);
		}
	}
}



//5. 复杂链表复制
struct RandomListNode
{
	int label;
	struct RandomListNode *random;
	struct RandomListNode *next;

};


struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
	if (head == NULL)
		return NULL;

	struct RandomListNode *cur = head;
	
	//创建一个等长链表，每个结点放在原链表每个结点后
	while (cur != NULL)
	{
		struct RandomListNode *node = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
		node->random = NULL;
		node->label = cur->label;

		//将创建的每个结点放在原链表的结点后
		node->next = cur->next;
		cur->next = node;

		cur = node->next;
	}

	//复制random
	cur = head;
	while (cur != NULL)
	{
		struct RandomListNode *next = cur->next;

		//复制random
		if (cur->random != NULL)
			next->random = cur->random->next;

		cur = next->next;

	}


	//拆开两个链表
	cur = head;
	struct RandomListNode *new_head = head->next;
	while (cur != NULL)
	{
		struct RandomListNode *node = cur->next;

		cur->next = node->next;
		if (node->next != NULL)
		{
			node->next = cur->next->next;
		}

		cur = cur->next;
	}

	return new_head;

}

