#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 100
#define MAX_INFO_LENGTH 1000
#define PROJECT_NAME_LENGTH 100

int main()
{
    // 변수 선언
    int num_judges;
    char project_name[PROJECT_NAME_LENGTH];
    char judges_array[MAX_JUDGES][MAX_INFO_LENGTH];
    char buffer[MAX_INFO_LENGTH];

    // 프로젝트 정보 입력
    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력      #\n");
    printf("####################################\n");
    
    printf("> 참여 프로젝트: ");
    scanf("%99[^\n]", project_name);
    getchar();

    printf("> 심사 풀 인원: ");
    scanf("%d", &num_judges);
    getchar();

    printf("> 선발 멤버 수: 4\n");

    // 심사자 정보 입력
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", num_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    int judge_idx = 0;
    while (judge_idx < num_judges) {
        printf("*심사자 %d: ", judge_idx + 1);
        fgets(buffer, MAX_INFO_LENGTH, stdin);

        // 입력된 문자열 길이 확인
        int length = 0;
        while (buffer[length] != '\0' && buffer[length] != '\n') {
            length++;
        }

        // 빈 입력 체크
        if (length == 0) {
            printf("입력 누락!\n");
            continue;
        }

        // 심사자 정보 저장
        for (int k = 0; k < length; k++) {
            judges_array[judge_idx][k] = buffer[k];
        }
        judges_array[judge_idx][length] = '\0';
        judge_idx++;
    }

    // 입력 완료 메시지
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 확인 여부
    printf("\n[%s] 심사자 풀을 확인할까요? (Y/N) ", project_name);
    char pool_check;
    scanf(" %c", &pool_check);
    getchar();

    if (pool_check == 'Y') {
        // 심사자 풀 출력
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력      #\n");
        printf("####################################\n");
        
        for (int i = 0; i < num_judges; i++) {
            printf("[심사자 %d]\n", i + 1);

            // 데이터 파싱 및 출력
            int start = 0;
            for (int j = 0; j < MAX_INFO_LENGTH; j++) {
                if (judges_array[i][j] == ',' || judges_array[i][j] == '\0') {
                    // 각 필드 출력
                    for (int k = start; k < j; k++) {
                        putchar(judges_array[i][k]);
                    }
                    putchar('\n');
                    
                    start = j + 1;
                    if (judges_array[i][j] == '\0') {
                        break;
                    }
                }
            }
            printf("-----------------------------------\n");
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    getchar();
    return 0;
}
