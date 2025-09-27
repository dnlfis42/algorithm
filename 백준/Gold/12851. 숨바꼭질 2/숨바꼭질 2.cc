#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int INF = 0x10000;

	int n, k;
	cin >> n >> k;

	vector<int> dist(100'001, INF);
	vector<int> cnt(100'001, INF);
	dist[n] = 0;
	cnt[n] = 1;

	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		int next[]{ cur - 1,cur + 1,cur * 2 };
		for (int x : next)
		{
			if (x < 0 || x>100'000)
			{
				continue;
			}

			if (dist[x] == INF)
			{
				dist[x] = dist[cur] + 1;
				cnt[x] = cnt[cur];
				q.push(x);
			}
			else if (dist[x] == dist[cur] + 1)
			{
				cnt[x] += cnt[cur];
			}
		}
	}
	cout << dist[k] << "\n" << cnt[k];

	return 0;
}

int main()
{
	return solution();
}