#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int get_max(int* sides)
{
    int max = -1;
    for(int i = 0; i < 3; i++)
    {
        if(max < sides[i])
            max = sides[i];
    }
    return max;
}

int get_sum(int* sides)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
    {
        sum += sides[i];
    }
    return sum;    
}

// sides_len은 배열 sides의 길이입니다.
int solution(int sides[], size_t sides_len)
{
    return get_max(sides) < get_sum(sides) - get_max(sides) ? 1 : 2;
}