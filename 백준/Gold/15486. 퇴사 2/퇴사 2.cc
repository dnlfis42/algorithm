#include <iostream>

using namespace std;

int day[1'500'001];
int pay[1'500'001];
int res[1'500'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> day[i] >> pay[i];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		if (i + day[i] > n)
		{
			res[i] = res[i + 1];
		}
		else
		{
			res[i] = max(res[i + day[i]] + pay[i], res[i + 1]);
		}
	}
	cout << res[0];

	return 0;
}