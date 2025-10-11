#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> buckets(1001, 0);

	int n;
	cin >> n;

	int mn_time = 2000;
	int mx_time = 0;
	for (int i = 0; i < n; ++i)
	{
		int s, t, c;
		cin >> s >> t >> c;
		mn_time = min(mn_time, s);
		mx_time = max(mx_time, t);

		for (int j = s; j <= t; ++j)
		{
			buckets[j] += c;
		}
	}

	int mx = 0;
	for (int i = mn_time; i <= mx_time; ++i)
	{
		mx = max(mx, buckets[i]);
	}
	cout << mx;

	return 0;
}

int main()
{
	return solution();
}