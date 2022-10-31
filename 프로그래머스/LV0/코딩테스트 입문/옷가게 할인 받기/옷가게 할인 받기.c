#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int price) 
{
    double dr = 0.2;

    for(int i = 5; i >= 1; i -= 2)
    {
        if(price >= 100000 * i) return (int)(price * (1 - dr));
        dr *= 0.5;
    }
    return price;
}