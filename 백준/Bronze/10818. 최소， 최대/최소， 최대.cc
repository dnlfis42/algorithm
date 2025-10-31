#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int mx = -1'000'001;
	int mn = 1'000'001;

	while (n--)
	{
		int x;
		cin >> x;
		mx = max(x, mx);
		mn = min(x, mn);
	}
	cout << mn << " " << mx;

	return 0;
}

int main()
{
	return solution();
}