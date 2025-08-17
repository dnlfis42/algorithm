#include <iostream>

using namespace std;

int n;
int m;

int order[8];

static void recur(int level, int before)
{
	if (level == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << order[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = before; i < n; ++i)
	{
		order[level] = i + 1;
		recur(level + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	recur(0, 0);

	return 0;
}