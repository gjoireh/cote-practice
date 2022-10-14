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

    return (arg2->number - arg1->number);
}

// numlist_len은 배열 numlist의 길이입니다.
int* solution(int numlist[], size_t numlist_len, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * numlist_len);
    int* distances = (int*)malloc(sizeof(int) * numlist_len);

    ND* nd = (ND*)malloc(sizeof(ND) * numlist_len);

    for (int i = 0; i < numlist_len; i++)
    {
        distances[i] = numlist[i] - n;
        if (distances[i] < 0)
            distances[i] *= -1;

        nd[i].number = numlist[i];
        nd[i].distance = distances[i];
    }
    qsort((void*)nd, numlist_len, sizeof(ND), compare);
   
    for (int i = 0; i < numlist_len; i++)
    {
        answer[i] = nd[i].number;
    }
    return answer;
}