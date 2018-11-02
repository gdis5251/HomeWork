#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ʵ��һ�����������������ַ����е�k���ַ���
  ABCD����һ���ַ��õ�BCDA
  ABCD���������ַ��õ�CDAB
* ���ķ�
* 2018/11/2
*/
void left_handed(char* p, int n, int size)
{
	int i = 0;

	//����n==1������һ���ַ��Ƶ����һ��
	//ABCDA
	for (i = 0; i < n; i++)
	{
		*(p + size + i) = *(p + i);
	}

	//�ٽ�����Ԫ����ǰ��n��λ�ã����Ǳ��Ƶ�λ�õ�Ԫ��
	//BCDA
	for (i = 0; i <= size; i++)
	{
		*(p + i) = *(p + n + i);
	}
}

int main(void)
{
	int n = 0;
	int size = 0;
	char arr[8] = "ABCD";

	scanf("%d", &n);

	size = strlen(arr);

	left_handed(arr, n, size);
	//printf("%d\n", size);
	printf("%s\n", arr);
	
	system("pause");
	return 0;

}