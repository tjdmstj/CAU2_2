#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//단어 바꾸기와 짧은 단어 받지 않는 것 10번 반복하는 것 처리하기

int main() {
	char firstword[11] = { 0, };
	char first[11] = { 0, };
	char second[11] = { 0, };
	int num = 0;
	int ft, sd;
	int i, j;
	printf("Word?");
	scanf("%s", firstword);
	for (i = 0; i < strlen(firstword); i++)
		first[i] = firstword[i];
	while (1) {
		printf("Word?");
		scanf("%s", second);
		if (second[0]=='e' && second[1]=='n' && second[2]=='d') {
			break;
		}
		else if (strlen(second) < 3) {
			printf("too short");
			printf("\n");
			continue;
		}
		else
			num = 0;
			for (i = 0; i < strlen(first); i++)
				for (j = 0; j < strlen(second); j++) {
					if (first[i] == second[j]) {
						num += 1;
						ft = i;
						sd = j;
					}
				}
			switch (num) {
			case 0:
				printf("no cross word");
				first[strlen(second)] = NULL;
				for (i = 0; i < strlen(second); i++)
					first[i] = second[i];
				printf("\n");
				break;
			default:
				for (i = 0; i < strlen(first); i++) {
					if (i == ft) {
						printf("(%c)", first[i]);
					}
					else
						printf("%c", first[i]);
				}
				printf(" - ");
				for (j = 0; j < strlen(second); j++) {
					if (j == sd) {
						printf("(%c)", second[j]);
					}
					else
						printf("%c", second[j]);
				}
				first[strlen(second)] = NULL;
				for (i = 0; i < strlen(second); i++)
					first[i] = second[i];
				printf("\n");
			}	
	}
}         