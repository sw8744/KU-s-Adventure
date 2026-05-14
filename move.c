#include "header.h"
#include "settings.h"

void goToXY(int x, int y) {
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void movePlayer(int* x, int* y, struct flag* flags) {
	int ch = _getch();
	if (ch == 224) {
		ch = _getch();
		switch (ch) {
		case 72:
			if (!isNotMove(*x, (*y) - 1, flags)) {
				(*y)--;
			}
			break;

		case 80:
			if (!isNotMove(*x, (*y) + 1, flags)) {
				(*y)++;
			}
			break;

		case 75:
			if (!isNotMove((*x) - 1, *y, flags)) {
				(*x)--;
			}
			break;

		case 77:
			if (!isNotMove((*x) + 1, *y, flags)) {
				(*x)++;
			}
			break;
		}
	}
}