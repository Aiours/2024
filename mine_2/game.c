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

char MineCount(char mine[Rows][Cols], char show[Row][Col], int x, int y)
{
	char count = mine[x - 1][y - 1];
	count += mine[x - 1][y]-'0';
	count += mine[x-1][y + 1] - '0';
	count += mine[x][y - 1] - '0';
	count += mine[x][y + 1]-'0';
	count += mine[x + 1][y - 1]-'0';
	count += mine[x + 1][y]-'0';
	count += mine[x + 1][y + 1]-'0';
	if (count == '0')
	{
		return ' ';
	}
	else
	{
		return count;
	}
}

void FindMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int i = 0;
	int j = 0;
	while (win < Row * Col - MineNum)
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
				char count = MineCount(mine ,show,x, y);
				show[x][y] = count;
				win++;
				printf("%d\n", win);
				if (count == ' ')
				{
					if (x > 1 && x < Row && y > 1 && y < Col)
					{
						for (i = -1; i <= 1; i++)
						{
							for (j = -1; j <= 1; j++)
							{
									if (show[x + i][y + j] == '*')
									{
										show[x + i][y + j] = MineCount(mine, show, x + i, y + j);
										win++;
										printf("%d\n", win);
									}	
							}
						}
					}					
				}
				DisplayBoard(show, Row, Col);
				
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


//void MineCount(int surround[Rows][Cols], int mine[Rows][Cols], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	int m = 0;
//	int n = 0;
//	for ( i = 1; i < Rows; i++)
//	{
//		for (j = 1; j < Cols; j++)
//		{
//			for (m = -1; m <= 1; m++)
//			{
//				for (n = -1; n <= 1; n++)
//				{
//					surround[i][j] += mine[i + m ][j + n ];
//				}
//			}
//		}
//	}
//}