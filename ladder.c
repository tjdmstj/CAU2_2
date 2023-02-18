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
			}																//Ȧ�� ��ȣ���� | �߰�
			else if (j % 2 == 1) {
				if ((rand() % 3) == 2 || (rand() % 5) == 5) {
					if (ladder[i][j - 2] != '-')
						ladder[i][j] = '-';
																			//¦�� ��ȣ���� '-' �߰�, �� ��ٸ��� '-'�� ��ġ�� �ʱ� ���� if (ladder[i][j - 2] != '-') �߰� 
																			//���μ��� 15�� �̻� �ֱ� ���� ���� ���� ���� ��(������?)

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
	printf("1 2 3 4 5 \n");													 //ó�� ���� ��ȣ

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 9; j++) {
			printf("%c", ladder[i][j]);
		}
		printf("\n");														 // ù��° ���� �ϼ��Ǹ� �����ٷ� �Ѿ��
	}
	printf("A B C D E \n");													 //������ ���
}

int main() {
	srand((unsigned)time(NULL));
	int arr[5][5] = { 0, };
	for (int z = 0; z < 100; z++) {
		make_ladder();
		for (int up = 1; up < 6; up++) {
			int num, choice;
			int a = 0, b = 0, c = 0, d = 0, e = 0;
			num = up;														 //ex)up=3 num=3 //up�� �ݺ��� ���� ����
			choice = num;													 // ex) num=3 choice=3
			num = num * 2 - 2;												//�迭�� 0���� �����ϱ� ������ 2�� ���ѵ� -2�� ���� // ex) num=4
			int x = 0;														//�ݺ����� ���� ����(���� '|'�� ����)

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