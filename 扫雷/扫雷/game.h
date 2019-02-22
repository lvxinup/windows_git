#define  _CRT_SECURE_NO_WARNINGS 1

#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 20
#define HARD_COUNT 40

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//初始化棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col);//打印雷盘
void FirstMove(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);//第一次移动不能死
void SetMine(char board[ROWS][COLS], int row, int col);//设置雷
int ClearMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);//扫雷的主要部分
int GetMineCount(char board[ROWS][COLS], int x, int y);//数雷的个数

#endif //__GAME_H__