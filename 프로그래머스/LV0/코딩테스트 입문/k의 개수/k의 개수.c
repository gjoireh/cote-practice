#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int i, int j, int k)
{
    int answer = 0;
    int cur_n = 0;

    for (int n = i; n <= j; n++)
    {
        cur_n = n;
        while (cur_n)
        {
            if (cur_n % 10 == k)
                answer++;
            cur_n /= 10;
        }
    }
    return answer;
}