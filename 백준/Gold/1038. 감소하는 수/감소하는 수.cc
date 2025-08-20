#include <iostream>

using namespace std;

int num[10][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 10; ++i)
	{
		num[0][i] = 1;
	}

	for (int i = 1; i < 10; ++i)
	{
		for (int j = i; j < 10; ++j)
		{
			num[i][j] = num[i][j - 1] + num[i - 1][j - 1];
		}
	}

	int n;
	cin >> n;
	int level = 0;
	int pos;
	for (; level < 10; ++level)
	{
		pos = level;
		for (; pos < 10; ++pos)
		{
			if (n < num[level][pos])
			{
				cout << pos;
				break;
			}
			n -= num[level][pos];
		}
		if (pos != 10)
		{
			break;
		}
	}

	if (level == 10)
	{
		cout << -1;
	}
	else
	{
		while (level--)
		{
			pos = level;
			for (; pos < 10; ++pos)
			{
				if (n < num[level][pos])
				{
					cout << pos;
					break;
				}
				n -= num[level][pos];
			}
		}
	}

	return 0;
}