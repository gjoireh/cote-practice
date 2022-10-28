#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const int* p1, const int* p2)
{
    return *p1 - *p2;
}

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) 
{
    qsort(array, array_len, sizeof(int), compare);
    return array[array_len / 2];
}