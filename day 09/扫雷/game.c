#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Init(char mine[ROWS][COLS], char show[ROWS][COLS],  int row, int col)
{
	memset(&mine[0][0], '0', row*col*sizeof(mine[0][0]));
	memset(&show[0][0], '*', row*col*sizeof(show[0][0]));
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	//打印横坐标
	printf("0 ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
		
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
		
	}
}

void setMine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASY_MODE;


	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//踩到雷返回1，没有踩到雷返回0
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;

	
	printf("请输入您选择的坐标：");
	scanf("%d%d", &x, &y);

	if (x < 1 && x > COL && y < 1 && y > ROW)
	{
		printf("您输入的坐标超过当前地图，请重新输入！\n");
			
	}
	else
	{
		if (mine[x][y] == '0')
		{
			char ch = GetCount(mine, x, y);
			show[x][y] = ch + '0';
			open(mine, show, x, y);
			if (CountShow(show, row, col) == COUNT)
			{
				/*printf("玩家赢!\n");
				displayboard(mine, rows, cols);*/
				return 0;
			}
		}
		else if (mine[x][y] == '1')
		{
			return 1;
		}

	}
	return 0;
}

int GetCount(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;

	if (mine[x - 1][y] == '1')
		count++;
	if (mine[x - 1][y - 1] == '1')
		count++;
	if (mine[x][y - 1] == '1')
		count++;
	if (mine[x + 1][y - 1] == '1')
		count++;
	if (mine[x + 1][y] == '1')
		count++;
	if (mine[x + 1][y + 1] == '1')
		count++;
	if (mine[x][y + 1] == '1')
		count++;
	if (mine[x - 1][y + 1] == '1')
		count++;

	return count;
}

void SafeMove(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int flag = 1;
	int count = 0;
	char ch = 0;

	while (1)
	{
		printf("请输入您要选择的坐标：");
		scanf("%d%d", &x, &y);

		if (x < 1 && x > COL && y < 1 && y > ROW)
		{
			printf("您输入的坐标超过当前地图，请重新输入！\n");
			continue;
		}

		if (mine[x][y] == '1')
		{
			mine[x][y] = '0';
			char ch = GetCount(mine, x, y);
			show[x][y] = ch + '0';
			open(mine, show, x, y);
			while (flag)
			{
				x = rand() % 9 + 1;
				y = rand() % 9 + 1;
				if (mine[x][y] == '0')
				{
					mine[x][y] = '1';
					flag--;
					break;
				}
			}break;
		}
		else if (mine[x][y] == '0')
		{
			char ch = GetCount(mine, x, y);
			show[x][y] = ch + '0';
			open(mine, show, x, y);
			break;
		}

	}

}
void open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//if (mine[x - 1][y - 1] == '0')
	//{
	//	show[x - 1][y - 1] = GetCount(mine, x - 1, y - 1) + '0';//显示该坐标周围雷数
	//}
	//if (mine[x - 1][y] == '0')
	//{
	//	show[x - 1][y] = GetCount(mine, x - 1, y) + '0';//显示该坐标周围雷数
	//}
	//if (mine[x - 1][y + 1] == '0')
	//{
	//	show[x - 1][y + 1] = GetCount(mine, x - 1, y + 1) + '0';//显示该坐标周围雷数
	//}
	//if (mine[x][y - 1] == '0')
	//{
	//	show[x][y - 1] = GetCount(mine, x, y - 1) + '0';//显示该坐标周围雷数
	//}
	//if (mine[x][y + 1] == '0')
	//{
	//	show[x][y + 1] = GetCount(mine, x, y + 1) + '0';//显示该坐标周围雷数
	//}
	//if (mine[x + 1][y - 1] == '0')
	//{
	//	show[x + 1][y - 1] = GetCount(mine, x + 1, y - 1) + '0';//显示该坐标周围雷数
	//}
	//if (mine[x + 1][y] == '0')
	//{
	//	show[x + 1][y] = GetCount(mine, x + 1, y) + '0';//显示该坐标周围雷数
	//}
	//if (mine[x + 1][y + 1] == '0')
	//{
	//	show[x + 1][y + 1] = GetCount(mine, x + 1, y + 1) + '0';//显示该坐标周围雷数
	//}
	int tx = 0;
	int ty = 0;
	int k = 0;
	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	book[x][y] = 1;
	if (mine[x][y] == '0')
	{
		if (GetCount(mine, x, y) != 0)
		{
			show[x][y] = GetCount(mine, x, y) + '0';
		}
		else if (GetCount(mine, x, y) == 0)
		{
			show[x][y] = ' ';
		}
	}
	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 1 || tx > ROW || ty < 1 || ty > COL)
		{
			continue;
		}
		if (mine[tx][ty] == '0' && book[tx][ty] == 0)
		{
			
			book[tx][ty] = 1;
			open(mine, show, tx, ty);
			book[tx][ty] = 0;
		
		}
		return;
	}
	
}

int CountShow(char show[ROWS][COLS], int row, int col)//判断剩余未知区域的个数，个数为雷数时玩家赢
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row - 2; i++)
	{
		for (j = 1; j <= col - 2; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}

	}
	return count;
}
