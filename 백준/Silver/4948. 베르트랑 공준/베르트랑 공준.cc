#include <iostream>
#include <vector>

using namespace std;

vector<bool> prime(250000, true);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	prime[1] = false;
	for (int i = 2; i * i < 250000; ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j < 250000; j += i)
			{
				prime[j] = false;
			}
		}
	}

	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}

		int cnt = 0;
		for (int i = n + 1; i <= n * 2; ++i)
		{
			cnt += prime[i];
		}
		cout << cnt << '\n';
	}

	return 0;
}