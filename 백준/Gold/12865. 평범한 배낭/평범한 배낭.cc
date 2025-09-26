#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 물품의 수
	int k; // 준서가 버틸 수 있는 무게
	cin >> n >> k;

	vector<pair<int, int>> stuff(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> stuff[i].first >> stuff[i].second;
	}

	vector<int> mxval(k + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		int w = stuff[i].first;
		int v = stuff[i].second;

		for (int j = 0; j <= k - w; ++j)
		{
			mxval[j] = max(mxval[j], v + mxval[j + w]);
		}
	}

	int mx = 0;
	for (int i = 0; i <= k; ++i)
	{
		if (mx < mxval[i])
		{
			mx = mxval[i];
		}
	}
	cout << mx;

	return 0;
}