#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int is_left_handed(char* orig, const char* ch_orig, int size_o, int size_c)
{
	
	int i = 0;

	//��������ַ����ĳ��ȶ�����ȣ���ô�������ַ����϶�������һ����ת��õ���
	if (size_o != size_c)
		return 0;

	//������תԭ�ַ������Ա������ַ����Ƿ����
	for (i = 1; i < size_o; i++)
	{
		left_handed(orig, i, size_o);
		if (strcmp(orig, ch_orig) == 0)
			return 1;
	}

	return 0;
}



int main(void)
{
	int n = 0;
	int size_o = 0;
	int size_c = 0;
	int is_l = 0;
	char orig[8] = "ABCD";
	char ch_orig[8] = "BCDA";

	size_o = strlen(orig);
	size_c = strlen(ch_orig);

	is_l = is_left_handed(orig, ch_orig, size_o, size_c);

	if (is_l == 1)
	{
		printf("YES!\n");
	}
	else
	{
		printf("NO!\n");
	}

	system("pause");
	return 0;

}