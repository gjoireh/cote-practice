#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct nd
{
    int number;
    int distance;
}typedef ND;

int compare(const ND* arg1, const ND* arg2)
{
    if (arg1->distance != arg2->distance)
        return (arg1->distance - arg2->distance);

    return (arg1->number - arg2->number);
}

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len, int n) {
    int answer = 0;
    int* distances = (int*)malloc(sizeof(int) * array_len);

    ND* nd = (ND*)malloc(sizeof(ND) * array_len);

    for (int i = 0; i < array_len; i++)
    {
        distances[i] = array[i] - n;
        if (distances[i] < 0)
            distances[i] *= -1;

        nd[i].number = array[i];
        nd[i].distance = distances[i];
    }
    qsort((void*)nd, array_len, sizeof(ND), compare);
    answer = nd[0].number;
    return answer;
}