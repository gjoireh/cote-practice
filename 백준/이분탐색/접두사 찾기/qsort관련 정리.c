#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_arr(const void* arg1, const void* arg2);
int compare_ptr1(const void* arg1, const void* arg2);
int compare_ptr2(const void** arg1, const void** arg2);
void input(char** NS, char** MS, int N, int M);
void free_pointer(char** NS, char** MS, int N, int M);

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);
	char** NS = (char**)malloc(sizeof(char*) * N);
	char** MS = (char**)malloc(sizeof(char*) * M);
	input(NS, MS, N, M);

	qsort(NS, N, sizeof(NS[0]), compare_ptr2);
	qsort(MS, M, sizeof(MS[0]), compare_ptr2);

	free_pointer(NS, MS, N, M);

	char arr[5][20] = {
		"egjoirth",
		"dgjioerg",
		"cgjiorth",
		"bfjioerg",
		"agjioerh"
	};
	qsort(arr, 5, sizeof(arr[0]), compare_arr);
	for (int i = 0; i < 5; i ++)
	{
		printf("%s\n", arr[i]);
	}
	return 0;

}
void input(char** NS, char** MS, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		NS[i] = (char*)malloc(sizeof(char) * 500);
	}
	for (int i = 0; i < M; i++)
	{
		MS[i] = (char*)malloc(sizeof(char) * 500);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%s", NS[i]);

	}
	for (int i = 0; i < M; i++)
	{
		scanf("%s", MS[i]);
	}
}


void free_pointer(char** NS, char** MS, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		free(NS[i]);
	}
	for (int i = 0; i < M; i++)
	{
		free(MS[i]);
	}
	free(NS);
	free(MS);
}

int compare_arr(const void* arg1, const void* arg2)
{
	return strcmp((char*)arg1, (char*)arg2);
}
/*
2차원 배열의 경우 넘어온 arg1, arg2가 문자열의 주소들이다.
그래서 그냥 바로 비교를 하면 된다.
*/


int compare_ptr1(const void* arg1, const void* arg2)
{
	return strcmp(*(char**)arg1, *(char**)arg2);
}

int compare_ptr2(const void** arg1, const void** arg2)
{
	return strcmp((char*)*arg1, (char*)*arg2);
}
/*
그러나 2차원 포인터 배열의 경우 arg1, arg2는 문자열의 주소가 아니라
문자열의 주소를 담고 있는 포인터의 주소이다
그래서 compare_ptr처럼 작성을 해야 한다.
1, 2의 차이는 매개변수를 바로 이중포인터로 받냐 안받냐인데
2차원 포인터 배열을 넘겨 받으므로 바로 2차원 포인터 형태로 받는게 더 직관적이고 일반적이지 않은가 싶은데
마이크로소프트의 설명서 에서는 1차원 포인터 형태로 받은 후에 다시 2차원 포인터 형태로 형변환을 해준 후 값에 접근하고 있다.
왜 그러는지는 모르겠는데 뭔가 이유가 있겠지 싶다. 아무튼 1, 2둘 중 아무렇게나 해도 된다.
*/

