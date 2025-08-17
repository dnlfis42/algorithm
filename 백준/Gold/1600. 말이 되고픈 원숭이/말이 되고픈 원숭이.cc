#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
	int x;
	int y;
	int k;
};

int field[200][200];
int visit[31][200][200];

int dx[12] = { 1,0,-1,0,2,1,-1,-2,-2,-1,1,2 };
int dy[12] = { 0,1,0,-1,1,2,2,1,-1,-2,-2,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k; // 점프 횟수
	int w; // 가로
	int h; // 세로
	cin >> k >> w >> h;

	bool can_horse = true;
	if (w == 1 || h == 1)
	{
		can_horse = false;
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> field[i][j];
		}
	}

	queue<Pos> q;
	q.push({ 0,0,0 });

	int cur_x;
	int cur_y;
	int cur_k;
	bool is_possible = false;
	while (!q.empty())
	{
		cur_x = q.front().x;
		cur_y = q.front().y;
		cur_k = q.front().k;
		q.pop();

		if (cur_x == w - 1 && cur_y == h - 1)
		{
			is_possible = true;
			break;
		}

		int tx;
		int ty;
		for (int i = 0; i < 4; ++i)
		{
			tx = cur_x + dx[i];
			ty = cur_y + dy[i];

			if (tx < 0 || tx >= w || ty < 0 || ty >= h)
			{
				continue;
			}

			if (field[ty][tx] == 1 || visit[cur_k][ty][tx] > 0)
			{
				continue;
			}

			visit[cur_k][ty][tx] = visit[cur_k][cur_y][cur_x] + 1;
			q.push({ tx,ty,cur_k });
		}

		if (cur_k < k && can_horse)
		{
			for (int i = 4; i < 12; ++i)
			{
				tx = cur_x + dx[i];
				ty = cur_y + dy[i];

				if (tx < 0 || tx >= w || ty < 0 || ty >= h)
				{
					continue;
				}

				if (field[ty][tx] == 1 || visit[cur_k + 1][ty][tx] > 0)
				{
					continue;
				}

				visit[cur_k + 1][ty][tx] = visit[cur_k][cur_y][cur_x] + 1;
				q.push({ tx,ty,cur_k + 1 });
			}
		}
	}

	if (is_possible)
	{
		cout << visit[cur_k][cur_y][cur_x];
	}
	else
	{
		cout << -1;
	}

	return 0;
}