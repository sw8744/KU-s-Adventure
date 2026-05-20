#include "header.h"
#include "settings.h"

/*
	0: 꽝, 1: 보물, 2: 상점, 3: 홀짝, 4: 가위바위보,
	5: 참참참 4방향, 6: 키 여러번 누르기, 7: 0 ~ 100 업다운,
	8: 네모칸 안에 멈추기, 9: 아이템 빨리 먹기, 10: 타자연습,
	11: 퀴즈
*/

void gameStarter(int gameID) {
	switch (gameID) {
	case 0: {
		dud();
		break;
	}
	case 1: {
		// TODO: 보물 클리어 관련 작업 필요
		break;
	}
	case 2: {
		// TODO: 상점 관련 작업 필요
		break;
	}
	case 3: {
		holZzak();
		break;
	}
	case 4: {
		rockScissorsPaper();
		break;
	}
	case 5: {
		chamCham();
		break;
	}
	case 6: {
		// TODO: 키 여러번 누르기 관련 작업 필요
		break;
	}
	case 7: {
		// TODO: 업다운 관련 작업 필요
		break;
	}
	case 8: {
		sniper();
		break;
	}
	case 9: {
		itemQuickPick();
		break;
	}
	case 10: {
		typingPractice();
		break;
	}
	case 11: {
		// TODO: 퀴즈 관련 작업 필요
		break;
	}
	}
}