#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
int m = 0;
int n = 0;
void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', col*row*sizeof(char));
}
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
		printf("\n");
		if (i != 2)
			printf("---|---|---\n");
	}

}
void PlayerMove(char board[ROW][COL], int row, int col)
{

	printf("请输入坐标:>\n");
	scanf("%d%d", &m, &n);
	m--;
	n--;
	while (1)                //保证玩家输入，输入错误仍可继续输入，直到输入正确为止
	{
		if ((m >= 0) && (m <= 2) && (n <= 2) && (n >= 0))   //判断输入是否越界
		{
			if (board[m][n] == ' ')                        //判断位置是否已被占用
			{
				board[m][n] = 'X';
				break;

			}
			else                                             //被占用 输入错误
				printf("输入错误，请重新输入\n");

		} 
		else                                                //越界 输入错误
		{
			printf("输入错误，请重新输入\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}

	}

}
int  Full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 1;
		}
	}
	return 0;
}
char CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != ' ')
			return board[i][0];
	}
	for (i = 0; i < col; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[0][i] != ' ')
			return board[0][i];

	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != ' ')
		return board[0][0];
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[0][2] != ' ')
		return board[0][2];
	return ' ';  
}

