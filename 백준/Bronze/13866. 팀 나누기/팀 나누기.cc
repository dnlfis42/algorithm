#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int sum = a + b + c + d;
	int ans = abs(sum - a * 2 - b * 2);
	ans = min(ans, abs(sum - a * 2 - c * 2));
	ans = min(ans, abs(sum - a * 2 - d * 2));
	cout << ans;

	return 0;
}

int main()
{
	return solution();
}