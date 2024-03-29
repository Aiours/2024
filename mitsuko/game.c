#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*****    1.play   ********\n");
	printf("*****    0.exit   ********\n");
	printf("**************************\n");
}

void InitBoard(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{

			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}

			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走->");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标被占用，请重新输入\n");
		}
		else
			printf("坐标非法，请重新输入\n");
	}
}

int	IsFull(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row ; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[Row][Col], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][1] !=' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[2][i] == board[1][i]&&board[1][i] != ' ')
		{
			return board[0][i];
		}
	}
	if ((board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] !=' ') || (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' '))
	{
		return board[1][1];
	}
	int ret = IsFull(board, Row, Col);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'C';
}

void ComputerMove(char board[Row][Col], int row, int col)
{
	
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x ][y ] == ' ')
		{
			board[x ][y ] = '#';
			break;
		}
	}		
}