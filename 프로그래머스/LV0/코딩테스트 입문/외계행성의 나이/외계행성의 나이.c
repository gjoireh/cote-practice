#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
char* solution(int age) {
    int age_len = (int)log10(age) + 1;
    int ans_idx = 0;
    char* answer = (char*)malloc(age_len + 1);
    answer[age_len] = '\0';
    
    while (age)
    {
        answer[age_len-1 - ans_idx++] = age % 10 + 'a';
        age /= 10;
    }
    return answer;
}