#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int INF = 1e9;
	int dp[2101]; // i 명의 고객을 얻기 위해 필요한 최소 비용
	fill(dp, dp + 2101, INF);
	dp[0] = 0; // 0 명의 고객을 얻는데 드는 비용 = 0

	int c; // 최소 고객 수
	int n; // 홍보할 수 있는 도시의 개수
	cin >> c >> n;

	vector<pair<int, int>> cities(n); // { 비용,고객의 수 }
	for (int i = 0; i < n; ++i)
	{
		cin >> cities[i].first >> cities[i].second;
	}

	for (auto city : cities)
	{
		int cost = city.first;
		int customer = city.second;
		for (int i = customer; i <= c + customer; ++i)
		{
			dp[i] = min(dp[i], dp[i - customer] + cost);
		}
	}

	int mn = INF;
	for (int i = c; i <= c + 100; ++i)
	{
		mn = min(mn, dp[i]);
	}
	cout << mn;

	return 0;
}

int main()
{
	return solution();
}