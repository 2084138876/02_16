#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()//�˵�
{
	printf("*******************************\n");
	printf("*******    1    ɨ��    *******\n");
	printf("*******    2    �˳�    *******\n");
	printf("*******************************\n");
	printf("��ѡ��>");
}

void game()
{
	char mine[ROWS][COLS] = {0};//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = {0};//����Ų�����׵���Ϣ
	//mine ������û�в����׵�ʱ���� '0'
	InitBoard(mine,ROWS,COLS,'0');
	//show ������û�����׵�ʱ����  '*'
	InitBoard(show, ROWS, COLS, '*');
	//������
	SetMine(mine, ROW, COL);
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//�Ų���
	Findmine(mine,show,ROW,COL);


	
}

int main()
{
	int input = 0;
	do 
	{
		menu();//�˵�
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�");
			break;
		default:
			printf("�������");
			break;

		}
	} while (input);

	return 0;
}