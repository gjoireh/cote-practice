#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len, int num1, int num2) 
{
    int* answer = (int*)malloc(sizeof(int) * (num2 - (num1-1)));
    memcpy(answer, numbers + num1, sizeof(int) * (num2 - (num1-1)));
    return answer;
}