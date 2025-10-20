#include <bits/stdc++.h>

using namespace std;

int dp[41][41];

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

string s1, s2;
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	vector<char> pwd;
	int i1 = s1.size();
	int i2 = s2.size();
	while (i1 > 0 && i2 > 0)
	{
		if (s1[i1 - 1] == s2[i2- 1])
		{
			pwd.push_back(s1[i1 - 1]);
			--i1;
			--i2;
		}
		else
		{
			if (dp[i1 - 1][i2] > dp[i1][i2 - 1])
			{
				--i1;
			}
			else if (dp[i1 - 1][i2] < dp[i1][i2 - 1])
			{
				--i2;
			}
			else
			{
				--i1;
				--i2;
			}
		}
	}

	reverse(pwd.begin(), pwd.end());
	for (char c : pwd)
	{
		cout << c;
	}

	return 0;
}

int main()
{
	return solution();
}