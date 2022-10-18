#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool in(char* s, char c)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if(s[i++] == c)
            return true;
    }
    return false;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) 
{
    char answer[1000] = {0,};

    int i_of_mys = 0;
    int i_of_ans = 0;
    while (my_string[i_of_mys] != '\0')
    {
        if(!in(answer, my_string[i_of_mys]))
            answer[i_of_ans++] = my_string[i_of_mys];
        i_of_mys++;
    }
    answer[i_of_ans] = '\0';
    return answer;
}