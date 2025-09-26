#include <bits/stdc++.h>

using namespace std;

#define SOLUTION 0

// 메모리	KB
// 시간		ms
#if (SOLUTION == 0)
int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int INF = 0xfffffff;

	int n; // 학생의 수
	int m; // 도로의 개수
	int x; // 파티 장소
	cin >> n >> m >> x;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; ++i)
	{
		dist[i][i] = 0;
	}

	while (m--)
	{
		int st, en, t;
		cin >> st >> en >> t;
		dist[st][en] = t;
	}

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

	int mx = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (mx < dist[i][x] + dist[x][i])
		{
			mx = dist[i][x] + dist[x][i];
		}
	}
	cout << mx;

	return 0;
}
#elif (SOLUTION == 1)
#endif

int main()
{
	return solution();
}