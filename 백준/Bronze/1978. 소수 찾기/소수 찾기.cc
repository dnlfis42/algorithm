#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> prime(1001, true);
	prime[1] = false;
	for (int i = 2; i * i <= 1000; ++i)
	{
		if (prime[i])
		{
			for (int j = i * 2; j <= 1000; j += i)
			{
				prime[j] = false;
			}
		}
	}

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		cnt += prime[m];
	}
	cout << cnt;

	return 0;
}