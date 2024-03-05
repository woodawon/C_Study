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

void account() { // 계정 만들기 함수
    char password[20], ch;
    FILE *fp;
    struct udata u1;

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

void accountcreated() { // 계정 만든 후 로그인으로 넘어가는 화면 함수수
    char ch;
    system("cls");
    
    printf("잠시만 기다려주세요.. \n\n데이터를 처리중입니다..");
    for(int i = 0; i < 200000000; i++) {
        i++;
        i--;
    }
    gotoxy(30, 10);
    printf("계정이 성공적으로 만들어졌습니다!");
    gotoxy(0, 20);
    printf("로그인을 하시려면 Enter 키를 눌러주세요.");
    getch();
    login();
}

void login() { // 로그인 함수수
    system("cls");

    char username[50];
    char password[50];
    char ch;
    FILE *fp;
    struct udata u1;
    struct upass p1;

    fp = fopen("username.txt", "rb");
    if(fp == NULL) { // 예외 처리
        printf("파일 실행 중 오류 발생");
    }

    gotoxy(34, 2);
    printf(" 계정 로그인 ");
    gotoxy(7, 5);
    printf("***********************************************"
           "********************************");
    gotoxy(35, 10);
    printf("=== 로그인 ===");

    gotoxy(35, 12);
    printf("닉네임 : ");
    scanf("%s", &username);

    gotoxy(35, 14);
    printf("비밀번호 : ");
    for(int i = 0; i < 50; i++) {
        ch = getch();
        if(ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        } else {
            break;
        }
    }

    // 로그인 시 입력한 닉네임이 계정 목록(파일)에 있는지 확인
    while(fread(&u1, sizeof(u1), 1, fp)) {
        if(strcmp(username, u1.username) == 0) {
            loginsu(); // 로그인 성공(login success)
            display(username);
        }
    }
    fclose(fp);
}

void loginsu() { // 로그인 성공 함수
    system("cls");
    printf("계정 정보를 가져오고 있습니다..");
    FILE *fp;
    struct udata u1;
    for(int i = 0; i < 20000; i++) {
        i++;
        i--;
    }
    gotoxy(30, 10);
    printf("로그인 성공!");
    gotoxy(0, 20);
    printf("계속하시려면 Enter키를 눌러주세요.");
    getch();
}

void display(char username1[]) { // 사용자 정보 출력 함수
    system("cls");
    FILE* fp;
    int choice;
    struct udata u1;
    fp = fopen("username.txt", "rb");
    if(fp == NULL) { // 예외 처리
        printf("파일 실행 중 오류 발생");
    }
    
    while(fread(&u1, sizeof(u1), 1, fp)) {
        if(strcmp(username1, u1.username) == 0) {
            gotoxy(30, 1);
            printf("환영합니다, %s %s !", u1.fname, u1.lname);
            gotoxy(28, 2);
            printf("..........................");
            gotoxy(55, 8);
            printf("***************************");
            gotoxy(55, 10);
            printf("닉네임 : %s %s", u1,fname, u1.lname);
            gotoxy(55, 12);
            printf("전화번호 : %s", u1.pnumber);
            gotoxy(55, 22);
            printf("주소 : %s", u1.address);
            gotoxy(55, 24);
        }
    }
    fclose(fp);
    gotoxy(0, 6);
    
    // 이제 다른 항목들을 사용자가 다시 선택할 수 있게 할 정보 출력하기
    printf("  메인  ");
    gotoxy(0, 7);
    printf("******");
    gotoxy(0, 9);
    printf("1. 밸런스 확인하기");
    gotoxy(0, 11);
    printf("2. 돈 전송하기");
    gotoxy(0, 13);
    printf("3. 로그아웃\n\n");
    gotoxy(0, 15);
    printf("4. 나가기\n\n");
    printf("선택해주세요. : ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            checkbalance(username1);
            break;
        case 2:
            transfermoney();
            break;
        case 3:
            logout();
            login();
            break;
        case 4:
            exit(0);
            break;
    }
}

void transfermoney() { // 돈 전송 함수
    system("cls");
    
    struct udata u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    FILE *fm, *fp;
    
    fp = fopen("username.txt", "rb"); // 사용자 이름
    fm = fopen("mon.txt", "ab"); // 전송할 돈 양
    
    gotoxy(33, 4);
    printf("--- 돈 전송하기 ---");
    gotoxy(33, 5);
    printf("========================");
    gotoxy(33, 11);
    printf("사용자님의 닉네임을 입력해주세요 : ");
    scanf("%s", &usernamet);
    gotoxy(33, 13);
    printf("전송할 분의 닉네임을 입력해주세요 : ");
    scanf("%s", &usernamep);
    
    while(fread(&u1, sizeof(u1), 1, fp)) {
        if(strcmp(usernamep, u1.username) == 0) {
            strcpy(m1.usernameto, u1.username);
            strcpy(m1.userpersonfrom, usernamet);
        }
    }
    gotoxy(33, 16);
    
    printf("전송하실 금액을 입력해주세요 : ");
    scanf("%d", &m1.money1);
    fwrite(&m1, sizeof(m1), 1, fm);
    gotoxy(0, 26);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");
    gotoxy(0, 28);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");
    gotoxy(0, 29);
    printf("전송중입니다. 잠시만 기다려주세요..");
    gotoxy(10, 27);
    for(int i = 0; i < 70; i++) {
        for(int j = 0; j < 1200000;j++) {
            j++;
            j--;
        }
        printf("*");
    }
    
    gotoxy(33 ,40);
    printf("성공적으로 금액이 전송되었습니다! \n");
    printf("계속하시려면 아무 키나 눌러주세요..");
    getch();
    fclose(fp);
    fclose(fm);
    display(usernamet); // 홈화면으로 반환
}

void checkbalance(char username2[]) {
    system("cls");
    struct money m1;
    char ch;
    int summoney = 0;
    int i = 1, l = 10, n = 10, v = 10;
    FILE *fm;
    fm = fopen("mon.txt", "rb");
    gotoxy(30, 2);
    printf("=== 밸런스 게시판 ===");
    gotoxy(30, 3);
    printf("***************************");
    gotoxy(5, l);
    printf("S no.");
    gotoxy(30, n);
    printf("transaction id");
    gotoxy(60, v);
    printf("amount");
    
    while(fread(&m1, sizeof(m1), 1, fm)) {
        if(strcmp(username2, m1.usernameto) == 0) {
            gotoxy(5, ++l);
            printf("%d", i);
            i++;
            gotoxy(30, ++n);
            printf("%s", m1.userpersonfrom);
            gotoxy(60, ++v);
            printf("%d", m1.money1);
            // total money
            summoney += m1.money1;
        }
    }
    gotoxy(80, 10);
    printf("총량 : ");
    gotoxy(80, 12);
    printf("%d\n", summoney);
    printf("계속하시려면 아무 키나 입력해주세요..");
    getch();
    
    fclose(fm);
    display(username2); // 다시 선택 화면으로 넘어감
}

void logout() {
    system("cls");
    printf("잠시만 기다려주세요, 로그아웃을 하는 중입니다..");
    for(int i = 0; i < 10; i++) {
        for(j = 0; j < 25000000; j++) {
            i++;
            i--;
        }
        printf(".");
    }
    gotoxy(30, 10);
    printf("정상적으로 로그아웃 되었습니다!\n");
    gotoxy(0, 20);
    printf("계속하시려면 아무 키나 입력해주세요..");
    getch();
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
