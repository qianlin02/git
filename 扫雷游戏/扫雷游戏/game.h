#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols,char charater);
void DisplayBorad(char borad[ROWS][COLS], int row, int col);
void SetplayBorad(char borad[ROWS][COLS], int row, int col);
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
int Findminelei(char borad[ROWS][COLS], int x, int y);