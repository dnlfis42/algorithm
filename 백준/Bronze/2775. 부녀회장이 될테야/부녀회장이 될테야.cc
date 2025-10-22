#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int apart[15][15];
	for (int i = 0; i < 15; ++i)
	{
		apart[i][0] = 0;
	}
	for (int i = 1; i < 15; ++i)
	{
		apart[0][i] = i;
	}
	for (int f = 1; f <= 14; ++f)
	{
		for (int r = 1; r <= 14; ++r)
		{
			apart[f][r] = apart[f][r - 1] + apart[f - 1][r];
		}
	}

	int t;
	cin >> t;

	while (t--)
	{
		int k, n;
		cin >> k >> n; // k층 n호
		cout << apart[k][n] << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}