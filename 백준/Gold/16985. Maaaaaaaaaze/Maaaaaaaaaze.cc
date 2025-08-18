#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Pos
{
	int x;
	int y;
	int z;
};

int maze_idx[5]; // 0 ~ 3
bool maze[5][4][5][5];
int maze_order[5];
bool check_maze[5];
int visit[5][5][5];
int answer = 10000;
bool found_shortest_path;

int dx[] = { 1,0,-1,0,0,0 };
int dy[] = { 0,1,0,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

static void bfs()
{
	if (!maze[maze_order[0]][maze_idx[0]][0][0] || !maze[maze_order[4]][maze_idx[4]][4][4]) // 입구나 출구가 막혀있는 경우
	{
		return;
	}

	memset(visit, 0, sizeof(int) * 125);

	queue<Pos> q;

	visit[0][0][0] = 1;
	q.push({ 0,0,0 });

	int route = 0;
	while (!q.empty())
	{
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_z = q.front().z;
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int tx = cur_x + dx[i];
			int ty = cur_y + dy[i];
			int tz = cur_z + dz[i];

			if (tx < 0 || tx >= 5 || ty < 0 || ty >= 5 || tz < 0 || tz >= 5)
			{
				continue;
			}

			if (!maze[maze_order[tz]][maze_idx[tz]][ty][tx] || visit[tz][ty][tx] > 0)
			{
				continue;
			}

			if (tx == 4 && ty == 4 && tz == 4)
			{
				route = visit[cur_z][cur_y][cur_x];
				break;
			}

			visit[tz][ty][tx] = visit[cur_z][cur_y][cur_x] + 1;
			q.push({ tx,ty,tz });
		}
	}

	if (route > 0)
	{
		if (route < answer)
		{
			answer = route;
			if (answer == 12)
			{
				found_shortest_path = true;
			}
		}
	}
}

static void maze_ordering(int idx = 0)
{
	if (found_shortest_path)
	{
		return;
	}

	if (idx == 5)
	{
		bfs();
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (!check_maze[i])
		{
			check_maze[i] = true;
			maze_order[idx] = i;
			maze_ordering(idx + 1);
			check_maze[i] = false;
		}
	}
}

static void backtracking(int idx)
{
	if (found_shortest_path)
	{
		return;
	}

	if (idx == 5)
	{
		for (int i = 0; i < 4; ++i)
		{
			maze_idx[0] = i;
			maze_ordering();
		}
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		maze_idx[idx] = i;
		backtracking(idx + 1);
	}
}

static void rotate(int z, int dir)
{
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			maze[z][dir + 1][c][4 - r] = maze[z][dir][r][c];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; ++i)
	{
		for (int r = 0; r < 5; ++r)
		{
			for (int c = 0; c < 5; ++c)
			{
				cin >> maze[i][0][r][c];
			}
		}

		rotate(i, 0);
		rotate(i, 1);
		rotate(i, 2);
	}

	backtracking(1);
	if (answer == 10000)
	{
		cout << -1;
	}
	else
	{
		cout << answer;
	}

	return 0;
}