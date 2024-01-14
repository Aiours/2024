#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void menu()
{
	printf("************************\n");
	printf("*****1.开始游戏*********\n");
	printf("*****0.退出游戏*********\n");
	printf("************************\n");
}
int main()
{
	int input = 0;

	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("开始游戏\n");
				break;
		case 0:
				printf("退出游戏\n");
				break;
		default:
			printf("请重新选择");
			break;
		}
	} while (input);
		return 0;
}