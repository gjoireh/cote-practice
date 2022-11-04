#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// strlist_len은 배열 strlist의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* strlist[], size_t strlist_len) 
{
    int* answer = (int*)malloc(sizeof(int) * strlist_len);
    for(int i = 0; i < strlist_len; i++)
    {
        answer[i] = strlen(strlist[i]);
    }
    return answer;
}