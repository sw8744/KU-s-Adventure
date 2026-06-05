#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

// visual.c
extern void printBanner(int start_x, int start_y);
extern void printBox(int start_x, int start_y, char* value, int isDisabled);
extern void printQuizBox(int start_x, int start_y, char* value);
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
extern void reward(int* coin, int* key, int chance, int reward, int isAlreadyCleared);

// game.c
extern void gameStarter(int gameID, int* coin, int* key, int keyStandard, int* chance, int* isGameCleared, int* isStageCleared, time_t startTime, int standardTime);

// ascii.c
extern char banner[];
extern char storeBanner[];
extern char box[];
extern char disabledBox[];
extern char quizBox[];
extern char dialog[];
extern char cutscene1[];
extern char cutscene2[];
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
extern char cup_left[];
extern char cup[];
extern char cup_right[];
extern char coin_one[];
extern char coin_two[];
extern char five_blank[];

// games
// dud.c
extern void dud();

// store.c
extern void store(int* coin, int* keys, int* chance);

// treasure.c
extern void treasure(int key, int keyStandard, int* isCleared, time_t startTime, int timeStandard);

// rockScissorsPaper.c
extern void printHand(int k, int isReverse);
extern int rockScissorsPaper();

// upDown.c
extern int upDown();

// sniper.c
extern int sniper();

// itemQuickPick.c
extern void initItems(int width_max, int height_max, struct flag* items, int count, struct coord playerPos);
extern void move(struct coord playerPos, struct flag* items, int size);
extern int checkItem(int x, int y, struct flag* items, int size);
extern int itemQuickPick();

// typingPractice.c
extern int typingPractice();

//chamCham.c
extern int chamCham();

// pressKey.c
extern int pressKey();

//holZzak.c
extern int holZzak();

// quiz.c
extern int quiz();
extern void quizInit(struct quiz* quizs);

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

struct quiz {
	char* question;
	char* first;
	char* second;
	char* third;
	char* fourth;
	int answer;
};