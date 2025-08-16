#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int x;
	int y;
	bool is_wrecked;
};

char map[1005][1005];
int route[1005][1005];
int route_wreck[1005][1005];

queue<Point> points;

int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> map[i];
	}

	points.push({ 0,0,false });
	route[0][0] = 1;

	bool is_possible = false;
	for (;;)
	{
		if (points.empty())
		{
			break;
		}

		auto sub = points.front();
		points.pop();

		if (sub.x == m - 1 && sub.y == n - 1)
		{
			is_possible = true;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int tx = sub.x + mx[i];
			int ty = sub.y + my[i];

			if (tx < 0 || tx >= m || ty < 0 || ty >= n)
			{
				continue;
			}

			if (sub.is_wrecked)
			{
				if (map[ty][tx] == '1')
				{
					continue;
				}

				if (route_wreck[ty][tx] > 0)
				{
					continue;
				}

				route_wreck[ty][tx] = route_wreck[sub.y][sub.x] + 1;
				points.push({ tx,ty,true });
			}
			else
			{
				if (map[ty][tx] == '1')
				{
					route_wreck[ty][tx] = route[sub.y][sub.x] + 1;
					points.push({ tx,ty,true });
				}
				else
				{
					if (route[ty][tx] > 0)
					{
						continue;
					}

					route[ty][tx] = route[sub.y][sub.x] + 1;
					points.push({ tx,ty, false });
				}
			}
		}
	}

	if (is_possible)
	{
		if (route[n - 1][m - 1] > 0)
		{
			cout << route[n - 1][m - 1];
		}
		else
		{
			cout << route_wreck[n - 1][m - 1];
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}