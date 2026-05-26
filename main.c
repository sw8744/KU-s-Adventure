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

			if (isEasyCleared == -1) {
				isEasyCleared = 0;
			}

			if (isNormalCleared == -1) {
				isNormalCleared = 0;
			}

			if (isHardCleared == -1) {
				isHardCleared = 0;
			}

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
				int isGameCleared[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				struct flag flags[FLAG_COUNT_EASY];
				int x = DEFAULT_PLAYER_X_EASY, y = DEFAULT_PLAYER_Y_EASY;
				struct coord playerPos = { x, y };
				initFlags(WIDTH_EASY, HEIGHT_EASY, flags, FLAG_COUNT_EASY, playerPos);
				placeStage(WIDTH_EASY, HEIGHT_EASY);
				placeFlag(flags, FLAG_COUNT_EASY);
				placePlayer(playerPos);

				time_t startTime = time(NULL);
				while (!isEasyCleared) {
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2 - 3);
					printf("[ 나의 정보 ]");
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2 - 1);
					printf("열쇠 : %3d개", key);
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2);
					printf("코인 : %3d개", coin);
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2 + 1);
					printf("확률 : %3d%%", chance);
					
					goToXY(playerPos.x, playerPos.y);
					int game = movePlayer(&playerPos.x, &playerPos.y, flags, FLAG_COUNT_EASY, WIDTH_EASY, HEIGHT_EASY).item_id;

					if (game >= 0) {
						gameStarter(game, &coin, &key, KEY_STANDARD_EASY, &chance, isGameCleared, &isEasyCleared, startTime, TIME_STANDARD_EASY);
						clear();
						placeStage(WIDTH_EASY, HEIGHT_EASY);
						placeFlag(flags, FLAG_COUNT_EASY);
						placePlayer(playerPos);
					}
				}
				break;
			}
			case 1: {
				clear();
				int coin = 0, key = 0, chance = 0;
				int isGameCleared[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				struct flag flags[FLAG_COUNT_NORMAL];
				int x = DEFAULT_PLAYER_X_NORMAL, y = DEFAULT_PLAYER_Y_NORMAL;
				struct coord playerPos = { x, y };
				initFlags(WIDTH_NORMAL, HEIGHT_NORMAL, flags, FLAG_COUNT_NORMAL, playerPos);
				placeStage(WIDTH_NORMAL, HEIGHT_NORMAL);
				placeFlag(flags, FLAG_COUNT_NORMAL);
				placePlayer(playerPos);

				time_t startTime = time(NULL);
				while (!isNormalCleared) {
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2 - 3);
					printf("[ 나의 정보 ]");
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2 - 1);
					printf("열쇠 : %3d개", key);
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2);
					printf("코인 : %3d개", coin);
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2 + 1);
					printf("확률 : %3d%%", chance);

					goToXY(playerPos.x, playerPos.y);
					int game = movePlayer(&playerPos.x, &playerPos.y, flags, FLAG_COUNT_NORMAL, WIDTH_NORMAL, HEIGHT_NORMAL).item_id;

					if (game >= 0) {
						gameStarter(game, &coin, &key, KEY_STANDARD_NORMAL, &chance, isGameCleared, &isNormalCleared, startTime, TIME_STANDARD_NORMAL);
						clear();
						placeStage(WIDTH_NORMAL, HEIGHT_NORMAL);
						placeFlag(flags, FLAG_COUNT_NORMAL);
						placePlayer(playerPos);
					}
				}
				break;
			}
			case 2: {
				clear();
				int coin = 0, key = 0, chance = 0;
				int isGameCleared[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				struct flag flags[FLAG_COUNT_HARD];
				int x = DEFAULT_PLAYER_X_HARD, y = DEFAULT_PLAYER_Y_HARD;
				struct coord playerPos = { x, y };
				initFlags(WIDTH_HARD, HEIGHT_HARD, flags, FLAG_COUNT_HARD, playerPos);
				placeStage(WIDTH_HARD, HEIGHT_HARD);
				placeFlag(flags, FLAG_COUNT_HARD);
				placePlayer(playerPos);

				time_t startTime = time(NULL);
				while (!isHardCleared) {
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2 - 3);
					printf("[ 나의 정보 ]");
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2 - 1);
					printf("열쇠 : %3d개", key);
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2);
					printf("코인 : %3d개", coin);
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2 + 1);
					printf("확률 : %3d%%", chance);

					goToXY(playerPos.x, playerPos.y);
					int game = movePlayer(&playerPos.x, &playerPos.y, flags, FLAG_COUNT_HARD, WIDTH_HARD, HEIGHT_HARD).item_id;

					if (game >= 0) {
						gameStarter(game, &coin, &key, KEY_STANDARD_HARD, &chance, isGameCleared, &isHardCleared, startTime, TIME_STANDARD_HARD);
						clear();
						placeStage(WIDTH_HARD, HEIGHT_HARD);
						placeFlag(flags, FLAG_COUNT_HARD);
						placePlayer(playerPos);
					}
				}
				break;
			}
			}
		}
		clear();

		printAsciiXY(cutscene2, 0, 0);
		printDialog(0, 24, "자라", "자. 보물 3개를 받았으니...");
		printDialog(0, 24, "자라", "약속대로 C프로그래밍 기말고사 A+를 줄게!");
		clear();
		printAsciiXY(cutscene1, 0, 0);
		printDialog(0, 24, "KU", "자라야 A+ 줘서 고마워!");
		spaceToStart();
	}

	clear();
	printBanner(0, 0);
	printf("\n\nGame Cleared!");
	printf("나가려면 ESC 키를 누르세요.");
	escToExit();

	return 0;
}
