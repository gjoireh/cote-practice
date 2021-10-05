#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable:4996)

bool broken[10];

int get_length(int n)
{
	if (n == 0)return 1;

	int len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return len;
}

bool is_can_only_number_button(int n)
{
	if (n == 0)
	{
		if (broken[0])return false;
		else return true;
	}
	while (n > 0)
	{
		if (broken[n % 10]) return false;
		n /= 10;
	}
	return true;
}

int main()
{
	int N, M, m;
	int ans, number_button_and_plus_or_minus;
	int plus_or_minus = 0;
	scanf("%d", &N);
	scanf("%d", &M);

	if (N == 100)
	{
		printf("%d\n", 0);
		return 0;
	}

	if (M > 0)
	{
		for (int i = 0; i < M; i++)
		{
			scanf("%d",&m);
			broken[m] = true;
		}
	}
	number_button_and_plus_or_minus = 0;
	ans = N - 100;
	if (ans < 0) ans *= -1;

	for (int i = 0; i < 1000000; i++)
	{
		if (is_can_only_number_button(i))
		{
			number_button_and_plus_or_minus = get_length(i);
			plus_or_minus = N - i;
			if (plus_or_minus < 0) plus_or_minus *= -1;
			number_button_and_plus_or_minus += plus_or_minus;
			if (ans > number_button_and_plus_or_minus)
			{
				ans = number_button_and_plus_or_minus;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}