#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 0xfffffff;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int m;
	cin >> n >> m;

	vector <vector<pair<int, int>>> edges(n);

	int a;
	int b;
	int c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		edges[a - 1].push_back({ c,b - 1 });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	for (int st = 0; st < n; ++st)
	{
		vector<int> costs(n, INF);
		costs[st] = 0;
		pq.push({ 0,st });

		while (!pq.empty())
		{
			auto x = pq.top();
			pq.pop();

			if (costs[x.second] != x.first)
			{
				continue;
			}

			for (auto edge : edges[x.second])
			{
				int sum = x.first + edge.first;
				if (sum < costs[edge.second])
				{
					costs[edge.second] = sum;
					pq.push({ sum, edge.second });
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (costs[i] == INF)
			{
				cout << "0 ";
			}
			else
			{
				cout << costs[i] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}