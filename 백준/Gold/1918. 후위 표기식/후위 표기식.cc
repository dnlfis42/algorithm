#include <bits/stdc++.h>

using namespace std;

string to_postfix(const string& str, int l, int r)
{
	if (str[l] == '(')
	{
		int st = 1;
		int idx = l + 1;

		while (st)
		{
			if (str[idx] == '(')
			{
				++st;
			}
			else if (str[idx] == ')')
			{
				--st;
			}
			++idx;
		}

		if (idx - 1 == r)
		{
			return to_postfix(str, l + 1, r - 1);
		}
	}

	int depth = 0;
	int pos = -1;
	int min_priority = 2;

	for (int i = l; i <= r; ++i)
	{
		if (str[i] == '(')
		{
			++depth;
		}
		else if (str[i] == ')')
		{
			--depth;
		}
		else if (depth == 0 &&
			(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'))
		{
			int priority = (str[i] == '+' || str[i] == '-') ? 0 : 1;
			if (priority <= min_priority)
			{
				min_priority = priority;
				pos = i;
			}
		}
	}

	if (pos != -1)
	{
		string left = to_postfix(str, l, pos - 1);
		string right = to_postfix(str, pos + 1, r);
		return left + right + str[pos];
	}

	return str.substr(l, r - l + 1);
}

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	string postfix = to_postfix(str, 0, str.size() - 1);
	cout << postfix;

	return 0;
}

int main()
{
	return solution();
}