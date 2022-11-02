#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int solution(int n) 
{
    int answer = 0;
    double root_n = pow(n, 0.5);
    for(int i = 1; i <= (int)root_n; i++)
    {
        if(n % i == 0)answer += 1;
    }
    return root_n == (int)root_n ? (answer-1) * 2 + 1 : answer * 2;
}