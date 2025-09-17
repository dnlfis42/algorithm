#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int dp[11];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; ++i)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}