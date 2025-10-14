#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int coin[10]{};

	int n; // 동전의 종류
	int k; // 가치
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> coin[i];
	}

	int cnt = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		for (;;)
		{
			if (k >= coin[i])
			{
				k -= coin[i];
				++cnt;
			}
			else
			{
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}

int main()
{
	return solution();
}