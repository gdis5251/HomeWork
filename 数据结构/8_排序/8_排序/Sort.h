#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ӡ����
void PrintArray(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", array[i]);
	}

	printf("\n");
}




//ֱ�Ӳ�������
//����һ����memmove���ƶ����Ƚ��鷳
void InsertSort1(int *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int k = array[i];	//��k����¼��ʱarray[i]��ֵ���Ա��ں����ƶ�

		int j = 0;
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] <= array[i])
			{
				memmove(array + j + 2, array + j + 1, (i - j - 1) * sizeof(int));
				array[j + 1] = k;
				break;
			}
		}

		//���j = -1 ˵����ʱ��array[i]��ǰ����κ�һ������С
		if (j == -1)
		{
			memmove(array + j + 2, array + j + 1, (i - j - 1) * sizeof(int));
			array[j + 1] = k;
		}
	}
}




//��������

//ʱ�临�Ӷ�
//��ã�O(N) (�Ѿ�����)
//ƽ����O(N^2)
//���O(N^2)  (�Ѿ�����������)

//�ռ临�Ӷ�
//O(1)
void InsertSort2(int *array, int size)
{
	//�����ѭ��ʵ�ּ��ι���
	//һ��ȡһ���������뵽ǰ�������������
	for (int i = 1; i < size; i++)
	{
		int k = array[i];
		
		//�ڲ�ѭ��ʵ�ֲ������
		//��[0,i)
		//���array[j] > k ,�����
		//���array[j] <= k ,����ѭ������֤�ȶ��ԣ�
		int j = 0;
		for (j = i - 1; j >= 0 && array[j] > k; j--)
		{
			array[j + 1] = array[j];
		}

		array[j + 1] = k;
	}
}




//ֱ�Ӳ��������Ž���
void InsertSortDown(int *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = 0;
		int k = array[i];
		
		for (j = i - 1; j >= 0 && array[j] < k; j--)
		{
			array[j + 1] = array[j];
		}

		array[j + 1] = k;
	}
}




//��Gap�����Ĳ�������
void InsertSortWithGap(int *array, int size, int gap)
{
	for (int i = gap; i < size; i++)
	{
		int k = array[i];
		int j = 0;
		for (j = i - gap; j >= 0 && array[j] > k; j -= gap)
		{
			array[j + gap] = array[j];
		}

		array[j + gap] = k;
	}
}




//ϣ������
//ʱ�临�Ӷ�
//��� O(N)
//ƽ�� O(N^1.2) - O(N^1.3)
//��� O(N^2)

//�ռ临�Ӷ�
//O(1)

//���ȶ���������ѱ�֤��ͬ�����ֵ�һ������
void ShellSort(int *array, int size)
{
	int gap = size;

	while (1)
	{
		gap = gap / 3 + 1; //����������û�о�������
		InsertSortWithGap(array, size, gap);

		if (gap == 1)
			break;
	}
}




//�����ӿ�
void Swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}




//ѡ������
//ʱ�临�Ӷ�
//��� ƽ�� � ���� O(N^2)

//�ռ临�Ӷ�
//O(1)

//���ȶ�
void SelectSort(int *array, int size)
{
	//ÿ���ҵ�һ���������ַŵ����
	for (int i = 0; i < size - 1; i++)
	{
		int max = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (array[j] > array[max])
				max = j;
		}

		Swap(&array[max], &array[size - i - 1]);
	}
}




//������
//���µ���
//ʱ�临�Ӷ�
//O(logN)
void AdjustDown(int *array, int root, int size)
{
	//�ȼ��root����Ƿ���Ҷ�ӽ��
	if (root * 2 + 1 >= size)
		return;

	//���ҳ�root���ĺ��ӽ�㣬���root������һ�����Ӵ�ֹͣ
	int left = root * 2 + 1;
	int max = left;
	int right = root * 2 + 2;
	if (right < size && array[right] > array[left])
		max = right;

	if (array[root] >= array[max])
		return;

	Swap(array + max, array + root);

	AdjustDown(array, max, size);

}




//����
//ʱ�临�Ӷ�
//O(N) or O(N*LogN)
void CreateHeap(int *array, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
		AdjustDown(array, i, size);
}




//������
//ʱ�临�Ӷ�
//O(N*LogN)

//�ռ临�Ӷ�
//O(1)

//���ȶ�
void HeapSort(int *array, int size)
{
	CreateHeap(array, size);

	for (int i = 0; i < size - 1; i++)
	{
		Swap(array + 0, array + size - 1 - i);

		AdjustDown(array, 0, size - 1 - i);
	}
}


void AdjustDown2(int *array, int size, int root)
{
	//����ʱ�Ƿ���Ҷ�ӽ��
	if (root * 2 + 1 >= size)
		return;

	int left = root * 2 + 1;
	int right = root * 2 + 2;
	int max = left;
	//���ж��Ƿ����ҽ�㣬���ҵ����ĺ���
	if (right < size && array[right] > array[left])
		max = right;

	//���жϴ�ʱ����Ƿ��������Ҷ�ӽ��
	if (array[root] >= array[max])
		return;

	Swap(&array[root], &array[max]);

	AdjustDown2(array, size, max);
}

//����
void CreateHeap2(int *array, int size)
{
	//������һ����Ҷ�ӽ�㿪ʼ
	//���µ���
	//ֱ����������µ�����
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown2(array, size, i);
	}
}

//������
void HeapSort2(int *array, int size)
{
	CreateHeap2(array, size);
	//ÿ�ν���һ��Ԫ�طŵ������
	//Ȼ����м���
	for (int i = 0; i < size - 1; i++)
	{
		Swap(&array[0], &array[size - i - 1]);
		
		//�����size��������Ϊ�Ѿ������ˣ������ܴ�Сsize Ҫ��1
		AdjustDown2(array, size - i - 1, 0);
	}
}




//ð������
void BubbleSort(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
				Swap(&array[j], &array[j + 1]);
		}
	}
}




//1.��Ҫ�����������ѡ��һ������
//2.�����������������ݽ������Ȼ���С�����ŵ�������࣬�Ȼ�����������ŵ������ұ�
//3.�����㷨(��һ������������С����)
//��ֹ����
//1.�ֳ�����size==0
//2.�ֳ�����С�����Ѿ����� �������size == 1��


//ʱ�临�Ӷ�
//��� | ƽ�� O(N * logN)
//� O(N^2)

//�ռ临�Ӷ�
//�ռ���ڵݹ�ĵ���ջ��
//���O(logN)
//�O(N)
//�����������

//�ȶ��ԣ����ȶ�partition���ܱ�֤���ȶ���


//��ѡ��׼ֵ��������
//���һ����������ÿ����˻�������

//����ѡ��׼ֵ�취
//1������ȡ��
//mid = (left + right) / 2
//��array[left, mid, right] ��ѡһ���м��С������Ϊ��׼ֵ
//Ȼ�󽫻�׼ֵ���������Ҳ�������
//��partition

//2�������������ѡһ����Ȼ�󽻻������

//Hover��
int Parition1(int *array, int left, int right)
{
	int div = left;
	int i = left;
	int j = right;//������һ���ӵ㣬һ��Ҫj = right ���Բ���right - 1

	//���������棬������
	//���������棬������
	while (i < j)
	{
		while (array[j] >= array[div] && i < j)
			j--;

		while (array[i] <= array[div] && i < j)
			i++;

		if (i < j)
			Swap(&array[i], &array[j]);
	}

	Swap(&array[i], &array[div]);
	
	return i;
}


//�ڿӷ�
int Parition2(int *array, int left, int right)
{
	int pivot = array[left];
	int begin = right; //�ұ�����
	int end = left;

	while (end < begin)
	{

		while (end < begin && array[begin] >= pivot)
		{
			begin--;
		}
		
		//�ߵ�����˵���ҵ�һ���Ȼ�׼ֵС������
		//����array[end]��
		array[end] = array[begin];
		while (end < begin && array[end] <= pivot)
		{
			end++;
		}
		
		//������˵���ҵ���һ���Ȼ�׼ֵ�������
		//����array[begin]��
		array[begin] = array[end];
	}


	array[begin] = pivot;

	return begin;
}



//ǰ���±귨
int Parition3(int *array, int left, int right)
{
	int i = left;
	int d = left;

	while (i < right)
	{
		if (array[i] >= array[right])
			i++;
		else
		{
			Swap(&array[d], &array[i]);
			i++;
			d++;
		}
	}

	Swap(&array[d], &array[right]);

	return d;
}



//�ݹ�
void _QuickSort(int *array, int left, int right)
{
	//��ֹ����
	if (left >= right)//left > right ��ʾsize == 0; left == right ��ʾ �Ѿ����� size == 1
		return;

	int div;
	div = Parition3(array, left, right);

	_QuickSort(array, left, div - 1);
	_QuickSort(array, div + 1, right);
}


//�ǵݹ�
//c++
#if 0
void NQuickSort(int *array, int left, int right)
{
	std::stack<int> s;
	s.push(right);
	s.push(left);

	int _left = -1;
	int _right = -1;

	while (!s.empty())
	{
		_left = s.top();
		s.pop();
		_right = s.top();
		s.pop();

		if (_left >= _right)
			continue;

		int d = partition(array, _left, _right);

		s.push(_right);
		s.push(d + 1);

		s.push(d - 1);
		s.push(_left);
	}
}
#endif



void QuickSort(int *array, int size)
{
	_QuickSort(array, 0, size - 1);
}



//�鲢����
//��������Ӳ���ϵ�����
void Merge(int *array, int *extra, int left, int mid, int right)
{
	int left_index = left;
	int right_index = mid;
	int extra_index = 0;

	while (left_index < mid && right_index < right)
	{
		if (array[left_index] <= array[right_index])
		{
			extra[extra_index++] = array[left_index++];
		}
		else
			extra[extra_index++] = array[right_index++];
	}

	while (left_index < mid)
	{
		extra[extra_index++] = array[left_index++];
	}

	while (right_index < right)
	{
		extra[extra_index++] = array[right_index++];
	}

	for (int i = 0; i < extra_index; i++)
	{
		array[left + i] = extra[i];
	}
}


void _MergeSort(int *array, int *extra, int left, int right)
{
	if (left >= right - 1)
		return;

	int mid = left + (right - left) / 2;

	_MergeSort(array, extra, left, mid);
	_MergeSort(array, extra, mid, right);

	Merge(array, extra, left, mid, right);
}

void MergeSort(int *array, int size)
{
	int *extra = (int *)malloc(sizeof(int) * size);
	if (!extra)
		exit(EXIT_FAILURE);

	_MergeSort(array, extra, 0, size);
	
	free(extra);
	extra = NULL;
}