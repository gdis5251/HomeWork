#pragma once

#include "HeapArray.h"

//�ѵĽṹ
typedef struct Heap
{
	int array[100];
	int size;
}	Heap;




//��ʼ��
void InitHeap(Heap *heap, int array[], int size)
{
	memmove(heap->array, array, size * sizeof(int));
	heap->size = size;
	CreateHeap(heap->array, heap->size);
}




//����
void HeapPush(Heap *heap, int val)
{
	heap->array[heap->size++] = val;

	AdjustUp(heap->array, heap->size, heap->size - 1);
}




//ɾ��
void HeapPop(Heap *heap)
{
	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;
	AdjustDown(heap->array, heap->size, 0);
}




//���ضѶ�Ԫ��
int HeapTop(Heap *heap)
{
	return heap->array[0];
}




void Test() {
	Heap heap;
	int array[] = { 15, 37, 2, 45, 63, 9, 18, 7, 16, 13 };
	int size = sizeof array / sizeof(int);
	InitHeap(&heap, array, size);

	PrintHeap(heap.array, heap.size);

	HeapPush(&heap, 99);

	PrintHeap(heap.array, heap.size);
}