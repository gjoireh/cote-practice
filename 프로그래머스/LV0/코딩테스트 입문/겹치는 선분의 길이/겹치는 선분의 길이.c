#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lines_rows는 2차원 배열 lines의 행 길이, lines_cols는 2차원 배열 lines의 열 길이입니다.
int solution(int** lines, size_t lines_rows, size_t lines_cols) 
{
    int temp = 0;
    int temp_cnt = 0;
    int answer = 0;
    int min = 100;
    int max = -100;

    for(int r = 0; r < 3; r++)
    {
        if(lines[r][1] < lines[r][0])
        {
            temp = lines[r][0];
            lines[r][0] = lines[r][1];
            lines[r][1] = temp;
        }

        if(lines[r][0] < min)
            min = lines[r][0];
        if(lines[r][1] < min)
            min = lines[r][1];       
        if(lines[r][0] > max)
            max = lines[r][0];
        if(lines[r][1] > max)
            max = lines[r][1];    
    }


    for(int i = min; i < max; i++)
    {
        for(int r = 0; r < 3; r++)
        {
            if(lines[r][0] <= i && lines[r][1] >= i+1)
                temp_cnt++;
        }
        if(temp_cnt > 1)
            answer++;
        temp_cnt = 0;
    }
    return answer;
}