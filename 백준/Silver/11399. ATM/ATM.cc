#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	vector<int> dp(n, 0);
	dp[0] = v[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = dp[i - 1] + v[i];
	}
	int sum = 0;
	for (auto i : dp)
	{
		sum += i;
	}
	cout << sum;

	return 0;
}