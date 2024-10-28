#include <stdio.h>
#include <stdlib.h>

int main()
{
    char candidate01[2500], candidate02[2500], candidate03[2500], candidate04[2500], candidate05[2500], candidate06[2500];
    char *candidates[6] = {candidate01, candidate02, candidate03, candidate04, candidate05, candidate06};

    const char *member_info[11] = {"성명", "생일(YYYY/MM/DD 형식)", "성별(여성이면 F 또는 남성이면 M)", 
                                  "메일 주소", "국적", "BMI", "주 스킬", "보조 스킬", 
                                  "한국어 등급(TOPIK)", "MBTI", "소개"};
    char *candidate_counting[6]={"첫","두","세","넷","다섯","여섯"}
    int candidate_count = 0;

    // 데이터 입력
    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");
    
    while (candidate_count < 6)
    {
        printf("=================================\n");
        printf("%d 번째 후보자의 정보를 입력합니다.\n", candidate_counting[candidate_count]);
        printf("---------------------------------\n");

        for (int i = 0; i < 11; i++)
        {
            printf("%s: ", member_info[i]);
            fgets(candidates[candidate_count] + (i * 200), 200, stdin);

            char *newline_pos = candidates[candidate_count] + (i * 200);
            while (*newline_pos != '\0')
            {
                if (*newline_pos == '\n')
                {
                    *newline_pos = '\0';
                    break;
                }
                newline_pos++;
            }
        }

        candidate_count++;
    }

    // 데이터 출력
    printf("\n####################################\n");
    printf("     오디션 후보자 데이터 조회\n");
    printf("####################################\n");
    
    for (int i = 0; i < 6; i++)
    {
        char *current_candidate = candidates[i];
        char gender[10];

        // 성별 확인
        char *gender_pointer = current_candidate + 400;
        int is_female = (*gender_pointer == 'F');

        // 성별 문자열 설정
        if (is_female)
        {
            char *src = "여";
            char *dest = gender;
            while (*src)
            {
                *dest++ = *src++;
            }
            *dest = '\0';
        }
        else
        {
            char *src = "남";
            char *dest = gender;
            while (*src)
            {
                *dest++ = *src++;
            }
            *dest = '\0';
        }

        printf("===============================================================================================================\n");
        printf("성  명 | 생   일      | 성별   | 메   일               | 국적 | BMI  | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
        printf("===============================================================================================================\n");

        printf("%-6s | %-14s | %-3s | %-20s | %-4s | %-4s | %-6s | %-7s | %-5s | %-4s |\n",
               current_candidate, current_candidate + 200, gender, current_candidate + 600, 
               current_candidate + 800, current_candidate + 1000, current_candidate + 1200, 
               current_candidate + 1400, current_candidate + 1600, current_candidate + 1800);
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("%s\n", current_candidate + 2000);
        printf("----------------------------------------------------------------------------------------------------------------\n");
    }

    getchar();
    return 0;
}
