#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ�������� 
  Aѡ��˵��B�ڶ����ҵ����� 
  Bѡ��˵���ҵڶ���E���ģ� 
  Cѡ��˵���ҵ�һ��D�ڶ��� 
  Dѡ��˵��C����ҵ����� 
  Eѡ��˵���ҵ��ģ�A��һ�� 
  ����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ� 
* ���ķ�
* 2018/10/23
*/

void PlayerNo()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	unsigned int flag = 0;

	//��ö�ٵķ������ж�˭˵�Ķ�
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						flag = 0;
						if ((2 == b) + (3 == a) == 1 && \
							(b == 2) + (e == 4) == 1 && \
							(c == 1) + (d == 2) == 1 && \
							(c == 5) + (d == 3) == 1 && \
							(e == 4) + (a == 1) == 1 )
						{
							flag |= (1 << (a - 1));
							flag |= (1 << (b - 1));
							flag |= (1 << (c - 1));
							flag |= (1 << (d - 1));
							flag |= (1 << (e - 1));

							////����һ
							//while (flag)
							//{
							//	if (!(flag & 1))
							//	{
							//		break;
							//	}
							//	flag >>= 1;
							//}
							//if (!flag)
							//{
							//	printf("a= %d, b= %d,c= %d,d= %d,e= %d\n", a, b, c, d, e);

							//}


							//������
							if (flag == 1 || flag == 3 || flag == 7 || flag == 15 || flag == 31)
								printf("a= %d, b= %d,c= %d,d= %d,e= %d\n", a, b, c, d, e);



						}
					}
				}
			}
		}
	}
}

int main(void)
{
	PlayerNo();
	system("pause");
	return 0;
}