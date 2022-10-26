#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_str, int n)
{
    int ans_idx = 0;
    int str_len = strlen(my_str);
    int ans_len = str_len % n == 0 ? str_len / n : str_len / n + 1;
    
    char** answer = (char**)malloc(sizeof(char*) * ans_len);
    for (int i = 0; i < ans_len; i++)
    {
        answer[i] = (char*)malloc(sizeof(char) * (n + 1));
        memset(answer[i], 0, sizeof(char) * (n + 1));
    }
    
    for (int i = 0; i < str_len; i += n)
    {
        strncpy(answer[ans_idx++], &my_str[i], n);
    }
    return answer;
}