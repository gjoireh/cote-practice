#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num, int total) 
{
    int* answer = (int*)malloc(sizeof(int) * num);
    int first = (total - (num-1)*num / 2) / num;
    for(int i = 0; i < num; i++)
    {
        answer[i] = first + i;
    }
    return answer;
}