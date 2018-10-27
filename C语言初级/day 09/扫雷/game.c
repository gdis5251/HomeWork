#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Init(char board[ROWS][COLS],   int row, int col, char ch)
{
	memset(&board[0][0], ch, row*col*sizeof(board[0][0]));
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
		//我们需要9个数字，如果%10产生的是0~8， 9个数字
		//但是我们需要1~9，所以先%9产生8个数字，再加1就好
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
			book[x][y] = 1;
			open(mine, show, x, y);
			if (CountShow(show, row, col) == EASY_MODE)
			{
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
	//分别对(x,y)坐标周围8个格子进行判断，如果是雷则count + 1
	//最后返回count就是(x,y)周围的地雷个数
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

//SafeMove函数是保证玩家输入第一个坐标时不被炸死
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
			//如果玩家输入的坐标是1，则强行把这个坐标改为0
			mine[x][y] = '0';
			char ch = GetCount(mine, x, y);
			show[x][y] = ch + '0';
			book[x][y] = 1;
			open(mine, show, x, y);
			//将一个地雷改为了空地，则需要再随机填一个雷
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
			book[x][y] = 1;
			open(mine, show, x, y);
			break;
		}

	}

}

//用深度优先搜索来对面板展开
void open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	
	int tx = 0;
	int ty = 0;
	int k = 0;
	//定义next数组，用来对四个方向进行搜索
	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	//在展开的时候如果GetCount函数返回的不是0，则给show数组赋返回的值
	if (GetCount(mine, x, y) != 0)
	{
		show[x][y] = GetCount(mine, x, y) + '0';
	}
	//如果是0，给show数组那个位置赋空格
	else if (GetCount(mine, x, y) == 0)
	{
		show[x][y] = ' ';
	}
	
	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 1 || tx > ROW || ty < 1 || ty > COL)
		{
			continue;
		}
		if (mine[tx][ty] == '0' && book[tx][ty] == 0 && GetCount(mine, tx, ty) < 1)
		{
			
			book[tx][ty] = 1;
			open(mine, show, tx, ty);
		
		}
		//这一步很关键，是展开时遇到数字停下来的一步
		if (mine[tx][ty] == '0' && book[tx][ty] == 0 && GetCount(mine, tx, ty) > 0)
		{
			show[tx][ty] = GetCount(mine, tx, ty) + '0';
			continue;
		}
		
	}
	return;
}

//统计面板上剩下的'*'
int CountShow(char show[ROWS][COLS], int row, int col)//判断剩余未知区域的个数，个数为雷数时玩家赢
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}

	}
	return count;
}
