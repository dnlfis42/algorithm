#include <iostream>
#include <algorithm>

using namespace std;

int n;

long long solutions[5001];
long long ans[3] = { 1'111'111'111,1'111'111'111 ,1'111'111'111 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> solutions[i];
	}
	sort(solutions, solutions + n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int idx = static_cast<int>(lower_bound(solutions, solutions + n, -solutions[i] - solutions[j]) - solutions);
			for (int k = -3; k <= 2; ++k)
			{
				if (idx + k < 0 || idx + k >= n)
				{
					continue;
				}
				if (idx + k == i || idx + k == j)
				{
					continue;
				}
				if (abs(ans[0] + ans[1] + ans[2]) > abs(solutions[i] + solutions[j] + solutions[idx + k]))
				{
					ans[0] = solutions[i];
					ans[1] = solutions[j];
					ans[2] = solutions[idx + k];
				}
			}
		}
	}
	sort(ans, ans + 3);
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

	return 0;
}