#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char rsp_dict[6] = {'5', 0, '0', 0, 0, '2'};

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* rsp) 
{
    int len = strlen(rsp);
    char* answer = (char*)malloc(len + 1);
    answer[len] = '\0';
    for(int i = 0; i < len; i++)
    {
        answer[i] = rsp_dict[rsp[i] - '0'];
    }
    return answer;
}