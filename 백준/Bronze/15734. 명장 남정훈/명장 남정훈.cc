#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int l, r, a;
	cin >> l >> r >> a;

	int diff = abs(l - r);
	int move = min(diff, a);

	if (l < r)
	{
		l += move;
	}
	else
	{
		r += move;
	}
	a -= move;

	cout << min(l, r) * 2 + (a / 2) * 2;

	return 0;
}

int main()
{
	return solution();
}