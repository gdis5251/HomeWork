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





