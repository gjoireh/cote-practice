#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num, int k) 
{
    char s[8] = {0,};
    int answer = 1;
    int i = 0;

    sprintf(s, "%d", num);

    while(s[i] != '\0')
    {
        if(s[i++]-48 == k)
            return answer;
        answer++;
    }
    return -1;
}