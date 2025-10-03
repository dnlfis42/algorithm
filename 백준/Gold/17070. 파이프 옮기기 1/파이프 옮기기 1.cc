#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int house[17][17]{};
	int dp[17][17][3]{}; // 가로, 세로, 대각선

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> house[i][j];
		}
	}

	dp[0][1][0] = 1;

	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			do // 가로
			{
				if (dp[r][c][0])
				{
					if (c + 1 >= n || house[r][c + 1]) // 가로로 갈 수 없다면 -> 어차피 이거 안되면 대각선도 못감
					{
						break;
					}
					dp[r][c + 1][0] += dp[r][c][0];

					if (r + 1 >= n || house[r + 1][c] || house[r + 1][c + 1])
					{
						break;
					}
					dp[r + 1][c + 1][2] += dp[r][c][0];
				}
			} while (false);

			do // 세로
			{
				if (dp[r][c][1])
				{
					if (r + 1 >= n || house[r + 1][c])
					{
						break;
					}
					dp[r + 1][c][1] += dp[r][c][1];

					if (c + 1 >= n || house[r][c + 1] || house[r + 1][c + 1])
					{
						break;
					}
					dp[r + 1][c + 1][2] += dp[r][c][1];
				}
			} while (false);

			do // 대각선
			{
				if (dp[r][c][2])
				{
					bool enable = true;

					if (c + 1 >= n || house[r][c + 1])
					{
						enable = false;
					}
					else
					{
						dp[r][c + 1][0] += dp[r][c][2];
					}

					if (r + 1 >= n || house[r + 1][c])
					{
						break;
					}
					dp[r + 1][c][1] += dp[r][c][2];

					if (!enable || house[r + 1][c + 1])
					{
						break;
					}
					dp[r + 1][c + 1][2] += dp[r][c][2];
				}
			} while (false);
		}
	}

	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];

	return 0;
}

int main()
{
	return solution();
}