#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printbingo(int player[5][5], int player2[5][5]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (player2[i][j] == 1)
				printf(" (%d) ", player[i][j]);
			else
				printf("  %d  ", player[i][j]);
		}
		printf("\n");
	}
}
void printbingo2(int com[5][5], int com2[5][5]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (com2[i][j] == 1)
				printf(" (%d) ", com[i][j]);
			else
				printf("  %d  ", com2[i][j]);
		}
		printf("\n");
	}
}

void make_bingo(int player[5][5], int com[5][5]) {
	srand((unsigned int)time(NULL));
	int i, j;
	int pan1[25], pan2[25];
	for (i = 0; i < 25; i++) {
		pan1[i] = i + 1;
		pan2[i] = i + 1;
	}

	for (i = 0; i < 50; i++) {
		int x = rand() % 25;																									// rand()% 25+0
		int y = rand() % 25;																									//rand()% 25+0 0~24���� ������ �� ���
		int z = pan1[x];
		pan1[x] = pan1[y];
		pan1[y] = z;																											//pan1[x]���� pan1[y]���� ���� ��ȯ
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			player[i][j] = pan1[i * 5 + j];
		}
	}
	for (i = 0; i < 50; i++) {																									 //�ٽ� �����ϰ� �ٲٱ� �����ʿ�!(����ڿ� ���� ���� ����
		int m = rand() % 25;																									 // rand()% 25+0
		int n = rand() % 25;																									 //rand()% 25+0 0~24���� ������ �� ���
		int l = pan2[m];
		pan2[m] = pan2[n];
		pan2[n] = l;																											 //pan2[x]���� pan2[y]���� ���� ��ȯ
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			com[i][j] = pan2[i * 5 + j];
		}
	}
}

int checkbingo(int player2[5][5]) {
	int i, j;
	int row = 0, col = 0, left = 0, right = 0;
	int count = 0;
	for (i = 0; i < 5; i++) {
		row = 0, col = 0;
		for (j = 0; j < 5; j++) {
			if (player2[i][j] == 1)
				row = row + 1;
			if (player2[j][i] == 1)
				col = col + 1;
		}
		if (row == 5)
			count++;
		if (col == 5)
			count++;
		
		if (player2[i][i] == 1)
			left = left + 1;
		if (player2[i][4 - i] == 1)
			right = right + 1;

		if (left == 5)
			count++;
		if (right == 5)
			count++;
	}
	return count;
}

int main() {
	int player[5][5];
	int com[5][5];
	int num;
	int player2[5][5];
	int com2[5][5] = { 0 };
	int playerbingo=0, combingo=0;
	make_bingo(player, com);
	while (1) {
		printf("    <������� ������>    \n");
		printbingo(player, player2);
		printf("\n");
		printf("    <��ǻ���� ������>    \n");
		printbingo2(com, com2);
		printf("\n");
		printf("1~25 �� �ϳ��� �����ϼ���.: ");
		scanf_s("%d", &num);
		
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (player[i][j] == num) {
					player2[i][j] = 1;
				}
			}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (com[i][j] == num) {
					com2[i][j] = 1;
				}
			}
		while (1) {																																	 //��ǻ�� ����
			num = rand() % 25;
			int i, j, k, l;
			int choose = 1;
			for(i=0;i<5;i++)
				for (j = 0; j < 5; j++) {
					if (com[i][j] == num && com2[i][j]==1)
						choose = 2;
				}
			switch (choose) 
			{
			case 1:
				for (i = 0; i < 5; i++) {
					for (j = 0; j < 5; j++) {
						if (com[i][j] == num && com2[i][j] == 0) {																					 //��ǻ�� �����ǿ� num�� �ִ� ��� (�����ϱ�)
							com2[i][j] = 1;
							for (k = 0; k < 5; k++)
								for (l = 0; l < 5; l++) {
									if (player[k][l] == num)
										player2[k][l] = 1;
								}
						}
					}
				}
				break;
			case 2:
				continue;
			}
			break;
		}


		playerbingo = checkbingo(player2);
		combingo = checkbingo(com2);
		printf("\n");
		printf("������� �����: %d / ��ǻ���� �����: %d\n", playerbingo, combingo);
		printf("=============================================\n");


		if (playerbingo >= 5 && combingo >= 5) {
			if (playerbingo > combingo) {
				printf("%d�� ����� ����ڰ� �̰���ϴ�.\n", playerbingo);
				printf("\n");
				break;
			}
			else if (playerbingo < combingo) {
				printf("%d�� ����� ��ǻ�Ͱ� �̰���ϴ�.\n", combingo);
				printf("\n");
				break;
			}
			else {
				printf("%d�� ����� �����ϴ�.\n", playerbingo);
				printf("\n");
				break;
			}
		}
		else if (playerbingo >= 5) {
			printf("%d�� ����� ����ڰ� �̰���ϴ�.\n", playerbingo);
			printf("\n");
			break;
		}
		else if (combingo >= 5) {
			printf("%d�� ����� ��ǻ�Ͱ� �̰���ϴ�.\n", combingo);
			printf("\n");
			break;
		}
		
	}
	printf("     <������� ������>    \n");
	printbingo(player,player2);
	printf("\n");
	printf("     <��ǻ���� ������>    \n");
	printbingo(com, com2);
}

