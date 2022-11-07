#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 500

struct stack
{
    int top;
    int data[MAX];
}typedef Stack;

struct s
{
    char** splitted;
    int len;
}typedef SL;

void init(Stack* s);
bool is_empty(Stack* s);
void push(Stack* s, int item);
int pop(Stack* s);
SL split(const char* s, char* c);

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s)
{
    int answer = 0;
    int last_add = 0;
    Stack adds;
    init(&adds);

    SL sl = split(s, " ");

    for (int i = 0; i < sl.len; i++)
    {
        if (strcmp(sl.splitted[i], "Z") != 0)
        {
            last_add = atoi(sl.splitted[i]);
            push(&adds, last_add);
            answer += last_add;
        }
        else
        {
            if (is_empty(&adds))continue;
            answer -= pop(&adds);
        }
    }
    return answer;
}

void init(Stack* s)
{
    s->top = -1;
}

bool is_empty(Stack* s)
{
    return s->top == -1;
}

void push(Stack* s, int item)
{
    s->top++;
    s->data[s->top] = item;
}

int pop(Stack* s)
{
    if (is_empty(s))return NULL;

    return s->data[s->top--];
}

SL split(const char* s, char* c)
{
    SL ret;
    int idx = 0;
    char** sp = (char*)malloc(sizeof(char*) * MAX);
    char* p;

    for (int i = 0; i < MAX; i++)
    {
        sp[i] = (char*)malloc(5);
        memset(sp[i], 0, 5);
    }

    p = strstr(s, c);
    while (p != NULL)
    {
        memcpy(sp[idx++], s, p - s);
        s = p + 1;
        p = strstr(s, c);
    }
    sp[idx++] = s;

    ret.splitted = sp;
    ret.len = idx;

    return ret;
}