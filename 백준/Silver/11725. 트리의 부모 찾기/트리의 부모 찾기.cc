#include <bits/stdc++.h>

using namespace std;

// 메모리	KB
// 시간		ms
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> parent(n + 1, 0);
	parent[1] = 1;
	vector<vector<int>> nodes(n + 1);

	for (int i = 1; i < n; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;

		if (parent[n1] == 0 && parent[n2] == 0)
		{
			nodes[n1].push_back(n2);
			nodes[n2].push_back(n1);
		}
		else // 둘 중 하나 방향성 가짐
		{
			queue<int> q;
			if (parent[n1]) // 둘 다 방향성을 가질 수는 없음
			{
				parent[n2] = n1;
				q.push(n2);
			}
			else
			{
				parent[n1] = n2;
				q.push(n1);
			}

			while (!q.empty())
			{
				int p = q.front();
				q.pop();

				for (int c : nodes[p])
				{
					if (parent[c])
					{
						continue;
					}
					parent[c] = p;
					q.push(c);
				}
			}
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}