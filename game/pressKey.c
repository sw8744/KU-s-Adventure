#include "../header.h"
#include "../settings.h"

int pressKey() {
    clear();

    int hitCount = HIT_COUNT;

    printf("[ SPACEBAR SPEEDRUN GAME ]\n\n");
    printf("제한 시간 내에 목표치를 달성하세요!\n");
    printf("  입력 키 : [ Spacebar ]\n");
    printf("  목표 횟수: %d회\n", TARGET_GOAL);
    printf("  제한 시간: %d초\n\n", GAME_DURATION);
    printf("시작 신호와 함께 스페이스바를 갈기세요!\n");

    printf("시작하려면 Spacebar를 누르세요.\n");
    spaceToStart();

    // 초기 카운트 표시
    printf(" 현재 연타 횟수: [%d / %d]", hitCount, TARGET_GOAL);

    // 게임 시작 시간 기록
    time_t startTime = time(NULL);

    // 제한 시간 내에 도는 루프
    while (time(NULL) - startTime < GAME_DURATION) {

        if (_kbhit()) {
            char inputKey = _getch();

            if (inputKey == ' ') {
                hitCount++;

                printf("\r 현재 연타 횟수: [%d / %d]", hitCount, TARGET_GOAL);
                fflush(stdout);
            }

            // 목표치 달성 시 즉시 게임 종료
            if (hitCount >= TARGET_GOAL) {
                printf("\n\n 목표 달성 성공! 시스템을 종료합니다.\n");
                break;
            }
        }
    }

    // 결과 출력
    time_t totalTime = time(NULL) - startTime;
    int returnValue = 0;
    if (hitCount >= TARGET_GOAL) {
        printf(" 축하합니다! 걸린 시간: [%ld초]!\n", totalTime); 
        returnValue = 1;
    }
    else {
        printf("\n 시간 초과... (최종 %d회 연타)\n", hitCount);
    }
    
    printf("나가려면 ESC 키를 누르세요.");
    escToExit();
    return returnValue;
}