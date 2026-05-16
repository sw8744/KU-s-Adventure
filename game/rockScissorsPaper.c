#include "../header.h"
#include "../ascii.h"

void printHand(int k, int isReverse) {
	if (!isReverse) {
		goToXY(0, 0);
		if (k == 0)
		{
			printf("%s\n", scissors);
		}
		else if (k == 1)
		{
			printf("%s\n", rock);
		}
		else if (k == 2)
		{
			printf("%s\n", paper);
		}
	}
	else {
		if (k == 0)
		{
			printAsciiXY(scissors_reverse, 20, 1);
		}
		else if (k == 1)
		{
			printAsciiXY(rock_reverse, 20, 1);
		}
		else if (k == 2)
		{
			printAsciiXY(paper_reverse, 20, 1);
		}
	}
}

void rockScissorsPaper() {
	clear();
	int com, play, fake;
	char answer[7];
	com = rand() % 3;
	fake = rand() % 3;

	if (fake == 0)
	{
		printf("%s \n ??? : 가위를 낼거야\n\n", scissors);
	}
	else if (fake == 1)
	{
		printf("%s \n ??? : 바위를 낼거야\n\n", rock);
	}
	else
	{
		printf("%s \n ??? : 보를 낼거야\n\n", paper);
	}


	//가위 0 바위 1 보 2

	do {
		com = rand() % 3;
		printf("가위, 바위, 보 중 하나를 입력하시오 : ");
		scanf("%s", answer);

		if (strcmp(answer, "바위") == 0) {
			printHand(1, 1);
			play = 1;
		}
		else if (strcmp(answer, "가위") == 0) {
			printHand(0, 1);
			play = 0;
		}
		else if (strcmp(answer, "보") == 0){
			printHand(2, 1);
			play = 2;
		}
		else
		{
			printf("올바른 값을 입력하시오\n");
			continue;
		}

		goToXY(0, 7);
		printf("??? : 안내면 진다 가위, 바위, 보!                 ");
		Sleep(3000);
		printHand(com, 0);

		if ((com - play == 1) || (com - play == -2)) //패배
		{

			printf("??? : 너의 패배야                  \n");
			break;
		}
		else if (com == play)//draw
		{
			printf("??? : 무승부야                    \n");
			break;
		}
		else if ((com - play == -1) || (com - play == 2))
		{
			printf("??? : 너의 승리야                    \n");
			break;
		}
		else
		{
			continue;
		}

		clear();
	} while (1);
	
}