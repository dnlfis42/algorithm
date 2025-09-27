#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int INF = 1e9;

	int v;
	cin >> v;
	vector<vector<pair<int, int>>> edges(v + 1);

	for (int i = 0; i < v; ++i)
	{
		int n1, n2;
		int d;
		cin >> n1;
		for (;;)
		{
			cin >> n2;
			if (n2 == -1)
			{
				break;
			}
			cin >> d;
			edges[n1].push_back({ d,n2 });
		}
	}

	auto dijkstra = [&](int st)
		{
			vector<int> dist(v + 1, INF);

			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
			dist[st] = 0;
			pq.push({ dist[st],st });

			while (!pq.empty())
			{
				auto p = pq.top();
				pq.pop();

				if (p.first != dist[p.second])
				{
					continue;
				}

				for (auto& en : edges[p.second])
				{
					if (dist[en.second] > p.first + en.first)
					{
						dist[en.second] = p.first + en.first;
						pq.push({ dist[en.second],en.second });
					}
				}
			}

			return dist;
		};

	auto from_1 = dijkstra(1);

	int idx = 0;
	int mx = 0;
	for (int i = 1; i <= v; ++i)
	{
		if (mx < from_1[i])
		{
			idx = i;
			mx = from_1[i];
		}
	}

	auto from_x = dijkstra(idx);
	mx = 0;
	for (int i = 1; i <= v; ++i)
	{
		if (mx < from_x[i])
		{
			mx = from_x[i];
		}
	}
	cout << mx;

	return 0;
}

int main()
{
	return solution();
}