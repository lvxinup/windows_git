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
		printf("�����:>");
		printf("\n");
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
     	if (Full(board, ROW, COL) == 0)
		{
			printf("ƽ��\n");
			break;
		}
		if (CheckWin(board, ROW, COL) != ' ')
		{
			printf("���Ӯ\n");
			break;
		}
		printf("������:>");
		printf("\n");
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		if (Full(board, ROW, COL) == 0)
		{
			printf("ƽ��\n");
			break;
		}
		if (CheckWin(board, ROW, COL) != ' ')
		{
			printf("����Ӯ\n");
			break;
		}
	}
	system("pause");
	return 0;
}