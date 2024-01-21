#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void game()
{
	char ret = 0;
	char mine[Rows][Cols] = { 0 };
	char show[Rows][Cols] = { 0 };
	InitBoard(mine, Rows, Cols, '0');
	InitBoard(show, Rows, Cols, '*');

	DisplayBoard(show, Row, Col);
	SetMine(mine, Row, Col);
	DisplayBoard(mine, Row, Col);
	FindMine(mine, show, Row, Col);

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
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
