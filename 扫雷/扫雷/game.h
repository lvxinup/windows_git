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

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//��ʼ������
void PrintBoard(char board[ROWS][COLS], int row, int col);//��ӡ����
void FirstMove(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);//��һ���ƶ�������
void SetMine(char board[ROWS][COLS], int row, int col);//������
int ClearMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);//ɨ�׵���Ҫ����
int GetMineCount(char board[ROWS][COLS], int x, int y);//���׵ĸ���

#endif //__GAME_H__