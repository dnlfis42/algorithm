#include <iostream>
#include <algorithm>

using namespace std;

int numbers[100001];

static bool bs(int n, int st, int en)
{
	if (st == en)
	{
		return false;
	}

	int mid = (st + en) / 2;
	if (numbers[mid] < n)
	{
		return bs(n, mid + 1, en);
	}
	else if (numbers[mid] == n)
	{
		return true;
	}
	else
	{
		return bs(n, st, mid);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
	}
	sort(numbers, numbers + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		cout << bs(t, 0, n) << '\n';
	}

	return 0;
}