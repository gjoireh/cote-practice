#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
// 당첨 가능한 최고 순위 == 중복 개수 + 0의 개수
// 당첨 가능한 최저 순위 == 중복 개수
int rank(int number)
{
    int ret = 0;
    switch (number)
    {
    case 6:
        ret = 1;
        break;
    case 5:
        ret = 2;
        break;
    case 4:
        ret = 3;
        break;
    case 3:
        ret = 4;
        break;
    case 2:
        ret = 5;
        break;
    default:
        ret = 6;
        break;
    }
    return ret;
}
bool isin(int number, int* arr)
{
    for (int i = 0; i < 6; i++)
    {
        if (number == arr[i])
        {
            return true;
        }
    }
    return false;
}
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int matches = 0;
    int duplicates = 0;
    int zeros = 0;
    int* answer = (int*)malloc(4 * 2);

    for (int i = 0; i < 6; i++)
    {
        if (isin(lottos[i], win_nums))
        {
            duplicates++;
        }
        if (lottos[i] == 0)
        {
            zeros++;
        }
    }
    matches = duplicates + zeros;
    answer[0] = rank(matches);
    answer[1] = rank(duplicates);

    return answer;
}