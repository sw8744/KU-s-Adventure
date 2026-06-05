#include "header.h"
#include "settings.h"

int main(void) {
	int isEasyCleared = 0, isNormalCleared = 0, isHardCleared = 0;
	int isEasySelected = 0, isNormalSelected = 0, isHardSelected = 0;
	srand((unsigned)time(NULL));
	initSound();
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
		printDialog(0, 24, "KU", "휴! 언제 다 보물을 모으지…");
		printDialog(0, 24, "KU", "그래도 A+를 받을 수만 있다면…");
		printDialog(0, 24, "KU", "가자! 보물을 찾으러 일감호로!");

		int stageOrder[3] = { -1, -1, -1 };
		int gameIndex = 0;

		for (int i = 0; i < 3; i++) {
			clear();

			// 난이도 선택
			printBanner(0, 0);
			printBox(0, 7, "쉬움(200초)", isEasySelected);
			printBox(0, 10, "보통(300초)", isNormalSelected);
			printBox(0, 13, "어려움(400초)", isHardSelected);

			struct coord coords[3] = { {3, -1}, {3, -1}, {3, -1} };
			int length = 3;

			if (!isEasySelected) {
				coords[0].x = 3;
				coords[0].y = 8;
			}

			if (!isNormalSelected) {
				coords[1].x = 3;
				coords[1].y = 11;
			}

			if (!isHardSelected) {
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
			stageOrder[gameIndex] = select;

			switch (select) {
			case 0:
				isEasySelected = 1;
				gameIndex++;
				break;
			case 1:
				isNormalSelected = 1;
				gameIndex++;
				break;
			case 2:
				isHardSelected = 1;
				gameIndex++;
				break;
			}
		}

		gameIndex = 0;
		while (1) {
			if (isEasyCleared && isNormalCleared && isHardCleared) {
				break;
			}

			select = stageOrder[gameIndex];

			switch (select) {
			case 0: {
				clear();
				int coin = 0, key = 0, chance = 0;
				int isGameCleared[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				struct flag flags[FLAG_COUNT_EASY];
				int x = DEFAULT_PLAYER_X_EASY, y = DEFAULT_PLAYER_Y_EASY;
				struct coord playerPos = { x, y };
				initFlags(WIDTH_EASY, HEIGHT_EASY, flags, FLAG_COUNT_EASY, playerPos);
				placeFlag(flags, FLAG_COUNT_EASY);
				placePlayer(playerPos);
				placeStage(WIDTH_EASY, HEIGHT_EASY);

				time_t startTime = time(NULL);
				while (!isEasyCleared) {
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2 - 3);
					printf("[ 나의 정보 ]");
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2 - 1);
					printf("난도 : 쉬움");
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2);
					printf("열쇠 : %3d개", key);
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2 + 1);
					printf("코인 : %3d개", coin);
					goToXY(WIDTH_EASY + 5, HEIGHT_EASY / 2 + 2);
					printf("확률 : %3d%%", chance);
					
					goToXY(playerPos.x, playerPos.y);
					int game = movePlayer(&playerPos.x, &playerPos.y, flags, FLAG_COUNT_EASY, WIDTH_EASY, HEIGHT_EASY).item_id;

					if (game >= -2) {
						gameStarter(game, &coin, &key, KEY_STANDARD_EASY, &chance, isGameCleared, &isEasyCleared, startTime, TIME_STANDARD_EASY);
						clear();
						placeFlag(flags, FLAG_COUNT_EASY);
						placePlayer(playerPos);
						placeStage(WIDTH_EASY, HEIGHT_EASY);
					}
				}
				gameIndex += isEasyCleared;
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
				placeFlag(flags, FLAG_COUNT_NORMAL);
				placePlayer(playerPos);
				placeStage(WIDTH_NORMAL, HEIGHT_NORMAL);

				time_t startTime = time(NULL);
				while (!isNormalCleared) {
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2 - 3);
					printf("[ 나의 정보 ]");
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2 - 1);
					printf("난도 : 보통");
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2);
					printf("열쇠 : %3d개", key);
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2 + 1);
					printf("코인 : %3d개", coin);
					goToXY(WIDTH_NORMAL + 5, HEIGHT_NORMAL / 2 + 2);
					printf("확률 : %3d%%", chance);

					goToXY(playerPos.x, playerPos.y);
					int game = movePlayer(&playerPos.x, &playerPos.y, flags, FLAG_COUNT_NORMAL, WIDTH_NORMAL, HEIGHT_NORMAL).item_id;

					if (game >= -2) {
						gameStarter(game, &coin, &key, KEY_STANDARD_NORMAL, &chance, isGameCleared, &isNormalCleared, startTime, TIME_STANDARD_NORMAL);
						clear();
						placeFlag(flags, FLAG_COUNT_NORMAL);
						placePlayer(playerPos);
						placeStage(WIDTH_NORMAL, HEIGHT_NORMAL);
					}
				}
				gameIndex += isNormalCleared;
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
				placeFlag(flags, FLAG_COUNT_HARD);
				placePlayer(playerPos);
				placeStage(WIDTH_HARD, HEIGHT_HARD);

				time_t startTime = time(NULL);
				while (!isHardCleared) {
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2 - 3);
					printf("[ 나의 정보 ]");
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2 - 1);
					printf("난도 : 어려움");
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2);
					printf("열쇠 : %3d개", key);
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2 + 1);
					printf("코인 : %3d개", coin);
					goToXY(WIDTH_HARD + 5, HEIGHT_HARD / 2 + 2);
					printf("확률 : %3d%%", chance);

					goToXY(playerPos.x, playerPos.y);
					int game = movePlayer(&playerPos.x, &playerPos.y, flags, FLAG_COUNT_HARD, WIDTH_HARD, HEIGHT_HARD).item_id;

					if (game >= -2) {
						gameStarter(game, &coin, &key, KEY_STANDARD_HARD, &chance, isGameCleared, &isHardCleared, startTime, TIME_STANDARD_HARD);
						clear();
						placeFlag(flags, FLAG_COUNT_HARD);
						placePlayer(playerPos);
						placeStage(WIDTH_HARD, HEIGHT_HARD);
					}
				}
				gameIndex += isHardCleared;
				break;
			}
			}
			if (isEasyCleared == -1) {
				gameIndex++;
				isEasyCleared = 0;
			}

			if (isNormalCleared == -1) {
				gameIndex++;
				isNormalCleared = 0;
			}

			if (isHardCleared == -1) {
				gameIndex++;
				isHardCleared = 0;
			}
		}
		clear();

		printAsciiXY(cutscene2, 0, 0);
		printDialog(0, 24, "자라", "보물 3개를 가져왔군!");
		printDialog(0, 24, "자라", "너가 원하는 건 C프로그래밍 A+이지?");
		printDialog(0, 24, "자라", "하지만 너는 보물을 찾으면서 성장하여");
		printDialog(0, 24, "자라", "이미 A+를 받을 정도의 능력을 갖추게 되었어.");
		printDialog(0, 24, "자라", "기말고사도 화이팅!");
		clear();
		printAsciiXY(cutscene1, 0, 0);
		printDialog(0, 24, "KU", "내가 그 정도 실력이 되었다고…?");
		printDialog(0, 24, "KU", "생각해 보니 내 C언어 실력도 확실히 성장한 것 같아.");
		printDialog(0, 24, "KU", "자라야 고마워!");
		clear();
		printDialog(0, 24, "", "과연 KU는 A+을 맞을 수 있을까?");
		clear();
		printBanner(0, 0);
		printf("\n\nGame Cleared!");
	}

	printf("\n\n나가려면 ESC 키를 누르세요.\n");
	escToExit();

	return 0;
}
