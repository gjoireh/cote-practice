#include <iostream>
#include <vector>

using namespace std;

int N;
int S[20][20];
int ans = 10000;
vector<int> team1;
vector<int> team2;

bool stop(vector<int> &t1, vector<int> &t2);
void get_diff(vector<int>& t1, vector<int>& t2);
bool make_team(int index, vector<int>& t1, vector<int>& t2);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> S[i][j];
		}
	}

	make_team(0, team1, team2);
	cout << ans;
	return 0;
}

bool stop(vector<int>& t1, vector<int>& t2)
{
	if (t1.size() > N / 2 || t2.size() > N / 2) return true;
	else return false;
}

void get_diff(vector<int>& t1, vector<int>& t2)
{
	int sum_of_t1 = 0;
	int sum_of_t2 = 0;
	int diff = 0;
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			if (i == j)continue;
			sum_of_t1 += S[t1[i]][t1[j]];
			sum_of_t2 += S[t2[i]][t2[j]];
		}
	}
	diff = abs(sum_of_t1 - sum_of_t2);
	if (diff < ans)ans = diff;
}

bool make_team(int index, vector<int>& t1, vector<int>& t2)
{
	if (index == N)
	{
		if (t1.size() == N / 2 and t2.size() == N / 2)return true;
		else return false;
	}

	if (stop(t1, t2))return false;

	t1.push_back(index);
	if (make_team(index + 1, t1, t2))get_diff(t1, t2);
	t1.pop_back();

	t2.push_back(index);
	if (make_team(index + 1, t1, t2))get_diff(t1, t2);
	t2.pop_back();

	return false;
	
}
