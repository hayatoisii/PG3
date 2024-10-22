#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono> 
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

int main() {
    int numbe;
    int dice;
    int result;

    std::srand(static_cast<unsigned int>(std::time(0)));

    printf("サイコロの目が奇数(1)か偶数(2)かどっち→ ");
    scanf_s("%d", &numbe);

    dice = std::rand() % 6 + 1;

    auto checkOddEven = (numbe == 1)
    ? [](int dice) { return dice % 2 != 0; }
    : [](int dice) { return dice % 2 == 0; };

    result = checkOddEven(dice) ? 1 : 0;

    setTimeout(DisplayResult, 3, &result, &dice);

    return 0;
}
