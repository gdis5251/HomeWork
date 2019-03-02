#include "Sort.h"

int main(void)
{
	int array[] = { 4, 5, 3, 7, 6, 8, 9, 1 };
	int size = sizeof(array) / sizeof(int);
	
	HeapSort(array, size);

	PrintArray(array, size);

	system("pause");
	return 0;
}