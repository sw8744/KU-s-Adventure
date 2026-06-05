#include "../header.h"
#include "../settings.h"

void dud() {
    clear();

    printf("[ 꽝 ]\n\n");

    char dud[6][100] = {
        "놀라지 마세요. 아무 일도 일어나지 않았습니다.",
        "축하합니다! 맑고 깨끗한 '공기'에 당첨되셨습니다.",
        "...놀랍도록 아무일도 없었다...",
        "허탕을 쳤다!",
        "꽝! 띠로리~",
        "앗! A + 이 아니라 B + 이었다!"
    };

    int randomIndex = rand() % 6;
    printf("%s\n\n", dud[randomIndex]);

    printf("나가려면 %d초를 기다려야 합니다.\n\n", DUD_SECONDS);
    Sleep(DUD_SECONDS * 1000);
    
    printf("나가려면 ESC를 누르세요.\n");
    escToExit();
}