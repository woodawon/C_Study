#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 'library' 구조체 입력
struct library {
    char book_name[20]; // 책 이름
    char author[20]; // 저자 이름
    int pages; // 페이지 수 입력
    float price; // 가격 입력
};

int main()
{ 
    struct library lib[100]; // struct instance 선언
    char ar_nm[30], bk_nm[30]; // 저자 이름, 책 이름

    int u, input, count = 0; // 사용자 수, 서비스 선택, 책 개수

    while(input != 5) {
        printf("Welcome to Library! \n");
        printf("1. Add book information \n");
        printf("2. Display book information \n");
        printf("3. List all books of given author \n");
        printf("4. List the count of books in the library \n");
        printf("5. Exit \n");
        printf("Enter one of the above: ");
        scanf("%d", &input);

        switch(input) {
            case 1: // 책 정보 추가하기
                printf("Enter book name : ");
                scanf("%s", &lib[u].book_name);

                printf("Enter author name : ");
                scanf("%s", &lib[u].author);

                printf("Enter pages : ");
                scanf("%d", &lib[u].pages);

                printf("Enter price : ");
                scanf("%f", &lib[u].price);
                count++;
                u++;
                break;
            case 2: // 모든 책 정보 출력
                printf("Okay. You have entered the following information \n");
                for(int i = 0; i < count; i++) {
                    printf("book name : %s", lib[i].book_name);
                    printf("\t author name : %s", lib[i].author);
                    printf("\t pages : %d", lib[i].pages);
                    printf("\t price : %f", lib[i].price);
                }
                break;
            case 3: // 저자 이름 입력 -> 책 정보 출력
                printf("Enter author name : "); 
                scanf("%s", &ar_nm); 
                for(int i = 0;i < count; i++) {
                    // strcmp(a, b) : string a, b 값 비교 => 값이 같으면 0 return
                    if(strcmp(ar_nm, lib[i].author) == 0) { 
                        printf("%s %s %d %f \n", lib[i].book_name,
                        lib[i].author, lib[i].pages, lib[i].price);
                    } else {
                        printf("No results! Please try again.");
                    }
                }
                break;
            case 4: // 전체 등록된 책 개수 출력
                if(count != 0) {
                    printf("%d \n", count);
                } else {
                    printf("No of books in library \n");
                }
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
