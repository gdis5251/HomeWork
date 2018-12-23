#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>

void SeqListInit(SeqList *seqlist)
{


	seqlist->array = (SDataType *)malloc(sizeof(SeqList) * CAP);
	if (!seqlist)
	{
		printf("malloc error!\n");
		exit(EXIT_FAILURE);
	}

	seqlist->cap = CAP;
	seqlist->size = 0;

}




void SeqListDestory(SDataType *array)
{
	assert(array);

	free(array);
	array = NULL;

}




void IncreaseCapacity(SeqList *seqlist)
{
	assert(seqlist);

	//调用此函数的时候应确定要扩容
	seqlist = realloc(seqlist, sizeof(SeqList) * (2 * seqlist->cap));
	if (!seqlist)
	{
		printf("realloc error\n");
		exit(EXIT_FAILURE);
	}

	seqlist->cap *= 2;
}




void SeqListPushFornt(SeqList *seqlist, SDataType x)
{
	assert(seqlist);

	if (!seqlist->size)
	{
		seqlist->array[0] = x;
		seqlist->size++;
		return;
	}

	if (seqlist->size == seqlist->cap)
	{
		IncreaseCapacity(seqlist);
	}

	//i表示空间下标
	//将所有数据向后移一位
	for (int i = seqlist->size; i > 0; i--)
	{
		seqlist->array[i] = seqlist->array[i - 1];
	}

	seqlist->array[0] = x;
	seqlist->size++;
	
}




void SeqListPushBack(SeqList *seqlist, SDataType x)
{
	assert(seqlist);

	if (seqlist->size == seqlist->cap)
	{
		IncreaseCapacity(seqlist);
	}

	seqlist->array[seqlist->size] = x;
	seqlist->size++;

}




void SeqListInsert(SeqList *seqlist, SDataType x, size_t pos)
{
	assert(seqlist);

	if (seqlist->size == seqlist->cap)
	{
		IncreaseCapacity(seqlist);
	}
	//i表示空间下标
	//将pos以及之后的所有数据将后移一位
	for (size_t i = seqlist->size; i > pos; i--)
	{
		seqlist->array[i] = seqlist->array[i - 1];
	}

	seqlist->array[pos] = x;
	seqlist->size++;
}




void SeqListPopFront(SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);

	//i表示空间下标
	for (int i = 0; i < seqlist->size - 1; i++)
	{
		seqlist->array[i] = seqlist->array[i + 1];
	}

	seqlist->size--;
}




void SeqListPopBack(SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);

	seqlist->size--;
}




void SeqListErase(SeqList *seqlist, size_t pos)
{
	assert(seqlist);
	assert(seqlist->array);

	//i表示空间下标
	for (int i = pos; i < seqlist->size - 1; i++)
	{
		seqlist->array[i] = seqlist->array[i + 1];
	}

	seqlist->size--;
}




void SeqListRemove(SeqList *seqlist, SDataType x)
{
	assert(seqlist);
	assert(seqlist->array);

	for (int i = 0; i < seqlist->size; i++)
	{
		if (x == seqlist->array[i])
		{
			SeqListErase(seqlist, i);
			return;
		}
	}
}





void SeqListRemoveAll(SeqList *seqlist, SDataType x)
{
	assert(seqlist);
	assert(seqlist->array);

	//创建一个新的内存块用来存放不是x元素的数据
	SeqList *new_seqlist = NULL;
	new_seqlist = (SeqList *)malloc(sizeof(SeqList));
	if (!new_seqlist)
	{
		printf("malloc new_seqlist error\n");
		exit(EXIT_FAILURE);
	}

	new_seqlist->array = (SDataType *)malloc(sizeof(SeqList) * seqlist->cap);
	if (!new_seqlist->array)
	{
		printf("malloc array error\n");
		exit(EXIT_FAILURE);
	}


	int index = 0;
	int size = seqlist->size;

	//将所有不是x数据的元素搬到另一个新的内存块中
	for (int i = 0; i < size; i++)
	{
		if (x != seqlist->array[i])
		{
			new_seqlist->array[index] = seqlist->array[i];
			index++;
		}
		else
			seqlist->size--;

	}

	SeqListDestory(seqlist->array);

	seqlist->array = new_seqlist->array;

}