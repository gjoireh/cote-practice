#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

__int128 factorial(int n)
{
    if(n <= 1)return 1;
    return n * factorial(n-1);
}

__int128 solution(int balls, int share) 
{
    return factorial(balls) / (factorial(balls - share) * factorial(share));
}