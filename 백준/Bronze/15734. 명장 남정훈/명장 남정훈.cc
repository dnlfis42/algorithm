#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int l, r, a;
	cin >> l >> r >> a;

	int diff = 0;
	int move = 0;
	int ans = 0;
	if (l < r)
	{
		diff = r - l;
		int move = min(diff, a);
		l += move;
		a -= move;
		ans = l * 2 + (a >> 1 << 1);
	}
	else if (l > r)
	{
		diff = l - r;
		int move = min(diff, a);
		r += move;
		a -= move;
		ans = r * 2 + (a >> 1 << 1);
	}
	else
	{
		ans = l * 2 + (a >> 1 << 1);
	}
	cout << ans;

	return 0;
}

int main()
{
	return solution();
}