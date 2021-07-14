#include "chess.h"
void menu()
{
	printf("***************************\n");
	printf("*****1.game     0.exit*****\n");
	printf("***************************\n");
}
void test()
{
	int input = 0;
	
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ->");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("exit\n");
				break;
			default:
				printf("wrong input\n");
				break;
		} 
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}
