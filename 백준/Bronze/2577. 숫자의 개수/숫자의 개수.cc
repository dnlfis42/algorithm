#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt[10]{};

	int a, b, c;
	cin >> a >> b >> c;
	
	int x = a * b * c;
	while (x)
	{
		++cnt[x % 10];
		x /= 10;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << cnt[i] << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}