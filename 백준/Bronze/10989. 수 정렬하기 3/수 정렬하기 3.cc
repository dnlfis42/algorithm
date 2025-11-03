#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v(10001, 0);
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		++v[x];
	}
	for (int i = 1; i <= 10000; ++i)
	{
		while (v[i]--)
		{
			cout << i << "\n";
		}
	}

	return 0;
}

int main()
{
	return solution();
}