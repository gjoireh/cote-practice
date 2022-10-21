#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
long long solution(const char* numbers)
{
    long long answer = 0;
    char n_words[10][6] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    char* ns = malloc(strlen(numbers));
    char back[50] = { 0, };
    char* p;
    strcpy(ns, numbers);

    for (int i = 0; i < 10; i++)
    {
        while (p = strstr(ns, n_words[i]))
        {
            strcpy(back, p + strlen(n_words[i]));
            ns[p - ns] = (char)(i + 48);
            ns[p - ns + 1] = '\0';
            strcat(ns, back);
        }
    }
    return atoll(ns);
}