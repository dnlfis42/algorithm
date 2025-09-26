#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int INF = 0xfffffff;

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

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	vector<int> from_x(n + 1, INF);
	from_x[x] = 0;
	pq.push({ from_x[x],x });
	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();

		int val = p.first;
		int cur = p.second;

		if (from_x[cur] != val)
		{
			continue;
		}

		for (auto edge : edges[cur])
		{
			int t = edge.first;
			int nxt = edge.second;

			if (from_x[nxt] > val + t)
			{
				from_x[nxt] = val + t;
				pq.push({ from_x[nxt],nxt });
			}
		}
	}

	vector<int> to_x(n + 1, INF);
	to_x[x] = 0;
	pq.push({ to_x[x],x });
	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();

		int val = p.first;
		int cur = p.second;

		if (to_x[cur] != val)
		{
			continue;
		}

		for (auto edge : reverse[cur])
		{
			int t = edge.first;
			int nxt = edge.second;

			if (to_x[nxt] > val + t)
			{
				to_x[nxt] = val + t;
				pq.push({ to_x[nxt],nxt });
			}
		}
	}

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