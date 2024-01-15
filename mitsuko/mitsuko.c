#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void game()
{
	char ret = 0;
	char board[Row][Col];
	InitBoard(board, Row, Col);
	DisplayBoard(board, Row, Col);
	while (1)
	{
		PlayerMove(board, Row, Col);
		ret=IsWin(board, Row, Col);
		ComputerMove(board, Row, Col);
		ret=IsWin(board, Row, Col);
		DisplayBoard(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}	
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	if (ret == 'Q')
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int )time(NULL));
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("请重新选择->\n");
		}

	} while (input);
	return 0;
}