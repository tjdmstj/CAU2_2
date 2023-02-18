#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	srand((unsigned int)time(NULL));
	char str[100][51] = { 0, };
	char* ptr[100];
	char sentence[51];
	int i,j;

	printf("배열 저장 방식\n");
	for (i = 0; i < 100; i++) {
		int len = rand() % 21 + 30;
		for (j = 0; j < len; j++) {
			str[i][j] = rand() % 26 + 'A';
		}
	}
	printf("정렬 전:\n");
	for (i = 0; i < 100; i++) {
		printf("%d : %s\n", i + 1, str[i]);
	}

	for (i = 0; i < 99; i++) {
		for (j = i; j < 100; j++) {
			if (strcmp(str[i], str[j]) > 0) {
				char tempstr[51];
				strcpy(tempstr,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],tempstr);
			}
		}
	}
	printf("\n");
	
	printf("정렬 후:\n");
	for (i = 0; i < 100; i++) {
		printf("%d : %s\n", i + 1, str[i]);
	}
	printf("\n");
	printf("==============================================================\n");
	printf("\n");
	printf("포인터 저장 방식\n");
	for (i = 0; i < 100; i++) {
		int len = rand() % 21 + 30;
		for (j = 0; j < len; j++) {
			sentence[j] = rand() % 26 + 'A';
		}
		sentence[len] = 0;
		ptr[i] = malloc(len + 1);
		strcpy(ptr[i], sentence);
	}

	printf("정렬 전:\n");
	for (i = 0; i < 100; i++) {
		printf("%d : %s\n", i + 1, ptr[i]);
	}

	for (i = 0; i < 99; i++) {
		for (j = i; j < 100; j++) {
			if (strcmp(ptr[i], ptr[j])>0) {
				char* temp;
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
	printf("\n");
	
	printf("정렬 후:\n");
	for (i = 0; i < 100; i++) {
		printf("%d : %s\n",i+1, ptr[i]);
	}
}


