#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) 
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* ans = (int*)malloc(n);
    int ans_idx = 0;
    int i = 2;
    while(n > 1)
    {
        if(n % i == 0)
        {
            ans[ans_idx++] = i;
            while (n % i == 0)
            {
                n /= i;
            }
        }
        i++;
    }
    return ans;
}