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

	bool has_cheese = false;
	vector<vector<bool>> cheese(n, vector<bool>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int x;
			cin >> x;
			cheese[i][j] = x;

			if (x == 1)
			{
				has_cheese = true;
			}
		}
	}

	if (!has_cheese)
	{
		cout << 0;
		return 0;
	}

	int time = 0;
	for (;;)
	{
		++time;
		vector<vector<bool>> outside(n, vector<bool>(m, false));

		queue<pair<int, int>> q;
		for (int c = 0; c < m; ++c)
		{
			if (!cheese[0][c])
			{
				q.push({ 0,c });
				outside[0][c] = true;
			}
			if (!cheese[n - 1][c])
			{
				q.push({ n - 1,c });
				outside[n - 1][c] = true;
			}
		}
		for (int r = 1; r < n - 1; ++r)
		{
			if (!cheese[r][0])
			{
				q.push({ r,0 });
				outside[r][0] = true;
			}
			if (!cheese[r][m - 1])
			{
				q.push({ r,m - 1 });
				outside[r][m - 1] = true;
			}
		}

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int tr = cur.first + dr[k];
				int tc = cur.second + dc[k];

				if (tr < 0 || tr >= n || tc < 0 || tc >= m)
				{
					continue;
				}

				if (cheese[tr][tc] || outside[tr][tc])
				{
					continue;
				}

				q.push({ tr,tc });
				outside[tr][tc] = true;
			}
		}

		bool all_gone = true;
		for (int r = 0; r < n; ++r)
		{
			for (int c = 0; c < m; ++c)
			{
				if (cheese[r][c])
				{
					int cnt = 0;
					for (int k = 0; k < 4; ++k)
					{
						int tr = r + dr[k];
						int tc = c + dc[k];

						if (tr < 0 || tr >= n || tc < 0 || tc >= m)
						{
							continue;
						}

						if (outside[tr][tc])
						{
							++cnt;
						}
					}

					if (cnt >= 2)
					{
						cheese[r][c] = false;
					}
					else
					{
						all_gone = false;
					}
				}
			}
		}

		if (all_gone)
		{
			break;
		}
	}
	cout << time;

	return 0;
}

int main()
{
	return solution();
}