#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void game()
{
	char ret = 0;
	char mine[Rows][Cols] = { 0 };		//��Ų����׵���Ϣ
	char show[Rows][Cols] = { 0 };		//����Ų�����Ϣ
	InitBoard(mine, Rows, Cols, '0');	//��ʼ��'0'
	InitBoard(show, Rows, Cols, '*');	//��ʼ��'*'
	DisplayBoard(show, Row, Col);		//��ӡ����
	SetMine(mine, Row, Col);			//������
	//DisplayBoard(mine, Row, Col);		//��ӡ�׵���Ϣ
	FindMine(mine, show, Row, Col);		//�Ų���

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
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

