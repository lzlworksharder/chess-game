#include <stdio.h>
#define ROW 10
#define COL 10
#include <time.h>
#include <stdlib.h>
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board,int row,int col);
void game();
void PlayerMove(char board,int row,int col);
void ComputerMove(char board,int row,int col);
char IsWin(char board[ROW][COL],int row,int col);
