#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) 
{
    int mul = 1;
    int i = 1;
    while(true)
    {
        mul *= i;
        if(mul > n)break;
        i += 1;
    }
    return i - 1;
}