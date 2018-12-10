#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* ����Ϊ��һ�θ�ϰ����day 02��ҵ�ĸ�ϰ
* ���ķ�
* 2018/12/10
*/

//�����������α�����ֵ
void swap1(int *num1, int *num2)
{
	assert(num1 && num2);

	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

//����������ʱ����������������������
void swap2(int *num1, int *num2)
{
	assert(num1 && num2);

	*num1 ^= *num2;
	*num2 ^= *num1;
	*num1 ^= *num2;
}


//��10�����������ֵ
int maxNum(int *arr)
{
	assert(arr);

	int max_ = 0;
	int i_ = 0;
	while (i_ < 10)
	{
		if (*arr > max_)
			max_ = *arr;
		arr++;

		i_++;
	}

	return max_;
}


//���������Ӵ�С���
void sortPrint(int *arr)
{
	assert(arr);

	int i_ = 0;
	int j_ = 0;

	for (i_ = 0; i_ < 3; i_++)
	{
		for (j_ = 0; j_ < 3 - i_; j_++)
		{
			if (arr[j_ + 1] > arr[j_])
				swap2(&arr[j_ + 1], &arr[j_]);
		}
	}

	for (i_ = 0; i_ < 3; i_++)
	{
		printf("%d ", arr[i_]);
	}
}


//5. �������������Լ��
int yue(int num1, int num2)
{
	if (0 == num1 % num2)
		return num2;
	if ((num1 % num2) > num1)
		yue(num1 % num2, num1);
	else
		yue(num2, num1 % num2);
	
}

int main(void)
{
	//1. //�����������α�����ֵ
	//int num1 = 0; 
	//int num2 = 0;

	//printf("Swap! one way:\n");
	//printf("Please input two numbers:");
	//scanf("%d%d", &num1, &num2);

	//printf("num1 : %d, num2 : %d\n", num1, num2);

	//swap1(&num1, &num2);

	//printf("num1 : %d, num2 : %d\n", num1, num2);

	//2. //����������ʱ����������������������
	//num1 = 0;
	//num2 = 0;

	//printf("Swap! another way:\n");
	//printf("Please input two numbers:");
	//scanf("%d%d", &num1, &num2);

	//printf("num1 : %d, num2 : %d\n", num1, num2);

	//swap2(&num1, &num2);

	//printf("num1 : %d, num2 : %d\n", num1, num2);


	//3. //��10�����������ֵ
	//int arr1[10] = { 3, 4, 6, 29, 345, 563, 32, 54, 12, 645 };
	//int max = 0;

	//max = maxNum(arr1);

	//printf("Max is %d\n", max);


	//4. ���������Ӵ�С���
	/*int arr2[3] = { 23, 65, 32 };

	sortPrint(arr2);*/
	
	//5. �������������Լ��
	int num1 = 319;
	int num2 = 377;
	int maxYue = 0;

	maxYue = yue(num1, num2);

	printf("%d\n", maxYue);

	system("pause");
	return 0;
}
