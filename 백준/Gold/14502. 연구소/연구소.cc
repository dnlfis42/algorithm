#include <bits/stdc++.h>

using namespace std;

const int dr[4]{ 0,1,0,-1 };
const int dc[4]{ 1,0,-1,0 };

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m, 0));
	vector<pair<int, int>> virus;
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < m; ++c)
		{
			int x;
			cin >> x;
			field[r][c] = x;
			if (x == 2)
			{
				virus.push_back({ r,c });
			}
		}
	}

	int mx = 0;
	int size = n * m;
	for (int i = 0; i < size; ++i)
	{
		if (field[i / m][i % m])
		{
			continue;
		}
		field[i / m][i % m] = 1;
		for (int j = i + 1; j < size; ++j)
		{
			if (field[j / m][j % m])
			{
				continue;
			}
			field[j / m][j % m] = 1;
			for (int k = j + 1; k < size; ++k)
			{
				if (field[k / m][k % m])
				{
					continue;
				}
				field[k / m][k % m] = 1;

				vector<vector<bool>> visited(n, vector<bool>(m, false));
				queue<pair<int, int>> q;
				for (auto& p : virus)
				{
					q.push(p);
					visited[p.first][p.second] = true;
				}

				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();

					for (int l = 0; l < 4; ++l)
					{
						int tr = cur.first + dr[l];
						int tc = cur.second + dc[l];

						if (tr < 0 || tr >= n || tc < 0 || tc >= m)
						{
							continue;
						}
						if (visited[tr][tc] || field[tr][tc])
						{
							continue;
						}
						q.push({ tr,tc });
						visited[tr][tc] = true;
					}
				}

				int cnt = 0;
				for (int r = 0; r < n; ++r)
				{
					for (int c = 0; c < m; ++c)
					{
						if (field[r][c] || visited[r][c])
						{
							continue;
						}
						++cnt;
					}
				}
				mx = max(mx, cnt);

				field[k / m][k % m] = 0;
			}
			field[j / m][j % m] = 0;
		}
		field[i / m][i % m] = 0;
	}
	cout << mx;

	return 0;
}

int main()
{
	return solution();
}