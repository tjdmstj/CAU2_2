#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


typedef struct BOOK {        //책이름, 저자, 출판사, 현재 보유?
	char title[100];
	char author[20];
	char where[20];
	char borrow[10];
}Booking;

typedef struct LEND {       //대여 여부?(책 제목, 누가, 언제, 반납 언제?
	char lend_title[100];
	char name_who[20];
	char start[12];
	char end[12];
	char lend[10];
}Lending;

typedef struct MEMBER {     //회원이름, 생일, 전화번호
	char name[20];
	char birth[12];
	char phone[15];
}Member;



int main() {
	int number;
	int i,j=0;
	Booking book[10] = { 
						{"파이썬프로그래밍","홍길동","A출판사","보유"},
						{"새로운 자료구조","강길동","C출판사","보유"},
						{"기초통계플러스알파","김명준","D출판사","보유"},
						{"AAA","서은서","B출판사","보유"},
						{"BBBB","서은지","CU출판사","보유"},
						{"ABCDE","강감찬","알파벳","보유"},
						{"비쥬얼프로그래밍","김승태","중앙출판사","보유"},
						{"수리통계학","임창원","중앙출판사","보유"},
						{"SPSS","서의훈","중앙","보유"},
						{"RAINBOW","비","JYP","보유"} };
	
	Member member[5] = { 
						{"서은서","20010125","010-1234-5677"},
						{"이지은","19930516","010-1111-2222"},
						{"도라에몽","19930818","010-3333-8888"},
						{"이하늬","19991223","010-5345-1424"},
						{"이순신","20010417","010-4444-5555"}};
	Lending lending[100] = {0,} ;
	while (1){
		printf("1. 책 목록 표시하기\n");
		printf("2. 대출 등록하기\n");
		printf("3. 반납 하기\n");
		printf("4. 대출 목록 표시하기\n");
		printf(">");
		scanf("%d", &number);

		if (number == 1) {
			for (i = 0; i < 10; i++)
				printf("%s %s %s %s\n", book[i].title, book[i].author, book[i].where, book[i].borrow);
		}
		else if (number == 2) {
			char who[20];
			char date[12];
			char book_title[100];
			int yes;
			printf("이름을 입력하세요: ");
  			scanf("%s", who);
			for (i = 0; i < 5; i++) {
				if (strcmp(member[i].name, who) == 0) {
					printf("빌리고 싶은 책 제목을 입력하세요: ");
					scanf("%s", book_title);
					for (int k = 0; k < 10; k++) {
						if (strcmp(book_title, book[k].title) == 0 && strcmp(book[k].borrow, "보유") == 0) {
							strcpy(lending[j].lend_title, book[k].title);
							strcpy(book[k].borrow, "대출중");
							strcpy(lending[j].name_who, who);
							printf("빌리는 날짜 입력: ");
							scanf("%s", date);
							strcpy(lending[j].start, date);
							j++;
							yes = 1;
							break;
						}
						else {
							yes = 0;
						}
					}
					if (yes == 0) {
						printf("존재하지 않는 책입니다.\n");
						break;
					}
				}
			}
		}

		else if (number == 3) {
			char who[20];
			char date[12];
			char lend_title[100];
			int yes = 0;
			printf("이름을 입력하세요: ");
			scanf("%s", who);
			printf("반납하려는 책을 입력하세요: ");
			scanf("%s", lend_title);
			for (i = 0; i < j; i++) {
				if (strcmp(lending[i].name_who, who) == 0 && strcmp(lending[i].end,"")==0) {
					for (int k = 0; k < 10; k++) {
						if (strcmp(lending[i].lend_title,lend_title) == 0 && strcmp(book[k].borrow, "대출중") == 0 && strcmp(lend_title,book[k].title)==0) {
							strcpy(book[k].borrow, "보유");
							printf("반납하는 날짜 입력: ");
							scanf("%s", date);
							strcpy(lending[i].end, date);
							yes = 1;
							break;
						}
					}
				}
				else yes = 0;
				if (yes == 1) break;
			}
			if (yes == 0)printf("회원님이 빌린 내역이 존재하지 않습니다.\n");
		}
		else {
			for (i = 0; i < j; i++) {

				if (strcmp(lending[i].name_who,"") == 0) break;
					
				for (int p = 0; p < 5; p++) {
						if (strcmp(lending[i].name_who, member[p].name) == 0)
							printf("%s %s(%s) %s %s\n", lending[i].lend_title, lending[i].name_who, member[p].phone, lending[i].start, lending[i].end);
				}
					
			}

		}
		printf("\n");
	}
}

