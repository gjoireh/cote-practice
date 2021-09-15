#include <string>
#include <vector>
using namespace std;

int get_min(vector<int> v)
{
	int min = 1001;
	for (int i = 0; i < v.size(); i++)
	{
		if (min > v[i])
		{
			min = v[i];
		}
	}
	return min;
}

string get_s(int n, string s)
{
	string result = "";
	string repeated = "";
	int cnt = 1;
	for (int i = 0; i < s.length(); i += n)
	{
		if ((i + n >= s.length()))
		{
			if (cnt != 1)
			{
				result += to_string(cnt) + repeated;
			}
			else
			{
				result += s.substr(i);
			}

			break;
		}

		if (s.substr(i, n) == s.substr(i + n, n))
		{
			if (cnt == 1)
			{
				repeated = s.substr(i, n);
			}
			cnt++;
		}
		else
		{
			if (cnt != 1)
			{
				result += to_string(cnt) + repeated;
				cnt = 1;
			}
			else
			{
				result += s.substr(i, n);
			}

		}
	}
	return result;
}

int solution(string s) {
	int answer = 0;

	if (s.length() == 1)
	{
		answer = 1;
		return answer;
	}

	int s_length = s.length();
	vector<int> lengths;

	for (int i = 1; i <= (s_length / 2); i++)
	{
		lengths.push_back(get_s(i, s).length());
	}
	answer = get_min(lengths);
	return answer;
}