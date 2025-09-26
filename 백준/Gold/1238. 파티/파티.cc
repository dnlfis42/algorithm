#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 학생의 수
	int m; // 도로의 개수
	int x; // 파티 장소
	cin >> n >> m >> x;

	vector<vector<pair<int, int>>> edges(n + 1); // edges[시작], {시간, 끝점}
	vector<vector<pair<int, int>>> reverse(n + 1); // reverse[끝], {시간, 시작}
	while (m--)
	{
		int st, en, t;
		cin >> st >> en >> t;
		edges[st].push_back({ t,en });
		reverse[en].push_back({ t,st });
	}

	auto dijkstra = [&](int start, const vector < vector<pair<int, int>>>& graph)
		{
			const int INF = 1e9;
			vector<int> dist(n + 1, INF);
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

			dist[start] = 0;
			pq.push({ dist[start],start });

			while (!pq.empty())
			{
				auto [val, cur] = pq.top();
				pq.pop();

				if (dist[cur] != val)
				{
					continue;
				}

				for (auto [t, nxt] : graph[cur])
				{
					if (dist[nxt] > val + t)
					{
						dist[nxt] = val + t;
						pq.push({ dist[nxt],nxt });
					}
				}
			}

			return dist;
		};

	auto from_x = dijkstra(x, edges);
	auto to_x = dijkstra(x, reverse);

	int mx = 0;
	for (int i = 1; i <= n; ++i)
	{
		mx = max(mx, from_x[i] + to_x[i]);
	}
	cout << mx;

	return 0;
}

int main()
{
	return solution();
}