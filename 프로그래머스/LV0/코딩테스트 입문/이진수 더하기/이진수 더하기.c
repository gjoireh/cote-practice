#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int get_len(const char* p)
{
    int i = 0;
    while (p[i] != '\0')
    {
        i++;
    }
    return i;
}

int get_bin_len(int s)
{
    if (s == 0)
        return 1;
    int i = 0;
    while (s)
    {
        s /= 2;
        i += 1;
    }
    return i;
}

int get_sum(const char* b1, const char* b2)
{
    int sum = 0;
    int b1_len = get_len(b1);
    int b2_len = get_len(b2);

    for (int i = 0; i < b1_len; i++)
    {
        if (b1[i] == '1')
            sum += (int)pow(2, b1_len - 1 - i);
    }

    for (int i = 0; i < b2_len; i++)
    {
        if (b2[i] == '1')
            sum += (int)pow(2, b2_len - 1 - i);
    }
    return sum;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* bin1, const char* bin2)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int sum = get_sum(bin1, bin2);
    int bin_len = get_bin_len(sum);
    char* answer = (char*)malloc(bin_len + 1);
    answer[bin_len] = '\0';


    for (int i = 0; i < bin_len; i++)
    {
        answer[bin_len - 1 - i] = sum % 2 + 48;
        sum /= 2;
    }

    return answer;
}