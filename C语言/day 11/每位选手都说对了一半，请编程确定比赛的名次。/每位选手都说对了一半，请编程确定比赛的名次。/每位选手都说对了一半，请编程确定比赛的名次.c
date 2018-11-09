#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
  A选手说：B第二，我第三； 
  B选手说：我第二，E第四； 
  C选手说：我第一，D第二； 
  D选手说：C最后，我第三； 
  E选手说：我第四，A第一； 
  比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。 
* 郭文峰
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

	//用枚举的方法来判断谁说的对
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

							////方法一
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


							//方法二
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