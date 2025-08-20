#include <iostream>

using namespace std;

int seq[1000];
int res[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> seq[i];
	}

	res[0] = seq[0];
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (seq[j] < seq[i] && res[j] > res[i])
			{
				res[i] = res[j];
			}
		}
		res[i] += seq[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (res[i] > ans)
		{
			ans = res[i];
		}
	}
	cout << ans;

	return 0;
}