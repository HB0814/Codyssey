#include<stdio.h>

char candidate01[2750],candidate02[2750],candidate03[2750],candidate04[2750],candidate05[2750],candidate06[2750];
char *candidates[6] = {candidate01, candidate02, candidate03, candidate04, candidate05, candidate06};
char input_text[250];

char *member_info[]={"성명:","생일(YYYY/MM/DD 형식)","성별(여성이면 F 또는 남성이면 M)","메일 주소","국적","BMI","주 스킬","보조 스킬","한국어 등급","MBTI","소개"};
char *number_count[]={"첫","두","셋","넷","다섯","여섯"};

int member_number=0;
void main()
{
    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력        \n");
    printf("####################################\n");

    while(member_number<6)
    {
        printf("%s 번째 후보자의 정보를 입력합니다.\n",number_count[member_number]);
        printf("---------------------------------");
        for(int i=0;i<11;i++)
        {
            printf("%d.%s",number_count+1,member_info[member_number]);
            scanf("%s",input_text);
            for(int j=0;j<250;j++)
            {
                candidates[i][j+(i*250)]=input_text[j];
            }
        }
        printf("=================================");
        member_number++;
    }
    printf("####################################\n");
    printf("     오디션 후보자 데이터 조회        \n");
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI | \n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI | \n");
    printf("---------------------------------------------------------------------------------------------\n");

}