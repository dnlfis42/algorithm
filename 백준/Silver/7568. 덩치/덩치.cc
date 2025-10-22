#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> human(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> human[i].first >> human[i].second;
	}

	vector<int> cnt(n, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j == i)
			{
				continue;
			}

			if (human[i].first < human[j].first && human[i].second < human[j].second)
			{
				++cnt[i];
			}
		}
	}

	for (int x : cnt)
	{
		cout << x + 1 << " ";
	}

	return 0;
}

int main()
{
	return solution();
}