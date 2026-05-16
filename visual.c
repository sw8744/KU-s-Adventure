#include "header.h"
#include "settings.h"
#include "ascii.h"

void printBanner(int start_x, int start_y) {
	goToXY(start_x, start_y);
	printf("%s", banner);
}

void printBox(int start_x, int start_y, char* value) {
	goToXY(start_x, start_y);
	printf("%s", box);
	goToXY(start_x + 6, start_y + 1);
	printf("%s", value);
	goToXY(start_x, start_y + 2);
}

void printAsciiXY(char* ascii, int x, int y) {
	goToXY(x, y);
	int line = 0;
	for (int i = 0; i >= 0; i++) {
		if (ascii[i] == '\0') {
			break;
		}
		if (ascii[i] == '\n') {
			goToXY(x, y + line);
			line++;
			continue;
		}
		printf("%c", ascii[i]);
	}
}

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
		goToXY(flags[i].x, flags[i].y);
		printf("%s", FLAG);
	}
}

void placePlayer(int x, int y) {
	printf(" ");
	goToXY(x, y);
	printf("%s\b", PLAYER);
}