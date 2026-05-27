#include "header.h"
#include "settings.h"

void goToXY(int x, int y) {
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

struct flag movePlayer(int* x, int* y, struct flag* flags, int flagSize, int width, int height) {
	while (1) {
		int ch = _getch();
;		if (ch == 'q') {
			struct flag fakeFlag = { -1, -1, -1 };
			return fakeFlag;
		}
		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			case 72: {
				if (!isNotMove(*x, (*y) - 1, flags, flagSize, width, height)) {
					(*y)--;
				}
				struct coord coord = { *x, (*y) - 1 };
				if (getFlagInfo(coord, flags, flagSize).y >= 0) {
					return getFlagInfo(coord, flags, flagSize);
				}
				break;
			}

			case 80: {
				if (!isNotMove(*x, (*y) + 1, flags, flagSize, width, height)) {
					(*y)++;
				}
				struct coord coord = { *x, (*y) + 1 };
				if (getFlagInfo(coord, flags, flagSize).y >= 0) {
					return getFlagInfo(coord, flags, flagSize);
				}
				break;
			}
	
			case 75: {
				if (!isNotMove((*x) - 1, *y, flags, flagSize, width, height)) {
					(*x)--;
				}
				struct coord coord = { (*x) - 1, *y };
				if (getFlagInfo(coord, flags, flagSize).y >= 0) {
					return getFlagInfo(coord, flags, flagSize);
				}
				break;
			}

			case 77: {
				if (!isNotMove((*x) + 1, *y, flags, flagSize, width, height)) {
					(*x)++;
				}
				struct coord coord = { (*x) + 1, *y };
				if (getFlagInfo(coord, flags, flagSize).y >= 0) {
					return getFlagInfo(coord, flags, flagSize);
				}
				break;
			}
			}
		}
		struct coord playerPos = { *x, *y };
		placePlayer(playerPos);
	}
	
}