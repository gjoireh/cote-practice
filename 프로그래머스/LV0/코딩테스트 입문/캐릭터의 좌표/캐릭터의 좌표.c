#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int dir_idx(char* s)
{
    if(strcmp(s, "down"))return 0;
    else if(strcmp(s, "up")) return 1;
    else if(strcmp(s, "left")) return 2;
    else if(strcmp(s, "right")) return 3;
}

// keyinput_len은 배열 keyinput의 길이입니다.
// board_len은 배열 board의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* keyinput[], size_t keyinput_len, int board[], size_t board_len) 
{
    int answer[2] = {0,};
    int x = 0, x_limit = board[0] / 2;
    int y = 0, y_limit = board[1] / 2;
    int x_move[4] = {0, 0, -1, 1};
    int y_move[4] = {-1, 1, 0, 0};
    int idx = 0;
    for(int i = 0; i < keyinput_len; i++)
    {   
        idx = dir_idx(keyinput[i]);
        if(x + x_move[idx] <= x_limit && x + x_move[idx] >= x_limit*-1) x += x_move[idx];
        if(y + y_move[idx] <= y_limit && y + y_move[idx] >= y_limit*-1) y += y_move[idx];
    }
    answer[0] = x;
    answer[1] = y;
    return answer;
}