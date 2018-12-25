#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
#include <windows.h>

void testSList()
{
	SList *first;
	//��ʼ��
	SListInit(&first);

	//����
	//ͷ��
	SListPushFront(&first, 5);
	SListPushFront(&first, 7);
	SListPushFront(&first, 1);
	SListPushFront(&first, 2);
	// 2 1 7 5
	
	//β��
	SListPushBack(&first, 4);
	SListPushBack(&first, 9);
	SListPushBack(&first, 2);
	SListPushBack(&first, 4);
	//2 1 7 5 4 9 2 4
	SListPrint(&first);
	
	//��7ǰ�������
	SList *pos = SListFind(&first, 7);
	//SListInsertBefore(&pos, 10);
	SListInsertAfter(&pos, 10);
	SListInsertAfter(&pos, 99);


	SListPrint(&first);


	SListPopBack(&first);
	SListPopFront(&first);
	SListRemove(&first, 5);
	SListPrint(&first);

}

int main(void)
{
	testSList();

	system("pause");
	return 0;
}