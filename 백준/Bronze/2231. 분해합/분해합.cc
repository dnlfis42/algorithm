#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int d = 0;
	int t = n;
	while (t)
	{
		t /= 10;
		++d;
	}

	int ans = 0;
	int i = max(n / 2, n - 9 * d);
	for (; i < n; ++i)
	{
		int cur = i;
		t = i;
		while (t)
		{
			cur += t % 10;
			t /= 10;
		}

		if (cur == n)
		{
			ans = i;
			break;
		}
	}
	cout << ans;

	return 0;
}

int main()
{
	return solution();
}