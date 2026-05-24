#include "../header.h"
#include "../settings.h"

void treasure(int key, int* isCleared) {
	clear();
	printf("[ 보물 ]\n\n");
	printf("자라가 가져와 달라고 하는 보물입니다!\n");
	printf("보물을 열기 위해서는 열쇠 3개가 필요합니다.\n\n");

	if (key >= CLEAR_KEY) {
		printf("키 %d개를 다 모았군요! 이제 보물을 드릴게요!\n", CLEAR_KEY);
		*isCleared = 1;
	}
	else {
		printf("아직 %d개의 키가 부족해요.\n", CLEAR_KEY - key);
	}

	printf("ESC 키를 누르면 나가집니다.\n");
	escToExit();
	clear();
}