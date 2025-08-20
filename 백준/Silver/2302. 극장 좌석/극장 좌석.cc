#include <iostream>

using namespace std;

int fibo[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 2;
	int len;
	int max_len = 2;

	int n;
	int m;
	cin >> n >> m;

	int ans = 1;
	int st = 1;
	int en = n + 1;
	for (int i = 0; i < m; ++i)
	{
		cin >> en;
		len = en - st;
		if (len > max_len)
		{
			for (int j = max_len + 1; j <= len; ++j)
			{
				fibo[j] = fibo[j - 1] + fibo[j - 2];
			}
			max_len = len;
		}
		ans *= fibo[len];

		st = en + 1;
	}
	len = n + 1 - st;
	if (len > max_len)
	{
		for (int i = max_len + 1; i <= len; ++i)
		{
			fibo[i] = fibo[i - 1] + fibo[i - 2];
		}
	}
	ans *= fibo[len];

	cout << ans;

	return 0;
}