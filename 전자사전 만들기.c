#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct {
	char word[20];
	char mean[100];
}WORD[51844];

int main() {
	FILE* fp;
	int i;
	char input[100];
	char* token;
	
		fp = fopen("dict_test.TXT", "r");
		if (fp == NULL) {
			printf("파일을 읽을 수 없습니다.");
			return 0;
		}
		for (i = 0; i < 51844; i++) {
			fgets(input, 100, fp);
			input[strlen(input) - 1] = 0;
			token = strtok(input, " : ");
			strcpy(WORD[i].word, token);
			token = strtok(NULL, ":");
			if (token == NULL) continue;
			strcpy(WORD[i].mean, token);
		}
	while(1){
		char word_name[20] = { 0, };
		printf("단어?");
		scanf("%s", word_name);
		for (i = 0; i < 51844; i++) {
			if (strcmp(word_name, WORD[i].word) == 0) {
				printf("%s%s", WORD[i].word, WORD[i].mean);
				break;
			}
		}
		printf("\n");
	}
	fclose(fp);
}