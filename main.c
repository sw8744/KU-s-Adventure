#include "header.h"
#include "settings.h"

int main(void) {
	int isEasyCleared = 0, isNormalCleared = 0, isHardCleared = 0;
	srand((unsigned)time(NULL));

	// 게임 시작 여부 선택
	printBanner(0, 0);
	printBox(0, 7, "시작", 0);
	printBox(0, 10, "나가기", 0);

	struct coord coords[2] = {{3, 8}, {3, 11}};
	int select = selectValue(coords, 2);

	if (!select) {
		clear();

		printAsciiXY(cutscene1, 0, 0);
		clearPos(0, 24, 60, 30);
		printDialog(0, 24, "KU", "안녕! 나는 KU야!");
		printDialog(0, 24, "KU", "지금 C프로그래밍 A+를 받기 위해 일감호에 왔어.");
		printDialog(0, 24, "KU", "어! 저기 자라가 있어!");
		clear();
		printAsciiXY(cutscene2, 0, 0);
		printDialog(0, 24, "자라", "안녕! 나는 자라야!");
		printDialog(0, 24, "자라", "A+를 받고 싶다면 일감호에서 보물 3개를 얻어 와!");
		clear();
		printAsciiXY(cutscene1, 0, 0);
		printDialog(0, 24, "KU", "휴! 언제 다 보물을 모으지...");
		printDialog(0, 24, "KU", "그래도 A+를 받을 수만 있다면...");
		printDialog(0, 24, "KU", "가자! 보물을 찾으러 일감호로!");

		while (1) {
			if (isEasyCleared && isNormalCleared && isHardCleared) {
				break;
			}
			
			clear();

			// 난이도 선택
			printBanner(0, 0);
			printBox(0, 7, "쉬움", isEasyCleared);
			printBox(0, 10, "보통", isNormalCleared);
			printBox(0, 13, "어려움", isHardCleared);

			struct coord coords[3] = { {3, -1}, {3, -1}, {3, -1} };
			int length = 3;

			if (!isEasyCleared) {
				coords[0].x = 3;
				coords[0].y = 8;
			}

			if (!isNormalCleared) {
				coords[1].x = 3;
				coords[1].y = 11;
			}

			if (!isHardCleared) {
				coords[2].x = 3;
				coords[2].y = 14;
			}
			
			for (int i = 0; i < 3; i++) {
				if (coords[i].y >= 0) {
					goToXY(coords[i].x, coords[i].y);
					break;
				}
			}

			int select = selectValue(coords, length);

			switch (select) {
			case 0: {
				clear();
				int coin = 0, key = 0, chance = 0;
				int isGameCleared[12] = { 0 };
				struct flag flags[FLAG_COUNT_EASY];
				int x = DEFAULT_PLAYER_X_EASY, y = DEFAULT_PLAYER_Y_EASY;
				struct coord playerPos = { x, y };
				initFlags(WIDTH_EASY, HEIGHT_EASY, flags, FLAG_COUNT_EASY, playerPos);
				placeStage(WIDTH_EASY, HEIGHT_EASY);
				placeFlag(flags, FLAG_COUNT_EASY);
				placePlayer(playerPos);

				while (!isEasyCleared) {
					goToXY(0, 20);
					printf("coin: %d / ", coin);
					printf("key: %d", isGameCleared[10]);
					goToXY(playerPos.x, playerPos.y);
					int game = movePlayer(&playerPos.x, &playerPos.y, flags, FLAG_COUNT_EASY, WIDTH_EASY, HEIGHT_EASY).item_id;

					if (game >= 0) {
						gameStarter(game, &coin, &key, chance, isGameCleared, &isEasyCleared);
						clear();
						placeStage(WIDTH_EASY, HEIGHT_EASY);
						placeFlag(flags, FLAG_COUNT_EASY);
						placePlayer(playerPos);
					}
					
				}
				break;
			}
			case 1: {
				isNormalCleared = 1;
				break;
			}
			case 2: {
				isHardCleared = 1;
				break;
			}
			}
		}
		clear();

		printAsciiXY(cutscene1, 0, 0);
		clearPos(0, 24, 60, 30);
		printDialog(0, 24, "KU", "A + 줘서 고마워 자라야!");
		spaceToStart();

	}

	clear();
	printBanner(0, 0);
	printf("\n\nGame Cleared!");

	return 0;
}
