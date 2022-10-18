#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int order) 
{
    int answer = 0;
    int cur_num = 0;
    while (order)
    {
        cur_num = order % 10;
        if(cur_num == 3 || cur_num == 6 || cur_num == 9)
            answer++;
        order /= 10;
    }
    return answer;
}