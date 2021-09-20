#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int compare(const void* arg1, const void* arg2);
void input(char** NS, char** MS, int N, int M);
int binary_search(char** NS, char** MS, int N, int M);
void free_pointer(char** NS, char** MS, int N, int M);


int main()
{
	int answer = 0;

	int N, M;
	scanf("%d %d", &N, &M);

	char** NS = (char**)malloc(sizeof(char*) * N);
	char** MS = (char**)malloc(sizeof(char*) * M);
	input(NS, MS, N, M);
	
	qsort(NS, N, sizeof(NS[0]), compare);

	answer = binary_search(NS, MS, N, M);
	printf("%d", answer);

	free_pointer(NS, MS, N, M);
	return 0;
}

int binary_search(char** NS, char** MS, int N, int M)
{
	int ret = 0;
	int left, right, mid;
	int len_of_M;
	for (int i = 0; i < M; i++)
	{
		left = 0;
		right = N - 1;
		mid = right / 2;
		len_of_M = strlen(MS[i]);
		while (left <= right)
		{
			if (strncmp(NS[mid], MS[i], len_of_M) == 0)
			{
				ret++;
				break;
			}
			
			if (strcmp(NS[mid], MS[i]) < 0) 
			{
				left = mid + 1;
				mid = (left + right) / 2;
			}
			else if(strcmp(NS[mid], MS[i]) > 0)
			{
				right = mid - 1;
				mid = (left + right) / 2;
			}
		}
	}
	return ret;
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

int compare(const void* arg1, const void* arg2)
{
	return strcmp(*(char**)arg1, *(char**)arg2);
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