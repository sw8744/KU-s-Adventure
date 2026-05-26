#include "header.h"
#include "settings.h"

/*
	0: 꽝, 1: 보물, 2: 상점, 3: 홀짝, 4: 가위바위보,
	5: 참참참 4방향, 6: 키 여러번 누르기, 7: 0 ~ 100 업다운,
	8: 네모칸 안에 멈추기, 9: 아이템 빨리 먹기, 10: 타자연습,
	11: 퀴즈
*/

void gameStarter(int gameID, int* coin, int* key, int chance, int* isGameCleared, int* isStageCleared) {
	int rewardCoin = 0, isCleared = 0;
	switch (gameID) {
	case 0: {
		dud();
		break;
	}
	case 1: {
		treasure(*key, isStageCleared);
		break;
	}
	case 2: {
		// TODO: 상점 관련 작업 필요
		break;
	}
	case 3: {
		isCleared = holZzak();
		rewardCoin = 2;
		break;
	}
	case 4: {
		isCleared = rockScissorsPaper();
		rewardCoin = 2;
		break;
	}
	case 5: {
		isCleared = chamCham();
		rewardCoin = 5;
		break;
	}
	case 6: {
		isCleared = pressKey();
		rewardCoin = 5;
		break;
	}
	case 7: {
		isCleared = upDown();
		rewardCoin = 7;
		break;
	}
	case 8: {
		isCleared = sniper();
		rewardCoin = 7;
		break;
	}
	case 9: {
		isCleared = itemQuickPick();
		rewardCoin = 10;
		break;
	}
	case 10: {
		isCleared = typingPractice();
		rewardCoin = 10;
		break;
	}
	case 11: {
		isCleared = quiz();
		rewardCoin = 10;
		break;
	}
	}
	clear();
	if (isCleared) {
		reward(coin, key, chance, rewardCoin, isGameCleared[gameID]);
		isGameCleared[gameID] = 1;
		clear();
	}
}