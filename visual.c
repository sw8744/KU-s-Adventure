#include "header.h"
#include "settings.h"


void placeStage(int width, int height) {
	for (int i = 0; i < width; i++) {
		printf("%s", STAGE_WALL);
	}

	printf("\n");

	for (int i = 1; i < height - 1; i++) {
		printf("%s", STAGE_WALL);
		for (int j = 1; j < width - 1; j++) {
			printf(" ");
		}
		printf("%s\n", STAGE_WALL);
	}

	for (int i = 0; i < width; i++) {
		printf("%s", STAGE_WALL);
	}
}

void placeFlag(struct flag* flags, int size) {
	for (int i = 0; i < size; i++) {
		gotoxy(flags[i].x, flags[i].y);
		printf("%s", FLAG);
	}
}

void placePlayer(int x, int y) {
	printf(" ");
	gotoxy(x, y);
	printf("%s\b", PLAYER);
}