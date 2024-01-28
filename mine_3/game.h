#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define Row 9
#define Col 9
#define Rows Row+2
#define Cols Col+2
#define MineNum 10

void menu();																	//��ӡ�˵�
void InitBoard(char board[Rows][Cols], int rows, int cols, char set);			//��ʼ������
void DisplayBoard(char board[Rows][Cols], int row, int col);					//��ӡ����
void SetMine(char board[Rows][Cols], int row, int col);							//������
void FindMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col);	//�Ų���
void MineCount(char mine[Rows][Cols], char show[Rows][Cols], int x, int y);		//ͳ���Ų����긽���׵�����
