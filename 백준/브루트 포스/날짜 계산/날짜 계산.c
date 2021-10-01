#include <stdio.h>
//#pragma warning(disable:4996)

int cal_date(int E, int S, int M);


int main()
{
	int E, S, M, year;
	scanf("%d %d %d", &E, &S, &M);

	year = cal_date(E, S, M);
	printf("%d", year);
	return 0;
}


int cal_date(int E, int S, int M)
{
	int e = 0;
	int s = 0;
	int m = 0;
	int y = 0;

	while (1)
	{
		e++;
		s++;
		m++;
		y++;

		if (e > 15) e = 1;
		if (s > 28) s = 1;
		if (m > 19) m = 1;

		if (e == E && s == S && m == M) return y;
	}
}