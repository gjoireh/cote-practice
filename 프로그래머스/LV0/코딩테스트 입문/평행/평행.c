#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct dot
{
    int x;
    int y;
}typedef DOT;

DOT l1[2];
DOT l2[2];
DOT sub1;
DOT sub2;

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

            l1[0].x = dots[i][0];
            l1[0].y = dots[i][1];
            l1[1].x = dots[j][0];
            l1[1].y = dots[j][1];

            for (int k = 0; k < 4; k++)
            {
                if (!group[k])
                {
                    l2[idx_of_l2].x = dots[k][0];
                    l2[idx_of_l2++].y = dots[k][1];
                }
            }

            idx_of_l2 = 0;
            group[i] = false;
            group[j] = false;

            sub1.x = l1[0].x - l1[1].x;
            sub1.y = l1[0].y - l1[1].y;
            sub2.x = l2[0].x - l2[1].x;
            sub2.y = l2[0].y - l2[1].y;

            if ((sub1.x == 0 && sub2.x != 0) || (sub1.x != 0 && sub2.x == 0))
                continue;

            if ((sub1.x == 0 && sub2.x == 0) ||
                (sub1.y == 0 && sub2.y == 0) ||
                ((float)sub1.y / (float)sub1.x) == (float)(sub2.y / (float)sub2.x))
                return 1;
        }
    }
    return 0;
}