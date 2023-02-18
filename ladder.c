#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char ladder[15][9] = { " " };
void make_ladder(void) {

	int i, j;

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 9; j++) {
			if (j % 2 == 0) {
				ladder[i][j] = '|';
			}																//홀수 번호에는 | 추가
			else if (j % 2 == 1) {
				if ((rand() % 3) == 2 || (rand() % 5) == 5) {
					if (ladder[i][j - 2] != '-')
						ladder[i][j] = '-';
																			//짝수 번호에는 '-' 추가, 옆 사다리와 '-'가 곂치지 않기 위해 if (ladder[i][j - 2] != '-') 추가 
																			//가로선은 15개 이상 넣기 위해 랜덤 수를 많이 함(교집합?)

				}

			}
		}
	}
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 9; j++) {
			if (ladder[i][j] != '-' && ladder[i][j] != '|')
				ladder[i][j] = ' ';
		}
	}
	printf("1 2 3 4 5 \n");													 //처음 고르는 번호

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 9; j++) {
			printf("%c", ladder[i][j]);
		}
		printf("\n");														 // 첫번째 줄이 완성되면 다음줄로 넘어가기
	}
	printf("A B C D E \n");													 //마지막 결과
}

int main() {
	srand((unsigned)time(NULL));
	int arr[5][5] = { 0, };
	for (int z = 0; z < 100; z++) {
		make_ladder();
		for (int up = 1; up < 6; up++) {
			int num, choice;
			int a = 0, b = 0, c = 0, d = 0, e = 0;
			num = up;														 //ex)up=3 num=3 //up은 반복을 위한 변수
			choice = num;													 // ex) num=3 choice=3
			num = num * 2 - 2;												//배열은 0부터 시작하기 때문에 2를 곱한뒤 -2를 해줌 // ex) num=4
			int x = 0;														//반복문을 위한 변수(세로 '|'의 개수)

			while (x < 15) {
				if (ladder[x][num - 1] == '-') {
					num = num - 2;
					choice--;
					x++;
				}
				else if (ladder[x][num + 1] == '-') {
					num = num + 2;
					choice++;
					x++;
				}
				else
					x++;

			}
			arr[up - 1][choice - 1] += 1;

		}
		for (int a = 0; a < 15; a++) {
			for (int b = 0; b < 9; b++) {
				ladder[a][b] = 0;
			}
		}
	}
	for (int upup = 0; upup < 5; upup++) {
		printf("%d:A(%d) B(%d) C(%d) D(%d) E(%d)\n", upup + 1, arr[upup][0], arr[upup][1], arr[upup][2], arr[upup][3], arr[upup][4]);
	}
}