|행\열 |0열|1열|
|---|---|---|
|0행| 3|	-1|
|1행|2|	42|
|2행|1|	12|
|3행|2|	2|
|4행|1|	1|

과 같은 2차원 배열을
```c
int** pp
```
가 가리키고 있을 때 2차원 배열의 행 순서를 0열 값 기준으로 정렬하고  
0열의 값이 같은 것들에 대하여 1열 값 기준으로 정렬 


```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(int** p1, int** p2)
{
    if((*p1)[0] != (*p2)[0])return (*p1)[0] - (*p2)[0];

    return (*p1)[1] - (*p2)[1];
}

int main(void)
{
    int mat[5][2] = { {3, -1}, {2, 42}, {1,12}, {2, 2}, {1,1} };
    int** pp = (int**)malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++)
    {
        pp[i] = mat[i];
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\n", pp[i][0], pp[i][1]);
    }
    /*
    [
        [3, -1],
        [2, 42],
        [1, 12],
        [2, 2],
        [1, 1]
    ]
    */

    qsort(pp, 5, sizeof(int*), compare);
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\n", pp[i][0], pp[i][1]);
    }
    /*
    [
        [1, 1],
        [1, 12],
        [2, 2],
        [2, 42],
        [3, -1]
    ]
    */
    return 0;
}
```

***
2차원 배열 mat을 동일하게 정렬 한다면  

```c
int compare2(int p1[2], int p2[2])
{
    if (p1[0] != p2[0])return p1[0] - p2[0];

    return p1[1] - p2[1];
}

qsort(mat, 5, sizeof(int) * 2, compare2);
```
