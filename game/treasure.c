#include "../header.h"
#include "../settings.h"

void treasure(int key, int keyStandard, int* isCleared, time_t startTime, int timeStandard) {
	clear();
	printf("[ 보물 상자 ]\n\n");
	printf("자라가 가져와 달라고 하는 보물이 담긴 보물상자입니다!\n");
	printf("보물 상자를 열기 위해서는 열쇠 %d개가 필요합니다.\n\n", keyStandard);

	if (key >= keyStandard) {
		printf("키 %d개를 다 모았군요!\n", keyStandard);
		int deltaTime = time(NULL) - startTime;
		if (deltaTime <= timeStandard) {
			printf("%d초 걸려 %d초 안에 깨셨어요! 보물을 드릴게요!\n", deltaTime, timeStandard);
			*isCleared = 1;
		}
		else {
			printf("%d초 걸려 %d초 안에 깨지 못했어요... 다시 시도해 보세요!\n", deltaTime, timeStandard);
			*isCleared = -1;
		}
	}
	else {
		printf("아직 %d개의 키가 부족해요.\n", keyStandard - key);
	}

	printf("ESC 키를 누르면 나가집니다.\n");
	escToExit();
	clear();
}