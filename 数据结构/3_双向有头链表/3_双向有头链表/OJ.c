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



// 删除链表中等于给定值 val 的所有节点
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL)
		return NULL;

	struct ListNode *cur = head;
	struct ListNode *prev = head;
	struct ListNode *next = NULL;

	while (cur != NULL)
	{
		//当头结点是要删除的结点时
		if (head->val == val)
		{
			//如果这个链表只有一个结点且是要删除的结点时
			if (head->next == NULL)
			{
				free(head);
				head = NULL;
				return NULL;
			}
			next = head->next;
			free(head);
			head = next;
			cur = head;
			continue;
		}
		else if (cur->val == val)
		{
			next = cur->next;
			free(cur);
			prev->next = next;
			cur = prev;
		}

		prev = cur;
		if (cur != NULL)
			cur = cur->next;
	}

	return head;
}




//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
struct ListNode* middleNode(struct ListNode* head) {
	if (head == NULL)
		return NULL;

	struct ListNode *prev = head;
	struct ListNode *cur = head;

	while (cur != NULL)
	{
		if (prev->next == NULL)
			return prev;
		prev = prev->next;

		cur = cur->next->next;
		if (cur == NULL || cur->next == NULL)
			return prev;
	}

	return prev;
}





//输入一个链表，输出该链表中倒数第k个结点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL)
		return NULL;

	ListNode *cur = pListHead;
	unsigned int count = 0;

	//统计一共有多少个结点
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}

	if (k > count)
		return NULL;

	cur = pListHead;
	while (count - k)
	{
		cur = cur->next;
		count--;
	}

	return cur;
}




//链表的回文结构 
//C++语法，用到了栈
bool chkPalindrome(ListNode* A) {
	if (A == NULL)
		return true;

	stack<int> st;

	ListNode *cur = A;

	while (cur != NULL)
	{
		if (st.empty())
		{
			st.push(cur->val);
		}
		else
		{
			if (st.top() == cur->val)
				st.pop();
			else
				st.push(cur->val);
		}

		cur = cur->next;
	}

	if (st.empty())
		return true;

	return false;
}