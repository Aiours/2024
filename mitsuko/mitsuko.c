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
		printf("���Ӯ��\n");
	}
	if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int )time(NULL));
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("������ѡ��->\n");
		}

	} while (input);
	return 0;
}