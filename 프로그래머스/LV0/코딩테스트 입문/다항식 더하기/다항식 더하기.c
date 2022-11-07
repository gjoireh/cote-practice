#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct s
{
    char** splitted;
    int len;
}typedef SL;

SL split(const char* s, char* c, int len, int unit_len);

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* polynomial)
{
    int x = 0, n = 0;
    SL sl = split(polynomial, " + ", strlen(polynomial), strlen(" + "));
    char* p;
    char* answer = malloc(strlen(polynomial));
    char* t = malloc(strlen(polynomial));

    for (int i = 0; i < sl.len; i++)
    {
        p = strstr(sl.splitted[i], "x");
        if (p != NULL) x += strcmp(sl.splitted[i], "x") == 0 ? 1 : atoi(strncpy(t, sl.splitted[i], strlen(sl.splitted[i]) - 1));
        else n += atoi(sl.splitted[i]);
    }

    if (!x && !n)sprintf(answer, "%d", 0);
    else if (x && !n) x == 1 ? sprintf(answer, "x") : sprintf(answer, "%dx", x);
    else if (!x && n) sprintf(answer, "%d", n);
    else x == 1 ? sprintf(answer, "x + %d", n) : sprintf(answer, "%dx + %d", x, n);
    
    return answer;
}

SL split(const char* s, char* c, int len, int unit_len)
{
    SL ret;
    int idx = 0;
    char** sp = (char*)malloc(sizeof(char*) * len);
    char* p;

    for (int i = 0; i < len; i++)
    {
        sp[i] = (char*)malloc(len);
        memset(sp[i], 0, len);
    }

    p = strstr(s, c);
    while (p != NULL)
    {
        memcpy(sp[idx++], s, p - s);
        s = p + unit_len;
        p = strstr(s, c);
    }
    sp[idx++] = s;

    ret.splitted = sp;
    ret.len = idx;

    return ret;
}