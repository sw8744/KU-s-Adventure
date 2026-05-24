#include "../header.h"
#include "../settings.h"

int isRealAnswer(int com, int choice) {
	if (com == choice) {
		return 1;
	}
	else if (com > choice) {
		return 2;
	}
	else if (com < choice) {
		return 3;
	}

}

int upDown(void) {

	int com = rand() % 97 + 1;
	int choice, result, i;
	int arr[5] = { 0,0,0,0,0 };
	char ch;

	clear();
	printf("[ 업다운 게임 ]\n\n");
	printf("1부터 100까지의 수를 유추해 보세요. 행운을 빕니다!!\n\n");
	printf("시작하려면 스페이스를 누르세요. \n나가려면 ESC를 누르세요.\n");

	if (spaceToStart()) {
		clear();

		printf("%s", five_blank);
		goToXY(3, 2);
		printf("%02d  %02d | %02d | %02d  %02d", arr[0], arr[1], arr[2], arr[3], arr[4]);

		do {
			goToXY(0, 4);
			printf("1~100 사이의 자연수를 입력하세요 : ");
			if (_kbhit()) {
				goToXY(3, 2);
				printf("%02d  %02d | %02d | %02d  %02d", arr[0], arr[1], arr[2], arr[3], arr[4]);
				goToXY(0, 4);
				printf("1~100 사이의 자연수를 입력하세요 :      \b\b\b\b\b");
				if (scanf("%d", &choice) != 1) {
					while (getchar() != '\n');
					continue;
				}

				arr[2] = choice;
				arr[0] = arr[2] - 2;
				arr[1] = arr[2] - 1;
				arr[3] = arr[2] + 1;
				arr[4] = arr[2] + 2;
				goToXY(3, 2);
				printf("%02d  %02d | %02d | %02d  %02d  |        \b\b\b\b\b\b\b\b", arr[0], arr[1], arr[2], arr[3], arr[4]);

				result = isRealAnswer(com, choice);
				if (result == 1) {
					break;
				}
				else if (result == 2) {
					goToXY(0, 5);
					printf("UP    \b\b\b\b");
				}
				else if (result == 3) {
					goToXY(0, 5);
					printf("DOWN    \b\b\b\b");
				}
			}
		} while (1);

		goToXY(0, 6);
		printf("정확합니다!!\n\n");
		printf("나가려면 ESC 키를 누르세요.");
		escToExit();
		return 1;
	}
}