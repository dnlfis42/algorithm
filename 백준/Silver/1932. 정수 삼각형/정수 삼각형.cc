#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int len = (n + 1) * n / 2;
	vector<int> w(len);
	vector<int> dp(len);

	for (int i = 0; i < len; ++i)
	{
		cin >> w[i];
	}
	dp[0] = w[0];

	for (int i = 1; i < n; ++i)
	{
		int st = (i + 1) * i / 2;
		int en = st + i;
		int prev_st = st - i;
		dp[st] = dp[prev_st] + w[st];

		for (int j = st + 1; j < en; ++j, ++prev_st)
		{
			dp[j] = max(dp[prev_st], dp[prev_st + 1]) + w[j];
		}

		dp[en] = dp[st - 1] + w[en];
	}

	int mx = 0;
	for (int i = len - n; i < len; ++i)
	{
		if (mx < dp[i])
		{
			mx = dp[i];
		}
	}
	cout << mx;

	return 0;
}