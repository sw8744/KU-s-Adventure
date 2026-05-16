#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

// visual.c
extern void printBanner(int start_x, int start_y);
extern void printBox(int start_x, int start_y, char* value);
extern void printAsciiXY(char* ascii, int x, int y);
extern void placeStage(int width, int height);
extern void placeFlag(struct flag* flags, int size); 
extern void placePlayer(int x, int y);

// flag.c
extern void initFlags(int width_max, int height_max, struct flag* flags);
extern int checkConflictFlag(int index, struct flag* flags);

// move.c
extern void goToXY(int x, int y);
extern void movePlayer(int* x, int* y, struct flag* flags);

// util.c
extern int random_range(int min, int max);
extern void clear();
extern int isNotMove(int x, int y, struct flag* flags);
extern int selectValue(struct coord* coords, int length);
extern void clear_pos(struct coord start_coord, struct coord end_coord);

// ascii.c
extern char* banner;
extern char* box;
extern char* rock;
extern char* paper;
extern char* scissors;
extern char* scissors_reverse;
extern char* rock_reverse;
extern char* paper_reverse;

// games
// rockScissorsPaper.c
extern void printHand(int k, int isReverse);
extern void rockScissorsPaper();

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