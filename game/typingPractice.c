#include "../header.h"
#include "../settings.h"

void typingPractice() {
    clear();
    char sentences[NUM_SENTENCES][MAX_LENGTH] = {
        "변수의 범위는 변수가 사용 가능한 가시성을 뜻한다.",
        "생존 시간은 변수가 메모리에 존재하는 시간이다.",
        "정적 지역 변수는 프로그램 종료 시까지 유지된다.",
        "지역 변수가 선언된 블록이 끝나면 자동으로 소멸된다.",
        "주소를 계산하는 연산자는 앰퍼샌드 기호를 사용한다.",
        "인덱스가 없는 배열 이름은 배열의 시작 주소이다.",
        "포인터를 함수의 매개 변수로 전달할 수 있다.",
        "gets_s 함수는 문자열 끝에 널 문자를 추가한다."
    };
    char typing[MAX_LENGTH];

    int randomIndex = rand() % NUM_SENTENCES;

    printf("[ C언어 복습 타자 연습 ]\n\n");
    printf("제시되는 문장을 10초 안에 정확하게 입력하세요!\n\n");
    printf("시작하려면 스페이스를 누르세요. \n나가려면 ESC를 누르세요.\n");
    if (spaceToStart()) {
        clear();

        printf("[ 문제 ] %s\n", sentences[randomIndex]);
        printf("[ 입력 ] ");

        time_t startTime = time(NULL);

        gets_s(typing, MAX_LENGTH);

        time_t endTime = time(NULL);
        int duration = endTime - startTime;

        printf("\n[ 결과 ]\n");
        if (duration > TIME_LIMIT)
            printf("실패! 시간 초과! (%d초 걸림 / 10초 제한)\n", duration);
        else if (strcmp(sentences[randomIndex], typing) == 0)
            printf("성공! (%d초 걸림)\n", duration);
        else
            printf("실패! 오타가 있습니다! (문장과 정확히 일치해야 합니다)\n");

        printf("ESC 키를 누르면 나가집니다.\n");
        escToExit();
        clear();
    }
}
