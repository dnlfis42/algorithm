#include <bits/stdc++.h>

using namespace std;

// 메모리	KB
// 시간		ms
int solution1()
{
	const int INF = 0x7fffffff;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int v; // 정점의 개수
	int e; // 간선의 개수
	int k; // 시작 정점의 번호
	cin >> v >> e >> k;

	vector<vector<pair<int, int>>> edges(v + 1);
	for (int i = 0; i < e; ++i)
	{
		int u; // 시작 정점
		int v; // 끝 정점
		int w; // 가중치
		cin >> u >> v >> w;
		edges[u].push_back({ w,v });
	}

	vector<int> mn(v + 1, INF);
	mn[k] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ mn[k],k });

	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();

		int weight = p.first;
		int st = p.second;

		if (mn[st] != weight)
		{
			continue;
		}

		for (auto en : edges[st])
		{
			if (mn[en.second] > weight + en.first)
			{
				mn[en.second] = weight + en.first;
				pq.push({ mn[en.second],en.second });
			}
		}
	}

	for (int i = 1; i <= v; ++i)
	{
		if (mn[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << mn[i] << "\n";
		}
	}

	return 0;
}

int main()
{
	return solution1();
}