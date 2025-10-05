#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;

	--n;
	long long sub = 6;
	int cnt = 1;
	while (n > 0)
	{
		n -= sub;
		sub += 6;
		++cnt;
	}
	cout << cnt;

	return 0;
}

int main()
{
	return solution();
}