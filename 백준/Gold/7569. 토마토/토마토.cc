#include <bits/stdc++.h>

using namespace std;

struct Tomato
{
	int h;
	int r;
	int c;
	int day;
};

constexpr int dh[]{ 0,0,0,0,1,-1 };
constexpr int dr[]{ 0,1,0,-1,0,0 };
constexpr int dc[]{ 1,0,-1,0,0,0 };

int cube[101][101][101]; // [층][세로][가로]

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m; // 가로
	int n; // 세로
	int h; // 높이
	cin >> m >> n >> h;

	queue<Tomato> q;

	for (int i = 0; i < h; ++i)
	{
		for (int r = 0; r < n; ++r)
		{
			for (int c = 0; c < m; ++c)
			{
				int x;
				cin >> x;
				cube[i][r][c] = x;
				if (x == 1)
				{
					q.push({ i,r,c,0 });
				}
			}
		}
	}

	int day = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		day = cur.day;

		for (int i = 0; i < 6; ++i)
		{
			int th = cur.h + dh[i];
			int tr = cur.r + dr[i];
			int tc = cur.c + dc[i];

			if (th < 0 || th >= h || tr < 0 || tr >= n || tc < 0 || tc >= m)
			{
				continue;
			}

			if (cube[th][tr][tc] == 0)
			{
				cube[th][tr][tc] = 1;
				q.push({ th,tr,tc,cur.day + 1 });
			}
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int r = 0; r < n; ++r)
		{
			for (int c = 0; c < m; ++c)
			{
				if (cube[i][r][c] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << day;
	return 0;
}

int main()
{
	return solution();
}