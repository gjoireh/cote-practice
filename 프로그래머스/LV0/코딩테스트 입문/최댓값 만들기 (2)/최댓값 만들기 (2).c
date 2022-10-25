#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const int* p1, const int* p2)
{
    return *p1 - *p2;
}

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) 
{
    int answer = 0;
    qsort(numbers, numbers_len, sizeof(int), compare);
    return numbers[0] * numbers[1] > numbers[numbers_len-2] * numbers[numbers_len-1] ? numbers[0] * numbers[1] : numbers[numbers_len-2] * numbers[numbers_len-1];
}