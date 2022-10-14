#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const int* arg1, const int* arg2)
{
    return (*arg2 - *arg1);
}

// score_rows는 2차원 배열 score의 행 길이, score_cols는 2차원 배열 score의 열 길이입니다.
int* solution(int** score, size_t score_rows, size_t score_cols)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * score_rows);
    int* sorted_score = (int*)malloc(sizeof(int) * score_rows);
    int* score_sums = (int*)malloc(sizeof(int) * score_rows);

    for (int r = 0; r < score_rows; r++)
    {
        sorted_score[r] = score[r][0] + score[r][1];
        score_sums[r] = score[r][0] + score[r][1];
    }

    qsort((void*)sorted_score, score_rows, sizeof(int), compare);

    for (int i = 0; i < score_rows; i++)
    {
        for (int j = 0; j < score_rows; j++)
        {
            if (score_sums[i] == sorted_score[j])
            {
                answer[i] = j + 1;
                break;
            }
        }
    }
    return answer;
}