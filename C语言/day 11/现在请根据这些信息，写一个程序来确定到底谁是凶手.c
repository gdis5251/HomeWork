#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�� 
  ���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ� 
  A˵�������ҡ� 
  B˵����C�� 
  C˵����D�� 
  D˵��C�ں�˵ 
  ��֪3����˵���滰��1����˵���Ǽٻ��� 
  �����������Щ��Ϣ��дһ��������ȷ������˭�����֡� 
* ���ķ�
* 2018/10/23
*/

int main(void)
{

	int murder;
	for (murder = 'A'; murder <= 'D'; murder++)
	{
		if (((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D')) == 3)    //����һ�٣���if���ģ�������Ϊ����Ϊ1��Ҫ�Ǽٽ��Ϊ0�����if����  �������������ض�Ϊ����һ�٣����ض�����3.  
		{
			printf("murder is %c\n", murder);     //��������Ҫ������֣�Ϊһ���ַ���%c��������ַ�  

		}

	}

	system("pause");
	return 0;
}