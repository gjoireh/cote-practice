#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int cal(vector<int>& A)
{
	int ret = 0;
	for (int i = 0; i < A.size() - 1; i++)
	{
		ret += abs(A[i] - A[i + 1]);
	}
	return ret;

}

int main()
{
	int N;
	int ans = 0;
	int temp;
	
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	while (true)
	{
		temp = cal(A);
		ans = max(ans, temp);
		if (next_permutation(A.begin(), A.end()))continue;
		else break;
	}

	cout << ans << endl;
}