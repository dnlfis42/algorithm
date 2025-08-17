#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool bool_map[105][105];
int number_map[105][105];
int visit[105][105];

int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> bool_map[i][j];
		}
	}

	int island_num = 1;
	int length = 500;
	bool found = false;

	queue<pair<int, int>> island;
	queue<pair<int, int>> bridge;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (bool_map[i][j] && number_map[i][j] == 0) // 최초의 섬 찾음
			{
				number_map[i][j] = island_num; // 섬 넘버링
				island.push({ i,j });

				while (!island.empty()) // 섬
				{
					auto p = island.front();
					island.pop();

					for (int k = 0; k < 4; ++k)
					{
						int ty = p.first + my[k];
						int tx = p.second + mx[k];

						if (tx < 0 || tx >= n || ty < 0 || ty >= n)
						{
							continue;
						}

						if (number_map[ty][tx] == 0) // 기록되지 않은 부분
						{
							if (bool_map[ty][tx]) // 섬이라면
							{
								number_map[ty][tx] = island_num;
								island.push({ ty,tx });
							}
							else // 바다라면
							{
								if (visit[ty][tx] == 0) // 이전에 기록 안해놨을 경우에
								{
									visit[ty][tx] = 1; // 다리 시작 길이
									bridge.push({ ty,tx });
								}
							}
						}
					}
				}

				found = false;

				while (!bridge.empty()) // 다리
				{
					pair<int, int> p = bridge.front();
					bridge.pop();

					for (int k = 0; k < 4; ++k)
					{
						int ty = p.first + my[k];
						int tx = p.second + mx[k];

						if (tx < 0 || tx >= n || ty < 0 || ty >= n)
						{
							continue;
						}

						if (bool_map[ty][tx]) // 섬임
						{
							if (number_map[ty][tx] != island_num) // 다른 섬임
							{
								found = true;
								break;
							}
						}
						else // 바다임
						{
							if (visit[ty][tx] == 0) // 다리 건설 안된 곳
							{
								visit[ty][tx] = visit[p.first][p.second] + 1; // 길이 증가
								bridge.push({ ty,tx });
							}
						}
					}

					if (found)
					{
						if (visit[p.first][p.second] < length)
						{
							length = visit[p.first][p.second];
						}
						break;
					}
				}

				if (length == 1)
				{
					break;
				}

				while (!bridge.empty())
				{
					bridge.pop();
				}

				memset(visit, 0, sizeof(int) * 105 * n);

				++island_num;
			}
		}

		if (length == 1)
		{
			break;
		}
	}

	cout << length;

	return 0;
}