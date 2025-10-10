#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int ans = 0;
	for (int i = n / 2; i <= n; ++i)
	{
		int cur = i;
		int t = i;

		while (t)
		{
			cur += t % 10;
			t /= 10;
		}

		if (n == cur)
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