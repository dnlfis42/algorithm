#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int x = 666;
	for (int i = 0;; ++x)
	{
		bool found = false;
		int t = x;
		while (t > 512)
		{
			if (t % 1000 == 666)
			{
				found = true;
				break;
			}
			t /= 10;
		}

		if (found && ++i == n)
		{
			break;
		}
	}
	cout << x;

	return 0;
}

int main()
{
	return solution();
}