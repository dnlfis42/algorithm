#include <bits/stdc++.h>

using namespace std;

// 메모리	KB
// 시간		ms
int solution1()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int dp[2][3];
		vector<vector<int>> sticker(2, vector<int>(n));
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> sticker[i][j];
			}
		}

		if (n == 1)
		{
			dp[0][1] = sticker[0][0];
			dp[1][1] = sticker[1][0];
		}
		else
		{
			dp[0][0] = sticker[0][0];
			dp[1][0] = sticker[1][0];
			dp[0][1] = sticker[0][1] + dp[1][0];
			dp[1][1] = sticker[1][1] + dp[0][0];

			for (int i = 2; i < n; ++i)
			{
				dp[0][2] = sticker[0][i] + max(dp[1][0], dp[1][1]);
				dp[1][2] = sticker[1][i] + max(dp[0][0], dp[0][1]);
				dp[0][0] = dp[0][1];
				dp[0][1] = dp[0][2];
				dp[1][0] = dp[1][1];
				dp[1][1] = dp[1][2];
			}
		}

		cout << max(dp[0][1], dp[1][1]) << "\n";
	}

	return 0;
}

int main()
{
	return solution1();
}