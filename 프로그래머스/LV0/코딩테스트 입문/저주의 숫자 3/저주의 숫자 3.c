#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool in(int n)
{
    while (n)
    {
        if(n % 10 == 3)return true;
        n /= 10;
    }
    return false; 
}

int solution(int n) 
{
    int ans = 0;
    while (n--)
    {
        ans++;
        while (ans % 3 == 0 || in(ans))
        {
            ans++;
        }
    }
    return ans;
}