#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char d_place[100][100] = { 0, };

void dangerous_area_record(int x, int y, int n)
{
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i < 0 || i > n - 1 || j < 0 || j > n - 1)
                continue;
            d_place[i][j] = 1;
        }
    }
}

int get_num_of_safe_place(int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d_place[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}
int solution(int** board, size_t board_rows, size_t board_cols)
{
    int answer = 0;
    int n = board_rows;


    for (int r = 0; r < board_rows; r++)
    {
        for (int c = 0; c < board_cols; c++)
        {
            if (*(*(board + r) + c) == 1)
                dangerous_area_record(r, c, n);
        }
    }

    answer = get_num_of_safe_place(n);
    return answer;
}