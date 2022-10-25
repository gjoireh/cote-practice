#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int* solution(int denum1, int num1, int denum2, int num2) 
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    int numerator = denum1 * num2 + denum2 * num1;
    int denominator = num1 * num2;
    int g = gcd(numerator, denominator);
    answer[0] = numerator / g;
    answer[1] = denominator / g;
    return answer;
}