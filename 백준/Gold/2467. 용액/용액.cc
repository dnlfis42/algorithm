#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int li = 0;
	int ri = n - 1;
	int s1 = v[li], s2 = v[ri];
	int mn = abs(s1 + s2);

	while (li < ri)
	{
		int res = v[li] + v[ri];
		if (abs(res) < mn)
		{
			mn = abs(res);
			s1 = v[li];
			s2 = v[ri];
		}

		if (res < 0)
		{
			++li;
		}
		else if (res > 0)
		{
			--ri;
		}
		else
		{
			break;
		}
	}
	cout << s1 << " " << s2;

	return 0;
}

int main()
{
	return solution();
}