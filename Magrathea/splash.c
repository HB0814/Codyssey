#include<stdio.h>

int YEAR,MONTH,DAY;
char NAME[20]="\0";

int VERTICAL_MAX=5;

void Phrase(int word)
{
    switch(word)
    {
        case 0:
        
        printf("\t                         [마그라테아 ver 0.1]                            ");
        break;
        case 1:
        printf("\t\"풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,       ");

        break;
        case 2:
        printf("\t사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,    ");

        break;
        case 3:
        printf("\t                    마그라테아에 오신걸 환영합니다.\"                        ");

        break;
        case 4:
        printf("\t                                                                             ");

        break;
        default:

    }
}
void Input()
{
    printf("현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요:");
    scanf("%d-%d-%d",&YEAR,&MONTH,&DAY);
    printf("[당신의 이름을 입력하세요]:");

    scanf("%s",NAME);
    printf("**입력이 정상적으로 처리되었습니다.**\n");
}
void OutPut()
{
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for(int column=0;column<VERTICAL_MAX;column++)
    {
        for(int row=0;row<VERTICAL_MAX+1;row++)
        {
            printf("*");
            if(row==column)
                Phrase(column);
        }
        printf("\n");
    }
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]:%s\t[실행 시간]:%04d년 %02d월 %02d일\n",NAME,YEAR,MONTH,DAY);

}
void main()
{
    Input();
    OutPut();
}