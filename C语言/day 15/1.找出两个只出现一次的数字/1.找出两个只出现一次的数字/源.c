#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>

/*
* һ��������ֻ�����������ǳ���һ�Σ�
  �����������ֶ����������Ρ�
  �ҳ����������֣����ʵ�֡�
* ���ķ�
* 2018/11/5
*/

int main(void)
{
	int stack[100] = { 0 };
	int n = 0;
	int top = 0;
	int i = 0;

	//ȷ���ж��ٸ�����
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &stack[top]);
		if (stack[top] == stack[top - 1])
		{
			//��������ͬ����������
			stack[top] = 0;
			stack[top - 1] = 0;

			top -= 2;
		}
		top++;
	}
	top--;
	
	////����һ��ջ�ҳ�������0�����ִ�ӡ
	//for (i = 0; i < n; i++)
	//{
	//	if (stack[i] != 0)
	//		printf("%d  ", stack[i]);
	//}

	//ֻ�����������ǵ����ģ�ֻ��Ҫ��ӡ�������ּ���
	//����������ʱ�临�Ӷ�
	printf("%d ", stack[top]);
	printf("%d ", stack[top - 1]);

	printf("\n");

	system("pause");
	return 0;
}