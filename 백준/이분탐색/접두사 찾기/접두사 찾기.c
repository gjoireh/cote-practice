#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int compare(const void* arg1, const void* arg2);
int find_start_idx(char **NS, char *MS, int N);
void input(char** NS, char** MS, int N, int M);
int get_number_of_prefixes(char** NS, char** MS, int N, int M);
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
	qsort(MS, M, sizeof(MS[0]), compare);

	answer = get_number_of_prefixes(NS, MS, N, M);
	printf("%d", answer);

	free_pointer(NS, MS, N, M);
	return 0;
}

int get_number_of_prefixes(char** NS, char** MS, int N, int M)
{
	int start_idx = 0;
	int ret = 0;
	for (int i = 0; i < M; i++)
	{
		start_idx = find_start_idx(NS, MS[i], N);
		if (start_idx == -1)
		{
			continue;
		}
		else
		{
			for (int j = start_idx; j < N; j++)
			{
				if (MS[i][0] != NS[j][0])
				{
					break;
				}
				if (strncmp(MS[i], NS[j], strlen(MS[i])) == 0)
				{
					ret++;
					break;
				}
			}
		}
	}
	return ret;
}

void input(char **NS, char **MS, int N, int M)
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

int find_start_idx(char** NS, char* MS, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (NS[i][0] == MS[0])
		{
			return i;
		}
	}
	return -1;
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