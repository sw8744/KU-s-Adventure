#define _CRT_SEUCRE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

// visual.c
extern void placeStage(int width, int height);
extern void placeFlag(struct flag* flags, int size); 
extern void placePlayer(int x, int y);

// flag.c
extern void initFlags(int width_max, int height_max, struct flag* flags);
extern int checkConflictFlag(int index, struct flag* flags);

// move.c
extern void gotoxy(int x, int y);
extern void movePlayer(int* x, int* y, struct flag* flags);

// util.c
extern int random_range(int min, int max);
extern void clear();
extern int isNotMove(int x, int y, struct flag* flags);

// structures
struct flag {
	int x;
	int y;
	int item_id;
};