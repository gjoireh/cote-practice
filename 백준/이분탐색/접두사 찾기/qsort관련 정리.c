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
2���� �迭�� ��� �Ѿ�� arg1, arg2�� ���ڿ��� �ּҵ��̴�.
�׷��� �׳� �ٷ� �񱳸� �ϸ� �ȴ�.
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
�׷��� 2���� ������ �迭�� ��� arg1, arg2�� ���ڿ��� �ּҰ� �ƴ϶�
���ڿ��� �ּҸ� ��� �ִ� �������� �ּ��̴�
�׷��� compare_ptró�� �ۼ��� �ؾ� �Ѵ�.
1, 2�� ���̴� �Ű������� �ٷ� ���������ͷ� �޳� �ȹ޳��ε�
2���� ������ �迭�� �Ѱ� �����Ƿ� �ٷ� 2���� ������ ���·� �޴°� �� �������̰� �Ϲ������� ������ ������
����ũ�μ���Ʈ�� ���� ������ 1���� ������ ���·� ���� �Ŀ� �ٽ� 2���� ������ ���·� ����ȯ�� ���� �� ���� �����ϰ� �ִ�.
�� �׷������� �𸣰ڴµ� ���� ������ �ְ��� �ʹ�. �ƹ�ư 1, 2�� �� �ƹ����Գ� �ص� �ȴ�.
*/

