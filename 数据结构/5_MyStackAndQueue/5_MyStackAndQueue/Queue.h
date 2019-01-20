#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//结点结构
typedef struct Node
{
	int val;
	struct Node *next;
}	Node;


//队列结构
typedef struct Queue
{
	Node *front;	//队首结点
	Node *rear;		//队尾元素
	int size;		//元素个数
}	Queue;



//初始化
void QueueInit(Queue *que)
{
	assert(que);

	que->front = NULL;
	que->rear = NULL;
	que->size = 0;
}




//销毁
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

	//防止野指针，将指针指向NULL
	que->front = que->rear = NULL;
	que->size = 0;
	
}




//申请一个结点
Node *BuyNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->val = val;
	node->next = NULL;

	return node;
}



//尾插、入队
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



//出队
void QueuePop(Queue *que)
{
	assert(que);
	assert(que->size > 0);

	Node *node = que->front;//记录一下队首结点
	
	que->front = que->front->next;
	if (que->front == NULL)
	{
		que->rear = NULL;
	}
	que->size--;

	free(node);
	node = NULL;
}



//返回队首元素
int QueueFrontValue(Queue *que)
{
	assert(que);

	return que->front->val;
}




//返回队尾元素
int QueueBackValue(Queue *que)
{
	assert(que);

	return que->rear->val;
}



//是否为空
int QueueEmpty(Queue *que)
{
	return que->size == 0 ? 1 : 0;
}



//队列大小
int QueueSize(Queue *que)
{
	return que->size;
}