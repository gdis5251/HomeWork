#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1. ˳����ͷ��
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

	//���������������һλ
	int i = 1;//i��ʾ�ռ��±�
	for (i = vector->size; i > 0; i--)
	{
		vector->array[i] = vector->array[i - 1];
	}

	//��Ҫ��������ݷŵ���һλ�ͺ�
	vector->array[0] = val;
	vector->size++;

}



//2. ����βɾ
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
	
	//�ҵ������ڶ������
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}

	end = cur->next;
	cur->next = NULL;

	free(end);
	end = NULL;

}



//3. ����ɾ������Val
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


//4. ð������
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



//5. ����������
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
	
	//����һ���ȳ�����ÿ��������ԭ����ÿ������
	while (cur != NULL)
	{
		struct RandomListNode *node = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
		node->random = NULL;
		node->label = cur->label;

		//��������ÿ��������ԭ����Ľ���
		node->next = cur->next;
		cur->next = node;

		cur = node->next;
	}

	//����random
	cur = head;
	while (cur != NULL)
	{
		struct RandomListNode *next = cur->next;

		//����random
		if (cur->random != NULL)
			next->random = cur->random->next;

		cur = next->next;

	}


	//����������
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

