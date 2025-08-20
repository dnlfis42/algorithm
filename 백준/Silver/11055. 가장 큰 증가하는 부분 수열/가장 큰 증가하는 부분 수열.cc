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
	cin >> seq[0];
	res[0] = seq[0];

	int ans = res[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> seq[i];
		for (int j = 0; j < i; ++j)
		{
			if (seq[j] < seq[i] && res[j] > res[i])
			{
				res[i] = res[j];
			}
		}
		res[i] += seq[i];

		if (ans < res[i])
		{
			ans = res[i];
		}
	}
	cout << ans;

	return 0;
}