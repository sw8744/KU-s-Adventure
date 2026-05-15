//가위 바위 보
#include "header.h"

void goToXY(int x, int y) {
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int rockScissorsPaper() {
	
	system("cls");



	int com, play;
	com = rand() % 3;
	//가위 0 바위 1 보 2



}