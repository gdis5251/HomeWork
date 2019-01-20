#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//���ṹ
typedef struct Node
{
	int val;
	struct Node *next;
}	Node;


//���нṹ
typedef struct Queue
{
	Node *front;	//���׽��
	Node *rear;		//��βԪ��
	int size;		//Ԫ�ظ���
}	Queue;



//��ʼ��
void QueueInit(Queue *que)
{
	assert(que);

	que->front = NULL;
	que->rear = NULL;
	que->size = 0;
}




//����
void QueueDestory(Queue *que)
{
	assert(que);
	assert(que->size != 0);

	Node *node;
	Node *next;

	for (node = que->front; node != NULL; node = next)
	{
		next = node->next;
		free(node);
	}

	//��ֹҰָ�룬��ָ��ָ��NULL
	que->front = que->rear = NULL;
	que->size = 0;
	
}




//����һ�����
Node *BuyNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->val = val;
	node->next = NULL;

	return node;
}



//β�塢���
void QueuePushBack(Queue *que, int val)
{
	assert(que);

	Node *node = BuyNode(val);

	if (que->size == 0)
	{
		que->front = node;
	}
	else
	{
		que->rear->next = node;
	}


	que->rear = node;
	que->size++;

}



//����
void QueuePop(Queue *que)
{
	assert(que);
	assert(que->size > 0);

	Node *node = que->front;//��¼һ�¶��׽��
	
	que->front = que->front->next;
	if (que->front == NULL)
	{
		que->rear = NULL;
	}
	que->size--;

	free(node);
	node = NULL;
}



//���ض���Ԫ��
int QueueFrontValue(Queue *que)
{
	assert(que);

	return que->front->val;
}




//���ض�βԪ��
int QueueBackValue(Queue *que)
{
	assert(que);

	return que->rear->val;
}



//�Ƿ�Ϊ��
int QueueEmpty(Queue *que)
{
	return que->size == 0 ? 1 : 0;
}



//���д�С
int QueueSize(Queue *que)
{
	return que->size;
}