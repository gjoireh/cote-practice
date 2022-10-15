#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int solution(int chicken) 
{
    return (int)chicken*0.1 *(pow(0.1, 7)-1)/(0.1-1);
}