#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const char* p1, const char* p2)
{
    return *p1 - *p2;
}

bool isdigit(char c)
{
    return c >= '0' && c <= '9' ? true : false;
}

int get_num_len(const char* my_string)
{
    int ret = 0;
    for (int i = 0; i < strlen(my_string); i++)
    {
        if (isdigit(my_string[i]))ret++;
    }
    return ret;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* my_string)
{
    int ans_idx = 0;
    int num_len = get_num_len(my_string);
    int* answer = (int*)malloc(sizeof(int) * num_len);
    
    for (int i = 0; i < strlen(my_string); i++)
    {
        if (isdigit(my_string[i]))answer[ans_idx++] = my_string[i] - 48;
    }
    qsort(answer, num_len, sizeof(int), compare);
    return answer;
}