#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const char* p1, const char* p2)
{
    return *p2 - *p1;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* before, const char* after) 
{
    qsort(before, strlen(before), 1, compare);
    qsort(after, strlen(after), 1, compare);
    return strcmp(before, after) == 0 ? 1 : 0;
}