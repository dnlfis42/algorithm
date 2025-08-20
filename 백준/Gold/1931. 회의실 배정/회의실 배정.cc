#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> sch[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> sch[i].second >> sch[i].first;
	}
	sort(sch, sch + n);

	int cnt = 0;
	int en = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sch[i].second < en)
		{
			continue;
		}
		en = sch[i].first;
		++cnt;
	}

	cout << cnt;

	return 0;
}