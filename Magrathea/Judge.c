#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 100    // 최대 심사자 수
#define MAX_STRING 1000   // 문자열 최대 길이

int main()
{
    char project[50];                         // 프로젝트명
    int judge_num, select_num;               // 심사자 수, 선발 인원
    char judges_array[MAX_JUDGES][MAX_STRING];// 심사자 정보 저장 배열
    char check;                              // 확인 입력용

    // 프로그램 시작 및 기본 정보 입력
    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");

    printf("참여 프로젝트: ");
    scanf("%s", project);

    printf("심사 풀 인원: ");
    scanf("%d", &judge_num);

    printf("선발 멤버 수: ");
    scanf("%d", &select_num);

    // 심사자 정보 입력 시작
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", judge_num);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 각 심사자의 정보를 콤마로 구분하여 한 줄로 입력받기
    for(int i = 0; i < judge_num; i++)
    {
        char name[50], gender[10], company[50], position[50];
        char expertise[50], email[50], phone[20];
        char input_line[MAX_STRING];
        
        printf("\n심사자 %d의 정보: ", i+1);
        scanf(" %[^\n]s", input_line);
        
        // 콤마로 구분된 입력을 분리
        sscanf(input_line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", 
               name, gender, company, position, expertise, email, phone);
        
        // JSON 형식으로 데이터 저장
        sprintf(judges_array[i], 
                "{\"name\":\"%s\",\"gender\":\"%s\",\"company\":\"%s\","
                "\"position\":\"%s\",\"expertise\":\"%s\",\"email\":\"%s\",\"phone\":\"%s\"}",
                name, gender, company, position, expertise, email, phone);
    }

    // 데이터 확인 여부 체크
    printf("\n[%s] 심사자 풀을 확인할까요? (y/n): ", project);
    scanf(" %c", &check);

    // 데이터 출력
    if(check == 'y' || check == 'Y')
    {
        printf("\n####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");

        for(int i = 0; i < judge_num; i++)
        {
            printf("\n[심사자 %d]\n", i+1);
            char name[50], gender[10], company[50], position[50];
            char expertise[50], email[50], phone[20];
            
            // JSON 문자열에서 각 필드의 값을 추출
            sscanf(judges_array[i], 
                "{\"name\":\"%[^\"]\",\"gender\":\"%[^\"]\",\"company\":\"%[^\"]\","
                "\"position\":\"%[^\"]\",\"expertise\":\"%[^\"]\",\"email\":\"%[^\"]\",\"phone\":\"%[^\"]\"}",
                name, gender, company, position, expertise, email, phone);
            
            printf("이름: %s\n", name);
            printf("성별: %s\n", gender);
            printf("소속: %s\n", company);
            printf("직함: %s\n", position);
            printf("전문분야: %s\n", expertise);
            printf("이메일: %s\n", email);
            printf("전화번호: %s\n", phone);
            printf("----------------------------------\n");
        }
    else
    {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
