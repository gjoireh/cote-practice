#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int angle) 
{
    return angle % 90 == 0 ? 2 * (angle / 90) : 2 * (angle / 90) + 1;
}