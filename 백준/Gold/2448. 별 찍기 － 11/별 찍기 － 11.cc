#include <iostream>
#include <cstring>

using namespace std;

bool line[6143];
int n;

static void recur(int size, int row, int col)
{
	if (size == 3)
	{
		switch (row)
		{
		case 0:
			line[col + 2] = true;
			break;
		case 1:
			line[col + 1] = true;
			line[col + 3] = true;
			break;
		case 2:
			memset(line + col, 1, 5);
			break;
		}

		return;
	}

	int sub = size / 2;
	if (row < sub)
	{
		recur(sub, row % sub, col + sub);
	}
	else
	{
		recur(sub, row % sub, col);
		recur(sub, row % sub, col + size);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int width = n * 2 - 1;

	for (int i = 0; i < n; ++i)
	{
		memset(line, 0, sizeof(bool) * width);
		recur(n, i, 0);
		for (int j = 0; j < width; ++j)
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