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

	vector<int> dp(k + 1, 0); // 배낭의 무게가 k일 때 최대로 넣을 수 있는 가치를 저장
	for (int i = 0; i < n; ++i)
	{
		int w = stuff[i].first;
		int v = stuff[i].second;

		for (int j = k; j >= w; --j)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];

	return 0;
}