#include <bits/stdc++.h>

using namespace std;

constexpr int INF = static_cast<int>(1e9);

struct Edge
{
	int from;
	int to;
	int cost;
};

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n; // 지점의 수
		int m; // 도로의 개수
		int w; // 웜홀의 개수
		cin >> n >> m >> w;

		vector<Edge> edges;

		int s;
		int e;
		int t;
		while (m--)
		{
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		while (w--)
		{
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		vector<int> costs(n + 1, 0);

		bool found = false;
		for (int i = 0; i < n; ++i)
		{
			for (auto& edge : edges)
			{
				if (costs[edge.to] > costs[edge.from] + edge.cost)
				{
					costs[edge.to] = costs[edge.from] + edge.cost;

					if (i == n - 1)
					{
						found = true;
						break;
					}
				}
			}

			if (found)
			{
				break;
			}
		}

		if (found)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}

int main()
{
	return solution();
}