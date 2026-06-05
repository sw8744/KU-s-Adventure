#include "../header.h"
#include "../settings.h"

int quiz() {
    clear();
    struct quiz quizs[4];
    quizInit(quizs);

    int quizNum = rand() % 4;

    clear();
    printf("[ 퀴즈 게임 ]\n\n");
    printf("랜덤으로 제공되는 퀴즈를 맞추세요!\n\n");
    printf("시작하려면 스페이스를 누르세요. \n나가려면 ESC를 누르세요.\n");

    if (spaceToStart()) {
        clear();

        int returnValue = 0;

        printf("Q. %s", quizs[quizNum].question);

        printQuizBox(0, 5, quizs[quizNum].first);
        printQuizBox(0, 8, quizs[quizNum].second);
        printQuizBox(0, 11, quizs[quizNum].third);
        printQuizBox(0, 14, quizs[quizNum].fourth);

        struct coord coords[4] = { {3, 6}, {3, 9}, {3, 12}, {3, 15} };
        int select = selectValue(coords, 4);
        if (select + 1 == quizs[quizNum].answer) {
            printf("정답입니다!\n");
            returnValue = 1;
        }
        else {
            printf("오답입니다!\n");
        }
        printf("나가려면 ESC 키를 누르세요.");
        escToExit();
        return returnValue;
    }
}

void quizInit(struct quiz* quizs) {
    quizs[0].question = "다음 중 팀 프로젝트를 진행할 때 '무임승차자'는 누구일까요?";
    quizs[0].first = "단톡방에서 읽씹하는 사람";
    quizs[0].second = "발표 당일 갑자기 조부모님이 위독하시다는 사람";
    quizs[0].third = "제가 자료조사 하겠습니다! 하고 AI 딸깍! 자료 보내는 사람";
    quizs[0].fourth = "위 모두";
    quizs[0].answer = 4;

    quizs[1].question = "다음 중 C프로그래밍(0055) 교수님의 올바른 성함은?";
    quizs[1].first = "김소영 교수님";
    quizs[1].second = "박소연 교수님";
    quizs[1].third = "박소영 교수님";
    quizs[1].fourth = "오병국 교수님";
    quizs[1].answer = 3;

    quizs[2].question = "다음 중 대학생이 팀 프로젝트 소스 코드를 제출할 때 가장 신뢰도가 높은 최종 파일 이름은 무엇일까요?";
    quizs[2].first = "main.c";
    quizs[2].second = "main_수정본_최종.c";
    quizs[2].third = "main_찐최종.c";
    quizs[2].fourth = "main_찐찐최종_이제그만_이거제출할거임.c";
    quizs[2].answer = 4;

    quizs[3].question = "소프트웨어에서 오류를 뜻하는 버그(Bug)는 과거 컴퓨터 기계 사이에 이 곤충이 끼어서 멈춘 것에서 유래되었습니다. 이 곤충은?";
    quizs[3].first = "나방";
    quizs[3].second = "파리";
    quizs[3].third = "바퀴벌레";
    quizs[3].fourth = "배추흰나비";
    quizs[3].answer = 1;

}