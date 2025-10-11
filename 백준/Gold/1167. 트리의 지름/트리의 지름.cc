#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int v;
	cin >> v;

	vector<vector<pair<int, int>>> edges(v + 1);

	for (int i = 0; i < v; ++i)
	{
		int st;
		cin >> st;
		for (;;)
		{
			int en;
			cin >> en;

			if (en == -1)
			{
				break;
			}

			int d;
			cin >> d;

			edges[st].push_back({ en,d });
		}
	}

	auto farthest = [&](int st)
		{
			int vortex = st;
			int dist = 0;

			vector<bool> visit(v + 1, false);
			visit[st] = true;

			queue<pair<int, int>> q;
			q.push({ st,0 });

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				if (dist < cur.second)
				{
					vortex = cur.first;
					dist = cur.second;
				}

				for (const auto& nxt : edges[cur.first])
				{
					if (visit[nxt.first])
					{
						continue;
					}

					visit[nxt.first] = true;
					q.push({ nxt.first,cur.second + nxt.second });
				}
			}

			return make_pair(vortex, dist);
		};

	auto st = farthest(1);
	auto en = farthest(st.first);
	cout << en.second;

	return 0;
}

int main()
{
	return solution();
}