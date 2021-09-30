#include <stdio.h>
#include <stdbool.h>
int N, M, ssize; //string size
char s[502];

typedef struct Node
{
	int child[26];
	bool end;
}NODE;
NODE trie[30000];
int tries = 1; //trie size

int init()
{
	tries++;
	return tries - 1;
}

void add(int node, char* s, int index) //node0 is root
{
	int c, next, child;

	if (index == ssize)
	{
		trie[node].end = true;
		return;
	}

	c = s[index] - 'a';
	if (trie[node].child[c] == 0)
	{
		next = init();
		trie[node].child[c] = next;
	}

	child = trie[node].child[c];
	add(child, s, index + 1);
}

int search(int node, char* s, int index)
{
	int c, child;

	if (index == ssize) return 1;

	c = s[index] - 'a';
	child = trie[node].child[c];
	if (child == 0) return 0; //node0 is root

	return search(child, s, index + 1);
}

int main()
{
	int i, j, res = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		scanf("%s", s);
		for (j = 0; s[j] != '\0'; j++);
		ssize = j;
		add(0, s, 0);
	}


	for (i = 0; i < M; i++)
	{
		scanf("%s", s);
		for (j = 0; s[j] != '\0'; j++);
		ssize = j;
		res += search(0, s, 0);
	}

	printf("%d\n", res);
	return 0;
}