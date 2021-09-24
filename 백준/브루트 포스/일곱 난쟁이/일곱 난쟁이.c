#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct selected_two
{
	int one;
	int two;
}typedef ST;


void input(int* inputs);
void select_two_people(ST* st);
int get_sum_except_two(int one, int two, int* inputs);
void get_answer_array(int one, int two, int* inputs, int* answer);
int compare(const void* a, const void* b);
void print_answer(int* answer, int len);


int main()
{


	int inputs[9] = {0,};
	int answer[7] = {0,};
	ST st[36];
	
	input(inputs);
	select_two_people(st);

	for (int i = 0; i < 36; i++)
	{
		if (get_sum_except_two(st[i].one, st[i].two, inputs) == 100)
		{
			get_answer_array(st[i].one, st[i].two, inputs, answer);
		}
	}
	qsort(answer, sizeof(answer) / sizeof(int), sizeof(int), compare);

	print_answer(answer, sizeof(answer) / sizeof(int));

	return 0;
}

void input(int * inputs)
{
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &inputs[i]);
	}
}

void select_two_people(ST* st)
{
	int st_idx = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			st[st_idx].one = i;
			st[st_idx].two = j;
			st_idx++;
		}
	}
}

int get_sum_except_two(int one, int two, int* inputs)
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == one || i == two)
		{
			continue;
		}
		else
		{
			sum += inputs[i];
		}
	}
	return sum;
}

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

void get_answer_array(int one, int two, int* inputs, int* answer)
{
	int answer_idx = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == one || i == two)
		{
			continue;
		}
		else
		{
			answer[answer_idx++] = inputs[i];
		}
	}
}

void print_answer(int* answer, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", answer[i]);
	}
}