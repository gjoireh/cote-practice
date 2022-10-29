#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const int p1[2], const int p2[2])
{
    return (p2[1] - p1[1]);
}

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len)
{
    int counter[1000][2]; // [0][1]] : [숫자][개수]
    for (int i = 0; i < 1000; i++)
    {
        counter[i][0] = -1;
        counter[i][1] = 0;
    }
        
    for (int i = 0; i < array_len; i++)
    {
        counter[array[i]][1]++;
        if (counter[array[i]][0] == -1)
            counter[array[i]][0] = array[i];
    }
    qsort(counter, 1000, sizeof(int) * 2, compare);

    return counter[0][1] == counter[1][1] ? -1 : counter[0][0];
}