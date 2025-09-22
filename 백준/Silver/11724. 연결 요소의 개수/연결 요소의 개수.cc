#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 정점의 개수
	int m; // 간선의 개수
	cin >> n >> m;

	vector<vector<int>> adjacents(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int u;
		int v;
		cin >> u >> v;

		adjacents[u].push_back(v);
		adjacents[v].push_back(u);
	}

	vector<bool> visit(n + 1, false);
	stack<int> st;
	int ans = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (visit[i])
		{
			continue;
		}

		++ans;

		st.push(i);
		visit[i] = true;

		while (!st.empty())
		{
			int cur = st.top();
			st.pop();

			for (int adj : adjacents[cur])
			{
				if (!visit[adj])
				{
					st.push(adj);
					visit[adj] = true;
				}
			}
		}
	}
	cout << ans;

	return 0;
}