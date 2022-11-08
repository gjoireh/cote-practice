#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int compare(const int** p1, const int** p2)
{
    return **p1 - **p2;
}

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols) 
{
    qsort(dots, dots_rows, sizeof(int*), compare);
    return abs(dots[0][1] - dots[1][1]) * abs(dots[0][0] - dots[2][0]);
}