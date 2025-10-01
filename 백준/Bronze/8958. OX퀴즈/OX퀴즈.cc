#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		string str;
		cin >> str;

		int cnt = 0;
		int ans = 0;
		for (char c : str)
		{
			if (c == 'O')
			{
				ans += ++cnt;
			}
			else
			{
				cnt = 0;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}