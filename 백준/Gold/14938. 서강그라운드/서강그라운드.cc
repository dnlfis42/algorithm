#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, r;
	cin >> n >> m >> r;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}

	vector<vector<int>> road(n + 1, vector<int>(n + 1, 1e9));
	for (int i = 1; i <= n; ++i)
	{
		road[i][i] = 0;
	}
	for (int i = 0; i < r; ++i)
	{
		int a, b, l;
		cin >> a >> b >> l;
		road[a][b] = l;
		road[b][a] = l;
	}

	for (int mid = 1; mid <= n; ++mid)
	{
		for (int st = 1; st <= n; ++st)
		{
			for (int en = 1; en <= n; ++en)
			{
				if (road[st][en] > road[st][mid] + road[mid][en])
				{
					road[st][en] = road[st][mid] + road[mid][en];
				}
			}
		}
	}

	int mx = 0;
	for (int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (road[i][j] <= m)
			{
				sum += v[j];
			}
		}
		mx = max(mx, sum);
	}
	cout << mx;

	return 0;
}

int main()
{
	return solution();
}