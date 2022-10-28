#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
// common_len은 배열 common의 길이입니다.
int solution(int common[], size_t common_len) 
{
    if(common[1] - common[0] == common[2] - common[1]) return common[0] + (common[1] - common[0]) * common_len;
    else return common[0] * (int)pow(common[1] / common[0], common_len);
}