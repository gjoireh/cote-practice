#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int hp) 
{
    int answer = 0;
    for(int damage = 5; damage >= 1; damage -= 2)
    {
        answer += hp / damage;
        hp %= damage;
    }
    return answer;
}