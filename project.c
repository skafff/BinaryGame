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

// (560 - 610) Случайное число в десятичном и двоичном виде
void rand_num() {
    srand(time(NULL)); // Новое время для случайного числа
    randInt = 0;
    for (int J = 0; J < 5; J++) {
        temp = rand() % 2; // Случайное число (0, 1)
        randInt = randInt * 2 + temp; // Запись в десятичном виде
        randChar[J] = temp + '0'; // Запись в двоичном виде
    }
}

/* (110 - 550) Инициализация игры и игрового поня
* Сначала нужно перевести 10 чисел в десятичный вид
* Потом перевести 10 чисел в двоичный вид */
void start_game() {
    for (int i = 1; i <= 10; i++) { // 10 двоичных чисел (300 - 510)
        rand_num();
        printf("\nBINARY: %s  ->  DECIMAL:", randChar);
        scanf("%s", str);
        num = atoi(str); // Введенная строка в число
        if (num != randInt) {
            printf("%d\n\n", randInt); // При проигрыше ответ и -1
            score = score - 1;
        }
    }
    printf("\nExample: '01010'");
    for (int i = 1; i <= 10; i++) { // 10 десятичных (150 - 290)
        rand_num();
        printf("\nDECIMAL: %d  ->  BINARY:", randInt);
        scanf("%s", str);
        if (strcmp(randChar, str) != 0) { // Сравнение строк
            printf("\n%s\n\n", randChar); // При проигрыше ответ и -1
            score = score - 1;
        }
    }
    // Так как всего 20 очков, 100% = 5*20, из этого процент равен score*5
    printf("\nYOUR SCORE : %d % (%d/20)", score*5, score);
}

int main() { // (10 - 20) 
    printf("                  BINARY");
    printf("\nCREATIVE COMPUTING  MORRISTOWN NEW JERSEY\n");

    start_game();
}
