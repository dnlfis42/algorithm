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
	vector<vector<pair<int, int>>> edges(n + 1);

	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ c,b });
		edges[b].push_back({ c,a });
	}

	auto min_dist = [&](int st, int en)
		{
			vector<int> dist(n + 1, INF);
			dist[st] = 0;

			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // st부터 현재 좌표까지의 거리,현재 좌표
			pq.push({ 0,st });

			while (!pq.empty())
			{
				auto cur = pq.top();
				pq.pop();

				if (cur.first != dist[cur.second])
				{
					continue;
				}

				for (const auto& nxt : edges[cur.second])
				{
					if (dist[nxt.second] > cur.first + nxt.first)
					{
						dist[nxt.second] = cur.first + nxt.first;
						pq.push({ dist[nxt.second],nxt.second });
					}
				}
			}

			return dist[en];
		};

	int v1, v2;
	cin >> v1 >> v2;

	int st_v1 = min_dist(1, v1);
	int st_v2 = min_dist(1, v2);
	int v1_v2 = min_dist(v1, v2);
	int v1_en = min_dist(v1, n);
	int v2_en = min_dist(v2, n);

	if (st_v1 == INF || st_v2 == INF || v1_v2 == INF || v1_en == INF || v2_en == INF)
	{
		cout << -1;
		return 0;
	}

	cout << min(st_v1 + v2_en, st_v2 + v1_en) + v1_v2;

	return 0;
}

int main()
{
	return solution();
}