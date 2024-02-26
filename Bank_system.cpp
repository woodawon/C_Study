#include <stdio.h> // fwrite() 함수용 헤더
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // gotoxy(), system() 함수용 헤더
#include <conio.h> // getch() 함수용 헤더

struct udata { // 사용자 데이터
    char username[50]; // 닉네임
    int date, month, year; // 일,월,년 - 생년월일(birth)
    char pnumber[15]; // 폰 번호(phone number)
    char fname[20]; // 성(first name)
    char lname[20]; // 이름(last name)
    char address[50]; // 주소
};

struct money { // 돈 전송
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};

struct upass { // 사용자 비번
    char password[50];
};

void gotoxy(int x, int y) { // 콘솔 커서 이동
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c
    );
}

void account() {
    char password[20], ch;
    FILE *fp;
    struct udata u1;
    struct upass p1;
    struct upass u2;

    // 사용자 데이터 담을 파일 열기
    fp = fopen("username.txt", "ab"); 
    
    system("cls"); // 현재 콘솔창에 입력된 내용들 지우기
    printf("\n\n** 만들고 싶은 계정의 정보를 입력해주세요. **");
    printf("\n\n성 : ");
    scanf("%s", &u1.fname);
    printf("\n\n이름 : ");
    scanf("%s", &u1.lname);
    printf("\n\n주소 : ");
    scanf("%s", &u1.address);
    printf("\n\n* 생년월일 *");
    printf("\n일-");
    scanf("%d", &u1.date);
    printf("\n월-");
    scanf("%d", &u1.month);
    printf("\n년-");
    scanf("%d", &u1.year);
    printf("\n\n전화번호 : ");
    scanf("%s", &u1.pnumber);
    printf("\n\n계정 닉네임 : ");
    scanf("%s", u1.username);
    printf("\n\n* 비밀번호 *");
    for(int i = 0;i < 50; i++) {
        // getch() : 콘솔 입력값을 화면 출력 없이 바로 반환함
        ch = getch(); 
        if(ch != 13) { // !! 13이 아니라면 !!
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        } else {
            break;
        }
    }

    // fwrite(배열(버퍼), 배열 크기, 배열의 원소 개수, 파일 주소)
    fwrite(&u1, sizeof(u1), 1, fp); 
    fclose(fp);
    accountcreated();
}

void accountcreated() {
    int i;
    char ch;
    system("cls");
    
}

int main() {

    // 변수 선언
    int a, b, i, choice;
    int passwordlength;

    // -- 시작
    gotoxy(20, 3); 
    printf("은행 시스템에 방문해 주셔서 감사합니다.\n\n");
    gotoxy(18,5);
    printf("**********************************");
    gotoxy(25,7);
    printf("DEVELOPER-Dawon");
    gotoxy(20,10);
    printf("1.... 은행 계정 만들기");
    gotoxy(20,12);
    printf("2.... 이미 계정이 있으신가요? 로그인하기");
    printf("3.... 종료\n\n");
    printf("\n\n선택해주세요.");
    scanf("%d", &choice);
    // --

    switch(choice) {
        case 1:
            system("cls");
            printf("\n\n사용자 이름 및 비밀번호는 최대 50글자로 입력해주세요.");
            account();
            break;
        case 2:
            //login();
            break;
        case 3:
            exit(0);
            break;
            // getch();
    }

    return 0;
}