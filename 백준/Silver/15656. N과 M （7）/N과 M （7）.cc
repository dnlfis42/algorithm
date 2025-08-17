#include <iostream>
#include <algorithm>

using namespace std;

int n;
int m;

int number[7];
int order[7];

static void recur(int level)
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

	for (int i = 0; i < n; ++i)
	{
		order[level] = number[i];
		recur(level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> number[i];
	}
	sort(number, number + n);

	recur(0);

	return 0;
}