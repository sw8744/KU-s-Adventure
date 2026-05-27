#include "../header.h"
#include "../settings.h"

int sniper() {
    clear();

    int isHorizontalAligned = 0, isVerticalAligned = 0;
    int returnValue = 0;

    printf("[ 스나이퍼 ]\n\n");
    printf("자라가 먹이 사냥에 어려움을 겪고 있네요!\n");
    printf("Enter 키를 눌러 움직이는 사각형을 틀 안에 넣어 조준경을 정렬해 자라를 도우세요!\n\n");
    printf("시작하려면 스페이스를 누르세요. \n나가려면 ESC를 누르세요.\n");
    
    if (spaceToStart()) {
        clear();
        int x = 1, y = 5;

        printAsciiXY(sniperHorizontal, 0, 4);
        printAsciiXY(sniperVertical, 6, 0);
        goToXY(x, y);
        printf("%s\b", "■");
        time_t startTime = time(NULL);
        while (1) {
            time_t endTime = time(NULL);
            if (endTime - startTime >= 1) {
                startTime = endTime;
                x++;
                printAsciiXY(sniperHorizontal, 0, 4);
                goToXY(x, y);
                printf("%s\b", "■");
            }
            if (_kbhit()) {
                char ch = _getch();
                if (ch == 13) {
                    if (x == 7) {
                        isHorizontalAligned = 1;
                    }
                    break;
                }
            }
            if (x > 13) {
                break;
            }
        }
        if (isHorizontalAligned) {
            clear();
            int x = 7, y = 1;
            printAsciiXY(sniperHorizontal, 0, 4);
            printAsciiXY(sniperVertical, 6, 0);
            goToXY(x, y);
            printf("%s\b", "■");
            time_t startTime = time(NULL);
            while (1) {
                time_t endTime = time(NULL);
                if (endTime - startTime >= 1) {
                    startTime = endTime;
                    y++;
                    printAsciiXY(sniperVertical, 6, 0);
                    goToXY(x, y);
                    printf("%s\b", "■");
                }
                if (_kbhit()) {
                    char ch = _getch();
                    if (ch == 13) {
                        if (y == 5) {
                            isVerticalAligned = 1;
                        }
                        break;
                    }
                }
                if (y > 9) {
                    break;
                }
            }
        }
        goToXY(0, 13);
        if (isHorizontalAligned && isVerticalAligned) {
            printf("조준경 정렬에 성공했습니다!\n\n");
            returnValue = 1;
        }
        else {
            printf("조준경 정렬에 실패했습니다!\n\n");
        }
        printf("나가려면 ESC 키를 누르세요.");
        escToExit();
    }
    return returnValue;
}