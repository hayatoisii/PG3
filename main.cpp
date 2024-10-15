#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void DisplayResult(int* result, int* dice) {
    printf("サイコロの目は%dでした。\n", *dice);

    if (*result == 1) {
        printf("正解\n");
    }
    else {
        printf("不正解\n");
    }
}

void setTimeout(void (*callback)(int*, int*), int second, int* result, int* dice) {
    Sleep(second * 1000);
    callback(result, dice);
}

int numbe1(int dice) {
    return dice % 2 != 0;
}
int numbe2(int dice) {
    return dice % 2 == 0;
}

int main() {
    int numbe;
    int dice;
    int result;

    printf("サイコロの目が奇数(1)か偶数(2)かどっち→ ");
    scanf_s("%d", &numbe);

    dice = rand() % 6 + 1;

    int (*funcArr[2])(int) = { numbe1, numbe2 };

    if (funcArr[numbe - 1](dice)) {
        result = 1;
    }
    else {
        result = 0;
    }

    setTimeout(DisplayResult, 3, &result, &dice);

    return 0;
}
