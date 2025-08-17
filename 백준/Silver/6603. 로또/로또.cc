#include <iostream>

using namespace std;

int number[12];
int order[6];

int k;

static void recur(int level, int start)
{
	if (level == 6)
	{
		for (int i = 0; i < level; ++i)
		{
			cout << order[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = start; i < k; ++i)
	{
		if (i + 6 - level > k)
		{
			break;
		}

		order[level] = number[i];
		recur(level + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (;;)
	{
		cin >> k;

		if (k == 0)
		{
			break;
		}

		for (int i = 0; i < k; ++i)
		{
			cin >> number[i];
		}

		recur(0, 0);
		cout << '\n';
	}

	return 0;
}