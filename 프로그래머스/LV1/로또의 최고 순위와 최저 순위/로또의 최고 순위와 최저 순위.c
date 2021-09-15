#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.
// ��÷ ������ �ְ� ���� == �ߺ� ���� + 0�� ����
// ��÷ ������ ���� ���� == �ߺ� ����
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
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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