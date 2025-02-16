#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <time.h>
#include <stdlib.h>


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Easy_Count 10//À×µÄ¸öÊý

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row,int col);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS],int row,int col);
