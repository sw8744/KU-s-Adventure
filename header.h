#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

// visual.c
extern void printBanner(int start_x, int start_y);
extern void printBox(int start_x, int start_y, char* value, int isDisabled);
extern void printDialog(int x, int y, char* name, char* dialog);
extern void printAsciiXY(char* ascii, int x, int y);
extern void placeStage(int width, int height);
extern void placeFlag(struct flag* flags, int size); 
extern void placePlayer(struct coord playerPos);

// flag.c
extern void initFlags(int width_max, int height_max, struct flag* flags, int count, struct coord playerPos);
extern int checkConflictFlag(int index, struct flag* flags, struct coord playerPos);
extern struct flag getFlagInfo(struct coord flagPos, struct flag* flags, int flagSize);

// move.c
extern void goToXY(int x, int y);
extern struct flag movePlayer(int* x, int* y, struct flag* flags, int flagSize, int width, int height);

// util.c
extern int random_range(int min, int max);
extern void clear();
extern int isNotMove(int x, int y, struct flag* flags, int flagSize, int width, int height);
extern int selectValue(struct coord* coords, int length);
extern void clearPos(int x0, int y0, int x, int y);
extern int spaceToStart();
extern void escToExit();

// game.c
extern void gameStarter(int gameID);

// ascii.c
extern char banner[];
extern char box[];
extern char disabledBox[];
extern char dialog[];
extern char cutscene1[];
extern char rock[];
extern char paper[];
extern char scissors[];
extern char scissors_reverse[];
extern char rock_reverse[];
extern char paper_reverse[];
extern char sniperHorizontal[];
extern char sniperVertical[];
extern char cham_stop[];
extern char cham_up[];
extern char cham_right[];
extern char cham_down[];
extern char cham_left[];
const char cup_left[];
const char cup[];
const char cup_right[];
const char coin_one[];
const char coin_two[];


// games
// dud.c
extern void dud();

// rockScissorsPaper.c
extern void printHand(int k, int isReverse);
extern void rockScissorsPaper();

// sniper.c
extern void sniper();

// itemQuickPick.c
extern void itemQuickPick();

// typingPractice.c
extern void typingPractice();

//chamCham.c
extern void chamCham();

//holZzak.c
extern void holZzak();


// structures
struct flag {
	int x;
	int y;
	int item_id;
};

struct coord {
	int x;
	int y;
};