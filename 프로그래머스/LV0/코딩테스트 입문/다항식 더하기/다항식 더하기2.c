#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isdigit(char c)
{
    return c >= '0' && c <= '9';
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* polynomial)
{
    int x = 0, n = 0, temp = 0;
    char* answer = malloc(strlen(polynomial));

    for (int i = 0; i <= strlen(polynomial); i++)
    {
        if (isdigit(polynomial[i])) 
        {
            temp = temp * 10 + polynomial[i] - '0';
        }
        else
        {
            if (polynomial[i] == 'x')
            {
                x += temp ? temp : 1;
                temp = 0;
            }
            else
            {
                n += temp;
                temp = 0;
            }
        }
    }

    if (!x && !n)sprintf(answer, "%d", 0);
    else if (x && !n) x == 1 ? sprintf(answer, "x") : sprintf(answer, "%dx", x);
    else if (!x && n) sprintf(answer, "%d", n);
    else x == 1 ? sprintf(answer, "x + %d", n) : sprintf(answer, "%dx + %d", x, n);

    return answer;
}