#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int mp[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	int n;
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			mp[i][j] = str[j] - '0' - 1;
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	mp[0][0] = 1;

	while (true)
	{
		auto cur = q.front();
		q.pop();

		if (cur.first == n - 1 && cur.second == m - 1)
		{
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int tr = cur.first + dy[i];
			int tc = cur.second + dx[i];

			if (tr < 0 || tr >= n || tc < 0 || tc >= m)
			{
				continue;
			}

			if (mp[tr][tc])
			{
				continue;
			}

			q.push({ tr,tc });
			mp[tr][tc] = mp[cur.first][cur.second] + 1;
		}
	}

	cout << mp[n - 1][m - 1];

	return 0;
}