#include "header.h"
#include "settings.h"

void printBanner(int start_x, int start_y) {
	goToXY(start_x, start_y);
	printf("%s", banner);
}

void printBox(int start_x, int start_y, char* value, int isDisabled) {
	goToXY(start_x, start_y);
	if (isDisabled) {
		printf("%s", disabledBox);
	}
	else {
		printf("%s", box);
	}
	goToXY(start_x + 6, start_y + 1);
	printf("%s", value);
	goToXY(start_x, start_y + 2);
}

void printQuizBox(int start_x, int start_y, char* value) {
	goToXY(start_x, start_y);
	printf("%s", quizBox);
	goToXY(start_x + 6, start_y + 1);
	printf("%s", value);
	goToXY(start_x, start_y + 2);
}

void printDialog(int x, int y, char* name, char* conv) {
	printAsciiXY(dialog, x, y);
	goToXY(x + 1, y + 1);
	printf("[ %s ]", name);
	goToXY(x + 1, y + 3);
	printf("%s", conv);
	goToXY(0, y + 5);
	spaceToStart();
}

void printAsciiXY(char* ascii, int x, int y) {
	goToXY(x, y);
	int line = 0;
	for (int i = 0; i >= 0; i++) {
		if (ascii[i] == '\0') {
			break;
		}
		if (ascii[i] == '\n') {
			line++;
			goToXY(x, y + line);
			continue;
		}
		printf("%c", ascii[i]);
	}
}

void placeStage(int width, int height) {
	goToXY(0, 0);
	for (int i = 0; i < width; i++) {
		printf("%s", STAGE_WALL);
	}

	printf("\n");

	for (int i = 1; i < height - 1; i++) {
		goToXY(0, i);
		printf("%s", STAGE_WALL);
		goToXY(width - 1, i);
		printf("%s", STAGE_WALL);
	}

	printf("\n");

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

void placePlayer(struct coord playerPos) {
	printf(" ");
	goToXY(playerPos.x, playerPos.y);
	printf("%s\b", PLAYER);
}

