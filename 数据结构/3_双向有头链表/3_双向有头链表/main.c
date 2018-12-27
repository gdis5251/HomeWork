#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

void TestDList1(void)
{
	DList dlist;
	DListInit(&dlist);

	DListPushFront(&dlist, 1);
	DListPushFront(&dlist, 2);
	DListPushFront(&dlist, 3);
	DListPrint(&dlist);
	//3 2 1
	DListPushBack(&dlist, 7);
	DListPushBack(&dlist, 8);
	DListPushBack(&dlist, 9);
	DListPrint(&dlist);
	//3 2 1 7 8 9

	DListNode *pos = DListSearch(&dlist, 7);
	DListInsertFront(pos, 10);
	DListInsertBack(pos, 11);
	DListPrint(&dlist);
	//3 2 1 10 7 11 8 9

	DListPopFront(&dlist);
	DListPopBack(&dlist);
	DListEreasePos(pos);
	DListPrint(&dlist);
	//2 1 10 7 8

	DListPushBack(&dlist, 10);
	DListPushBack(&dlist, 8);
	DListPushBack(&dlist, 10);
	DListRemoveAll(&dlist, 10);
	DListPrint(&dlist);
	//2 1 7 8 8


}

int main(void)
{
	TestDList1();

	system("pause");
	return 0;

}