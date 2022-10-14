#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int get_len(char* p)
{
    int i = 0;
    while (p[i] != '\0')
    {
        i++;
    }
    return i;
}

int check(char* ID, char* PW, int id_len, const char*** db, int db_rows)
{
    bool id_exist = false;
    bool pw_match = false;
    for (int i = 0; i < db_rows; i++)
    {
        if (id_len != get_len(db[i][0]))
            continue;
        else if (strcmp(ID, db[i][0]) == 0)
        {
            id_exist = true;
            if (strcmp(PW, db[i][1]) == 0)
                pw_match = true;
            break;
        }
    }

    if (id_exist && pw_match)
        return 1;
    else if (id_exist && !pw_match)
        return -1;
    else if (!id_exist)
        return 0;
}

// id_pw_len은 배열 id_pw의 길이입니다.
// db_rows는 2차원 배열 db의 행 길이, db_cols는 2차원 배열 db의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char** id_pw, size_t id_pw_len, const char*** db, size_t db_rows, size_t db_cols)
{
    char* ID = id_pw[0];
    char* PW = id_pw[1];

    int id_len = get_len(ID);
    int result = check(ID, PW, id_len, db, db_rows);

    switch (result)
    {
    case 1:
        return "login";
    case -1:
        return "wrong pw";
    case 0:
        return "fail";
    }
}