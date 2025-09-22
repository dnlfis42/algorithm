#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;

	vector<vector<int>> board(n, vector<int>(m));
	queue<tuple<int, int, int>> q; // 행, 열, 일
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				q.push({ i,j,0 });
			}
		}
	}

	int day = 0;
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();

		int cur_day = get<2>(t);
		if (day < cur_day)
		{
			day = cur_day;
		}

		for (int i = 0; i < 4; ++i)
		{
			int tr = get<0>(t) + dr[i];
			int tc = get<1>(t) + dc[i];

			if (tr < 0 || tr >= n || tc < 0 || tc >= m)
			{
				continue;
			}
			if (board[tr][tc] != 0)
			{
				continue;
			}

			board[tr][tc] = 1;
			q.push({ tr,tc,cur_day + 1 });
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << day;

	return 0;
}