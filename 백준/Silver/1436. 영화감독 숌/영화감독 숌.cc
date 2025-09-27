#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int idx = 0;
	int x = 666;
	for (;; ++x)
	{
		if (to_string(x).find("666") != string::npos)
		{
			if (++idx == n)
			{
				break;
			}
		}
	}
	cout << x;

	return 0;
}

int main()
{
	return solution();
}