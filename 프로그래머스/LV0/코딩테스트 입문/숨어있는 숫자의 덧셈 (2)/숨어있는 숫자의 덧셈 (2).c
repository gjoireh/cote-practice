#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isdigit(char c)
{
    return c >= 48 && c <= 57 ? true : false;
}

char** findall(const char* s)
{
    char** positions = (char**)malloc(sizeof(char*) * strlen(s));
    memset(positions, -1, sizeof(char*) * strlen(s));
    int pos_idx = 0;
    while (*s != '\0')
    {
        if (isdigit(*s))
        {
            positions[pos_idx++] = s++;
            while (isdigit(*s))
            {
                s++;
            }
        }
        else
        {
            s++;
        }

    }
    return positions;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string)
{
    int answer = 0;
    char** positions = (char**)malloc(sizeof(char*) * strlen(my_string));

    positions = findall(my_string);

    while (*positions != -1)
    {
        answer += atoi(*positions);
        positions++;
    }
    return answer;
}