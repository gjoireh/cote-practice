#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isdigit(char c)
{
    if (c < 48 || c > 57)
        return false;
    return true;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string)
{
    int answer = 0;
    int sign = 1;
    int idx = 0;
    char splited[100][6] = { 0, };
    char* p = NULL;

    for (int i = 0; i < strlen(my_string); i++)
    {
        if (isdigit(my_string[i]))
        {
            if(p == NULL)
                p = &my_string[i];
        }
        else if (my_string[i] == '+')
        {
            splited[idx++][0] = '+';
        }
        else if (my_string[i] == '-')
        {
            splited[idx++][0] = '-';
        }
        else
        {
            if (p != NULL)
            {
                memcpy(splited[idx++], p, &my_string[i] - p);
                p = NULL;
            }
        }
    }
    
    strcpy(splited[idx++], p);
    
    for (int i = 0; i < idx; i++)
    {
        if (splited[i][0] == '+')
            sign = 1;
        else if (splited[i][0] == '-')
            sign = -1;
        else
            answer += sign * atoi(splited[i]);
    }
    return answer;
}