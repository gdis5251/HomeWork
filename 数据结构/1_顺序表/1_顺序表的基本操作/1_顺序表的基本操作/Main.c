#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

/*
** �˳���������˳���Ĳ���������ϰ
** ��ʼ�������١�����ɾ���顢��
** ���ķ�
** 2018/12/21
*/

void testSeqList1()
{
	SeqList seqlist;
	
	SeqListInit(&seqlist);

	//��������
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 7);
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 7);
	SeqListPushFornt(&seqlist, 1);
	SeqListPushFornt(&seqlist, 2);
	SeqListInsert(&seqlist, 8, 2);
	//2 1 8 4 7 4 3 4 7

	//ɾ������
	SeqListPopFront(&seqlist);
	//1 8 4 7 4 3 4 7
	SeqListPopBack(&seqlist);
	//1 8 4 7 4 3 4    
	SeqListErase(&seqlist, 1);
	//1 4 7 4 3 4
	SeqListRemove(&seqlist, 3);
	//1 4 7 4 4
	SeqListRemoveAll(&seqlist, 4);
	//1 7


	SeqListDestory(seqlist.array);
}

int main(void)
{
	
	testSeqList1();

	return 0;
}