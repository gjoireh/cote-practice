#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

int get_len(char* b)
{
    int i = 0;
    while (b[i] != '\0')
        i++;
    return i;
}

bool impossible_pronounce2(char* b)
{
    char* words[4] = { "aya", "ye", "woo", "ma" };
    int lens[4] = { 3,2,3,2 };
    int len_of_b = get_len(b);
    char temp[30] = {0,};
    char* finded_pos = NULL;

    for (int i = 0; i < 4; i++)
    {
        while (true)
        {
            finded_pos = strstr(b, words[i]);
            if (finded_pos == NULL)
                break;
            if (finded_pos == b)
            {
                b = b + lens[i];
            }
            else
            {
                strcpy(temp, finded_pos + lens[i]);
                *(b + (finded_pos - b)) = '\0';
                strcat(b, temp);
            }
            len_of_b -= lens[i];
            if (len_of_b == 0)
                return false;
        }
    }

    if (len_of_b != 0)
        return true;
    else
        return false;

}

bool impossible_pronounce1(char* b)
{
    char* sc[4] = { "ayaaya", "yeye", "woowoo", "mama" };
    int sc_len[4] = { 6,4,6,4 };

    for (int i = 0; i < 4; i++)
    {
        if (strstr(b, sc[i]) != NULL)
            return true;
    }
    return false;
}

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len)
{
    char babs[10][30] = {0,};
    for (int i = 0; i < babbling_len; i++)
    {
        strcpy(babs[i], babbling[i]);
    }
    int answer = 0;

    for (int i = 0; i < babbling_len; i++)
    {
        if (impossible_pronounce1(babs[i]))
            continue;
        if (impossible_pronounce2(babs[i]))
            continue;
        answer++;
    }
    return answer;
}