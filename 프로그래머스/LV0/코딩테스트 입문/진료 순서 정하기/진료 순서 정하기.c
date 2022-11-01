#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int compare(const int* p1, const int* p2)
{
    return *p2 - *p1;
}

int index(int* e, int n, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(e[i] == n)return i;
    }
}

// emergency_len은 배열 emergency의 길이입니다.
int* solution(int emergency[], size_t emergency_len) 
{
    int* answer = (int*)malloc(sizeof(int) * emergency_len);
    int* e = (int*)malloc(sizeof(int) * emergency_len);
    memcpy(e, emergency, emergency_len);
    qsort(e, emergency_len, sizeof(int), compare);
    for(int i = 0; i < emergency_len; i++)
    {
        answer[i] = index(e, emergency[i], emergency_len) + 1;
    }
    return answer;
}