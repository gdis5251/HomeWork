#ifndef __GEME_H__
#define __GEME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
char IsFull(char board[ROW][COL], int row, int col);

#endif //__GEME_H__