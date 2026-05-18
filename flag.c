#include "header.h"
#include "settings.h"

void initFlags(int width_max, int height_max, struct flag* flags, int count, struct coord playerPos) {
	for (int i = 0; i < count; i++) {
		while (1) {
			flags[i].x = random_range(1, width_max - 1);
			flags[i].y = random_range(1, height_max - 1);
			int items[5] = {0, 4, 8, 9, 10};
			flags[i].item_id = items[rand() % 5]; // FIXME: 나중에 추가되면 random_range() 사용
			if (!checkConflictFlag(i, flags, playerPos)) {
				break;
			}
		}
	}
}

int checkConflictFlag(int index, struct flag* flags, struct coord playerPos) {
	for (int i = 0; i < index; i++) {
		if (flags[i].x == flags[index].x && flags[i].y == flags[index].y) {
			return 1;
		}
	}
	if (flags[index].x == playerPos.x && flags[index].y == playerPos.y) {
		return 1;
	}
	return 0;
}

struct flag getFlagInfo(struct coord flagPos, struct flag* flags, int flagSize) {
	struct flag flag = { -1, -1, -1 };
	for (int i = 0; i < flagSize; i++) {
		if (flags[i].x == flagPos.x && flags[i].y == flagPos.y) {
			flag.x = flags[i].x;
			flag.y = flags[i].y;
			flag.item_id = flags[i].item_id;
			return flag;
		}
	}
	return flag;
}