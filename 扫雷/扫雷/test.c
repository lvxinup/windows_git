#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

const int rows = 11;
const int cols = 11;
const int row = 9;
const int col = 9;
int x = 0, y = 0;
char set = '*';

int main()
{
	int choice = 0;
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };
	srand((unsigned)time(0));
	while (1)
	{
		printf("1.开始游戏 0.退出游戏\n");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			InitBoard(show, rows, cols, set);
			PrintBoard(show, row, col);
			SetMine(mine, row, col);
			//PrintBoard(mine, row, col);//测试的时候用
			FirstMove(show, mine, row, col);//第一次移动不会死
			system("cls");
			PrintBoard(show, row, col);
			while (ClearMine(show, mine, row, col))
			{
				system("cls");
				PrintBoard(show, row, col);
				//PrintBoard(mine, row, col);//测试的时候用
			}
			PrintBoard(mine, row, col);
			break;
		case 0:
			exit(0);
			break;
		}
	}
	return 0;
}