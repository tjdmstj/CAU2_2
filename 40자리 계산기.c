#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void ADD(char num11[100], char num22[100]);
void MINUS(char num11[100], char num22[100]);
void MULTIPLY(char num11[100], char num22[100]);

int main() {
    char X[100], Y[100];
    printf("input X ");
    scanf("%s", X);
    printf("input Y ");
    scanf("%s", Y);
    ADD(X,Y);   
    MINUS(X, Y);
    MULTIPLY(X, Y);
}
void ADD(char num11[100], char num22[100]) {                     //µ¡¼ÀÇÔ¼ö
    int max, val, up;
    int i, len1, len2;
    int first[100] = { 0, };
    int second[100] = { 0, };
    int result[100] = { 0, };
    len1 = strlen(num11);
    len2 = strlen(num22);

    for (i = 0; i < len1; i++) {
        first[len1 - 1 - i] = num11[i] - 48;
    }
    for (i = 0; i < len2; i++) {
        second[len2 - 1 - i] = num22[i] - 48;
    }

    if (len1 > len2)
        max = len1;
    else
        max = len2;

    up = 0;
    for (i = 0; i < max; i++) {
        val = first[i] + second[i] + up;
        up = val / 10;                  //upÀº intÇü
        result[i] = val % 10;
    }
    if (up == 1) {
        result[max] = 1;
        max += 1;
    }

    printf("X+Y=");
    for (i = 0; i < max; i++) {
        printf("%d", result[max - 1 - i]);
    }
    printf("\n");
}

void MINUS(char num11[100], char num22[100]) {       //»¬¼À
    int max, val, down;
    int i, len1, len2;
    int first[100] = { 0, };
    int second[100] = { 0, };
    int result[100] = { 0, };
    len1 = strlen(num11);
    len2 = strlen(num22);

    for (i = 0; i < len1; i++) {
        first[len1 - 1 - i] = num11[i] - 48;
    }
    for (i = 0; i < len2; i++) {
        second[len2 - 1 - i] = num22[i] - 48;
    }

    if (len1 > len2) {
        max = len1;
        down = 0;
        for (i = 0; i < max; i++) {
            val = first[i] - second[i] - down;
            if (val < 0) {
                down = 1;
                result[i] = 10 + val;
            }
            else {
                down = 0;
                result[i] = val;
            }

        }
        printf("X-Y=");
        for (i = 0; i < max; i++) {
            printf("%d", result[max - 1 - i]);
        }
    }
    else if (len1 < len2) {
        max = len2;

        down = 0;
        for (i = 0; i < max; i++) {
            val = second[i] - first[i] - down;
            if (val < 0) {
                down = 1;
                result[i] = 10 + val;
            }
            else {
                down = 0;
                result[i] = val;
            }

        }
        printf("X-Y=-");
        for (i = 0; i < max; i++) {
            printf("%d", result[max - 1 - i]);
        }
    }
    else if (len1 == len2 && first[len1-1] < second[len2-1]) {
        max = len2;

        down = 0;
        for (i = 0; i < max; i++) {
            val = second[i] - first[i] - down;
            if (val < 0) {
                down = 1;
                result[i] = 10 + val;
            }
            else {
                down = 0;
                result[i] = val;
            }

        }
        printf("X-Y=-");
        for (i = 0; i < max; i++) {
            printf("%d", result[max - 1 - i]);
        }
    }
    else {
        max = len1;
        down = 0;
        for (i = 0; i < max; i++) {
            val = first[i] - second[i] - down;
            if (val < 0) {
                down = 1;
                result[i] = 10 + val;
            }
            else {
                down = 0;
                result[i] = val;
            }

        }
        printf("X-Y=");
        for (i = 0; i < max; i++) {
            printf("%d", result[max - 1 - i]);
        }
    }
    printf("\n");
}

void MULTIPLY(char num11[100],char num22[100]) {           //°ö¼À
    int max,min, val, up;
    int i,j,len1, len2;
    int first[100] = { 0, };
    int second[100] = { 0, };
    int result[100][100] = { 0, };
    int final[100] = { 0, };
    len1 = strlen(num11);
    len2 = strlen(num22);


    for (i = 0; i < len1; i++) {
        first[len1 - 1 - i] = num11[i] - 48;
    }
    for (i = 0; i < len2; i++) {
        second[len2 - 1 - i] = num22[i] - 48;
    }
    up = 0;
    int row = 0;
    if (len1 > len2) {
        max = len1;
        min = len2;
        int len = max + min;
        for (i = 0; i < min; i++) {
            up = 0;
            for (j = 0; j < max; j++) {
                val = first[j] * second[i] + up;
                up = val / 10;
                result[i][row + j] = val % 10;
            }
            if (up >= 1) {
                result[i][row + max] = up;
            }
            row++;
        }


        up = 0;
        int sum;
        for (i = 0; i < len; i++) {
            sum = 0;
            for (j = 0; j < min; j++) {
                sum += result[j][i];
            }
            val = sum + up;
            up = val / 10;
            final[i] = val % 10;
        }
        if (up == 1) {
            final[len] = 1;
            max += 1;
        }
        
        for (i = 0; i < max + min; i++) {
            if (final[len - 1 - i] == 0) {
                len -= 1;
            }
            else break;
        }

        printf("X*Y=");
        for (i = 0; i < len; i++) {
            printf("%d", final[len - 1 - i]);
        }
        printf("\n");
    }
    else if (len1 < len2) {
        max = len2;
        min = len1;
        int len = max + min;
        for (i = 0; i < min; i++) {
            up = 0;
            for (j = 0; j < max; j++) {
                val = first[i] * second[j] + up;
                up = val / 10;
                result[i][row + j] = val % 10;
            }
            if (up >= 1) {
                result[i][row + max] = up;
            }
            row++;
        }


        up = 0;
        int sum;
        for (i = 0; i < len; i++) {
            sum = 0;
            for (j = 0; j < min; j++) {
                sum += result[j][i];
            }
            val = sum + up;
            up = val / 10;
            final[i] = val % 10;
        }
        if (up == 1) {
            final[len] = 1;
            max += 1;
        }

        for (i = 0; i < max + min; i++) {
            if (final[len - 1 - i] == 0) {
                len -= 1;
            }
            else break;
        }

        printf("X*Y=");
        for (i = 0; i < len; i++) {
            printf("%d", final[len - 1 - i]);
        }
        printf("\n");
    }
    else {
        max = len1;
        min = len2;
        int len = max + min;
        for (i = 0; i < min; i++) {
            up = 0;
            for (j = 0; j < max; j++) {
                val = first[j] * second[i] + up;
                up = val / 10;
                result[i][row + j] = val % 10;
            }
            if (up >= 1) {
                result[i][row + max] = up;
            }
            row++;
        }


        up = 0;
        int sum;
        for (i = 0; i < len; i++) {
            sum = 0;
            for (j = 0; j < len2; j++) {
                sum += result[j][i];
            }
            val = sum + up;
            up = val / 10;
            final[i] = val % 10;
        }
        if (up == 1) {
            final[len] = 1;
            max += 1;
        }
        for (i = 0; i < max+min; i++) {
            if (final[len - 1 - i] == 0) {
                len -= 1;
            }
            else break;
        }

        printf("X*Y=");
        for (i = 0; i < len; i++) {
            printf("%d", final[len - 1 - i]);
        }
        printf("\n");
        }
}