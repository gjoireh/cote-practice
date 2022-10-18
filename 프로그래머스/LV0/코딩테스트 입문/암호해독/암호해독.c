#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* cipher, int code)
{
    char* answer = (char*)malloc(strlen(cipher) / code + 1);
    int ans_idx = 0;
    for (int i = code - 1; i < strlen(cipher); i += code)
    {
        answer[ans_idx++] = cipher[i];
    }
    answer[ans_idx] = '\0';
    return answer;
}