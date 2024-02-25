#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

struct udata { // 사용자 데이터
    char username[50];
    int date, month, year;
    char pnumber[15];
    char fname[20]; // first name
    char lname[20]; // last name
    char address[50];
    char typeaccount[20];
};

struct money { // 돈 전송
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};

struct upass { // 사용자 비번
    char password[50];
};

int main() {

    

    return 0;
}