#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct letter
{
    char** splitted;
    int len;
}typedef LET;

LET split(const char* letter, char* c)
{
    LET ret;
    int idx = 0;
    char** sp = (char*)malloc(sizeof(char*) * 500);
    char* p;

    for (int i = 0; i < 500; i++)
    {
        sp[i] = (char*)malloc(5);
        memset(sp[i], 0, 5);
    }

    p = strstr(letter, c);
    while (p != NULL)
    {
        memcpy(sp[idx++], letter, p - letter);
        letter = p + 1;
        p = strstr(letter, c);
    }
    sp[idx++] = letter;

    ret.splitted = sp;
    ret.len = idx;

    return ret;
}

char morse_to_alphabet(char* s)
{
    char morse[26][5] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

    for (int i = 0; i < 26; i++)
    {
        if (strcmp(morse[i], s) == 0)return 'a' + i;
    }
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* letter)
{
    LET let = split(letter, " ");
    char* answer = (char*)malloc(let.len + 1);
    answer[let.len] = '\0';
    for (int i = 0; i < let.len; i++)
    {
        answer[i] = morse_to_alphabet(let.splitted[i]);
    }
    return answer;
}