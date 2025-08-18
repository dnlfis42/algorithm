#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int field[12][6];
bool visit[12][6];
bool result[12][6];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int minimum_row = 0;
	bool is_empty_row;
	char str[7];
	for (int i = 0; i < 12; ++i)
	{
		is_empty_row = true;
		cin >> str;
		for (int j = 0; j < 6; ++j)
		{
			if (str[j] == '.')
			{
				field[i][j] = 0;
			}
			else if (str[j] == 'R')
			{
				field[i][j] = 1;
				is_empty_row = false;
			}
			else if (str[j] == 'G')
			{
				field[i][j] = 2;
				is_empty_row = false;
			}
			else if (str[j] == 'B')
			{
				field[i][j] = 3;
				is_empty_row = false;
			}
			else if (str[j] == 'P')
			{
				field[i][j] = 4;
				is_empty_row = false;
			}
			else if (str[j] == 'Y')
			{
				field[i][j] = 5;
				is_empty_row = false;
			}
		}

		if (is_empty_row)
		{
			minimum_row++;
		}
	}

	int cnt = 0;
	int color;
	bool can_delete;

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	for (;;)
	{
		can_delete = false;
		for (int r = minimum_row; r < 12; ++r)
		{
			for (int c = 0; c < 6; ++c)
			{
				if (field[r][c] > 0 && !visit[r][c])
				{
					visit[r][c] = true;
					color = field[r][c];
					q1.push({ r,c });
					q2.push({ r,c });
					while (!q1.empty())
					{
						auto p = q1.front();
						q1.pop();

						for (int k = 0; k < 4; ++k)
						{
							int tx = dx[k] + p.second;
							int ty = dy[k] + p.first;

							if (tx < 0 || tx >= 6 || ty < 0 || ty >= 12)
							{
								continue;
							}

							if (field[ty][tx] != color || visit[ty][tx])
							{
								continue;
							}

							visit[ty][tx] = true;
							q1.push({ ty,tx });
							q2.push({ ty,tx });
						}
					}

					if (q2.size() >= 4)
					{
						while (!q2.empty())
						{
							auto p = q2.front();
							q2.pop();

							result[p.first][p.second] = true;
						}
						can_delete = true;
					}
					else
					{
						while (!q2.empty())
						{
							q2.pop();
						}
					}
				}
			}
		}

		if (can_delete)
		{
			// result 토대로 field 수정 & result 초기화
			for (int c = 0; c < 6; ++c)
			{
				for (int r = minimum_row; r < 12; ++r)
				{
					if (result[r][c])
					{
						result[r][c] = false;
						for (int k = r; k >= minimum_row; --k)
						{
							field[k][c] = field[k - 1][c];
						}
						field[minimum_row][c] = 0;
					}
				}
			}

			// visit 초기화
			memset(visit, 0, sizeof(bool) * 12 * 6);

			// minimum_row 업데이트
			while (minimum_row < 12)
			{
				if (field[minimum_row][0] > 0 ||
					field[minimum_row][1] > 0 ||
					field[minimum_row][2] > 0 ||
					field[minimum_row][3] > 0 ||
					field[minimum_row][4] > 0 ||
					field[minimum_row][5] > 0)
				{
					break;
				}
				++minimum_row;
			}

			++cnt;
		}
		else
		{
			break;
		}
	}
	cout << cnt;

	return 0;
}