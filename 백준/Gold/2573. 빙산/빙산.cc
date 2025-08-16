#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int ocean[2][305][305];
int active = 0;
bool ice[305][305];

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
		for (int j = 0; j < m; ++j)
		{
			cin >> ocean[active][i][j];
		}
	}

	int year = 0;
	for (;;)
	{
		// 녹이기
		memset(ocean[1 - active], 0, sizeof(int) * 305 * 305);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (ocean[active][i][j] > 0)
				{
					int melt = 0;
					for (int k = 0; k < 4; ++k)
					{
						int ty = i + my[k];
						int tx = j + mx[k];

						if (tx < 0 || tx >= m || ty < 0 || ty >= n)
						{
							continue;
						}

						if (ocean[active][ty][tx] > 0)
						{
							continue;
						}

						++melt;
					}

					ocean[1 - active][i][j] = ocean[active][i][j] - melt;
					if (ocean[1 - active][i][j] < 0)
					{
						ocean[1 - active][i][j] = 0;
					}
				}
			}
		}

		++year;
		active = 1 - active;

		// 개수 세기
		memset(ice, 0, sizeof(bool) * 305 * 305);

		int cnt = 0;
		bool found = false;

		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (ocean[active][i][j] > 0 && ice[i][j] == false)
				{
					if (cnt > 0)
					{
						found = true;
						break;
					}

					ice[i][j] = true;
					q.push({ i,j });

					for (;;)
					{
						if (q.empty())
						{
							++cnt;
							break;
						}

						auto now = q.front();
						q.pop();

						for (int k = 0; k < 4; ++k)
						{
							int ty = now.first + my[k];
							int tx = now.second + mx[k];

							if (tx < 0 || tx >= m || ty < 0 || ty >= n)
							{
								continue;
							}

							if (ocean[active][ty][tx] == 0)
							{
								continue;
							}

							if (ice[ty][tx] == true)
							{
								continue;
							}

							ice[ty][tx] = true;
							q.push({ ty,tx });
						}
					}
				}
			}

			if (found)
			{
				break;
			}
		}

		if (found)
		{
			cout << year;
			break;
		}

		if (cnt == 0)
		{
			cout << 0;
			break;
		}
	}

	return 0;
}