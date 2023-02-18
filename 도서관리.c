#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


typedef struct BOOK {        //å�̸�, ����, ���ǻ�, ���� ����?
	char title[100];
	char author[20];
	char where[20];
	char borrow[10];
}Booking;

typedef struct LEND {       //�뿩 ����?(å ����, ����, ����, �ݳ� ����?
	char lend_title[100];
	char name_who[20];
	char start[12];
	char end[12];
	char lend[10];
}Lending;

typedef struct MEMBER {     //ȸ���̸�, ����, ��ȭ��ȣ
	char name[20];
	char birth[12];
	char phone[15];
}Member;



int main() {
	int number;
	int i,j=0;
	Booking book[10] = { 
						{"���̽����α׷���","ȫ�浿","A���ǻ�","����"},
						{"���ο� �ڷᱸ��","���浿","C���ǻ�","����"},
						{"��������÷�������","�����","D���ǻ�","����"},
						{"AAA","������","B���ǻ�","����"},
						{"BBBB","������","CU���ǻ�","����"},
						{"ABCDE","������","���ĺ�","����"},
						{"��������α׷���","�����","�߾����ǻ�","����"},
						{"���������","��â��","�߾����ǻ�","����"},
						{"SPSS","������","�߾�","����"},
						{"RAINBOW","��","JYP","����"} };
	
	Member member[5] = { 
						{"������","20010125","010-1234-5677"},
						{"������","19930516","010-1111-2222"},
						{"���󿡸�","19930818","010-3333-8888"},
						{"���ϴ�","19991223","010-5345-1424"},
						{"�̼���","20010417","010-4444-5555"}};
	Lending lending[100] = {0,} ;
	while (1){
		printf("1. å ��� ǥ���ϱ�\n");
		printf("2. ���� ����ϱ�\n");
		printf("3. �ݳ� �ϱ�\n");
		printf("4. ���� ��� ǥ���ϱ�\n");
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
			printf("�̸��� �Է��ϼ���: ");
  			scanf("%s", who);
			for (i = 0; i < 5; i++) {
				if (strcmp(member[i].name, who) == 0) {
					printf("������ ���� å ������ �Է��ϼ���: ");
					scanf("%s", book_title);
					for (int k = 0; k < 10; k++) {
						if (strcmp(book_title, book[k].title) == 0 && strcmp(book[k].borrow, "����") == 0) {
							strcpy(lending[j].lend_title, book[k].title);
							strcpy(book[k].borrow, "������");
							strcpy(lending[j].name_who, who);
							printf("������ ��¥ �Է�: ");
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
						printf("�������� �ʴ� å�Դϴ�.\n");
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
			printf("�̸��� �Է��ϼ���: ");
			scanf("%s", who);
			printf("�ݳ��Ϸ��� å�� �Է��ϼ���: ");
			scanf("%s", lend_title);
			for (i = 0; i < j; i++) {
				if (strcmp(lending[i].name_who, who) == 0 && strcmp(lending[i].end,"")==0) {
					for (int k = 0; k < 10; k++) {
						if (strcmp(lending[i].lend_title,lend_title) == 0 && strcmp(book[k].borrow, "������") == 0 && strcmp(lend_title,book[k].title)==0) {
							strcpy(book[k].borrow, "����");
							printf("�ݳ��ϴ� ��¥ �Է�: ");
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
			if (yes == 0)printf("ȸ������ ���� ������ �������� �ʽ��ϴ�.\n");
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

