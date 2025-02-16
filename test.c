#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()//菜单
{
	printf("*******************************\n");
	printf("*******    1    扫雷    *******\n");
	printf("*******    2    退出    *******\n");
	printf("*******************************\n");
	printf("请选择：>");
}

void game()
{
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
	char show[ROWS][COLS] = {0};//存放排查出的雷的信息
	//mine 数组在没有布置雷的时候都是 '0'
	InitBoard(mine,ROWS,COLS,'0');
	//show 数组在没有排雷的时候都是  '*'
	InitBoard(show, ROWS, COLS, '*');
	//设置雷
	SetMine(mine, ROW, COL);
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//排查雷
	Findmine(mine,show,ROW,COL);


	
}

int main()
{
	int input = 0;
	do 
	{
		menu();//菜单
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出");
			break;
		default:
			printf("输入错误");
			break;

		}
	} while (input);

	return 0;
}