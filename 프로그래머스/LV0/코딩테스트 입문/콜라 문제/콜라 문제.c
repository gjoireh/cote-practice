#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) 
{
    int x = 1;
    while(n - (a-b)*x >= a)
    {
        x++;
    }
    return x * b;
}