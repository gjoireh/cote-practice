#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const int* p1, const int* p2)
{
    return *p2 - *p1;
}

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    qsort(numbers, numbers_len, sizeof(int), compare);
    return numbers[0] * numbers[1];
}