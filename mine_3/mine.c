#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void game()
{
	char ret = 0;
	char mine[Rows][Cols] = { 0 };		//存放布置雷的信息
	char show[Rows][Cols] = { 0 };		//存放排查后的信息
	InitBoard(mine, Rows, Cols, '0');	//初始化'0'
	InitBoard(show, Rows, Cols, '*');	//初始化'*'
	DisplayBoard(show, Row, Col);		//打印棋盘
	SetMine(mine, Row, Col);			//布置雷
	//DisplayBoard(mine, Row, Col);		//打印雷的信息
	FindMine(mine, show, Row, Col);		//排查雷

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

