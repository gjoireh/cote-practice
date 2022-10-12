#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int a, int b)
{
    return fmod((float)a/(float)b * 1000, 1) == 0 ? 1 : 2; //  fmod : c에서의 나머지 연산
}

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <math.h>

// bool is_prime_number(int x)
// {
//     for(int i = 2; i < (int)pow(x, 0.2) + 1; i++)
//     {
//         if(x % i == 0)
//             return false;
//         return true;
//     }
// }

// int gcd(int m, int n)
// {
//     int t;
//     while (n != 0)
//     {
//         t = m % n;
//         m = n;
//         n = t;
//     }
//     return m;
// }

// int solution(int a, int b) 
// {
//     int prime_factors[1000] = {0,};
//     int pf_idx = 0;
//     int denominator;

//     denominator = b / gcd(a, b);

//     if(denominator == 2)
//         return 1;

//     for(int i = 2; i <= denominator; i++)
//     {
//         if(denominator % i == 0 && is_prime_number(i))
//             prime_factors[pf_idx++] = i;
//     }

//     for(int i = 0; i < pf_idx; i++)
//     {
//         if(prime_factors[i] != 2 && prime_factors[i] != 5)
//             return 2;
//     }
//     return 1;
// }
