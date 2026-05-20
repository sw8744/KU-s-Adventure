#include "../header.h"
#include "../settings.h"

int isHolZzakSame(int chi, int a) {
	if (chi == a)
		return 1;
	else
		return 0;

}

void openCup(int a) {
	if (a == 1)
	{
		for (int i = 0; i < 2; i++) {
			clear();
			printf("%s", cup);
			Sleep(200);
			clear();
			printf("%s", cup_left);
			Sleep(200);
			clear();
			printf("%s", cup_right);
			Sleep(200);
			clear();
			printf("%s", cup);
			Sleep(1000);
		}
		clear();
		printf("%s", coin_one);
	}
	else
	{
		for (int i = 0; i < 2; i++) {
			clear();
			printf("%s", cup);
			Sleep(200);
			clear();
			printf("%s", cup_left);
			Sleep(200);
			clear();
			printf("%s", cup_right);
			Sleep(200);
			clear();
			printf("%s", cup);
			Sleep(1000);
		}
		clear();
		printf("%s", coin_two);
	}
}

void holZzak(void) {

	int a, chi, s;

	clear();
	printf("[ 홀짝 게임 ]\n\n");
	printf("홀, 짝 둘 중 하나를 고르세요. 행운을 빕니다!!\n\n");
	printf("시작하려면 스페이스를 누르세요. \n나가려면 ESC를 누르세요.\n");

	if (spaceToStart())
	{
		a = rand() % 2 + 1;

		clear();

		printf("%s", cup);


		do {
			goToXY(0, 12);
			printf("홀이면 1 짝이면 2를 입력하세요 :       \b\b\b\b\b\b");


			if (scanf("%d", &chi) != 1) {
				while (getchar() != '\n');
				continue;
			}

			if ((chi == 1) || (chi == 2))
			{
				s = isHolZzakSame(a, chi);
				if (s == 1)
				{
					clear();
					openCup(a);
					goToXY(0, 10);
					printf("성공!!\n\n");
				}
				else
				{
					clear();
					openCup(a);
					goToXY(0, 10);
					printf("실패!!\n\n");
				}
				break;
			}

		} while (1);




		printf("나가려면 ESC 키를 누르세요.");
		escToExit();
	}


}