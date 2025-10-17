#include <bits/stdc++.h>

using namespace std;

constexpr int dr[]{ 0,1,0,-1 };
constexpr int dc[]{ 1,0,-1,0 };

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> paint(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> paint[i];
	}

	int cnt = 0;
	int cnt_rg = 0;

	vector<vector<bool>> visit(n, vector<bool>(n, false));
	vector<vector<bool>> visit_rg(n, vector<bool>(n, false));
	queue<pair<int, int>> q;

	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			char color = paint[r][c];

			if (!visit[r][c])
			{
				++cnt;
				visit[r][c] = true;
				q.push({ r,c });

				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int tr = dr[i] + cur.first;
						int tc = dc[i] + cur.second;

						if (tr < 0 || tr >= n || tc < 0 || tc >= n ||
							visit[tr][tc] || paint[tr][tc] != color)
						{
							continue;
						}

						visit[tr][tc] = true;
						q.push({ tr,tc });
					}
				}
			}

			if (!visit_rg[r][c])
			{
				++cnt_rg;
				visit_rg[r][c] = true;
				q.push({ r,c });

				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int tr = dr[i] + cur.first;
						int tc = dc[i] + cur.second;

						if (tr < 0 || tr >= n || tc < 0 || tc >= n || visit_rg[tr][tc])
						{
							continue;
						}

						if (color == 'B')
						{
							if (paint[tr][tc] != 'B')
							{
								continue;
							}
						}
						else if (paint[tr][tc] == 'B')
						{
							continue;
						}

						visit_rg[tr][tc] = true;
						q.push({ tr,tc });
					}
				}
			}
		}
	}
	cout << cnt << " " << cnt_rg;

	return 0;
}

int main()
{
	return solution();
}