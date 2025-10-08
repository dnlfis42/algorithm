#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 도시의 개수
	int m; // 버스의 개수
	cin >> n >> m;
	vector<vector<pair<int, int>>> cities(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		cities[s].push_back({ c,e }); // cost,end
	}
	int st, en;
	cin >> st >> en;

	priority_queue<pair<int, int>> pq; // cost,st
	vector<int> costs(n + 1, INT_MAX);
	vector<int> pre(n + 1, INT_MAX);

	costs[st] = 0;
	pq.push({ 0,st });

	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();

		if (cost != costs[cur])
		{
			continue;
		}

		for (auto [c, nxt] : cities[cur])
		{
			if (costs[nxt] > costs[cur] + c)
			{
				costs[nxt] = costs[cur] + c;
				pq.push({ costs[nxt],nxt });
				pre[nxt] = cur;
			}
		}
	}

	stack<int> route;
	int node = en;
	while (node != INT_MAX)
	{
		route.push(node);
		node = pre[node];
	}

	cout <<
		costs[en] << "\n" <<
		route.size() << "\n";
	while (!route.empty())
	{
		cout << route.top() << " ";
		route.pop();
	}

	return 0;
}

int main()
{
	return solution();
}