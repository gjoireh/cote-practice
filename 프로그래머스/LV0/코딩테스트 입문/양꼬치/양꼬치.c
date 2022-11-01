#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int k) 
{
    return k - n / 10 <= 0 ? 12000 * n : 12000 * n + (k - n / 10) * 2000;
}