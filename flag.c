#include "header.h"
#include "settings.h"

void initFlags(int width_max, int height_max, struct flag* flags) {
	for (int i = 0; i < FLAG_COUNT; i++) {
		while (1) {
			flags[i].x = random_range(1, width_max - 1);
			flags[i].y = random_range(1, height_max - 1);
			flags[i].item_id = 0; // FIXME : 아이템 추가되면 랜덤하게 아이템을 배치해야 함
			if (!checkConflictFlag(i, flags)) {
				break;
			}
		}
	}
}

int checkConflictFlag(int index, struct flag* flags) {
	for (int i = 0; i < index; i++) {
		if (flags[i].x == flags[index].x && flags[i].y == flags[index].y) {
			return 1;
		}
	}
	if (flags[index].x == DEFAULT_PLAYER_X && flags[index].y == DEFAULT_PLAYER_Y) {
		return 1;
	}
	return 0;
}