#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isupper(char c)
{
    return c >= 'A' && c <= 'Z' ? true : false;
}

char* lower(char* s)
{
    for(int i = 0; i < strlen(s); i++)
    {
        if(isupper(s[i]))
            s[i] += 32;
    }
    return s;
}

int compare(const char* p1, const char* p2)
{
    return *p1 - *p2;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) 
{
    my_string = lower(my_string);
    qsort(my_string, strlen(my_string), sizeof(char), compare);
    return my_string;
}