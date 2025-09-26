#include <bits/stdc++.h>

using namespace std;

int dr[4]{ 1,0,-1,0 };
int dc[4]{ 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int row, col;
	cin >> row >> col;

	queue<pair<int, int>> q;
	vector<vector<int>> board(row, vector<int>(col));
	vector<vector<int>> ans(row, vector<int>(col, -1));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				ans[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		auto p = q.front();
		q.pop();

		int cr = p.first;
		int cc = p.second;

		for (int d = 0; d < 4; ++d)
		{
			int tr = cr + dr[d];
			int tc = cc + dc[d];

			if (tr < 0 || tr >= row || tc < 0 || tc >= col)
			{
				continue;
			}

			if (board[tr][tc] == 0)
			{
				continue;
			}

			if (ans[tr][tc] != -1)
			{
				continue;
			}

			ans[tr][tc] = ans[cr][cc] + 1;
			q.push({ tr,tc });
		}
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (board[i][j] == 0)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << ans[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}