#include <stdio.h>
#include <stdbool.h>
//#pragma warning(disable:4996)

bool c[10];
int a[10];

void go(int index, int n, int m)
{
	if (index == m)
	{
		// 수열을 출력
		for (int i = 0; i < m; i++)
		{
			if (i == m - 1)
			{
				printf("%d\n", a[i]);
			}
			else
			{
				printf("%d ", a[i]);
			}

		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i])
		{
			continue;
		}
		c[i] = true;
		a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}

}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	go(0, n, m);

	return 0;
}