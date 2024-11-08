#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

static const int R4[4]{ 0,-1,0,1 };
static const int C4[4]{ 1,0,-1,0 };

static int answer;
static vector<string> students(5);
static bool selected[5][5];
static bool copied[5][5];

static void collect7(const int row, const int col, const int cnt, const int numOfS);
static bool checkConnection(const int row, const int col);
static void copying();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 5; ++i)
	{
		cin >> students[i];
	}

	collect7(0, 0, 0, 0);
	cout << answer;

	return 0;
}

void collect7(const int row, const int col, const int cnt, const int numOfS)
{
	if (cnt == 7)
	{
		if (col == 0 && checkConnection(row - 1, 4))
		{
			++answer;
		}
		else if (checkConnection(row, col - 1))
		{
			++answer;
		}

		return;
	}

	for (int c = col; c < 5 && row * 5 + c <= 18 + cnt; ++c)
	{
		if (students[row][c] == 'S')
		{
			selected[row][c] = true;
			if (c == 4)
			{
				collect7(row + 1, 0, cnt + 1, numOfS + 1);
			}
			else
			{
				collect7(row, c + 1, cnt + 1, numOfS + 1);
			}
			selected[row][c] = false;
		}
		else if (cnt < numOfS + 3)
		{
			selected[row][c] = true;
			if (c == 4)
			{
				collect7(row + 1, 0, cnt + 1, numOfS);
			}
			else
			{
				collect7(row, c + 1, cnt + 1, numOfS);
			}
			selected[row][c] = false;
		}
	}

	for (int r = row + 1; r < 5; ++r)
	{
		for (int c = 0; c < 5 && r * 5 + c <= 18 + cnt; ++c)
		{
			if (students[r][c] == 'S')
			{
				selected[r][c] = true;
				if (c == 4)
				{
					collect7(r + 1, 0, cnt + 1, numOfS + 1);
				}
				else
				{
					collect7(r, c + 1, cnt + 1, numOfS + 1);
				}
				selected[r][c] = false;
			}
			else if (cnt < numOfS + 3)
			{
				selected[r][c] = true;
				if (c == 4)
				{
					collect7(r + 1, 0, cnt + 1, numOfS);
				}
				else
				{
					collect7(r, c + 1, cnt + 1, numOfS);
				}
				selected[r][c] = false;
			}
		}
	}
}

bool checkConnection(const int row, const int col)
{
	copying();

	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ row,col });
	copied[row][col] = false;

	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int cr = r + R4[i];
			int cc = c + C4[i];
			if (cr < 0 || 4 < cr || cc < 0 || 4 < cc || !copied[cr][cc])
			{
				continue;
			}
			++cnt;
			q.push({ cr,cc });
			copied[cr][cc] = false;
		}
	}

	if (cnt == 7)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void copying()
{
	for (int r = 0; r < 5; ++r)
	{
		for (int c = 0; c < 5; ++c)
		{
			copied[r][c] = selected[r][c];
		}
	}
}