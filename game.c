#define _CRT_SECURE_NO_WARNINGS
#include "game.h"



void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}



void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	printf("--------------------扫雷游戏-----------------\n");
	printf("  ");
	for (j = 1; j <=col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	printf("-+------------------");
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d|", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("--------------------扫雷游戏-----------------\n");

}



void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//雷的位置由随机数生成
	int x = 0;
	int y = 0;
	srand((unsigned int)time(NULL));
	int count = Easy_Count;//设置雷的个数
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


int get_mine_count(char mine[ROWS][COLS], int x,int y)
{
	//计算坐标 (x,y)  周围的雷的个数
	//根据字符的ascll码值计算
	int count = mine[x - 1][y] + mine[x + 1][y] + mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y - 1] + mine[x + 1][y - 1] + mine[x - 1][y + 1] + mine[x + 1][y + 1] - 8 * '0';
	return count;
}





void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win_count = 0;

	while (win_count<row*col-Easy_Count)
	{
		printf("请输入要排查的坐标>");
		scanf("%d %d", &x, &y);
		//判断坐标是否已经被排查过了
		if (show[x][y] == '*')
		{
			//坐标没有被排查过
			
			//首先判断玩家输入的坐标是否在棋盘内
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				//坐标合法   判断坐标位置是否是雷(在mine棋盘中）
				if (mine[x][y] == '1')
				{
					//坐标位置是雷
					printf("砰！你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					//坐标位置不是雷，在show棋盘中显示坐标位置周围有几颗雷
					//在mine棋盘中判断雷的个数，在show棋盘中显示
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//转化为字符
					//打印棋盘
					DisplayBoard(show, ROW, COL);
					win_count++;
				}
			}
			else
			{
				//坐标非法
				printf("坐标非法！请重新输入坐标\n");
			}
		}
		else
		{
			printf("该坐标已经被排查过了，请重新输入坐标");
		}

	}


	if (win_count == row * col - Easy_Count)
	{
		printf("恭喜你！排雷成功\n");
	}
}
