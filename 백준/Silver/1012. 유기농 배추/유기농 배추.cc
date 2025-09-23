#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int field[51][51]{};

	int t;
	cin >> t;
	while (t--)
	{
		int m, n, k;
		cin >> m >> n >> k;

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		int ans = 0;
		for (int r = 0; r < n; ++r)
		{
			for (int c = 0; c < m; ++c)
			{
				if (field[r][c] == 1)
				{
					++ans;

					queue<pair<int, int>> q;
					field[r][c] = 0;
					q.push({ r,c });

					while (!q.empty())
					{
						auto p = q.front();
						q.pop();

						for (int k = 0; k < 4; ++k)
						{
							int tr = dr[k] + p.first;
							int tc = dc[k] + p.second;

							if (tr < 0 || tr >= n || tc < 0 || tc >= m)
							{
								continue;
							}
							if (field[tr][tc] == 0)
							{
								continue;
							}

							field[tr][tc] = 0;
							q.push({ tr,tc });
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}