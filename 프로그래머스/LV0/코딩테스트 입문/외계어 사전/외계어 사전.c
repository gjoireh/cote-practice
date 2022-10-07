#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// spell_len은 배열 spell의 길이입니다.
// dic_len은 배열 dic의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {

    int cnt = 0;
    int j = 0;
    int spell_sum = 0;
    int word_sum = 0;
    
    for(int i = 0; i < spell_len; i++)
    {
        spell_sum += *spell[i];
    }
                
    for (int i = 0; i < dic_len; i++)
    {
        cnt = 0;
        j = 0;
        word_sum = 0;
        
        while (dic[i][j] != '\0')
        {
            j++;
        }
        
        if (j != spell_len)
            continue;
        
        for(int j = 0; j < spell_len; j++)
        {
            word_sum += dic[i][j];
        }
                
        if (spell_sum == word_sum)
            return 1;        
    }
    return 2;
}