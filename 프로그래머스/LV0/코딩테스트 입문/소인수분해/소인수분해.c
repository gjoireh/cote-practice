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

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct prime_numbers_and_len
{
    int* pns;
    int len;
}typedef PNAL;

PNAL sieve_of_eratosthenes(n)
{
    PNAL pnal;
    int* pns = (int*)malloc(sizeof(int) * n);
    int pns_idx = 0;
    bool* sieve = malloc(n + 1);
    memset(sieve, true, n + 1);

    int m = (int)pow(n, 0.5);

    for (int i = 2; i <= m; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i]) pns[pns_idx++] = i;
    }
    pnal.pns = pns;
    pnal.len = pns_idx;
    return pnal;
}

int* solution(int n)
{
    PNAL pnal = sieve_of_eratosthenes(n);
    int* answer = (int*)malloc(sizeof(int) * pnal.len);
    int ans_idx = 0;
    for (int i = 0; i < pnal.len; i++)
    {
        if (n % pnal.pns[i] == 0) answer[ans_idx++] = pnal.pns[i];
    }
    return answer;
}
*/