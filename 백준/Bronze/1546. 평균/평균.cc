#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vec(n);
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
		mx = max(mx, vec[i]);
	}
	int sum = 0;
	for (int x : vec)
	{
		sum += x * 10000 / mx;
	}
	cout << fixed << setprecision(2) << static_cast<double>(sum) / n / 100;

	return 0;
}

int main()
{
	return solution();
}