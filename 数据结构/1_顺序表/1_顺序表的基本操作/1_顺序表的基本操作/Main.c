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


	//��������
	int ret = SeqListFind(&seqlist, 4);
	//��ӡ
	SeqListPrint(&seqlist);
	//����
	SeqListBubbleSort(&seqlist);
	SeqListPrint(&seqlist);
	//1 2 3 4 4 4 7 7 8
	//�޸�
	SeqListModify(&seqlist, 10, 3);
	SeqListPrint(&seqlist);

	//���ֲ���
	int ret1 = SeqListBinaryFind(&seqlist, 8);
	//8





	//ɾ������
	SeqListPopFront(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListErase(&seqlist, 1);
	SeqListRemove(&seqlist, 3);
	SeqListRemoveAll(&seqlist, 4);


	SeqListDestory(seqlist.array);
}

int main(void)
{
	
	testSeqList1();

	return 0;
}