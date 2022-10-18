#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_lower(char c)
{
    if(c >= 97 && c <= 122)
        return true;
    return false;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) 
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int ans_idx = 0;
    int len = strlen(my_string);
    char* answer = (char*)malloc(len + 1);

    for(int i = 0; i < len; i++)
    {
        if(is_lower(my_string[i]))
            answer[ans_idx++] = my_string[i] - 32;
        else
            answer[ans_idx++] = my_string[i] + 32;
    }
    answer[ans_idx] = '\0';
    return answer;
}