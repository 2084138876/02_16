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

	printf("--------------------ɨ����Ϸ-----------------\n");
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
	printf("--------------------ɨ����Ϸ-----------------\n");

}



void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//�׵�λ�������������
	int x = 0;
	int y = 0;
	srand((unsigned int)time(NULL));
	int count = Easy_Count;//�����׵ĸ���
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
	//�������� (x,y)  ��Χ���׵ĸ���
	//�����ַ���ascll��ֵ����
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
		printf("������Ҫ�Ų������>");
		scanf("%d %d", &x, &y);
		//�ж������Ƿ��Ѿ����Ų����
		if (show[x][y] == '*')
		{
			//����û�б��Ų��
			
			//�����ж��������������Ƿ���������
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				//����Ϸ�   �ж�����λ���Ƿ�����(��mine�����У�
				if (mine[x][y] == '1')
				{
					//����λ������
					printf("�飡�㱻ը����\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					//����λ�ò����ף���show��������ʾ����λ����Χ�м�����
					//��mine�������ж��׵ĸ�������show��������ʾ
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//ת��Ϊ�ַ�
					//��ӡ����
					DisplayBoard(show, ROW, COL);
					win_count++;
				}
			}
			else
			{
				//����Ƿ�
				printf("����Ƿ�����������������\n");
			}
		}
		else
		{
			printf("�������Ѿ����Ų���ˣ���������������");
		}

	}


	if (win_count == row * col - Easy_Count)
	{
		printf("��ϲ�㣡���׳ɹ�\n");
	}
}
