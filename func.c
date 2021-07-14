#include "chess.h"

void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j<col-1) printf("|");
		}
		printf("\n");
		if (i<row-1)
		{
			for (j=0;j<col;j++)
			{
				printf("---");
				if (j<col-1) printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����������-> ");
		scanf("%d%d",&x,&y);
		if (x>=1 && x<=row && y>=1 && y<=row)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else printf("��λ�ñ�ռ��\n");
		}
		else printf("��λ�÷Ƿ�\n");
	}
}

void ComputerMove(char board[ROW][COL],int row,int col)
{
	
	while (1)
	{
		int x = rand()%row;
		int y = rand()%col;
		if (board[x][y] == ' ' && x<row && y<col) 
		{
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	int com = 0;
	// ��һ��:
	for (int i=0;i<row;i++)
	{
		int com = board[i][0];
		for (int j=0;j<col;j++)
		{
			if (board[i][j] == ' ') com = 1;
			else com = com^board[i][j];
		}
		if (com == 0 || com == board[i][0]) return board[i][0];
	 } 
	// ��һ��:
	for (int j=0;j<col;j++)
	{
		int com = board[0][j];
		for (int i=0;i<row;i++)
		{
			if (board[i][j] == ' ') com = 1;
			else com = com^board[i][j];
		}
		if (com == 0 || com == board[0][j]) return board[0][j];
	}
	// ���Խ���:
	com = board[0][0];
	for (int i=0;i<row;i++)
	{
		
		if (board[i][i] == ' ') com = 1;
		else com = com^board[i][i];
	}
	if (com == 0 || com == board[0][0]) return board[0][0];
	// ���Խ���:
	com = board[0][col-1];
	for (int i=0;i<row;i++)
	{
		if (board[i][row-1-i] == ' ') com = 1;
		else com = com^board[i][row-1-i];
	}
	if (com == 0 || com == board[0][col-1]) return board[0][col-1];
	// ƽ��:
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			if (board[i][j] == ' ') return 'C';
		}
	 } 
	return 'Q';

	 
	
	
}

// ��Ϸ�㷨ʵ�� 
void game()
{
	// ����-����߳���������Ϣ 
	char board[ROW][COL] = {'a'}; // ȫ���ո� 
	// ��ʼ������
	InitBoard(board,ROW,COL); 
	// ��ӡ����
	DisplayBoard(board,ROW,COL);  
	char ret = ' ';
	while (1)
	{
		
		// player
		PlayerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		// �ж���Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret != 'C') break;
		// computer
		ComputerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		ret = IsWin(board,ROW,COL);
		if (ret != 'C') break;	
	}
	if (ret == '*') printf("���Ӯ\n");
	else if (ret == '#') printf("����Ӯ\n");
	else if (ret == 'Q') printf("ƽ��\n");
}
	
	
	
	
	
	
	
	
	
	

