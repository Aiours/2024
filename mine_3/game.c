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
	//
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
	int count = MineNum;			//布置MineNum个雷
	while (count)
	{
		//产生随机下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void MineCount(char mine[Rows][Cols], char show[Rows][Cols], int x, int y)
{
	int i = 0;
	int j = 0;
	char count = mine[x - 1][y - 1];
	count += mine[x - 1][y] - '0';
	count += mine[x - 1][y + 1] - '0';
	count += mine[x][y - 1] - '0';
	count += mine[x][y + 1] - '0';
	count += mine[x + 1][y - 1] - '0';
	count += mine[x + 1][y] - '0';
	count += mine[x + 1][y + 1] - '0';
	if (count == '0')
	{
		show[x][y] = ' ';
	}
	else
	{
		show[x][y] = count;
	}
	//展开附近雷的数量为零的区域
	if (show[x][y] == ' ')
	{
		if (x > 1 && x < Row && y > 1 && y < Col)
		{
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (show[x + i][y + j] == '*')
					{
						MineCount(mine, show, x + i, y + j);
						//win++;
						//printf("%d\n", win);
					}
				}
			}
		}
	}
}

void FindMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col)
{
	//输入排查坐标
	//判断坐标
		//是否非法		x > 0 && x <= row && y > 0 && y <= col
			//非法		坐标不存在，请重新输入   
			//合法 
				//是否有雷
					//是雷		很遗憾，你被炸死了		打印棋盘
					// 不是雷	统计坐标附近雷的数量
						//数量是否为零
							//为零		展开附近项
							// 不为零	打印棋盘 		
	//统计剩余格子数量
	//数量为MineNum		跳出while循环
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	int win = 0;	//剩余格子的数量
	while (1)
	{
		win = 0;
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
				MineCount(mine, show, x, y);
				DisplayBoard(show, Row, Col);
				//for (i = 1; i < Rows; i++)
				//{
				//	for (j = 1; j < Cols; j++)
				//	{
				//		if (show[i][j] == '*')
				//		{
				//			win++;
				//		}
				//	}
				//}
				//win++;
				//printf("%d\n", win);
				//if (count == ' ')
				//{
				//	if (x > 1 && x < Row && y > 1 && y < Col)
				//	{
				//		for (i = -1; i <= 1; i++)
				//		{
				//			for (j = -1; j <= 1; j++)
				//			{
				//				if (show[x + i][y + j] == '*')
				//				{
				//					show[x + i][y + j] = MineCount(mine, show, x + i, y + j);
				//					win++;
				//					//printf("%d\n", win);
				//				}
				//			}
				//		}
				//	}
				//}
			}
		}
		else
		{
			printf("坐标不存在，请重新输入\n");
		}
		for (i = 1; i <= Row; i++)
		{
			for (j = 1; j <= Col; j++)
			{
				if (show[i][j] == '*')
				{
					win++;
				}
			}
		}
		//printf("%d\n", win);
		if (win == 10)
		{
			break;
		}
	}
	if (win == MineNum)
	{
		printf("恭喜你，排雷成功\n");
	}
}
