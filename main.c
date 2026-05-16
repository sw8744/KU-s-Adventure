#include "header.h"
#include "settings.h"

int main(void) {
	struct flag flags[FLAG_COUNT];
	int x = DEFAULT_PLAYER_X, y = DEFAULT_PLAYER_Y - 1;

	srand((unsigned)time(NULL));

	initFlags(WIDTH, HEIGHT, flags);

	printBanner(0, 0);
	printBox(0, 7, "Game Start");
	printBox(0, 10, "Exit");

	struct coord coords[2] = {{3, 8}, {3, 11}};
	int select = selectValue(coords, 2);

	if (!select) {
		clear();
		placeStage(WIDTH, HEIGHT); // 가로 : 세로 = 2 : 1 정도 비율로 해야 정사각형 처럼 나옴!?
		placeFlag(flags, FLAG_COUNT);
		goToXY(WIDTH, HEIGHT);

		rockScissorsPaper();

		/*while (1) {
			placePlayer(x, y);
			movePlayer(&x, &y, flags);
		}*/
	}
	return 0;
}
