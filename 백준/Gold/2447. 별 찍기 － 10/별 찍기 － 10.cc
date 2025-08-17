#include <iostream>
#include <cstring>

using namespace std;

bool line[6561];
int n;

static void recur(int size, int row, int col)
{
	if (size == 3)
	{
		if (row == 1)
		{
			line[col + 1] = false;
		}

		return;
	}

	int sub = size / 3;

	recur(sub, row % sub, col);
	if (row >= sub && row < sub * 2)
	{
		memset(line + col + sub, 0, sizeof(bool) * sub);
	}
	else
	{
		recur(sub, row % sub, col + sub);
	}
	recur(sub, row % sub, col + sub * 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		memset(line, 1, sizeof(bool) * n);
		recur(n, i, 0);
		for (int j = 0; j < n; ++j)
		{
			if (line[j])
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}