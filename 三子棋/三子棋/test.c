#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include "game.h"

int main()
{

	char board[ROW][COL];
	char ret = 0;
	int a = 0;
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	while (1)
	{
		printf("玩家走:>");
		printf("\n");
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
     	if (Full(board, ROW, COL) == 0)
		{
			printf("平局\n");
			break;
		}
		if (CheckWin(board, ROW, COL) != ' ')
		{
			printf("玩家赢\n");
			break;
		}
		printf("电脑走:>");
		printf("\n");
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		if (Full(board, ROW, COL) == 0)
		{
			printf("平局\n");
			break;
		}
		if (CheckWin(board, ROW, COL) != ' ')
		{
			printf("电脑赢\n");
			break;
		}
	}
	system("pause");
	return 0;
}