#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) 
{
    int len = strlen(my_string);
    char* answer = (char*)malloc(len * n + 1);
    answer[len * n] = '\0';

    for(int i = 0; i < len; i++)
    {
        memset(&answer[n*i], my_string[i], n);
    }
    return answer;
}