#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ���ʵ�֣� 
  һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
  ���ҳ�������֡���ʹ��λ���㣩
* ���ķ�
* 2018/10/28
*/

int main(void)
{
	int arr[100] = { 0 };
	int n = 0;
	int i = 0;

	scanf("%d", &n);

	//����һ�����֣�����һ������ֻ��һ�������ǵ������������ǳɶԳ���
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	//��λ��������ÿ�����ֽ����ֻ򣬵������ֻᱣ���Լ�ԭ�е�ֵ
	for (i = 0; i < n - 1; i++)
	{
		arr[i+1] = arr[i] ^ arr[i + 1];
	}

	printf("%d", arr[n - 1]);

	system("pause");
	return 0;
}