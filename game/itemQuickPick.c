#include "../header.h"
#include "../settings.h"

void initItems(int width_max, int height_max, struct flag* items, int count, struct coord playerPos) {
	for (int i = 0; i < count; i++) {
		while (1) {
			items[i].x = random_range(1, width_max - 1);
			items[i].y = random_range(1, height_max - 1);
			items[i].item_id = 0; 
			if (!checkConflictFlag(i, items, playerPos)) {
				break;
			}
		}
	}
}

int checkWall(int x, int y, int width, int height) {
	if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
		return 1;
	}
	return 0;
}

void move(struct coord playerPos, struct flag* items, int size) {
	int x = playerPos.x, y = playerPos.y;
	int score = 0;
	while (1) {
		goToXY(x, y);
		printf("%s\b", PLAYER);
		if (score == size) {
			break;
		}
		int ch = _getch();
		if (ch == 224) {
			printf(" ");
			ch = _getch();
			switch (ch) {
			case 72:
				if (!checkWall(x, y - 1, 15, 7)) {
					y--;
				}
				break;

			case 80:
				if (!checkWall(x, y + 1, 15, 7)) {
					y++;
				}
				break;

			case 75:
				if (!checkWall(x - 1, y, 15, 7)) {
					x--;
				}
				break;

			case 77:
				if (!checkWall(x + 1, y, 15, 7)) {
					x++;
				}
				break;
			}
		}
		if (checkItem(x, y, items, 5)) {
			score++;
		}
		
	}
}

int checkItem(int x, int y, struct flag* items, int size) {
	for (int i = 0; i < size; i++) {
		if (items[i].x == x && items[i].y == y && items[i].item_id == 0) {
			items[i].item_id = 1;
			return 1;
		}
	}
	return 0;
}

int itemQuickPick() {
    clear();
    printf("[ 먹이 빨리 먹기 ]\n\n");
    printf("방향키를 눌러 자라를 조종해 먹이를 모두 먹으세요!\n\n");
    printf("시작하려면 스페이스를 누르세요. \n나가려면 ESC를 누르세요.\n");

    if (spaceToStart()) {
        clear();
        struct flag items[5];
        struct coord playerPos = { 7, 3 };
        initItems(15, 7, items, 5, playerPos);
        placeStage(15, 7);
        placeFlag(items, 5);
        placePlayer(playerPos);
		move(playerPos, items, 5);
		goToXY(0, 9);
		printf("성공!\n\n");
		printf("나가려면 ESC 키를 누르세요.\n");
		escToExit();
		return 1;
    }
}