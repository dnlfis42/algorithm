#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	for (auto& d : v)
	{
		cout << d.first << " " << d.second << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}