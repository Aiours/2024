#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void menu()
{
	printf("************************\n");
	printf("*****1.��ʼ��Ϸ*********\n");
	printf("*****0.�˳���Ϸ*********\n");
	printf("************************\n");
}
int main()
{
	int input = 0;

	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("��ʼ��Ϸ\n");
				break;
		case 0:
				printf("�˳���Ϸ\n");
				break;
		default:
			printf("������ѡ��");
			break;
		}
	} while (input);
		return 0;
}