#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <string.h>

/*
** ������Ϊ����ѡ������½ڵĸ�ϰ�����а�����ص�һЩ��ϰ
** ���ķ�
** 2018/12/5
*/

//1. �ж�һ�����Ƿ�Ϊ����
//int main(void)
//{
//
//	int num = 0;
//	
//	printf("Please input a number :> ");
//	scanf("%d", &num);
//
//	if (0 == (num % 2))
//	{
//		printf("%d is even!\n", num);
//	}
//	else
//	{
//		printf("%d is odd!\n", num);
//	}
//
//	system("pause");
//	return 0;
//}



//2. ���1~100֮�������
//void printOdd(int range)
//{
//	assert(range > 0);
//	
//	int i_ = 1;
//
//	for (; i_ <= range; i_++)
//	{
//		if ((i_ % 2))
//			printf("%d ", i_);
//	}
//	printf("\n");
//
//}
//
//int main(void)
//{
//	int range = 100;
//
//	printOdd(range);
//
//	system("pause");
//	return 0;
//	
//}


//3. switch��Ƕ��ʹ��
//int main(void)
//{
//	int n = 1;
//	int m = 2;
//
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch (n)
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default :
//		break;
//	}
//
//	printf("n = %d,m = %d", n, m);
//
//
//	system("pause");
//	return 0;
//}


//4. break �� continue �ĶԱ�
//int main(void)
//{
//	int i = 1;
//
//	while (i <= 10)
//	{
//		if (5 == i)
//			break;
//
//		printf("%d ", i);
//		i++;
//	}
//
//
//	system("pause");
//	return 0;
//}

//int main(void)
//{
//	int i = 1;
//
//	while (i <= 10)
//	{
//		if (5 == i)
//			continue;//���򽫻Ῠ������
//
//		printf("%d ", i);
//		i++;
//	}
//
//
//	system("pause");
//	return 0;
//}

//int main(void)
//{
//	int i = 0;
//
//	while (i <= 10)
//	{
//		i++;
//
//		if (5 == i)
//			continue;//���򽫻Ῠ������
//
//		printf("%d ", i);
//	}
//
//
//	system("pause");
//	return 0;
//}


//5. C���Ե�һ��BUG
//���γ���ѭ��
//int main(void)
//{
//	//C�����ڴ�����ʱ����ʱ����ջ�ϴ�����
//	//ջ�ϴ�����Ӵ��µ���һ�δ���
//	//���������Ǵ���һ���ڴ棬���ϵ�����������
//	//������Խ������������������紴���ı���
//	int i = 0;
//	int a[10] = { 0 };
//
//	for (i = 0; i <= 12; i++)
//	{
//		printf("hehe\n");
//		a[i] = 0;
//	}
//
//	system("pause");
//	return 0;
//}

//6. ��ʾ����ַ������߿�ʼ���м���
//int main(void)
//{
//	char str1[] = { "Hi! I am Gerald Kwok!" };
//	char str2[] = { "$$$$$$$$$$$$$$$$$$$$$" };
//	int left = 0;
//	int right = strlen(str2) - 1;
//
//	puts(str2);
//
//	while (left <= right)
//	{
//		Sleep(1000);
//		system("CLS");//clear screen
//		str2[left] = str1[left];
//		str2[right] = str1[right];
//
//		puts(str2);
//		
//		left++;
//		right--;
//	}
//
//	system("pause");
//	return 0;
//}


//7. ģ���û���¼���龰���������룬������
void login(const char *pwd, int lim)
{
	assert(pwd);
	assert(lim > 0);

	int i_ = 0;
	char my_pwd[100] = { '\0' };


	printf("Please input your password:> ");
	for (i_ = 0; i_ < lim; i_++)
	{
		gets(my_pwd);

		if (0 == strcmp(pwd, my_pwd))
		{
			printf("Welcome!\n");
			return;
		}
		else if (i_ < lim - 1)
		{
			printf("Sorry. Error password!\n Please try again(left %d):> ", lim - i_ - 1);
		}
		else
		{
			printf("ERROR PASSWORD! EXIT!\n");
		}
	}

}

int main(void)
{
	const char *pwd = "123";
	int limit = 3;

	login(pwd, limit);


	system("pause");
	return 0;
}