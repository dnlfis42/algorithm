#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> dot[1'000'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> dot[i].first >> dot[i].second;
	}
	sort(dot, dot + n);

	int ans = 0;
	int st = dot[0].first;
	int en = dot[0].second;
	for (int i = 1; i < n; ++i)
	{
		if (dot[i].first <= en)
		{
			en = max(en, dot[i].second);
		}
		else
		{
			ans += (en - st);
			st = dot[i].first;
			en = dot[i].second;
		}
	}
	ans += (en - st);
	cout << ans;

	return 0;
}