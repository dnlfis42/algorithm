#include <iostream>

using namespace std;

pair<int, int> result[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	result[0].first = 1;
	result[1].second = 1;

	int t;
	cin >> t;

	int n;
	int max_num = -1;
	while (t--)
	{
		cin >> n;
		if (max_num < n)
		{
			max_num = n;
			for (int i = 2; i <= n; ++i)
			{
				result[i].first = result[i - 2].first + result[i - 1].first;
				result[i].second = result[i - 2].second + result[i - 1].second;
			}
		}
		cout << result[n].first << ' ' << result[n].second << '\n';
	}

	return 0;
}