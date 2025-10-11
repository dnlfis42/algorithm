#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int INF = static_cast<int>(1e9);

	int n; // 정점의 개수
	int e; // 간선의 개수
	cin >> n >> e;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; ++i)
	{
		dist[i][i] = 0;
	}
	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	int v1, v2;
	cin >> v1 >> v2;

	for (int mid = 1; mid <= n; ++mid)
	{
		for (int st = 1; st <= n; ++st)
		{
			for (int en = 1; en <= n; ++en)
			{
				dist[st][en] = min(dist[st][en], dist[st][mid] + dist[mid][en]);
			}
		}
	}

	if (dist[1][v1] == INF || dist[1][v2] == INF || dist[v1][v2] == INF || dist[v1][n] == INF || dist[v2][n] == INF)
	{
		cout << -1;
		return 0;
	}

	cout << min(dist[1][v1] + dist[v2][n], dist[1][v2] + dist[v1][n]) + dist[v1][v2];
	return 0;
}

int main()
{
	return solution();
}