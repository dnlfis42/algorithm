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
	sort(v.begin(), v.end());

	int mn = INT_MAX;
	int s1 = 0, s2 = 0;
	for (int li = 0, ri = n - 1;;)
	{
		if (li == ri)
		{
			break;
		}

		int res = v[li] + v[ri];
		if (res < 0)
		{
			if (mn > res * -1)
			{
				mn = res * -1;
				s1 = v[li];
				s2 = v[ri];
			}
			++li;
		}
		else if (res > 0)
		{
			if (mn > res)
			{
				mn = res;
				s1 = v[li];
				s2 = v[ri];
			}
			--ri;
		}
		else
		{
			s1 = v[li];
			s2 = v[ri];
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