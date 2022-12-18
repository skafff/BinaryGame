#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


static int score = 20;
static int randInt = 0;
static char randChar[5] = "00000";

static int num = 0;
static int temp;
static char str[5];

// (560 - 610) ��������� ����� � ���������� � �������� ����
void rand_num() {
    srand(time(NULL)); // ����� ����� ��� ���������� �����
    randInt = 0;
    for (int J = 0; J < 5; J++) {
        temp = rand() % 2; // ��������� ����� (0, 1)
        randInt = randInt * 2 + temp; // ������ � ���������� ����
        randChar[J] = temp + '0'; // ������ � �������� ����
    }
}

/* (110 - 550) ������������� ���� � �������� ����
* ������� ����� ��������� 10 ����� � ���������� ���
* ����� ��������� 10 ����� � �������� ��� */
void start_game() {
    for (int i = 1; i <= 10; i++) { // 10 �������� ����� (300 - 510)
        rand_num();
        printf("\nBINARY: %s  ->  DECIMAL:", randChar);
        scanf("%s", str);
        num = atoi(str); // ��������� ������ � �����
        if (num != randInt) {
            printf("%d\n\n", randInt); // ��� ��������� ����� � -1
            score = score - 1;
        }
    }
    printf("\nExample: '01010'");
    for (int i = 1; i <= 10; i++) { // 10 ���������� (150 - 290)
        rand_num();
        printf("\nDECIMAL: %d  ->  BINARY:", randInt);
        scanf("%s", str);
        if (strcmp(randChar, str) != 0) { // ��������� �����
            printf("\n%s\n\n", randChar); // ��� ��������� ����� � -1
            score = score - 1;
        }
    }
    // ��� ��� ����� 20 �����, 100% = 5*20, �� ����� ������� ����� score*5
    printf("\nYOUR SCORE : %d % (%d/20)", score*5, score);
}

int main() { // (10 - 20) 
    printf("                  BINARY");
    printf("\nCREATIVE COMPUTING  MORRISTOWN NEW JERSEY\n");

    start_game();
}
