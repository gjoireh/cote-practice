//------------------------------------------
#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);
    
    for(int r = 1; r <= n; r++)
    {
        for(int c = 1; c <= r; c++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
//------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
    int n;
    scanf("%d", &n);
    char** s = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        s[i] = (char*)malloc(n + 1);
        memset(s[i], '*', i + 1);
        s[i][i + 1] = '\0';
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }
    return 0;
}
//------------------------------------------