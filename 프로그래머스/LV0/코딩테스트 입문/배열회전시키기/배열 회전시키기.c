#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// numbers_len은 배열 numbers의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(int numbers[], size_t numbers_len, const char* direction)
{
    int* answer = (int*)malloc(sizeof(int) * numbers_len);
    if (strcmp(direction, "right") == 0)
    {
        answer[0] = numbers[numbers_len - 1];
        memcpy(answer + 1, numbers, sizeof(int) * (numbers_len - 1));
    }
    else
    {
        answer = numbers + 1;
        answer[numbers_len - 1] = numbers[0];
    }
    return answer;
}