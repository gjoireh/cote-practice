#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int M, int N) 
{
    return M * N == 1 ? 0 : M * N - 1;
}