#include <iostream>
#include <algorithm>

using namespace std;

int n;
int m;

int number[8];
int order[8];
bool check[8];

static void recur(int level, int start)
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

	int before = 0;
	for (int i = start; i < n; ++i)
	{
		if (!check[i] && before != number[i])
		{
			check[i] = true;
			order[level] = number[i];
			before = number[i];
			recur(level + 1, i + 1);
			check[i] = false;
		}
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

	recur(0, 0);

	return 0;
}