#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 트리의 정점의 수
	int r; // 루트의 번호
	int q; // 쿼리의 수
	cin >> n >> r >> q;
	vector<vector<int>> adj(n + 1);
	vector<int> parents(n + 1, 0);

	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> que;
	que.push(r);
	parents[r] = r;

	queue<int> nodes;
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		bool is_leaf = true;
		for (int child : adj[cur])
		{
			if (parents[child])
			{
				continue;
			}
			que.push(child);
			parents[child] = cur;

			is_leaf = false;
		}
		if (is_leaf)
		{
			nodes.push(cur);
		}
	}

	vector<int> subtree(n + 1, 0);
	while (!nodes.empty())
	{
		int cur = nodes.front();
		nodes.pop();

		if (subtree[cur])
		{
			continue;
		}

		int total = 1;
		for (int node : adj[cur])
		{
			if (node == parents[cur])
			{
				continue;
			}

			if (subtree[node])
			{
				total += subtree[node];
			}
			else
			{
				total = 0;
				break;
			}
		}
		subtree[cur] = total;
		nodes.push(parents[cur]);
	}

	for (int i = 0; i < q; ++i)
	{
		int root;
		cin >> root;
		cout << subtree[root] << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}