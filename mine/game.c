#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*****    1.play   ********\n");
	printf("*****    0.exit   ********\n");
	printf("**************************\n");
}

void InitBoard(char board[Rows][Cols], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
  			board[i][j] = set;

		}
	}
}

void DisplayBoard(char board[Rows][Cols], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);

		}
		printf("\n");

	}
	printf("\n");
}

void SetMine(char board[Rows][Cols], int row, int col)
{
	int count = MineNum;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}	
}

int MineCount(char board[Rows][Cols], int x, int y)
{
	return board[x - 1][y - 1] + board[x - 1][y] +
		board[x][y + 1] + board[x][y - 1] +
		board[x][y + 1] + board[x + 1][y - 1] +
		board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';
}

void FindMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<Row * Col - MineNum)
	{
		printf("请输入排查的坐标->");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, Row, Col);				
				break;
			}
			else
			{
				int count = MineCount(mine, x, y);
				show[x][y] = count+'0';
				DisplayBoard(show, Row, Col);
				win++;
			}
		}
		else
		{
			printf("坐标不存在，请重新输入\n");
		}
	}
	if (win == Row * Col - MineNum)
	{
		printf("恭喜你，排雷成功\n");
	}

}