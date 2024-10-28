#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGE 5
#define MAX_CANDIDATE 6

char *judge_names[] = {"김영수","이지영","박민준","송현우","박지영"};
char *judge_specialities[] = {"음악","댄스","보컬","비주얼","음악평론"};
char *candidate_names[] = {"박지연","Ethan Smith","Suphanan Wong","Helena Silva","Karolina Nowak","Liam Wilson"};
int scoring_sheet[MAX_CANDIDATE * 7]; // 총 42개 요소 (6명 * 7항목)

int main() 
{
    int judge_num = 0;
    char submit;  // submit 변수 선언 추가
    
    printf("####################################\n");
    printf("#          오디션 심사 결과 입력  #\n");
    printf("####################################\n");\
    while(judge_num < MAX_JUDGE)
    {
        printf("심사자 이름: %s\n",judge_names[judge_num]);
        printf("전문분야:%s\n",judge_specialities[judge_num]);
        printf("++++++++++++++++++++++++++++++++++++\n");

        for(int i = 0; i < MAX_CANDIDATE; i++)    
        {
            int base_idx = i * 7; // 각 후보자의 시작 인덱스
            // 100000-999999 사이의 랜덤 6자리 숫자 생성
            scoring_sheet[base_idx] = 100000 + (rand() % 900000);
            
            printf("후보자: %s\n", candidate_names[i]);
            printf("%s:\n",judge_specialities[judge_num]); scanf("%d", &scoring_sheet[base_idx + judge_num]);
            printf("------------------------------------\n");
        }
        printf("++++++++++++++++++++++++++++++++++++\n");
        printf("입력을 모두 완료했습니다.\n");
        printf("입력하신 내용을 검토하세요!\n");
        printf("------------------------------------\n");
        for(int i=0;i<MAX_CANDIDATE;i++)
        {
            int base_idx = i * 7;
            printf("%s,%d\n",candidate_names[i],scoring_sheet[base_idx + judge_num]);
        }
        printf("제출하시겠습니까? (y/n): "); 
        getchar();  // 버퍼 비우기
        scanf("%c", &submit);
        if(submit == 'y')
        {
            printf("***최종 제출이 완료되었습니다.***\n");
            judge_num++;
        }
        else
        {
            return 0;
        }

    }
    for(int i=0;i<MAX_CANDIDATE;i++)
    {
        int base_idx = i * 7;
        scoring_sheet[base_idx + 6] = 0;

        for(int j = 1; j <= 5; j++) 
        {
            scoring_sheet[base_idx + 6] += scoring_sheet[base_idx + j];
        }
    }

    // 후보자 인덱스 배열 생성
    int candidate_indices[MAX_CANDIDATE];
    for(int i = 0; i < MAX_CANDIDATE; i++) {
        candidate_indices[i] = i;
    }
    
    // 점수 기준으로 인덱스 정렬 (버블 정렬)
    for(int i = 0; i < MAX_CANDIDATE-1; i++) {
        for(int j = 0; j < MAX_CANDIDATE-1-i; j++) {
            int idx1 = candidate_indices[j];
            int idx2 = candidate_indices[j+1];
            if(scoring_sheet[idx1 * 7 + 6] < scoring_sheet[idx2 * 7 + 6]) {
                // 인덱스 교환
                int temp = candidate_indices[j];
                candidate_indices[j] = candidate_indices[j+1];
                candidate_indices[j+1] = temp;
            }
        }
    }
    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");

    printf("#######################################\n");
    printf("#밀리웨이즈 멤버가 된 걸 축하합니다!     #\n");
    printf("#######################################\n");
    
    // 상위 4명 출력
    for(int i = 0; i < 4; i++) {
        int idx = candidate_indices[i];
        printf("%d. %s\n",i+1,candidate_names[idx]);
    }
    
    return 0;
}
