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


	//查找数据
	int ret = SeqListFind(&seqlist, 4);
	//打印
	SeqListPrint(&seqlist);
	//排序
	SeqListBubbleSort(&seqlist);
	SeqListPrint(&seqlist);
	//1 2 3 4 4 4 7 7 8
	//修改
	SeqListModify(&seqlist, 10, 3);
	SeqListPrint(&seqlist);

	//二分查找
	int ret1 = SeqListBinaryFind(&seqlist, 8);
	//8





	//删除数据
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