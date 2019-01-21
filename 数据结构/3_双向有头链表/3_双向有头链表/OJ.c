#define _CRT_SECURE_NO_WARNINGS 1
#include "OJ.h"


//���õ�����
ListNode *reverseList(ListNode *head)
{
	if (head == NULL)
		return NULL;

	struct ListNode *new_head = NULL;
	struct ListNode *cur = NULL;
	//ͷɾ��ͷ��
	while (head != NULL)
	{
		//ͷɾ
		cur = head;
		head = head->next;

		//ͷ��
		cur->next = new_head;
		new_head = cur;

	}

	return new_head;
}




//�ϲ�������������
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

	//�Ƚ�cur1��cur2
	//����С�ķŽ�new_head����β��
	//�������ֵһ���ȷ�curA��
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
		else//curB��ֵС��curA��ֵ
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

// ��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
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


//ɾ���ظ����
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *prev = NULL;	// ����ɾ���Ľ�㣬�� p1 ��ǰһ�����
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;
	ListNode *result = pHead;		// ���ڷ��صĵ�һ�����

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

			// ɾ��
			ListNode *next;
			for (ListNode *node = p1; node != p2; node = next) {
				next = node->next;
				free(node);
			}

			// ����ƴ������
			if (prev != NULL) {
				prev->next = p2;
			}
			else {
				// 1 --> 1 --> 1 --> 2 --> NULL
				// �����
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



// ɾ�������е��ڸ���ֵ val �����нڵ�
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL)
		return NULL;

	struct ListNode *cur = head;
	struct ListNode *prev = head;
	struct ListNode *next = NULL;

	while (cur != NULL)
	{
		//��ͷ�����Ҫɾ���Ľ��ʱ
		if (head->val == val)
		{
			//����������ֻ��һ���������Ҫɾ���Ľ��ʱ
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




//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���
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





//����һ����������������е�����k�����
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL)
		return NULL;

	ListNode *cur = pListHead;
	unsigned int count = 0;

	//ͳ��һ���ж��ٸ����
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




//����Ļ��Ľṹ 
//C++�﷨���õ���ջ
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