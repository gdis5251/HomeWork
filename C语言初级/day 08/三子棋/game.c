#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(&board[0][0], ' ', row*col*sizeof(board[0][0]));
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		if (i < row - 1)
			printf("---------------------------\n");

	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����������:>");
		scanf("%d%d", &x, &y);

		//�ж��Ƿ�Խ��
		if (x >= row && x <= 1 && y >= col && y <= 1)
		{
			printf("����������������룺\n");
			continue;
		}
		//����û�ѡ�������Ϊ�գ��򽫿ո��ΪX��������ʾ�������
		if (board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = 'X';
			break;
		}
		else
		{
			printf("����������������룺\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int a = 0;
	char ch = 0;

	////�ж�ÿһ���Ƿ�һ��
	//for (i = 0; i < row; i++)
	//{
	//	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == 'X')
	//	{
	//		return 'X';
	//	}
	//	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '0')
	//	{
	//		return '0';
	//	}
	//}
	//
	////�ж�ÿһ���Ƿ�һ��
	//for (i = 0; i < col; i++)
	//{
	//	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] == 'X')
	//	{
	//		return 'X';
	//	}
	//	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] == '0')
	//	{
	//		return '0';
	//	}
	//}
	//
	////�ж϶Խ����Ƿ��������
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'X')
	//{
	//	return 'X';
	//}
	//if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'X')
	//{
	//	return 'X';
	//}
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == '0')
	//{
	//	return '0';
	//}
	//if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == '0')
	//{
	//	return '0';
	//}

	for (i = 0; i < row; i++)
	{
		a =  0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] == 'X')
			{
				a++;
			}
			if (board[i][j] == board[i][j + 1] && board[i][j] == '0')
			{
				a--;
			}
			if (a == col - 1)
			{
				return 'X';
			}
			if (a == -col + 1)
			{
				return '0';
			}
		}
	}

	for (i = 0; i < col; i++)
	{
		a = 0;
		for (j = 0; j < row - 1; j++)
		{
			if (board[j][i] == board[j + 1][i] && board[j][i] == 'X')
			{
				a++;
			}
			if (board[j][i] == board[j + 1][i] && board[j][i] == '0')
			{
				a--;
			}
			if (a == row - 1)
			{
				return 'X';
			}
			if (a == -row + 1)
			{
				return '0';
			}
		}
	}

	for (i = 0, j = 0; i < row - 1; i++, j++)
	{
		
		
		if (board[i][j] == board[i + 1][j + 1] && board[i][j] == 'X')
		{
			a++;
		}
		if (board[i][j] == board[i + 1][j + 1] && board[i][j] == '0')
		{	
			a--;
		}
		if (a == row - 1)
		{
			return 'X';
		}
		if (a == -row + 1)
		{
			return '0';
		}
		
	}

	for (i = 0, j = col - 1; i < row - 1; i++, j--)
	{
		
		if (board[i][j] == board[i + 1][j - 1] && board[i][j] == 'X')
		{
			a++;
		}
		if (board[i][j] == board[i + 1][j - 1] && board[i][j] == '0')
		{
			a--;
		}
		if (a == row - 1)
		{
			return 'X';
		}
		if (a == -row + 1)
		{
			return '0';
		}
		
	}
	

	//��board���鱻��������Ϊƽ�ַ��ء�Q'
	ch = IsFull(board, row, col);
	if (ch == 'Q')
	{
		return 'Q';
	}
}

char IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'C';
			}
		}
	}
	return 'Q';
}