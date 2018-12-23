#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

/*
** 此程序用来对顺序表的操作进行练习
** 初始化、销毁、增、删、查、改
** 郭文峰
** 2018/12/21
*/

void testSeqList1()
{
	SeqList seqlist;
	
	SeqListInit(&seqlist);

	//插入数据
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

	//删除数据
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