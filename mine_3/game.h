#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define Row 9
#define Col 9
#define Rows Row+2
#define Cols Col+2
#define MineNum 10

void menu();																	//打印菜单
void InitBoard(char board[Rows][Cols], int rows, int cols, char set);			//初始化棋盘
void DisplayBoard(char board[Rows][Cols], int row, int col);					//打印棋盘
void SetMine(char board[Rows][Cols], int row, int col);							//布置雷
void FindMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col);	//排查雷
void MineCount(char mine[Rows][Cols], char show[Rows][Cols], int x, int y);		//统计排查坐标附近雷的数量
