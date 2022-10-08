#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int l1[2][2] = { {0,0}, {0,0} };
int l2[2][2] = { {0,0}, {0,0} };
int sub1[2] = { 0,0 };
int sub2[2] = { 0,0 };
int idx_of_l1 = 0;
int idx_of_l2 = 0;
bool group[4] = { false, false, false, false };

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols)
{
    int answer = 0;

    for (int i = 0; i < 1; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            group[i] = true;
            group[j] = true;

            l1[idx_of_l1][0] = dots[i][0];
            l1[idx_of_l1++][1] = dots[i][1];
            l1[idx_of_l1][0] = dots[j][0];
            l1[idx_of_l1][1] = dots[j][1];

            for (int k = 0; k < 4; k++)
            {
                if (!group[k])
                {
                    l2[idx_of_l2][0] = dots[k][0];
                    l2[idx_of_l2++][1] = dots[k][1];
                }
            }

            idx_of_l1 = 0;
            idx_of_l2 = 0;
            group[i] = false;
            group[j] = false;

            sub1[0] = l1[0][0] - l1[1][0];
            sub1[1] = l1[0][1] - l1[1][1];
            sub2[0] = l2[0][0] - l2[1][0];
            sub2[1] = l2[0][1] - l2[1][1];

            if ((sub1[0] == 0 && sub2[0] != 0) || (sub1[0] != 0 && sub2[0] == 0))
                continue;

            if ((sub1[0] == 0 && sub2[0] == 0) ||
                (sub1[1] == 0 && sub2[1] == 0) ||
                ((float)sub1[1] / (float)sub1[0]) == (float)(sub2[1] / (float)sub2[0]))
                return 1;
        }
    }
    return 0;
}