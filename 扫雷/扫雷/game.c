#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int win = 0;//计算翻开的格子数
int n = 0;//难度

void FirstMove(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);
void ShowSafeArea(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int x, int y);//翻开安全区域

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;//i、j循环变量
	win = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;//i、j循环变量
	int x = 0;
	int y = 0;
	int choice = 0;
	printf("选择难度：1.简单 2.困难:>");
	scanf("%d", &choice);
	if (choice == 1)
	{
		n = EASY_COUNT;
	}
	else
	{
		n = HARD_COUNT;
	}
	//此部分初始化雷棋盘
	for (i = 0; i < row + 2; i++)
	{
		for (j = 0; j < col + 2; j++)
		{
			board[i][j] = '0';
		}
	}
	//埋雷部分
	i = 0;
	while (i < n)
	{
		while (1)
		{
			x = rand() % row + 1;
			y = rand() % col + 1;
			if (board[x][y] != '1')
			{
				board[x][y] = '1';
				break;
			}
		}
		i++;
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;//i、j循环变量
	//打印棋盘
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}

void FirstMove(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;//i、j循环变量
	int x = 0, y = 0;
	printf("输入坐标:>");
	scanf("%d%d", &x, &y);
	while (x > row || y > col || x < 1 || y < 1)
	{
		printf("重新输入:>");
		scanf("%d%d", &x, &y);
	}
	if (mine[x][y] == '1')//第一次碰到雷，把雷移走
	{
		do
		{
			i = rand() % row + 1;
			j = rand() % col + 1;
		} while (mine[i][j] != '0');
		mine[x][y] = '0';
		mine[i][j] = '1';
	}
	if (mine[x][y] == '0')//不是雷，正常步骤进行
	{
		ShowSafeArea(show, mine, row, col, x, y);
	}
}

int ClearMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;//i、j循环变量
	int x = 0, y = 0;;
	printf("输入坐标:>");
	scanf("%d%d", &x, &y);
	while (x > row || y > col || x < 1 || y < 1)
	{
		printf("重新输入:>");
		scanf("%d%d", &x, &y);
	}
	if (mine[x][y] == '1')
	{
		printf("你输了！\n");
		return 0;
	}
	if (mine[x][y] == '0')
	{
		ShowSafeArea(show, mine, row, col, x, y);
		if (win == row * col - n)
		{
			printf("你赢了！\n");
			return 0;
		}
		return 1;
	}
}

void ShowSafeArea(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int x, int y)
{
	int i = 0, j = 0;//i、j循环变量
	if (show[x][y] != '*')
	{
		return;//已经翻开，返回
	}
	else
	{
		show[x][y] = '0' + GetMineCount(mine, x, y);//先翻开点的这一格
		win++;
	}
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if ((show[i][j] == '*') && (i > 0) && (i <= row) && (j > 0) && (j <= col))//如果show为*说明没有翻开
			{
				if (mine[i][j] == '1')
				{
					continue;
				}
				else if ((GetMineCount(mine, i, j) != 0) && (mine[i][j] == '0'))
				{
					show[i][j] = '0' + GetMineCount(mine, i, j);
					win++;
				}
				if ((GetMineCount(mine, i, j) == 0) && (mine[i][j] == '0'))
				{
					ShowSafeArea(show, mine, row, col, i, j);
				}
			}
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;//i、j循环变量
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)//数雷的个数
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}