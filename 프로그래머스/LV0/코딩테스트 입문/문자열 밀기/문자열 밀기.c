#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* A, const char* B)
{
    int b_len = strlen(B);
    char* BB = (char*)malloc(b_len * 2 + 1);
    strcpy(BB, B);
    strcat(BB, B);
    char* p = strstr(BB, A);
    return p != NULL ? p - BB : -1;
}