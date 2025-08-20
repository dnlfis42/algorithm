#include <iostream>
#include <algorithm>

using namespace std;

int w[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> w[i];
	}
	sort(w, w + n);

	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		ans = max(ans, w[i] * (n - i));
	}
	cout << ans;

	return 0;
}