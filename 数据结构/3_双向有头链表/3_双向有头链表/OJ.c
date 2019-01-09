#define _CRT_SECURE_NO_WARNINGS 1
#include "OJ.h"


//逆置单链表
ListNode *reverseList(ListNode *head)
{
	if (head == NULL)
		return NULL;

	struct ListNode *new_head = NULL;
	struct ListNode *cur = NULL;
	//头删和头插
	while (head != NULL)
	{
		//头删
		cur = head;
		head = head->next;

		//头插
		cur->next = new_head;
		new_head = cur;

	}

	return new_head;
}




//合并两个有序链表
ListNode *mergeOrderedList(ListNode *l1, ListNode *l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;


	struct ListNode *curA = l1;
	struct ListNode *curB = l2;
	struct ListNode *curN = NULL;
	struct ListNode *new_head = NULL;

	//比较cur1和cur2
	//将更小的放进new_head进行尾插
	//如果两个值一样先放curA的
	while (curA != NULL && curB != NULL)
	{
		if (curA->value <= curB->value)
		{
			if (curN == NULL)
			{
				curN = curA;
				new_head = curN;
			}
			else
			{
				curN->next = curA;
				curN = curN->next;
			}

			curA = curA->next;

		}
		else//curB的值小于curA的值
		{
			if (curN == NULL)
			{
				curN = curB;
				new_head = curN;
			}
			else
			{
				curN->next = curB;
				curN = curN->next;
			}

			curB = curB->next;

		}
	}

	if (curA == NULL)
		curN->next = curB;
	else if (curB == NULL)
	{
		curN->next = curA;
	}

	return new_head;
}

// 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
ListNode* partition(ListNode* pHead, int x) {
	// write code here
	if (pHead == NULL)
		return NULL;

	struct ListNode *curLT = pHead;
	struct ListNode *curGT = pHead;
	struct ListNode *cur = pHead;
	struct ListNode *gTHead = NULL;
	struct ListNode *new_head = NULL;


	while (cur)
	{
		if (cur->val < x)
		{
			if (new_head == NULL)
			{
				new_head = cur;
				curLT = cur;
			}
			else
			{
				curLT->next = cur;
				curLT = cur;
			}
			cur = cur->next;
		}
		else
		{
			if (gTHead == NULL)
			{
				gTHead = cur;
				curGT = cur;
			}
			else
			{
				curGT->next = cur;
				curGT = cur;
			}
			cur = cur->next;
		}
	}
	if (gTHead == NULL)
		curLT->next = NULL;
	else if (new_head == NULL)
	{
		new_head = gTHead;
		curGT->next = NULL;
	}
	else
	{
		curGT->next = NULL;
		curLT->next = gTHead;
	}

	return new_head;
}


//删除重复结点
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *prev = NULL;	// 用于删除的结点，是 p1 的前一个结点
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;
	ListNode *result = pHead;		// 用于返回的第一个结点

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}

			// 删除
			ListNode *next;
			for (ListNode *node = p1; node != p2; node = next) {
				next = node->next;
				free(node);
			}

			// 重新拼接链表
			if (prev != NULL) {
				prev->next = p2;
			}
			else {
				// 1 --> 1 --> 1 --> 2 --> NULL
				// 的情况
				result = p2;
			}

			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;
			}
		}
	}
	return result;
}