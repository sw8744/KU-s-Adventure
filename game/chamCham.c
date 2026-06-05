#include "../header.h"
#include "../settings.h"

void dirCham(int a) {
	goToXY(0, 0);

	if (a == 1){
		printf("%s", cham_up);
	}
	else if (a == 2){
		printf("%s", cham_right);
	}
	else if (a == 3){
		printf("%s", cham_down);
	}
	else if (a == 4){
		printf("%s", cham_left);
	}
	else if (a == 0){
		printf("%s", cham_stop);
	}
}

int isSameDir(int a, int k, int c) {
	if (c == 1) {
		if (a == k)
			return 1;
		else
			return 0;
	}
	else
		return 0;

}

int chamCham(void) {
	clear();
	printf("[ 참참참 2.0 ]\n\n");
	printf("화살표가 가르키는 방향에 대한 방향키를 1초 안에 누르세요!\n\n");
	printf("시작하려면 스페이스를 누르세요. \n나가려면 ESC를 누르세요.\n");


	if (spaceToStart()) {
		clear();

		time_t s_time = time(NULL);
		time_t current_time;
		time_t last_time = 0;
		int a = rand() % 4 + 1;
		int c = 0; //가능 여부
		int k = 0;
		int e = 0;
		int ch;

		dirCham(0);
		goToXY(0, 16);
		printf("연속 성공 횟수 : %d / 4", e);

		while (e <= 3) {
			current_time = time(0);

			if (current_time != last_time) {
				time_t elapsed = current_time - s_time;

				if (elapsed < 2){
					c = 0;
					dirCham(0);
				}
				else if (elapsed == 2) {
					c = 1;
					dirCham(a);
				}
				else if (elapsed >= 3) {
					c = 0;
					s_time = current_time;
					a = rand() % 4 + 1;
					dirCham(0);
				}
				last_time = current_time;
			}

			if (_kbhit()) {
				ch = _getch();
				if (ch == 224) {
					ch = _getch();
					switch (ch) {
					case 72:
						k = 1;
						if (isSameDir(a, k, c)) {
							e += 1;
						}
						else {
							e = 0;
						}
						break;
					case 77:
						k = 2;
						if (isSameDir(a, k, c)) {
							e += 1;
						}
						else {
							e = 0;
						}
						break;
					case 80:
						k = 3;
						if (isSameDir(a, k, c)) {
							e += 1;
						}
						else {
							e = 0;
						}
						break;
					case 75:
						k = 4;
						if (isSameDir(a, k, c)) {
							e += 1;
						}
						else {
							e = 0;
						}
						break;
					}
				}
				else {
					e = 0;
				}
				goToXY(0, 16);
				printf("연속 성공 횟수 : %d / 4", e);
			}
		}
		goToXY(0, 15);
		printf("성공!!\n");
		printf("나가려면 ESC 키를 누르세요.");
		escToExit();
		return 1;
	}
}